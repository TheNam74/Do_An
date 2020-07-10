#pragma once
#include<iostream>
#include "conio.h"
#include "windows.h"
using namespace std;

int InputUser(char user[]);
int InputPass(char pass[]);
void Input(char user[], char pass[]);

int InputFullname(char fullname[]);

int Input1Num();

int Input2Num();

int Input4Num();

long Input9Num();

int InputIndentity(char ID[]);

int InputAddress(char address[]);

int InputFullname(char fullname[]);

bool ValidPass(char x);
bool ValidUser(char x);
bool ValidName(char x);
bool ValidNumber(char x);
