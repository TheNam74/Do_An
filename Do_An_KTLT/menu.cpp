#define _CRT_SECURE_NO_WARNINGS
#include"menu.h"


void OpenMenu(int status) {
	FILE *f = fopen("STOREZONE/Actions.txt", "w");
	switch (status)
	{
	case 1:	//admin
		fprintf(f, "%d %s", 9, "sssssssss");
		fclose(f);
		Menu(9, "sssssssss");
		break;
	case 2:	//manager
		fprintf(f, "%d %s", 8, "shsssssss");
		fclose(f);
		Menu(8, "shsssssss");
		break;
	case 3:	//expert
		fprintf(f, "%d %s", 8, "shsssssss");
		fclose(f);
		Menu(8, "shsssssss");
		break;
	}
}
void Menu(int Actions, const char numberAction[]) {
	char f[9][50] =
	{
		"Update Information  : press 1",
		"Create User         : press 2",
		"Manage reader       : press 3",
		"Manage book         : press 4",
		"Create borrowing    : press 5",
		"Create paying       : press 6",
		"Statics             : press 7",
		"Change Password     : press 8",
		"Logout              : press 0"
	};
	drawRectangle(47, 6, 35, 10, 6);
	int line = 6;
	for (int i = 0; i < 10; i++) {
		if (numberAction[i] == 's') {
			drawRectangle(47, line, 35, 1, 6);
			gotoxy(48, line);
			cout << f[i];
			line++;
		}
	}
	choseAction();
}
void choseAction() {
	char ch = _getch();
	while (ch != 27) {
		if (ch == '0') Logout();
		if (ch == '2') CreateUser();
	}
}
