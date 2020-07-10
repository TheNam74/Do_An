#define _CRT_SECURE_NO_WARNINGS
#include"input.h"
#include"login.h"
#include"standardFunction.h"
#include"thaoTacVoiManHinh.h"
#include"struct.h"
#include"users.h"
using namespace std;
//test2222
int main(int argc, char* argv[]) {
	char user[21], pass[31];
	initSystemFolder();
	Login(user, pass);
	return 0;
}
