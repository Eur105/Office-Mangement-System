#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
//File Pointers(GLOBAL)
FILE *ptr;
FILE *login;
FILE *desig;
FILE *editing;
FILE *salaryslip;
char checker[256];
//FUNCTIONS
void myleaves(char f2[], int *leaveptr, int leaves2) {
	editing = fopen(f2, "r+");
	if (editing == NULL) {
		printf("Error\n");
	}
	*leaveptr = *leaveptr + leaves2;
	float attendance = 100;
	fprintf(editing, "Leaves: %d\n", *leaveptr);
	if (*leaveptr >= 1) {
		attendance = attendance - (float)(*leaveptr * 100) / 30;
	}
	fprintf(editing, "Attendance: %.2f%\n", attendance);
	fclose(editing);
}
void writetasks(char f2[]) {
	int task = 0, i;
	char sentence[50];
	editing = fopen(f2, "a+");
	if (editing == NULL) {
		printf("Error\n");
	}
	printf("How many Tasks you want to add: \n");
	scanf("%d", &task);
	fputs("TASKS: \n", editing);
	for (i = 1; i <= task; i++) {
		printf("Enter Task %d: ", i);
		fflush(stdin);
		gets(sentence);
		fprintf(editing, "\t%d) %s\n", i, sentence);
	}
	fclose(editing);
}
void readtasks(char f2[]) {
	editing = fopen(f2, "r+");
	if (editing == NULL) {
		printf("Error\n");
	}
	fgets(checker, 256, editing);
	fgets(checker, 256, editing);
	while (fgets(checker, 256, editing) != NULL) {
		printf("%s", checker);
	}

	fclose(editing);
}
void showattendance(char f2[]) {
	char sentence[20];
	editing = fopen(f2, "r+");
	if (editing == NULL) {
		printf("Error\n");
	}
	fgets(sentence, 256, editing);
	fgets(sentence, 256, editing);
	printf("Your %s %\n", sentence);
	fclose(editing);
}
void createsalary(char salaryfile[], char names[], char i[], char designation[], int post[]) {
	editing = fopen(salaryfile, "w");
	if (editing == NULL) {
		printf("Error");
	}
	fputs("\t\t\t\t\t\t\t-------------------------------------\t\t\t\t\n",editing);
	fputs("\t\t\t\t\t\t\t   Welcome To Office Management Sytem\t\t\t\t\n",editing);
	fputs("\t\t\t\t\t\t\tSalary SlipS\t\t\t\t\n",editing);
	fputs("\t\t\t\t\t\t\t-------------------------------------\t\t\t\t\n",editing);
	fprintf(editing,"Name: %s\n",names);
	fprintf(editing,"Employee ID: %.9s\n",i);
	fprintf(editing,"Designation: %s\n",designation);
	if (post[0] == 0) {
		fprintf(editing, "Netpay: %d", 85000);
	} else if (post[1] == 0) {
		fprintf(editing, "Netpay: %d", 82000);
	} else if (post[2] == 0) {
		fprintf(editing, "Netpay: %d", 50000);
	} else if (post[3] == 0) {
		fprintf(editing, "Netpay: %d", 55000);
	} else if (post[4] == 0) {
		fprintf(editing, "Netpay: %d", 48000);
	}
	fclose(editing);
}
void sslip(char salaryfile[]) {
	salaryslip = fopen(salaryfile,"r+");
	fseek(ptr, 0, SEEK_SET);
	while (fgets(checker, 256, salaryslip)) {
		printf("%s", checker);
	}
}
//FUNCTIONS END
int main() {
	time_t t;
	//VARIABLES
	static char i[14] = "21OMS-411";
	char f2[14] ;
	char salaryfile[14];

	char names[20];
	char dob[8], gender[8], cnic[13], p_email[50], address[100];
	int cellnum[12];
	int choice, loginchoice;
	float ssc, hsc, cgpa;
	int experience;
	int k;
	char username[14];
	char pass1[8];
	char pass2[8];
	char password[8];
	int templeaves;
	int incorrect = 0;
	static int post[5] = {1, 1, 1, 1, 1};
main:
	system("color 0F");
	time(&t);
	printf("\t\t\t\t\t\t\t-------------------------------------\t\t\t\t\n");
	printf("\t\t\t\t\t\t\tWelcome To Office Management Sytem\t\t\t\t\t\t%s\n", ctime(&t));
	printf("\t\t\t\t\t\t\t-------------------------------------\t\t\t\t\n\n\n\n\n");
	printf("%235s\t1)LOGIN\n\n\n\n", " ");
	printf("%235s\t2)SIGNUP\n\n\n\n", " ");
	printf("%235s", " ");
	scanf("%d", &choice);
	if (choice == 1) {
		printf("Are you sure you want to login\n");
		printf("1)Yes\n2)Exit\n");
		scanf("%d", &choice);
		if (choice == 1) {
			system("cls");
			goto login;
		} else {
			system("cls");
			goto main;
		}
	} else if (choice == 2) {
		printf("Are you sure you want to signup\n");
		printf("1)Yes\n2)Exit\n");
		scanf("%d", &choice);
		if (choice == 1) {
			system("cls");
			goto signup;
		} else {
			system("cls");
			goto main;
		}
	} else {
		system("cls");
		goto main;
	}

login:
	printf("\t\t\t\t\t\t\t\t\t-----\t\t\t\t\n");
	printf("\t\t\t\t\t\t\t\t\tLOGIN\t\t\t\t\t\t\t %s", ctime(&t));
	printf("\t\t\t\t\t\t\t\t\t-----\t\t\t\t\n");
	int mode;
	if (mode == 1 || mode == 2) {
		goto username;
	}

theme:
	printf("%300s Select Your Fav Theme: \n1)Dark\n2)Light\n", " ");
	scanf("%d", &mode);
	if (mode == 1) {
		system("color 0F");
		system("cls");
		goto login;
	}
	if (mode == 2) {
		system("color F0");
		system("cls");
		goto login;
	}
username:
	login = fopen("login.txt", "r");

	printf("\t\t\t\t\t\t\tEnter Your Username :[21OMS-***]\n");
	printf("\t\t\t\t\t\t\t");
	fflush(stdin);
	gets(username);
	printf("\t\t\t\t\t\t\tEnter Your Password :\n");
	printf("\t\t\t\t\t\t\t");
	fflush(stdin);
	gets(password);
	goto checking;
	//CHECKING USERNAME AND PASSWORD IN FILE

checking:

	fseek(login, 0, SEEK_SET);
	while (fscanf(login, "%s", checker) != EOF) {
		if ((strcmp(checker, username)) == 0) {
			fscanf(login, "%s", checker);
			if (strcmp(checker, password) == 0) {
				printf("\t\t\t\t\t\t\tSuccefull\n");
				printf("\t\t\t\t\t\t\tPlease wait while opening your Account...\n");
				strcpy(f2,username);
				strcat(f2,"b.txt");
				strcpy(salaryfile,username);
				strcat(salaryfile,"c.txt");
				strcat(username,"a.txt");
				sleep(2);
				system("cls");
				goto f2create;
			} else {
				incorrect++;
				if (incorrect == 3) {
					goto main;
				}
				printf("\t\t\t\t\t\t\tIncorrect password\n");
				goto username;
			}
		}
		fseek(login, 10, SEEK_CUR);
	}
	fclose(login);
	goto userinterface;
//Username is correct
f2create:
	editing = fopen(f2, "w+");
	int leaves = 0;
	int *leaveptr;
	leaveptr = &leaves;
	if (fgets(checker, 256, editing) == NULL) {
		int leaves2 = 0;
		myleaves(f2,leaveptr, leaves2);
	}
	fclose(editing);
userinterface:
	ptr = fopen(username, "r+");
	if (ptr == NULL) {
		incorrect++;
		if (incorrect == 3) {
			goto main;
		}
		printf("\t\t\t\t\t\t\tIncorrect ID\n");
		goto username;
	}
	int leaves2 = 0;
	printf("\t\t\t\t\t\t\t\t-------------------------------------\t\t\t\t\n");
	printf("%240sWelcome %.9s\t\t%60s\n", " ", username, ctime(&t));
	printf("\t\t\t\t\t\t\t\t-------------------------------------\t\t\t\t\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t1)Show My Personal Data\n");
	printf("\t\t\t\t\t\t\t2)Request Some Leaves\n");
	printf("\t\t\t\t\t\t\t3)Enter New Task\n");
	printf("\t\t\t\t\t\t\t4)Show My Tasks\n");
	printf("\t\t\t\t\t\t\t5)Show My Attendance\n");
	printf("\t\t\t\t\t\t\t6)My salary slip\n");
	printf("\t\t\t\t\t\t\t0)Logout\n");
	scanf("%d", &loginchoice);
	switch (loginchoice) {
		case 1:
			printf("\t\t\t\t\t\t\tPlease wait while fetching your data...\n");
			sleep(3);
			fseek(ptr, 0, SEEK_SET);
			while (fgets(checker, 256, ptr)) {
				printf("%s", checker);
			}
			break;
		case 2:
			printf("\t\t\t\t\t\t\tHow many leaves you want\n");
			scanf("%d", &leaves2);
			printf("\t\t\t\t\t\t\tPlease wait...\n");
			sleep(2);
			printf("\t\t\t\t\t\t\tYou have succesfully granted %d leaves\n", leaves2);
			int *leaveptr;
			leaveptr = &leaves;
			myleaves(f2, leaveptr, leaves2);
			break;
		case 3:
			writetasks(f2);
			break;
		case 4:
			readtasks(f2);
			break;
		case 5:
			showattendance(f2);
			break;
		case 6:
			strcpy(salaryfile,i);
			strcat(salaryfile,"s.txt");
			sslip(salaryfile);
			break;
		case 0:
			leaves = 0;
			printf("\t\t\t\t\t\t\tLogging out....");
			sleep(3);
			printf("\t\t\t\t\t\t\tLogout successfully");
			system("cls");
			goto main;

		default:
			printf("\t\t\t\t\t\t\tWrong option\n");
			sleep(2);
			system("cls");
			goto userinterface;
			break;
	}
	getch();
	system("cls");
	goto userinterface;

signup:
	//HEADER
	printf("\t\t\t\t\t\t\t-------------------------------------\t\t\t\t\n");
	printf("%260s\t\t%60s", "Welcome To Office Management Sytem", ctime(&t));
	printf("\t\t\t\t\t\t\t-------------------------------------\t\t\t\t\n\n");
	printf("%252s\n", "SIGNUP YOUR DETAILS");
	printf("\t\t\t\t\t\t\t-------------------------------------\t\t\t\t\n\n\n");
	//CHECKING USERNAME EXISTENCE TO UPDATE AND DESIGNATION
	login = fopen("login.txt", "r");

	fseek(login, 0, SEEK_SET);
	while (fgets(checker, 256, login) != NULL) {
		if ((strstr(checker, i)) != NULL) {
			if (i[8] == 9) {
				i[7] = i[7] + 1;
				i[8] = 0;
			} else {
				i[8] = i[8] + 1;
			}
			fseek(login, 0, SEEK_SET);
		}
		fseek(login, 10, SEEK_CUR);
	}
	fclose(login);
	//VACANCIES
	printf("\t\t\t\t\t\t\t We have some vacancies available\n\n");
	if (post[0] != 0) {
		int check = 0;
		char designation[3] = "CFO";
		desig = fopen("designation.txt", "r");
		fseek(desig, 0, SEEK_SET);
		while (fgets(checker, 256, desig) != NULL) {
			if ((strstr(checker, designation)) != NULL) {
				check = 1;
				fseek(desig, 0, SEEK_SET);
				post[0] = 0;
				break;
			}
		}
		if (check != 1)
			printf("CFO\n");
		fclose(desig);
	}

	if (post[1] != 0) {
		int check = 0;
		char designation[19] = "Executive Assistant";
		desig = fopen("designation.txt", "r");
		fseek(desig, 0, SEEK_SET);
		while (fgets(checker, 256, desig) != NULL) {
			if ((strstr(checker, designation)) != NULL) {
				check = 1;
				fseek(desig, 0, SEEK_SET);
				post[1] = 0;
				break;
			}
		}
		if (check != 1)
			printf("Executive Assistant\n");
	}

	if (post[2] != 0) {
		int check = 0;
		char designation[9] = "Secretary";
		desig = fopen("designation.txt", "r");
		fseek(desig, 0, SEEK_SET);
		while (fgets(checker, 256, desig) != NULL) {
			if ((strstr(checker, designation)) != NULL) {
				check = 1;
				fseek(desig, 0, SEEK_SET);
				post[2] = 0;
				break;
			}
		}
		if (check != 1)
			printf("Secretary\n");
	}

	if (post[3] != 0) {
		int check = 0;
		char designation[9] = "Junior HR";
		desig = fopen("designation.txt", "r");
		fseek(desig, 0, SEEK_SET);
		while (fgets(checker, 256, desig) != NULL) {
			if ((strstr(checker, designation)) != NULL) {
				check = 1;
				fseek(desig, 0, SEEK_SET);
				post[3] = 0;
				break;
			}
		}
		if (check != 1)
			printf("Junior HR\n");
	}

	if (post[4] != 0) {
		int check = 0;
		char designation[16] = "Trainee Engineer";
		desig = fopen("designation.txt", "r");
		fseek(desig, 0, SEEK_SET);
		while (fgets(checker, 256, desig) != NULL) {
			if ((strstr(checker, designation)) != NULL) {
				check = 1;
				fseek(desig, 0, SEEK_SET);
				post[4] = 0;
				break;
			}
		}

		if (check != 1)
			printf("Trainee Engineer\n");
	}
	printf("\t\t\t\t\t\t\tYour assigned Rollno is: %.9s\n\n", i);
	//DATA FILE AND SALARY FILE
	strcpy(salaryfile, i);
	strcat(salaryfile, "s.txt");
	strcat(i, "a.txt");
	ptr = fopen(i, "w+");
	//FORM DETAILS
	//PERSONAL INFO
	fputs("Personal Information: \n", ptr);
	fflush(stdin);

	printf("Enter Your Name: ");
	gets(names);
	fflush(stdin);
	fprintf(ptr, "\tName: %s\n", names);

	printf("Enter CNIC number: ");
	gets(cnic);
	fprintf(ptr, "\tCNIC No: %s\n", cnic);

	printf("Enter D.O.B [dd-mm-yyyy]: ");
	gets(dob);
	fprintf(ptr, "\tDate Of Birth: %s\n", dob);

	printf("Your Gender: ");
	gets(gender);
	fprintf(ptr, "\tGender: %s\n", gender);

	//CONTACT INFO

	fputs("Contact Information: \n", ptr);
	printf("Your PhoneNo: ");
	scanf("%s", &cellnum);
	fprintf(ptr, "\tCell Number: %s\n", cellnum);

	printf("Your Personal Email: ");
	fflush(stdin);
	gets(p_email);
	fprintf(ptr, "\tPersonal Email: %s\n", p_email);

	printf("Your Address: ");
	gets(address);
	fprintf(ptr, "\tAddress: %s\n", address);

	//ACADEMIC INFO

	fputs("Academic Information: \n", ptr);
	printf("Your O-Level/Matric Percentage: ");
	scanf("%f", &ssc);
	fprintf(ptr, "\tO-Level/Matric Percentage:  %.2f\n", ssc);

	printf("Your A-Level/Intermediate Percentage: ");
	scanf("%f", &hsc);
	fprintf(ptr, "\tA-Level/Intermediate Percentage:  %.2f\n", hsc);

	printf("Your CGPA: ");
	scanf("%f", &cgpa);
	fprintf(ptr, "\tCGPA: %.2f\n", cgpa);

	printf("Your Experience: ");
	scanf("%d", &experience);
	fprintf(ptr, "\tExperience: %d\n", experience);

	fclose(ptr);
	printf("Your details are Saved\n");

	if (ssc >= 70 && hsc >= 70 && cgpa >= 2.4) {
		getch();
		system("cls");
		goto selected;
	} else {
		fclose(ptr);
		ptr = fopen(i, "w");
		fputs(" ", ptr);
		fclose(ptr);
		printf("You are not eligible for any job");
		getch();
		system("cls");
		goto main;
	}

//ELIGIBILITY CRITERIA
selected:

	if ((post[0] == 1) && ssc >= 90 && hsc >= 85 && cgpa >= 3.5) {
		printf("\t\t\t\t\tCongrats you are eligible for the post of CFO\n");
		char designation[3] = "CFO";
		ptr = fopen(i, "a+");
		fputs("Designation: CFO\n", ptr);
		fclose(ptr);

		desig = fopen("designation.txt", "a+");
		fprintf(desig, "%s\n", designation);
		fclose(desig);
		post[0] = 0;
		createsalary(salaryfile, names, i, designation, post);
	}

	else if ((post[1] == 1) && ssc >= 85 && hsc >= 80 && cgpa >= 3.0) {
		printf("\t\t\t\t\tCongrats you are eligible for the post of Executive Assistant\n");
		fputs("Designation: Executive Assistant\n", ptr);

		desig = fopen("designation.txt", "a+");
		char designation[19] = "Executive Assistant";
		fprintf(desig, "%s\n", designation);
		fclose(desig);
		post[1] = 0;
		createsalary(salaryfile, names, i, designation, post);
	}

	else if ((post[2] == 1) && ssc >= 80 && hsc >= 75 && cgpa >= 2.8) {
		printf("\t\t\t\t\tCongrats you are eligible for the post of Secretary\n");
		fputs("Designation: Secretary\n", ptr);

		desig = fopen("designation.txt", "a+");
		char designation[9] = "Secretary";
		fprintf(desig, "%s\n", designation);
		fclose(desig);
		post[2] = 0;
		createsalary(salaryfile, names, i, designation, post);
	} else if ((post[3] == 1) && ssc >= 75 && hsc >= 70 && cgpa >= 2.6) {
		printf("\t\t\t\t\tCongrats you are eligible for the post of Junior HR\n");
		fputs("Designation: Junior HR\n", ptr);

		desig = fopen("designation.txt", "a+");
		char designation[9] = "Junior HR";
		fprintf(desig, "%s\n", designation);
		fclose(desig);
		post[3] = 0;
		createsalary(salaryfile, names, i, designation, post);
	} else if ((post[4] == 1) && ssc >= 70 && hsc >= 70 && cgpa >= 2.4) {
		printf("\t\t\t\t\tCongrats you are eligible for the post of Trainee Engineer\n");
		fputs("Designation: Trainee Engineer\n", ptr);
		char designation[16] = "Trainee Engineer";
		desig = fopen("designation.txt", "a+");
		fprintf(desig, "%s\n", designation);
		fclose(desig);
		post[4] = 0;
		createsalary(salaryfile, names, i, designation, post);
	} else {
		printf("\t\t\t\t\tSorry You Haven't selected\n");
	}
	fclose(ptr);

	//LOGIN FILE OPEN
	login = fopen("login.txt", "a+");
	//USERNAME
	printf("\t\t\t\t\t\t\tYour Username is: %.9s\n", i); //GIVEN
	printf("\t\t\t\t\tEnter your desired password: [maximum 8 characters long]\n");
//PASSWORD
newpass:
	printf("\t\t\t\t\t\t\tPassword should contain atleast 1 capital,1 small, and 1 number with no whitespace\n");
	printf("\t\t\t\t\t\t\t");
	fflush(stdin);
	gets(pass1);
	int capital = 0, small = 0, numeric = 0;
	if (strlen(pass1) > 8) {
		printf("Password should be atleast 8 characters\n");
		goto newpass;
	}
	for (k = 0; k < strlen(pass1); k++) {
		if (pass1[k] >= 'A' && pass1[k] <= 'Z') {
			capital++;
		}
	}
	for (k = 0; k < strlen(pass1); k++) {
		if (pass1[k] >= 'a' && pass1[k] <= 'z') {
			small++;
		}
	}
	for (k = 0; k < strlen(pass1); k++) {
		if (pass1[k] >= '0' && pass1[k] <= '9') {
			numeric++;
		}
	}
	if (capital == 0)
		printf("\t\t\t\t\t\t\tPassword should contain atleast One Capital letter\n");
	else if (small == 0)
		printf("\t\t\t\t\t\t\tPassword should contain atleast One Small letter\n");
	else if (numeric == 0)
		printf("\t\t\t\t\t\t\tPassword should contain atleast One Number\n");
	if (capital == 0 || small == 0 || numeric == 0) {
		goto newpass;
	}
	//PASSWORD CRITERIA IS TRUE
	printf("\t\t\t\t\t\t\tRe-Enter your password: \n");
	printf("\t\t\t\t\t\t\t");
	fflush(stdin);
	gets(pass2);

	//CHECKING PASSWORD

	if (strcmp(pass1, pass2) == 0) {
		printf("Account Created Succesfully!!\n");
		fprintf(login, "%.9s\n", i);
		fseek(login, 0, SEEK_CUR);
		fprintf(login, "%s\n", pass1);

		fclose(login);
		//Appending ptr in userfile
		ptr = fopen(i, "a+");
		fprintf(ptr, "Username: %.9s\n", i);
		// fseek(ptr,0,SEEK_SET);
		fputs("Userpass: ", ptr);
		fprintf(ptr, "%s", pass1);
		fclose(ptr);
	} else {
		printf("Password does not match!!!\n");
		goto newpass;
	}
	//ROLL NO CHANGE
	if (i[8] == 9) {
		i[7] = i[7] + 1;
		i[8] = 0;
	} else {
		i[8] = i[8] + 1;
	}
	getch();
	system("cls");
	goto main;
	return 0;
}
