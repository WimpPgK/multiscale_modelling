
import tkinter as tk
from tkinter import simpledialog
import matrix
import CA_matrix
from tkinter import ttk
from tkinter import *


import time

class Gui:

    def guiInit(self):




        window = tk.Tk()
        window.state('zoomed')
        xDimention = IntVar()
        yDimention = IntVar()
        amountOfGrains = IntVar()
        MCS = IntVar()
        numberGrainSelect = IntVar()
        secondGrainGrowth = StringVar()
        energyDistribution = StringVar()

        xDimention.set(60)
        yDimention.set(50)
        amountOfGrains.set(3)
        MCS.set(10)
        numberGrainSelect.set(2)

        self.size_x_canvas = int(window.winfo_screenwidth()*0.84)
        self.size_y_canvas = int(window.winfo_screenheight()*0.91)

        # generate dwawing space
        canvas = tk.Canvas(window, width=self.size_x_canvas, height=self.size_y_canvas, bg="blue")
        canvas.grid(row=0, column=4, rowspan=70,
                    columnspan=5)  # plansza do rysowania bedzie zajmowac 100 wierszy i 4 kolumny

        ################# GUI of space generation ##########################

        label_xDimention = ttk.Label(window, text="X space dimention").grid(column=0, row=0, sticky=E)
        label_yDimention = ttk.Label(window, text="Y space dimention").grid(column=0, row=1, sticky=E)
        label_amountOfGrain = ttk.Label(window, text="Amount of grain").grid(column=0, row=2, sticky=E)
        label_MCS = ttk.Label(window, text="MCS").grid(column=0, row=9, sticky=E)
        label_numberGrainSelect = ttk.Label(window, text="Number of grain to select").grid(column=0, row=12, sticky=E)
        label_secondGrainGrowth = ttk.Label(window, text="Second grain growth").grid(column=0, row=15, sticky=E)
        label_energyDistribution = ttk.Label(window, text="Energy distribution").grid(column=0, row=17, sticky=E)



        entry_xDimention = ttk.Entry(window, textvariable=xDimention).grid(column=1, row=0)
        entry_yDimention = ttk.Entry(window, textvariable=yDimention).grid(column=1, row=1)
        entry_amountOfGrain = ttk.Entry(window, textvariable=amountOfGrains).grid(column=1, row=2)
        entry_MCS = ttk.Entry(window, textvariable=MCS).grid(column=1, row=9)
        entry_numberGrainSelect = ttk.Entry(window, textvariable=numberGrainSelect).grid(column=1, row=12)

        entry_amountOfGrain = ttk.Button(window, text="Generate space",
                                         command=lambda: self.generateSpace(xDimention.get(), yDimention.get(), amountOfGrains.get(), canvas)
                                         ).grid(column=0, columnspan=2, row=3)  #uzywamy funkcji lambda do wywolania docelowej funkcji obslugi kilkniecia

        button_startMCS = ttk.Button(window, text="DO IT",
                                         command=lambda: self.MCSiteration(self.m, xDimention.get(), yDimention.get(),
                                                                            amountOfGrains.get(), canvas, MCS.get())
                                         ).grid(column=0, columnspan=2,
                                                row=10)  # uzywamy funkcji lambda do wywolania docelowej funkcji obslugi kilkniecia

        button_grainSelect = ttk.Button(window, text="Clear space",
                                    command=lambda: self.grainSelect(xDimention.get(), yDimention.get(),
                                                                      amountOfGrains.get(), canvas, numberGrainSelect.get())
                                    ).grid(column=0, columnspan=2,
                                           row=13)  # uzywamy funkcji lambda do wywolania docelowej funkcji obslugi kilkniecia

        button_recrystallization = ttk.Button(window, text="Start dual phase",
                                         command=lambda: self.recrystallization(amountOfGrains.get(), canvas, MCS.get(), secondGrainGrowth.get())
                                         ).grid(column=0, columnspan=2,row=16)  # uzywamy funkcji lambda do wywolania docelowej funkcji obslugi kilkniecia

        button_showEnergy = ttk.Button(window, text="Start dual phase",
                                             command=lambda: self.recrystallization(amountOfGrains.get(), canvas, MCS.get(), secondGrainGrowth.get())
                                             ).grid(column=0, columnspan=2,
                                                    row=18)  # uzywamy funkcji lambda do wywolania docelowej funkcji obslugi kilkniecia



        combobox_secondGrainGrowth = ttk.Combobox(window, textvariable=secondGrainGrowth,
                                                    state='readonly')  # nie mozna wpisac wlasnej liczby zamiast tych do wybrania
        combobox_secondGrainGrowth['values'] = ("Monte Carlo", "Cellular Automata")
        combobox_secondGrainGrowth.grid(column=1, row=15)
        combobox_secondGrainGrowth.current(0)


        combobox_energyDistribution = ttk.Combobox(window, textvariable=energyDistribution,
                                                    state='readonly')  # nie mozna wpisac wlasnej liczby zamiast tych do wybrania
        combobox_energyDistribution['values'] = ("Homogenious", "Heterogenous")
        combobox_energyDistribution.grid(column=1, row=17)
        combobox_energyDistribution.current(0)

        ############# end of space generation ##############################



        #####################  FRAGMEMT DO TESTOWANIA  #########################


        self.generateSpace(xDimention.get(), yDimention.get(), amountOfGrains.get(), canvas)




        window.mainloop()




##############################################################################################
    def energyDistribution(self, a,b, type):


        if type == "Homogenious":
            print ()
        elif type == "Heterogenous":
            print()



    def recrystallization(self, amountOfGrains, canvas, MCS, secondGrainGrowth):


        if secondGrainGrowth == "Monte Carlo":
            self.m02 = matrix.Matrix(self.x, self.y, amountOfGrains)  # wymiary planszys, liczba ziarn
            self.m02.createGrains()  # utworzenie ziarn o zadanej ilosci ronych id
            self.RecIteration(self.m02, self.x, self.y, amountOfGrains, canvas, MCS)
            self.showImage(self.m, self.x, self.y, amountOfGrains, canvas, "recrystallization")


        elif secondGrainGrowth == "Cellular Automata":
            print("kokos")
            s = simpledialog.askinteger("", "Amount of grains")
            self.m02 = CA_matrix.Matrix(self.x, self.y, s)
            self.m02.createGrains(self.m.grain)
            self.m02.randomizeGrainPosition()
            self.showImage(self.m02, self.x, self.y, amountOfGrains, canvas, "recrystallization")


            while True:
                flaga = self.m02.algorithmCA("ToDo")
                self.showImage(self.m02, self.x, self.y, amountOfGrains, canvas, "recrystallization")
                if flaga:
                    break

            self.showImage(self.m02, self.x, self.y, amountOfGrains, canvas, "recrystallization")

    def grainSelect(self,  x,y,n, canvas, Ngrains):
        self.m.selectGrains(Ngrains)
        self.showImage(self.m, x, y, n, canvas, "white")






    def MCSiteration(self,matrix, x,y,n, canvas, MCS):

        for i in range (MCS):
            matrix.monteCarloIteratio()
            #time.sleep(.5)
            self.showImage(matrix, x, y, n, canvas, "")
            print(i)


    def RecIteration(self,matrix, x,y,n, canvas, MCS):

        for i in range (MCS):
            matrix.monteCarloIteratio()
            self.showImage(self.m, self.x, self.y, n, canvas, "recrystallization")

    def generateSpace(self, x,y,n, canvas):

        self.m = matrix.Matrix(x, y, n)  # wymiary planszys, liczba ziarn
        self.m.createGrains()  # utworzenie ziarn o zadanej ilosci ronych id
        self.showImage(self.m ,x, y, n, canvas, "")



    def showImage(self, matrix, x, y, n, canvas, flag):

        canvas.delete("all")
        self.x = x
        self.y = y
        x_size = self.size_x_canvas / (x -1)
        y_size = self.size_y_canvas / (y-1)
        x_pointer = 1
        y_pointer = 1

        if flag =="":
            for i in range(0, self.size_x_canvas, int(x_size+1)):
                for j in range(0, self.size_y_canvas, int(y_size+1)):
                    kolor = matrix.getColour(matrix.grain[x_pointer][y_pointer])
                    canvas.create_rectangle(i, j, i + x_size+1, j + y_size+1, fill=kolor, outline="")
                    y_pointer += 1
                x_pointer += 1
                y_pointer = 0


        elif flag =="white":
            for i in range(0, self.size_x_canvas, int(x_size+1)):
                for j in range(0, self.size_y_canvas, int(y_size+1)):
                    if(matrix.grain[x_pointer][y_pointer] == -1):
                        kolor = "#ffffff"
                        canvas.create_rectangle(i, j, i + x_size + 1, j + y_size + 1, fill=kolor, outline="")
                    else:
                        #kolor = matrix.getColour(matrix.grain[x_pointer][y_pointer])
                        kolor = 'black'
                        canvas.create_rectangle(i, j, i + x_size+1, j + y_size+1, fill=kolor, outline="")
                    y_pointer += 1
                x_pointer += 1
                y_pointer = 0

        elif flag == "recrystallization":
            for i in range(0, self.size_x_canvas, int(x_size+1)):
                for j in range(0, self.size_y_canvas, int(y_size+1)):
                    if self.m.grain[x_pointer][y_pointer] == -1:
                        kolor = self.m02.getColour(self.m02.grain[x_pointer][y_pointer])

                        canvas.create_rectangle(i, j, i + x_size + 1, j + y_size + 1, fill=kolor, outline="")

                    else:
                        #kolor = self.m.getColour(self.m.grain[x_pointer][y_pointer])
                        kolor = 'black'
                        canvas.create_rectangle(i, j, i + x_size+1, j + y_size+1, fill=kolor, outline="")
                    y_pointer += 1
                x_pointer += 1
                y_pointer = 0


        canvas.update()
