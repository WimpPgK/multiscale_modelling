#ifndef FILEOPERATOR_H
#define FILEOPERATOR_H
#include "Grain.h"


class FileOperator
{
public:
	FileOperator();
	void saveToFile(Grain***, int, int, int);	

	virtual ~FileOperator();

protected:

private:
};

#endif // FILEOPERATOR_H