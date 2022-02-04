#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>


//Name - Etay Lorberboym
//Id - 314977596
int main()
{

	char* MorseNum[] = {// Morse dictionary for Numers
		"_ _ _ _ _",//0
		". _ _ _ _",//1
		". . _ _ _",//2
		". . . _ _",//3
		". . . . _",//4
		". . . . .",//5
		"_ . . . .",//6
		"_ _ . . .",//7
		"_ _ _ . .",//8
		"_ _ _ _ ."//9
	};

	char* MorseChars[] = {// Morse dictionary for Letters
		". _",//A
		"_ . . .",//B
		"_ . _ .",//C
		"_ . .",//D
		".",//E
		". . _ .",//F
		"_ _ .",//G
		". . . .",//H
		". .",//I
		". _ _ _",//J
		"_ . _",//K
		". _ . .",//L
		"_ _",//M
		"_ .",//N
		"_ _ _",//O
		". _ _ .",//p
		"_ _ . _",//Q
		". _ .",//R
		". . .",//S
		"_",//T
		". . _",//U
		". . . _",//V
		". _ _",//W
		"_ . . _",//X
		"_ . _ _",//Y
		"_ _ . ." //Z
	};

	int end = 0;//boolean for ending program
	char input[200];
	while(end == 0){

		printf("Please enter a sentance that you want to convert to Morse: \n");
		gets(input);
		int finish = strcmp(input, "bye");

		if (finish == 0) {
			end = 1;
			break;
		}
		
		for (int i = 0; i < strlen(input); i++)
		{
			char c = tolower(input[i]);
			
			if (c >= 'a' && c <= 'z') {// char is a letter
				char *curr_morse = MorseChars[c - 'a'];
				beepAndPrintMorse(curr_morse);
				printf("   ");
			}
			else if (c >= '0' && c <= '9') {//char is number
				char *curr_morse = MorseNum[c - '0'];
				beepAndPrintMorse(curr_morse);
				printf("   ");
			
			}
			else if (c == 32) {//char is space - 32 is ascii for space
				printf("       ");
			}
		}
		printf("\n");
	
	}

	return 0;
}

int beepAndPrintMorse(char str[]) {
	int dot = 100;
	int dah = 300;// 3 times the dot
	for (int i = 0; i < strlen(str); i++) {
		char c = str[i];
		printf("%c", c);

		if (c == '.') {
			Beep(850, dot);
		}
		else if (c == '_') {
			Beep(850, dah);
		}
	}
	return 0;
}
