#ifndef GRAIN_H
#define GRAIN_H
#include "Id.h"

class Grain
{
    public:

        Id* id;
        void setPosition(int,int,int);
        void setId(Id*);
       // void setColor(double,double,double);

        Id* getId();
        void getValues();
        void getColor();
        void getPisition();
        Grain();

        virtual ~Grain();

    protected:

    private:
        int position_x;
        int position_y;
        int position_z;
        float color_r;
        float color_g;
        float color_b;
        float alpha;
};

#endif // GRAIN_H
