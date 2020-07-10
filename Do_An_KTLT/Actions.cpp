#define _CRT_SECURE_NO_WARNINGS
#include"Actions.h"


void Logout() {
	char username[21], password[31];
	Login(username, password);
}
void CreateUser()
{
	bool BACK = false;	//Biến kiểm tra có bấm 'Trở về' [F12] hay chưa?
	do
	{
		//Vẽ khung đăng nhập
		drawRectangle(39, 6, 50, 21, 3);
		//Ghi các thuộc tính của trường nhập
		gotoxy(41, 7);
		printf("USERNAME[20]: ");
		gotoxy(41, 9);
		printf("PASSWORD[30]: ");
		gotoxy(41, 11);
		printf("FULLNAME[44]: ");
		gotoxy(41, 13);
		printf("DAY OF BIRTH: dd/mm/yyyy");
		gotoxy(41, 15);
		printf("NUMBER OF IDENTICAL CARD[11]: ");
		gotoxy(41, 17);
		printf("ADDRESS[100]: ");
		gotoxy(41, 19);
		printf("GENDER: 1->Male ; 2-> Female");
		gotoxy(41, 21);
		printf("CLASSIFICATION: 1->Manager ; 2->Expert");
		//Vẽ các trường nhập
		drawRectangle(41, 8, 44, 1, 15);
		drawRectangle(41, 10, 44, 1, 15);
		drawRectangle(41, 12, 44, 1, 15);
		drawRectangle(41, 14, 44, 1, 15);
		gotoxy(43, 14);
		printf("/  /");
		drawRectangle(41, 16, 44, 1, 15);
		drawRectangle(41, 18, 44, 1, 15);
		drawRectangle(41, 20, 44, 1, 15);
		drawRectangle(41, 22, 44, 1, 15);
		//Vẽ nút điều hướng
		textBgColor(0, 7);
		gotoxy(60, 24);
		printf("ENTER to Creat account");
		gotoxy(60, 25);
		printf("F12 to Back");
		textBgColor(0, 15);
		//Nhập <USERNAME>
		Accounts A;
		do
		{
			gotoxy(41, 8);
			int status = InputUser(A.username);
			if (status == -1)
			{
				BACK = true;	//Đã bấm 'Trở về' [F12]
			}
		} while (strlen(A.username) == 0 && !BACK);
		//Nhập Mật khẩu
		if (!BACK)
		{
			do
			{
				gotoxy(41, 10);
				int status = InputPass(A.password);
				if (status == -1)
				{
					BACK = true;
				}
			} while (strlen(A.password) == 0 && !BACK);
		}
		//Nhập Họ tên
		if (!BACK)
		{
			do
			{
				gotoxy(41, 12);
				int status = InputFullname(A.fullname);
				if (status == -1)
				{
					BACK = true;
				}
			} while (strlen(A.fullname) == 0 && !BACK);
		}
		//Nhập Ngày sinh
		if (!BACK)
		{
			do {
				gotoxy(41, 14);
				A.DoB.Date = Input2Num();
				if (A.DoB.Date == -1)
				{
					BACK = true;
				}
			} while (A.DoB.Date == 0 && !BACK);
		}
		if (!BACK)
		{
			do
			{
				gotoxy(44, 14);
				A.DoB.Month = Input2Num();
				if (A.DoB.Month == -1)
				{
					BACK = true;
				}
			} while (A.DoB.Month == 0 && !BACK);
		}
		if (!BACK)
		{
			do
			{
				gotoxy(47, 14);
				A.DoB.Year = Input4Num();
				if (A.DoB.Year == -1)
				{
					BACK = true;
				}
			} while (A.DoB.Year == 0 && !BACK);
		}
		//Nhập CMND
		if (!BACK)
		{
			do
			{
				gotoxy(41, 16);
				int status = InputIndentity(A.ID);
				if (status == -1)
				{
					BACK = true;
				}
			} while (strlen(A.ID) == 0 && !BACK);
		}
		//Nhập Địa chỉ
		if (!BACK)
		{
			do
			{
				gotoxy(41, 18);
				int status = InputAddress(A.address);
				if (status == -1)
				{
					BACK = true;
				}
			} while (strlen(A.address) == 0 && !BACK);
		}
		//Nhập Giới tính
		if (!BACK)
		{
			gotoxy(41, 20);
			A.sex = Input1Num();
			if (A.sex == -1)
			{
				BACK = true;
			}
		}
		//Nhập Phân quyền
		if (!BACK)
		{
			gotoxy(41, 22);
			A.classification = Input1Num();
			if (A.classification == -1)
			{
				BACK = true;
			}
		}
		char user[21], pass[21];
		int actions = 0;
		char menu[10];
		//Nếu chưa ấn 'Trở về' [F12]
		if (!BACK)
		{
			//Nếu username khả dụng thì tạo mới tài khoản kèm thông báo tạo thành công
			if (AcceptUser(A.username))
			{
				AddAccount(A);
				drawRectangle(42, 12, 46, 3, 10);
				char Alert[100] = "CREATE ACCOUNT SUCCESSFULL";
				gotoxy(53, 13);
				printf("%s", Alert);
				Sleep(1500);
			}
			//Nếu username không khả dụng thì thông báo tài khoản đã được sử dụng
			else
			{
				drawRectangle(42, 12, 46, 3, 12);
				gotoxy(46, 13);
				char Alert[100] = "USER NAME IS AVAILABLE";
				gotoxy(53, 13);
				printf("%s", Alert);
				Sleep(2000);
			}
		}
		//Nếu đã ấn 'Trở về' [F12]
		else
		{

			FILE *f = fopen("STOREZONE/currentMenu.txt", "r");
			fscanf(f, "%d %s", &actions, menu);
			fclose(f);
			drawRectangle(39, 6, 50, 21, 15);
			Menu(actions, menu);
			break;
		}
	} while (!BACK);
}

void AddAccount(Accounts A)
{
	char LINK[100], link[100], listlink[100];
	if (A.classification == 1)
		strcpy(LINK, "USER/managers/");
	else
		strcpy(LINK, "USER/experts/");

	strcpy(link, LINK);
	strcat(link, A.username);
	strcat(link, ".bin");

	errno_t error;
	FILE *f;
	error = fopen_s(&f, link, "rb");
	if (error != 0)	//Không mở được file để đọc
	{
		strcpy(listlink, LINK);
		strcat(listlink, "List.txt");
		fopen_s(&f, listlink, "a");
		fprintf(f, "%s\n", A.username);
		fclose(f);
	}
	else
		fclose(f);

	A.active = true;

	fopen_s(&f, link, "wb");
	fwrite(&A, sizeof(Accounts), 1, f);
	fclose(f);
}

bool AcceptUser(char username[])
{
	if (strcmp(username, "admin") == 0) return false;	//Nếu tài khoản đăng kí mới trùng tên admin thì trả về false

	bool ACCEPT = true;

	//Kiểm tra các tài khoản thuộc nhóm Quản lý
	char link[100] = "USER/managers/";
	strcat(link, username);
	strcat(link, ".bin");
	errno_t error;
	FILE *f;
	error = fopen_s(&f, link, "rb");
	if (error == 0)	//Mở được file để đọc
	{
		Accounts A;
		fread(&A, sizeof(Accounts), 1, f);
		fclose(f);
		if (A.active)
			ACCEPT = false;	//ACCEPT bằng false chỉ khi tài khoản đã được tạo trước đó và vẫn còn đang trạng thái ACTIVE
	}

	//Kiểm tra các tài khoản thuộc nhóm Chuyên viên
	strcpy(link, "USER/experts/");
	strcat(link, username);
	strcat(link, ".bin");
	error = fopen_s(&f, link, "rb");
	if (error == 0)	//Mở được file để đọc
	{
		Accounts A;
		fread(&A, sizeof(Accounts), 1, f);
		fclose(f);
		if (A.active)
			ACCEPT = false;
	}
	return ACCEPT;
}