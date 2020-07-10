#pragma once
struct Day{
	int Date;
	int Month;
	int Year;
}; 

struct Accounts{
	char username[21];
	char password[21];
	bool active;
	char fullname[45];
	Day DoB;
	char ID[45];
	char address[101];
	int sex;
	int classification;
};
struct Reader {
	long Code;
	char Fullname[45];
	char ID[45];
	Day DOB;
	int Sex;
	char Email[101];
	char Address[101];
	Day CreatedDate;
	Day ExpirationDate;
};