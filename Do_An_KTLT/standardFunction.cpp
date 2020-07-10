#include"standardFunction.h"

void initSystemFolder()
{
	_mkdir("BOOKS");
	_mkdir("BORROWEDBOOKS");
	_mkdir("STOREZONE");
	_mkdir("parameterSYSTEM");
	_mkdir("READERS");
	_mkdir("USER");
	_mkdir("USER/admin");
	_mkdir("USER/experts");
	_mkdir("USER/managers");
}