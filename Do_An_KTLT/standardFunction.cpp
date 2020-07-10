#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<fstream>
#include<string>
#include <direct.h>
#include <ctime>
#include<stdio.h>
#include <conio.h>
#include"standardFunction.h"
#include<fstream>
using namespace std;

void initSystemFolder()
{
	fstream f;
	_mkdir("BOOKS");
	_mkdir("BORROWEDBOOKS");
	_mkdir("STOREZONE");
	_mkdir("parameterSYSTEM");
	_mkdir("READERS");
	f.open("readers/readers.csv", ios::in);
	if (f.fail())
	{
		f.open("readers/readers.csv", ios::out);
		f.close();
	}
	else
		f.close();

	f.open("readers/readersCount.txt", ios::in);
	if (f.fail())
	{
		f.close();
		f.open("readers/readersCount.txt", ios::out);
		f << 0;
		f.close();
	}
	else f.close();

	_mkdir("USER");
	_mkdir("USER/admin");
	_mkdir("USER/experts");
	_mkdir("USER/managers");
}
