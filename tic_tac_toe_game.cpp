#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<mmsystem.h>

#pragma comment(lib, "winmm.lib")

char places[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
bool isEmpty[9] = {true, true, true, true, true, true, true, true, true};
int player = 2;

void heading(){
	system("cls");
	printf("TIC TAC TOE\n");
	printf("<<<<<<>>>>>>\n\n");
	printf("PLAYER 1 - X, PLAYER 2 - O\n\n\n");

}

void board(){
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n", places[0], places[1], places[2]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n", places[3], places[4], places[5]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n", places[6], places[7], places[8]);
	printf("     |     |     \n\n\n");
}

void restart(){
	player = 2;
	for(int i=0;i<9;i++){
		places[i] = '1' + i;
		isEmpty[i] = true;
	}
}

void *t;

void move(){

	printf("PLAYER %d! Tab the number of square... ", player);
	int choise = getch() - '0';
	char mark = (!(player-1)) ? 'X' : 'O';
	if(isEmpty[choise-1] && (choise > 0 && choise < 10)){
		places[choise-1] = mark;
		isEmpty[choise-1] = false;
	}
	else{
		printf(" Invalid move!");
		getch();
		goto *t;
	}
}

bool isFull(){
	for(int i=0;i<9;i++){
		if(isEmpty[i]){
			return false;
		}
	}
	return true;
}

bool checkWin(){

	if(
		(places[0] == places[1] && places[1] == places[2]) ||
		(places[3] == places[4] && places[4] == places[5]) ||
		(places[6] == places[7] && places[7] == places[8]) ||
		(places[0] == places[3] && places[3] == places[6]) ||
		(places[1] == places[4] && places[4] == places[7]) ||
		(places[2] == places[5] && places[5] == places[8]) ||
		(places[0] == places[4] && places[4] == places[8]) ||
		(places[2] == places[4] && places[4] == places[6])
	){
		return true;
	}
	else{
		return false;
	}
 
}

int main(){
	system("color 17");
	t = &&Start;
	while(true){
		player = (player % 2) ? 2 : 1;
		
		Start:
		heading();
		board();
		move();
		
		
		if(checkWin()){
			system("cls");
			heading();
			board();
			printf("PLAYER %d WIN!\n\nTab any key to restart game...", player);
			PlaySound(TEXT("win.wav"), NULL, SND_SYNC);
			getch();
			restart();
		}
		else if(isFull()){
			heading();
			board();
			printf("Board is FULL! Tab any key to restart game...\n\n");
			PlaySound(TEXT("fullboard.wav"), NULL, SND_SYNC);
			getch();
			restart();
		}

	}
	
	return 0;
}