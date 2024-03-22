#include<conio.h>
#include<stdio.h>
#include "graphics.h"
#include "dibapi.h"
#include "dibutil.h"
#include "winbgi.h"
#include "winbgim.h"
#include "winbgitypes.h"
#include<stdlib.h>
#include<ctype.h> 
#include<dos.h>
#include<iostream>
#include<string.h> 
#include<time.h>
#include<fstream>
#include<windows.h>
#include<chrono>
#define MAX_FILENAME_LENGTH 100
#define MAX_FILE_CONTENT_LENGTH 1000
using namespace std;
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void nosound() {
	Beep(0, 0);  // Stop any ongoing beep
}

void sound(int frequency) {
	Beep(frequency, 100);
}

void playSoundEffect() {
	for (int a = 150; a <= 200; a += 10) {
		for (int b = 150; b <= 200; b += 10) {
			sound(a);  // Adjust duration as needed
			Sleep(25);
			sound(b);  // Adjust duration as needed
		}
	}
	nosound();
}

void TABLE(int, int, int, int, int);
void background(int, int, int, int, int);
void lock();
void MENU();
void arrow();
void SHOW_ARROW();
void LOAD();
void EXIT();
void game();
void start();
void s1();
void s2();
void s3();
void s4();
void s5();
void s5quiz();
int x_pos, y_pos;
int a = 1, number = 0, b, r, s = 0, e = 0, h = 0, r1[50], locked = 1;
char c, ch, g, p_word[20], rp_word[20], c_word[20], root = 251;
int main() {
	system("cls");
	int i{};
	LOAD();
	lock();
	start();
	return 0;
}
void start() {
	system("Color 0A");
	system("Color 0A");
	MENU();
	system("Color 0A");
	while (1) {
		c = _getch();
		system("Color 0A");
		system("cls");
		arrow();
		MENU();
		SHOW_ARROW();
		if (a == 1 && c == 13) { game(); }
		if (a == 2 && c == 13) { s1(); }
		if (a == 3 && c == 13) { s2(); }
		if (a == 4 && c == 13) { s3(); }
		if (a == 5 && c == 13) { s4(); }
		if (a == 6 && c == 13) { s5(); }
		if (a == 7 && c == 13) { EXIT(); }
	}
}
void EXIT() {
	system("cls");
	cout << "\t\tSaving User Files.....\n";
	Sleep(1000);
	cout << "\t\tClearing Up Files MyOS VERSION 2.0:)\n";
	Sleep(1000);
	exit(0);
}
void border() {
	int k, j, i;
	for (k = 1; k < 79; k++) {
		gotoxy(k, 2);
		cout << char(124);
		Sleep(5);
	}
	for (j = 2; j <= 22; j++) {
		gotoxy(1, j);
		cout << char(124);
		Sleep(5);
	}
	for (i = 2; i <= 79; i++) {
		gotoxy(i, 23);
		cout << char(124);
		Sleep(5);
	}
	for (int l = 22; l >= 2; l--) {
		gotoxy(79, l);
		cout << char(124);
		Sleep(5);
	}
}
void lock()
{
	char input[100], input2[100], y, c;
	int g = 0, i = 0;
point:
	border();
	cout << "\n\n\n\n\n\n\t\tEnter the password:";
	while (true) {
		ch = _getch();  // Get character without echoing to the console
		if (ch == 13) { // Check if Enter key is pressed
			input[i] = '\0'; // Null-terminate the string
			break;
		}
		cout << '*'; // Print '*' to the console
		input[i] = ch;
		i++;
	}
	char charArray[100];
	ifstream f;
	f.open("password.txt");
	while ((!f.eof()))
	{
		f >> charArray;
	}
	f.close();
	if (strcmp(charArray, input) == 0) {
		cout << "\n\n\n\n\n\t\tWant to Update Password Press'Y' (or) Press Any key to continue ";
		cin >> y;
		border();
		if (y == 'y') {
			cout << "\n\n\n\n\n\t\tEnter the New password:";
			cin >> input2;
			ofstream stream;
			char charArray1[100];
			stream.open("password.txt");
			stream << input2;
			cout << "\n\n\n\n\n\t\tpassword Updated.!!";
			system("cls");
			goto point;
		}
	}
	else {
		cout << "\n\n\n\n\n\t\tWrong password...";
		Sleep(1000);
		system("cls");
		goto point;
	}
	system("cls");
}
void TABLE(int a1, int a2, int b1, int b2, int color) {
	int i;
	system("Color 0A");
	for (i = a1 + 1; i < a2; i++) {
		gotoxy(i, b1); cprintf("%c", 205);
		gotoxy(i, b2); cprintf("%c", 205);
	}
	for (i = b1 + 1; i < b2; i++) {
		gotoxy(a1, i); cprintf("%c", 186);
		gotoxy(a2, i); cprintf("%c", 186);
	}
	gotoxy(a1, b1); cprintf("%c", 201);
	gotoxy(a2, b1); cprintf("%c", 187);
	gotoxy(a1, b2); cprintf("%c", 200);
	gotoxy(a2, b2); cprintf("%c", 188);
}

void MENU() {
	time_t t;
	time(&t);
	TABLE(10, 70, 2, 20, 1);
	TABLE(34, 44, 1, 3, 6);
	gotoxy(35, 2); cprintf("Welcome To Main Menu");
	gotoxy(30, 4); cprintf(ctime(&t));
	gotoxy(30, 6); cprintf("%c Calculator", 16);
	gotoxy(30, 8); cprintf("%c Piano", 16);
	gotoxy(30, 10); cprintf("%c Calendar", 16);
	gotoxy(30, 12); cprintf("%c Word Document", 16);
	gotoxy(30, 14); cprintf("%c StopWatch", 16);
	gotoxy(30, 16); cprintf("%c Games", 16);
	gotoxy(30, 18); cprintf("%c Exit", 16);
	system("Color 0A");
}
void arrow() {
	if (c == 72 || c == 77) { a--; }
	if (c == 80 || c == 75) { a++; }
}
void SHOW_ARROW() {
	if (a <= 0) { a = 8; }
	if (a >= 8) { a = 1; }
	switch (a) {
	case 1: gotoxy(30, 6); system("Color 0A"); cprintf("%c Calculator ", 16); break;
	case 2: gotoxy(30, 8); system("Color 04"); cprintf("%c Piaono ", 16); break;
	case 3: gotoxy(30, 10); system("Color 01"); cprintf("%c Calender ", 16); break;
	case 4: gotoxy(30, 12); system("Color 06"); cprintf(" % c Word Document ", 16); break;
	case 5: gotoxy(30, 14); system("Color 01"); cprintf("%c StopWatch ", 16); break;
	case 6: gotoxy(30, 16); system("Color 06"); cprintf(" %c Games ", 16); break;
	case 7: gotoxy(30, 18); system("Color 04"); cprintf(" %c Exit", 16); break;
	}
}
void LOAD() {
	int gd = DETECT, gm, a, color, overlap = 1;
	initgraph(&gd, &gm, "C:\\tc\\bgi");
	setcolor(YELLOW);
	rectangle(90, 385, 610, 405);
	setcolor(BLUE);
	for (a = 100; a <= 600; a++) {
		rectangle(125, 402, a, 388);
		Sleep(10);
		if (overlap == 1) {
			setcolor(BLUE);
			settextstyle(3, HORIZ_DIR, 5);
			outtextxy(100, 20, "Loading Please wait...");
			settextstyle(10, HORIZ_DIR, 4);
			setcolor(RED);
			outtextxy(280, 100, "MyOS");
			settextstyle(10, HORIZ_DIR, 8);
			outtextxy(250, 150, "2.0");
			overlap = 0;
			setcolor(RED);
		}
	}
	system("cls");
	closegraph();
}

void s1() {  // Piano
	system("cls");
	char n;
	int counter = 0;
	system("cls");
	printf("Enter any character between a-z or 1-0 from the keyboard\nPress'!' to exit\n");
	do {
		scanf("%c", &n);

		// MIDDLE LINE 9 keys middle frequency
		if (n == 'a') { sound(370); Sleep(200); nosound(); Sleep(50); }
		if (n == 's') { sound(392); Sleep(200); nosound(); Sleep(50); }
		if (n == 'd') { sound(415); Sleep(200); nosound(); Sleep(50); }
		if (n == 'f') { sound(440); Sleep(200); nosound(); Sleep(50); }
		if (n == 'g') { sound(466); Sleep(200); nosound(); Sleep(50); }
		if (n == 'h') { sound(493); Sleep(200); nosound(); Sleep(50); }
		if (n == 'j') { sound(523); Sleep(200); nosound(); Sleep(50); }
		if (n == 'k') { sound(554); Sleep(200); nosound(); Sleep(50); }
		if (n == '1') { sound(587); Sleep(200); nosound(); Sleep(50); }

		// Last line 7 keys lowest frequency
		if (n == 'z') { sound(233); Sleep(200); nosound(); Sleep(50); }
		if (n == 'x') { sound(261); Sleep(200); nosound(); Sleep(50); }
		if (n == 'c') { sound(277); Sleep(200); nosound(); Sleep(50); }
		if (n == 'v') { sound(293); Sleep(200); nosound(); Sleep(50); }
		if (n == 'b') { sound(311); Sleep(200); nosound(); Sleep(50); }
		if (n == 'n') { sound(329); Sleep(200); nosound(); Sleep(50); }
		if (n == 'm') { sound(349); Sleep(200); nosound(); Sleep(50); }

		// 1st line qwerty 10 keys highest frequency 
		if (n == 'q') { sound(622); Sleep(200); nosound(); Sleep(50); }
		if (n == 'w') { sound(659); Sleep(200); nosound(); Sleep(50); }
		if (n == 'e') { sound(698); Sleep(200); nosound(); Sleep(50); }
		if (n == 'r') { sound(740); Sleep(200); nosound(); Sleep(50); }
		if (n == 't') { sound(783); Sleep(200); nosound(); Sleep(50); }
		if (n == 'y') { sound(831); Sleep(200); nosound(); Sleep(50); }
		if (n == 'u') { sound(880); Sleep(200); nosound(); Sleep(50); }
		if (n == 'i') { sound(932); Sleep(200); nosound(); Sleep(50); }
		if (n == 'o') { sound(987); Sleep(200); nosound(); Sleep(50); }
		if (n == 'p') { sound(1046); Sleep(200); nosound(); Sleep(50); }

		// Higher than highest :p 10 keys 
		if (n == '1') { sound(622); Sleep(200); nosound(); Sleep(50); }
		if (n == '2') { sound(659); Sleep(200); nosound(); Sleep(50); }
		if (n == '3') { sound(698); Sleep(200); nosound(); Sleep(50); }
		if (n == '4') { sound(740); Sleep(200); nosound(); Sleep(50); }
		if (n == '5') { sound(783); Sleep(200); nosound(); Sleep(50); }
		if (n == '6') { sound(831); Sleep(200); nosound(); Sleep(50); }
		if (n == '7') { sound(880); Sleep(200); nosound(); Sleep(50); }
		if (n == '8') { sound(932); Sleep(200); nosound(); Sleep(50); }
		if (n == '9') { sound(987); Sleep(200); nosound(); Sleep(50); }
		if (n == ' ') { sound(1046); Sleep(200); nosound(); Sleep(50); }

		counter++;
		if (counter % 10 == 0) {
			printf("Enter any character between a-z or 1-0 from the keyboard\nPress '!' to exit \n");
		}
	} while (n != '!');
	int quit = 1;
	Sleep(2000);
	if (quit == 1) {
		system("cls");
		start();
	}
}


void s2() {
	system("cls");
	Beep(440, 100);

	std::cout << "\t\t\tCalendar\n";
	std::cout << "_______________________________________________________________________________________________________________________\n";

	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	const char week[7][10] = {
		"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
	};

	int date, mon, year;
	std::cout << "Enter a valid date (dd/mm/yyyy): ";
	std::cin >> date >> mon >> year;

	// Validate input
	if (date <= 0 || mon <= 0 || mon > 12 || year <= 0) {
		std::cerr << "Invalid date input\n";
		return;
	}

	// Adjust February days for leap years
	if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) {
		month[1] = 29;
	}

	int totalDays = date;
	for (int i = 0; i < mon - 1; i++) {
		totalDays += month[i];
	}
	totalDays += year + (year / 4) - 2;
	int dayIndex = totalDays % 7;

	std::cout << "\nThe day is " << week[dayIndex] << std::endl;

	// Delay for 2 seconds before returning to the start
	Sleep(2000);
	system("cls");
	start();
}

void createFile() {
	char filename[MAX_FILENAME_LENGTH];
	printf("Enter file name: ");
	scanf("%s", filename);
	FILE* file = fopen(filename, "w");
	if (file == NULL) {
		printf("Error creating file.\n");
		return;
	}
	printf("File created successfully.\n");
	fclose(file);
}

void openFile() {
	char filename[MAX_FILENAME_LENGTH];
	printf("Enter file name: ");
	scanf("%s", filename);
	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		printf("Error opening file.\n");
		return;
	}
	char content[MAX_FILE_CONTENT_LENGTH];
	printf("\n--- File Content ---\n");
	while (fgets(content, MAX_FILE_CONTENT_LENGTH, file) != NULL) {
		printf("%s", content);
	}
	printf("\n");
	fclose(file);
}

void editFile() {
	char filename[MAX_FILENAME_LENGTH];
	printf("Enter file name: ");
	scanf("%s", filename);
	FILE* file = fopen(filename, "a");
	if (file == NULL) {
		printf("Error opening file.\n");
		return;
	}
	printf("Enter text to append (press Enter to finish):\n");
	char text[MAX_FILE_CONTENT_LENGTH];
	getchar(); // Clear input buffer
	fgets(text, MAX_FILE_CONTENT_LENGTH, stdin);
	fprintf(file, "%s", text);
	fclose(file);
}

void deleteFile()
{
	char filename[MAX_FILENAME_LENGTH];
	printf("Enter file name: ");
	scanf("%s", filename);
	remove(filename);
	printf("File Deleted Successfully\n");
}

void renameFile()
{
	char filename1[MAX_FILENAME_LENGTH], filename2[MAX_FILENAME_LENGTH];
	printf("Enter old file name: ");
	scanf("%s", filename1);
	printf("Enter new file name: ");
	scanf("%s", filename2);
	printf("File has been renamed from %s to %s successfully\n", filename1, filename2);
}
void s3() { //word document
	system("cls");
	int choice{ 0 };
	do {
		printf("Text Editor Menu\n");
		printf("1. Create File\n");
		printf("2. Open File\n");
		printf("3. Edit File\n");
		printf("4. Delete File\n");
		printf("5. Rename File\n");
		printf("6. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			createFile();
			break;
		case 2:
			openFile();
			break;
		case 3:
			editFile();
			break;
		case 4:
			deleteFile();
			break;
		case 5:
			renameFile();
			break;
		case 6:
			printf("Exiting.\n");
			break;
		default:
			printf("Invalid choice. Please enter a number between 1 and 4.\n");
		}
	} while (choice != 4);
	int quit = 1;
	if (quit == 1)
	{
		Sleep(2000);
		system("cls");
		start();
	}
}


void s4() {  //stopwatch
	system("cls");

	int s, m, h, opt;
	int s1 = 0, m1 = 0, h1 = 0;
	int i;
	cout << "\n\t\t\tStopwatch\n";
	cout << "____________________________________________________________________________________________________\n";
	cout << "\nEnter the Seconds=";
	cin >> s;
	cout << "\nEnter the Min=";
	cin >> m;
	cout << "\nEnter the Hours=";
	cin >> h;
	cout << "____________________________________________________________________________________________________\n";
	cout << "\nTimer Set For:";
	cout << h << ":" << m << ":" << s << "\n";
	cout << "\t\t\tL";
	Sleep(100);
	cout << "E";
	Sleep(100);
	cout << "T";
	Sleep(100);
	cout << "S";
	Sleep(100);
	cout << " S";
	Sleep(100);
	cout << "T";
	Sleep(100);
	cout << "A";
	Sleep(100);
	cout << "R";
	Sleep(100);
	cout << "T\n";

	if (h != 0) {
		cout << "Counting Hours";
	}
	for (i = 0; i < h; i++) {
		for (int d = 0; d < 3600; d++) {
			Sleep(1000);
		}
		cout << ++h1 << ":" << m1 << ":" << s1 << "\n";
	}
	if (m != 0) {
		cout << "Counting Min";
	}

	for (i = 0; i < m; i++) {
		for (int d = 0; d < 60; d++)
		{
			Sleep(1000);
		}
		cout << h1 << ":" << ++m1 << ": " << s1 << "\n";
	}
	for (i = 0; i < s; i++)
	{
		Sleep(1000);
		cout << h1 << ":" << m1 << ":" << ++s1 << "\n";
	}
	for (int u = 0; u < 4; u++) {

		Sleep(200);
	}
	system("cls");
	cout << "\n The Timer Is Up..";
	int quit = 1;
	Sleep(2000);
	if (quit == 1) {
		system("cls");
		start();
	}
}

void s5guessnumber() {
	int choice{};
mainhome1:
	system("cls");

	printf("\n\t\t\t WELCOME");
	printf("\n\t\t\t to ");
	printf("\n\t\t\t THE GUESSING GAME");
	printf("\n\t\t________________________________________");
	printf("\n\t\t________________________________________");
	printf("\n\t\t GUESS THE NUMBER!!!!!!!!!!!");
	printf("\n\t\t________________________________________");
	printf("\n\t\t________________________________________");
	printf("\n\t\t > Press S to start the game");
	printf("\n\t\t > press Q to quit ");
	printf("\n\t\t________________________________________\n\n");
	choice = toupper(_getch());
	if (choice == 'Q') {
		Sleep(3000);

		system("cls");
		start();
	}
	else if (choice == 'S')
	{
		int number, guess, nguesses = 1;
		srand(time(0));
		number = rand() % 100 + 1; // Generates a random number between 1 and 100
		// printf("The number is %d\n", number);
		// Keep running the loop until the number is guessed
		do {
			printf("Guess the number between 1 to 100\n");
			cin >> guess;
			if (guess < 1 || guess>100) break;
			if (guess > number) {
				printf("Lower number please!\n");
			}
			else if (guess < number) {
				printf("Higher number please!\n");
			}
			else {
				printf("You guessed it in %d attempts\n", nguesses);
			}
			nguesses++;
		} while (guess != number);
		cout << "Do you want to continue?\nPress y to continue\nPress any key to go back to main menu";
		char ch{};
		cin >> ch;
		if (ch == 'y' || ch == 'Y')
			goto mainhome1;
	}

}
int snakeWaterGunutility(char you, char comp) {
	// returns 1 if you win, -1 if you lose and 0 if draw
	// Condition for draw
	// Cases covered:
	// ss
	// gg
	// ww
	if (you == comp) {
		return 0;
	}

	// Non-draw conditions
	// Cases covered:
	// sg
	// gs
	// sw 
	// ws
	// gw
	// wg


	if (you == 's' && comp == 'g') {
		return -1;
	}
	else if (you == 'g' && comp == 's') {
		return 1;
	}

	if (you == 's' && comp == 'w') {
		return 1;
	}
	else if (you == 'w' && comp == 's') {
		return -1;
	}

	if (you == 'g' && comp == 'w') {
		return -1;
	}
	else if (you == 'w' && comp == 'g') {
		return 1;
	}

}
void s5swg() {
	int choice{};
mainhome2:
	system("cls");

	printf("\n\t\t\t WELCOME");
	printf("\n\t\t\t to ");
	printf("\n\t\t\t SNAKE WATER GUN");
	printf("\n\t\t________________________________________");
	printf("\n\t\t________________________________________");
	printf("\n\t\t SNAKE WATER GUN!!!!!!!!!!!");
	printf("\n\t\t________________________________________");
	printf("\n\t\t________________________________________");
	printf("\n\t\t > Press S to start the game");
	printf("\n\t\t > press Q to quit ");
	printf("\n\t\t________________________________________\n\n");
	choice = toupper(_getch());
	if (choice == 'Q') {
		Sleep(3000);

		system("cls");
		start();
	}
	else if (choice == 'S')
	{
		char you, comp;
		srand(time(0));
		int number = rand() % 100 + 1;

		if (number < 33) {
			comp = 's';
		}
		else if (number > 33 && number < 66) {
			comp = 'w';
		}
		else {
			comp = 'g';
		}

		printf("Enter 's' for snake, 'w' for water and 'g' for gun\n");
		cin >> you;
		int result = snakeWaterGunutility(you, comp);
		if (result == 0) {
			printf("Game draw!\n");
		}
		else if (result == 1) {
			printf("You win!\n");
		}
		else {
			printf("You Lose!\n");
		}
		printf("You chose %c and computer chose %c. ", you, comp);
		cout << "Do you want to continue?\nPress y to continue\nPress any key to go back to main menu";
		char ch{};
		cin >> ch;
		if (ch == 'y' || ch == 'Y')
			goto mainhome2;

	}
}
int lsrch(string s, char x)
{
	for (int i = 0; i < s.size(); i++)
		if (s[i] == x)
			return i;
	return -1;
}
void s5wordle()
{
	cout << "Rules:" << endl << endl;
	cout << "Your objective is to guess a secret five-letter word in as 6 guesses." << endl << endl;
	cout << "To submit a guess, type any five-letter word and press enter." << endl << endl;
	cout << "All of your guesses must be real words, according to a dictionary." << endl << endl;
	cout << "The whole word is capitalized" << endl << endl;
	cout << "for every guess, you will get a vector output of digits {-1,0,1} indicating accuracy of each letter\n\n";
	cout << "-1->not in word\n0->in word but wrong position\n1->correct and in position\n" << endl;
	srand(time(0));
	int r = rand() % 90 + 1, n{ 0 };
	string ans{ "" };
	fstream fp{};
	fp.open("words.txt", ios::in);
	if (!fp)
	{
		cerr << "Can't Open file for reading!!!" << endl;
		return;
	}
	while (!fp.eof())
	{
		n++;
		getline(fp, ans);
		if (n == r)
			break;
	}
	int c{ 6 };
	while (c)
	{
		string inp{ "" };
		cout << "Enter 5-letter word:";
		cin >> inp;
		vector<int>acc(5, -1);
		if (inp.length() != 5)
		{
			cout << "Invalid word!!!enter 5 letter word" << endl;
			continue;
		}
		if (inp == ans)
		{
			cout << "You Won!!!" << endl;
			return;
		}
		else
		{
			for (int i = 0; i < 5; i++)
			{
				int in = lsrch(ans, inp[i]);
				if (in == i)
				{
					acc[i] = 1;
				}
				else if (in > -1)
					acc[i] = 0;
			}
		}
		cout << "accuracy:" << endl;
		for (int i = 0; i < 5; i++)
			cout << acc[i] << " ";
		cout << endl;
		c--;
	}
	cout << "The answer is:" << ans << endl;
	cout << "Good try!!!Better luck next time" << endl << endl;
	return;
}

void s5() {   //quiz
	system("cls");
	int ch{};
	cout << "Enter the game you want to play:\n";
	cout << "1.Guess a random number\n2.Quiz\n3.Snake Water Gun\n4.Wordle\nPress any key to exit\n";
	cin >> ch;
	if (ch == 1) s5guessnumber();
	if (ch == 2) s5quiz();
	if (ch == 3) s5swg();
	if (ch == 4) s5wordle();
}
void game() {

	int op;
	system("cls");
	cout << "\t\t\t\tCalculator\n";
	cout << "\n\t\t\t1. Add\n";
	cout << "\t\t\t2. Sub\n";
	cout << "\t\t\t3. Mul\n";
	cout << "\t\t\t4. Div\n";
	cout << "\t\t\t5. SIN\n";
	cout << "\t\t\t6. COS\n";
	cout << "\t\t\t7. TAN\n";
	cout << "\t\t\tSelect: ";
	cin >> op;

	if (op == -1) {
		cout << "\t\tYou have selected Quit\n";
	}
	else if (op == 2) {
		cout << "\t\tYou have selected Sub(-)\n";
	}
	else if (op == 3) {
		cout << "\t\tYou have selected Mul(*)\n";
	}
	else if (op == 4) {
		cout << "\t\tYou have selected Div(/)\n";
	}
	else if (op == 5) {
		cout << "\t\tYou have selected SIN\n";
	}
	else if (op == 6) {
		cout << "\t\tYou have selected COS\n";
	}
	else if (op == 7) {
		cout << "\t\tYou have selected TAN\n";
	}
	else {
		cout << "\t\tInvalid selection\n";
	}

	long float v1, v2, ans;
	int quit = 0;

	switch (op) {
	case 1:
		cout << "Enter Value 1: ";
		cin >> v1;
		cout << "Enter Value 2: ";
		cin >> v2;
		cout << "\t\t\t....\n";
		cout << "\t\t\t" << v1 + v2 << "\n";
		cout << "\t\t\t----";
		quit = 1;
		break;

	case 2:
		cout << "Enter Value 1: ";
		cin >> v1;
		cout << "Enter Value 2: ";
		cin >> v2;
		cout << "\t\t\t----\n";
		cout << "\t\t\t" << v1 - v2 << "\n";
		cout << "\t\t\t----";
		quit = 1;
		break;

	case 3:
		cout << "Enter Value 1: ";
		cin >> v1;
		cout << "Enter Value 2: ";
		cin >> v2;
		cout << "\t\t\t----\n";
		cout << "\t\t\t" << v1 * v2 << "\n";
		cout << "\t\t\t----";
		quit = 1;
		break;

	case 4:
		cout << "Enter Value 1: ";
		cin >> v1;
		cout << "Enter Value 2: ";
		cin >> v2;
		cout << "\t\t\t----\n";
		cout << "\t\t\t" << v1 / v2 << "\n";
		cout << "\t\t\t----";
		quit = 1;
		break;

	case 5:
		cout << "Angle  \t\t0    30    45     60    90 \n";
		cout << "Value  \t\t0    1/2    1/" << root << "2" << "   " << root << "3/2" << "    " << "1";
		quit = 1;
		break;

	case 6:
		cout << "Angle  \t\t0    30    45     60    90 \n";
		cout << "Value  \t\t1    " << root << "3/2" << "   " << "1/" << root << "2" << "   " << root << "1/2" << "    " << "0";
		quit = 1;
		break;

	case 7:
		cout << "Angle  \t\t0    30    45     60    90 \n";
		cout << "Value  \t\t0    " << "1/" << root << "3" << "   " << "1     " << root << "3" << "     " << "INFINITY";
		quit = 1;
		break;

	default:
		cout << "\t\tPlease Enter a Valid Number\n";
		quit = 1;
	}
	if (quit == 1) {
		Sleep(3000);
		system("cls");
		start();
	}
}


void s5quiz() {
	int countr, r, r1, count, i, n;
	float score;
	char choice;
	string playername;
mainhome:
	system("cls");

	printf("\n\t\t\t WELCOME");
	printf("\n\t\t\t to ");
	printf("\n\t\t\t THE QUIZ");
	printf("\n\t\t________________________________________");
	printf("\n\t\t________________________________________");
	printf("\n\t\t BECOME A MILLIONAIRE!!!!!!!!!!!");
	printf("\n\t\t________________________________________");
	printf("\n\t\t________________________________________");
	printf("\n\t\t > Press S to start the game");
	printf("\n\t\t > press Q to quit ");
	printf("\n\t\t________________________________________\n\n");
	choice = toupper(_getch());
	if (choice == 'Q') {
		Sleep(3000);

		system("cls");
		start();
	}
	else if (choice == 'S')
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\t\t\tRegister your name:");
		getline(cin, playername);
		printf("\n\n\t!!!!!!!!!!!!!! ALL THE BEST!!!!!!!!!!!!!!");
		printf("\n\n\n Press Y to start the game!\n");
		printf("\n Press any other key to return to the main menu!");
		if (toupper(_getch()) == 'Y')
		{
			goto home;
		}
		else
		{
			goto mainhome;
			system("cls");
		}
	home:
		system("cls");
		count = 0;
		for (i = 1; i <= 3; i++) {
			system("cls");
			r1 = i;

			switch (r1) {
			case 1:
				printf("\n\nWhich of the following is a Palindrome number?");
				printf("\n\nA.42042\t\tB.101010\n\nC.23232\t\tD.01234");
				if (toupper(_getch()) == 'C') {
					printf("\n\nCorrect!!!"); count++; _getch(); break;
				}
				else {
					printf("\n\nWrong!!! The correct answer is C.23232");
					_getch(); break;
				}
			case 2:
				printf("\n\n\nThe country with the highest environmental performance index is...");
				printf("\n\nA.France\t\tB.Denmark\n\nC.Switzerland\t\tD.Finland");
				if (toupper(_getch()) == 'C') {
					printf("\n\nCorrect!!!"); count++; _getch();	break;
				}
				else
				{
					printf("\n\nWrong!!! The correct answer is C.Switzerland");
					_getch(); break;
				}
			case 3:
				printf("\n\n\nWhich animal laughs like human being?");
				printf("\n\nA.Polar Bear\t\tB.Hyena\n\nC.Donkey\t\tD.Chimpanzee");
				if (toupper(_getch()) == 'B') { printf("\n\nCorrect!!!"); count++; _getch(); break; }
				else
				{
					printf("\n\nWrong!!! The correct answer is B.Hyena"); _getch(); break;
				}
			case 4:
				printf("\n\n\nWho was awarded the youngest player awarded in Fifa World Cup 2006 ? ");
				printf("\n\nA.Wayne Rooney\t\tB.Lucas Podolski\n\nC.Messi\t\tD.Christiano Ronaldo");
				if (toupper(_getch()) == 'B') { printf("\n\nCorrect!!!"); count++; _getch(); break; }
				else {
					printf("\n\nWrong!!! The correct answer is B.Lucas Podolski"); _getch(); break;
				}
			case 5:
				printf("\n\n\nWhich is the third highest mountain in the world?");
				printf("\n\nA.Mt. K2\t\tB.Mt. Kanchanjungha\n\nC.Mt.Makalu\t\tD.Mt.Kilimanjaro");
				if (toupper(_getch()) == 'B') { printf("\n\nCorrect!!!"); count++; _getch(); break; }
				else {
					printf("\n\nWrong!!! The correct answer is B.Mt. Kanchanjungha");
					_getch(); break;
				}
			case 6:
				printf("\n\n\nWhat is the group of frogs known as?");
				printf("\n\nA.A traffic\t\tB.A toddler\n\nC.A police\t\tD.AnArmy");
				if (toupper(_getch()) == 'D') { printf("\n\nCorrect!!!"); count++; _getch(); break; }
				else {
					printf("\n\nWrong!!! The correct answer is D.An Army"); _getch(); break;
				}
			}
		}
		if (count >= 2) {
			goto test;
		}
		else {
			system("cls");
			printf("\n\nSORRY YOU ARE NOT ELIGIBLE TO PLAY THIS GAME, BETTER LUCK NEXT TIME");
			_getch();
			goto mainhome;
		}
	test:
		system("cls");
		printf("\n\n\t** CONGRATULATION %s you are eligible to play the Game ***", playername);
		printf("\n\n\n\n\t!Press any key to Start the Game!");
		if (toupper(_getch()) == 'p') { goto game; }
	game:
		countr = 0;
		for (i = 1; i <= 10; i++) {
			system("cls");
			r = i;
			switch (r) {
			case 1:
				printf("\n\nWhat is the National Game of England?");
				printf("\n\nA. Football\t\tB.Basketball\n\nC.Cricket\t\tD.Baseball");
				if (toupper(_getch()) == 'C') {
					printf("\n\nCorrect!!!"); countr++; _getch(); break; _getch();
				}
				else {
					printf("\n\nWrong!!! The correct answer is C.Cricket"); _getch(); goto score; break;
				}
			case 2:
				printf("\n\n\nStudy of Earthquake is called.............");
				printf("\n\nA.Seismology\t\tB.Cosmology\n\nC.Orology\t\tD.Etimology");
				if (toupper(_getch()) == 'A') {
					printf("\n\nCorrect!!!"); countr++; _getch(); break;
				}
				else {
					printf("\n\nWrong!!! The correct answer is A.Seismology"); _getch(); goto score; break;
				}
			case 3:
				printf("\n\n\nAmong the top 10 highest peaks in the world, how many lie in Nepal? ");
				printf("\n\nA.6\t\tB.7\n\nC.8\t\tD.9");
				if (toupper(_getch()) == 'C') {
					printf("\n\nCorrect!!!"); countr++; _getch(); break;
				}
				else {
					printf("\n\nWrong!!! The correct answer is C.8"); _getch(); goto score; break;
				}
			case 4:
				printf("\n\n\nThe Laws of Electromagnetic Induction were given by?");
				printf("\n\nA.Faraday\t\tB.Tesla\n\nC. Maxwell\t\tD.Coulomb");
				if (toupper(_getch()) == 'A') {
					printf("\n\nCorrect!!!"); countr++; _getch(); break;
				}
				else {
					printf("\n\nWrong!!! The correct answer is A.Faraday"); _getch(); goto score; break;
				}
			case 5:
				printf("\n\n\nin what unit is electric power measured?");
				printf("\n\nA.Coulomb\t\tB.Watt\n\nC.Power\t\tD.Units");
				if (toupper(_getch()) == 'B') {
					printf("\n\nCorrect!!!"); countr++; _getch(); break;
				}
				else {
					printf("\n\nWrong!!! The correct answer is B.Power"); _getch(); goto score; break;
				}
			case 6:
				printf("\n\n\nWhich element is found in Vitamin B12?");
				printf("\n\nA.Zinc\t\tB.Cobalt\n\nC.Calcium\t\tD.Iron");
				if (toupper(_getch()) == 'B') {
					printf("\n\nCorrect!!!"); countr++; _getch(); break;
				}
				else
				{
					printf("\n\nWrong!!! The correct answer is B.Cobalt"); _getch(); goto score; break;
				}
			case 7:
				printf("\n\n\nWhat is the National Name of Japan?");
				printf("\n\nA.Polska\t\tB.Hellas\n\nC.Drukyul\t\tD.Nippon");
				if (toupper(_getch()) == 'D') {
					printf("\n\nCorrect!!!"); countr++; _getch(); break;
				}
				else {
					printf("\n\nWrong!!! The correct answer is D. Nippon"); _getch(); goto score; break;
				}
			case 8:
				printf("\n\n\nHow many times a piece of paper can be folded at the most?");
				printf("\n\nA.6\t\tB.7\n\nC.8\t\tD.Depends on the size of paper");
				if (toupper(_getch()) == 'B') {
					printf("\n\nCorrectill"); countr++; _getch(); break;
				}
				else {
					printf("\n\nWrong!!! The correct answer is B.7"); _getch(); goto score; break;
				}
			case 9:
				printf("\n\n\nWhat is the capital of Denmark?");
				printf("\n\nA.Copenhagen\t\tB.Helsinki\n\nC.Ajax\t\tD.Galatasaray");
				if (toupper(_getch()) == 'A') {
					printf("\n\nCorrect!!!"); countr++; _getch(); break;
				}
				else {
					printf("\n\nWrong!!! The correct answer is A.Copenhagen"); _getch(); goto score; break;
				}
			case 10:
				printf("\n\n\nWhich is the longest River in the world?");
				printf("\n\nA.Nile\t\tB.Koshi\n\nC.Ganga\t\tD.Amazon");
				if (toupper(_getch()) == 'A') {
					printf("\n\nCorrect!!!"); countr++; _getch(); break;
				}
				else
				{
					printf("\n\nWrong!!! The correct answer is A.Nile"); _getch(); break; goto score;
				}
			case 11:
				printf("\n\n\nWhat is the color of the Black Box in aeroplanes?");
				printf("\n\nA.White\t\tB.Black\n\nC.Orange\t\tD.Red");
				if (toupper(_getch()) == 'C')
				{
					printf("\n\nCorrect!!!"); countr++; _getch(); break;
				}
				else {
					printf("\n\nWrong!!! The correct answer is C.Orange"); _getch(); break; goto score;
				}

			case 12:
				printf("\n\n\nWhich city is known as The City of Seven Hills?");
				printf("\n\nA.Rome\t\tB.Vatican City\n\nC.Madrid\t\tD.Berlin");

				if (toupper(_getch()) == 'A') {
					printf("\n\nCorrect!!!");
					countr++;
					_getch();
					break;
				}
				else {
					printf("\n\nWrong!!! The correct answer is A. Rome");
					_getch();
					break;
					goto score;
				}

			case 13:
				printf("\n\n\nName the country where there are no mosquitoes found?");
				printf("\n\nA.Japan\t\tB.Italy\n\nC.Argentina\t\tD.France");

				if (toupper(_getch()) == 'D') {
					printf("\n\nCorrect!!!");
					countr++;
					_getch();
					break;
				}
				else {
					printf("\n\nWrong!!! The correct answer is D. France");
					_getch();
					break;
					goto score;
				}

			case 14:
				printf("\n\n\nWho is the author of 'Pulpasa Cafe'?");
				printf("\n\nA.Narayan Wagle\t\tB.Lal Gopal Subedi\n\nC.B.P. Koirala\t\tD.Khagendra Sangraula");

				if (toupper(_getch()) == 'A') {
					printf("\n\nCorrect!!!");
					countr++;
					_getch();
					break;
				}
				else {
					printf("\n\nWrong!!! The correct answer is A. Narayan Wagle");
					_getch();
					break;
					goto score;
				}

			case 15:
				printf("\n\n\nWhich Blood Group is known as the Universal Recipient?");
				printf("\n\nA.A\t\tB.AB\n\nC.B\t\tD.O");

				if (toupper(_getch()) == 'B') {
					printf("\n\nCorrect!!!");
					countr++;
					_getch();
					break;
				}
				else {
					printf("\n\nWrong!!! The correct answer is B. AB");
					_getch();
					goto score;
					break;
				}
			case 16:
				printf("\n\n\nWhat is the unit of measurement of distance between Stars?");
				printf("\n\nA.Light Year\t\tB.Coulomb\n\nC.Nautical Mile\t\tD.Kilometer");

				if (toupper(_getch()) == 'A') {
					printf("\n\nCorrect!!!");
					countr++;
					_getch();
					break;
				}
				else {
					printf("\n\nWrong!!! The correct answer is A.Light Year");
					_getch();
					goto score;
					break;
				}

			case 17:
				printf("\n\n\nThe country famous for Samba Dance is........");
				printf("\n\nA.Brazil\t\tB.Venezuela\n\nC.Nigeria\t\tD.Bolivia");

				if (toupper(_getch()) == 'A') {
					printf("\n\nCorrect!!!");
					countr++;
					_getch();
					break;
				}
				else {
					printf("\n\nWrong!!! The correct answer is A.Brazil");
					_getch();
					goto score;
					break;
				}

			case 18:
				printf("\n\n\nWind speed is measured by");
				printf("\n\nA.Lysimeter\t\tB.Air vane\n\nC.Hydrometer\t\tD.Anemometer\n\n");

				if (toupper(_getch()) == 'D') {
					printf("\n\nCorrect!!!");
					countr++;
					_getch();
					break;
				}
				else {
					printf("\n\nWrong!!! The correct answer is D.Anemometer");
					_getch();
					goto score;
					break;
				}

			case 19:
				printf("\n\n\nWhich city in the world is popularly known as The City of Temple?");
				printf("\n\nA.Delhi\tB.Bhaktapur\n\nC.Kathmandu\tD.Agra\n\n");

				if (toupper(_getch()) == 'C') {
					printf("\n\nCorrect!!!");
					countr++;
					_getch();
					break;
				}
				else {
					printf("\n\nWrong!!! The correct answer is C.Kathmandu");
					_getch();
					break;
				}
			case 20:
				printf("\n\n\nWhich hardware was used in the First Generation Computer?");
				printf("\n\nA.Transistor\t\tB.Valves\n\nC.I.C\t\tD.S.S.I");

				if (toupper(_getch()) == 'B') {
					printf("\n\nCorrect!!!");
					countr++;
					_getch();
					break;
				}
				else {
					printf("\n\nWrong!!! The correct answer is B.Valves");
					_getch();
					goto score;
					break;
				}

			case 21:
				printf("\n\n\nOzone plate is being destroyed regularly because of ?");
				printf("\n\nA.L.P.G\t\tB.Nitrogen\n\nC.Methane\t\tD.C.F.C");

				if (toupper(_getch()) == 'D') {
					printf("\n\nCorrect!!!");
					countr++;
					_getch();
					break;
				}
				else {
					printf("\n\nWrong!!! The correct answer is D.C.F.C");
					_getch();
					goto score;
					break;
				}

			case 22:
				printf("\n\n\nWho won the Women's Australian Open Tennis in 2007?");
				printf("\n\nA.Martina Hingis\t\tB. Maria Sharapova\n\nC.Kim Clijsters\t\tD.Serena Williams");

				if (toupper(_getch()) == 'D') {
					printf("\n\nCorrect!!!");
					countr++;
					_getch();
					break;
				}
				else {
					printf("\n\nWrong!!! The correct answer is D.Serena Williams");
					_getch();
					goto score;
					break;
				}

			case 23:
				printf("\n\n\nWhich film was awarded the Best Motion Picture at Oscar in 2010?");
				printf("\n\nA.The Secret in their Eyes\t\tB.Shutter Island\n\nC.The King's Speech\t\tD.The Reader");

				if (toupper(_getch()) == 'C') {
					printf("\n\nCorrect!!!");
					countr++;
					_getch();
					break;
				}
				else {
					printf("\n\nWrong!!! The correct answer is C.The King's Speech");
					_getch();
					goto score;
					break;
				}
			}
		}
	score:
		system("cls");
		score = (float)countr * 100000;

		if (score > 0.00 && score < 1000000) {
			printf("\n\n\t\t........ CONGRATULATIONS ........");
			printf("\n\t You won $%.2f", score);
			goto go;
		}
		else if (score == 1000000.00) {
			printf("\n\n\n \t\t******* CONGRATULATIONS ********");
			printf("\n\t\t\t YOU ARE A MILLIONAIRE!!!!!!!!!");
			printf("\n\t\t You won $%.2f", score);
			printf("\n\t\t Thank You!!");
		}
		else {
			printf("\n\n\t**** SORRY YOU DIDN'T WIN ANY CASH ***...");
			printf("\n\t\t Thanks for your participation");
			printf("\n\t\t TRY AGAIN");
			goto go;
		}
	go:
		puts("\n\n Press Y if you want to play the next game");
		puts(" Press any key if you want to go to the main menu");

		if (toupper(_getch()) == 'Y')
			goto home;
		else
			goto mainhome;

		_getch();
	}
}
