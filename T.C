// #include <t.h>
#include <stdio.h>
//#include<stdint.h>
#include<stdlib.h>
#include <ctype.h>
// #define _int        int
// #define int        int
// #define 0        0
// #define 1        1

char main_array[10] = "          "; 
char show_array[9] = "123456789";
char get_choice(){
	char choice;
	printf("Choose your Charcter \n"); 
	scanf("%c",&choice);
	while(choice != 'o' && choice != 'x' && choice != 'O' && choice != 'X')
	{
		scanf("%c",&choice);
		
	}
	choice = toupper(choice);
	return choice; 
}
int check_draw()
{
	int i;
	for(i=1; i<=9; i++) {
		if (main_array [i] == ' ')
		{
			return 0;
		}
 //		return 1;
	}
	return 1;
}
int genrate_random_move ()
{
    	int move  = 0; 
    	//long rand;
		move=rand()%10; 
    	while(move == 0 || main_array [move] != ' ') {
    		move = rand() % 10; 
    	}
    	return move; 
    }
int can_win(char player)
{
	// check if player can win on next step or not 
	
	if(main_array[1] == player && main_array[2] == player && main_array[3] == ' '){
		return 3;
	}
	if(main_array[4] == player && main_array[5] == player && main_array[6] == ' '){
		return 6;
	}
	if(main_array[7] == player && main_array[8] == player && main_array[9] == ' '){
		return 9;
	}
	if(main_array[1] == player && main_array[4] == player && main_array[7] == ' '){
		return 7;
	}
	if(main_array[2] == player && main_array[5] == player && main_array[8] == ' '){
		return 8;
	}
	if(main_array[3] == player && main_array[6] == player && main_array[9] == ' '){
		return 9;
	}
	if(main_array[1] == player && main_array[5] == player && main_array[9] == ' '){
		return 9;
	}
	if(main_array[3] == player && main_array[5] == player && main_array[7] == ' '){
		return 7;
	}
//---=====================//---=====================//---=====================//---==========
	if(main_array[1] == ' ' && main_array[2] == player && main_array[3] == player){
		return 1;
	}
	if(main_array[4] == ' ' && main_array[5] == player && main_array[6] == player){
		return 4;
	}
	if(main_array[7] == ' ' && main_array[8] == player && main_array[9] == player){
		return 7;
	}
	if(main_array[1] == ' ' && main_array[4] == player && main_array[7] == player){
		return 1;
	}
	if(main_array[2] == ' ' && main_array[5] == player && main_array[8] == player){
		return 2;
	}
	if(main_array[3] == ' ' && main_array[6] == player && main_array[9] == player){
		return 3;
	}
	if(main_array[1] == ' ' && main_array[5] == player && main_array[9] == player){
		return 1;
	}
	if(main_array[3] == ' ' && main_array[5] == player && main_array[7] == player){
		return 3;
	}
//---=====================//---=====================//---=====================//---==========

	if(main_array[1] == player && main_array[2] == ' ' && main_array[3] == player){
		return 2;
	}
	if(main_array[4] == player && main_array[5] == ' ' && main_array[6] == player){
		return 5;
	}
	if(main_array[7] == player && main_array[8] == ' ' && main_array[9] == player){
		return 8;
	}
	if(main_array[1] == player && main_array[4] == ' ' && main_array[7] == player){
		return 4;
	}
	if(main_array[2] == player && main_array[5] == ' ' && main_array[8] == player){
		return 5;
	}
	if(main_array[3] == player && main_array[6] == ' ' && main_array[9] == player){
		return 6;
	}
	if(main_array[1] == player && main_array[5] == ' ' && main_array[9] == player){
		return 5;
	}
	if(main_array[3] == player && main_array[5] == ' ' && main_array[7] == player){
		return 5;
	}
return -1; 
}
int has_won(char player)
{
	// checks if the player has won 
	if(main_array[1] == player && main_array[2] == player && main_array[3] == player){
		return 1;
	}
	if(main_array[4] == player && main_array[5] == player && main_array[6] == player){
		return 1;
	}
	if(main_array[7] == player && main_array[8] == player && main_array[9] == player){
		return 1;
	}
	if(main_array[1] == player && main_array[4] == player && main_array[7] == player){
		return 1;
	}
	if(main_array[2] == player && main_array[5] == player && main_array[8] == player){
		return 1;
	}
	if(main_array[3] == player && main_array[6] == player && main_array[9] == player){
		return 1;
	}
	if(main_array[1] == player && main_array[5] == player && main_array[9] == player){
		return 1;
	}
	if(main_array[3] == player && main_array[5] == player && main_array[7] == player){
		return 1;
	}
	return 0;
}

int put(int position,char player)
{ 
	// This function puts the char if there is space and the input char is also valid
	if(player != 'O' && player != 'X'){
		return 0;
	}
	else{ 
		if (main_array[position] != ' '){
			return 0; 
		}
		else{ 
			main_array[position] = player;
			return 1;
		}

	}

}

void player_move(char player){
	int pos; 		
	printf("(Please give your choice) YOUR TURN:=>  \n"); 
	scanf("%d",&pos); 
	while(put(pos,player) == 0){
		printf("Please provide a valid choice.\n");
		scanf("%d",&pos);
	}
}

void computer_move(char comp, char player){
	int pos = can_win(comp);
	if(pos  != -1){
		put(pos, comp);
		return;
	}
	pos = can_win(player); 
	if(pos  != -1){
		put(pos, comp);
		return;
	}
	if(main_array[5] == ' '){
		put(5,comp);
		return;
	}
	pos = genrate_random_move();
	put(pos, comp); 
}

int get_game_status (char p1, char p2){ 
	if (check_draw()){
		return 0;
	}
	if(has_won(p1)){
		return 1; 
	}
	if(has_won(p2)){
		return 2; 
	}
	return -1;
}
void screen_refresh_2()
{

	/*
	This function refresh the entire
	game screen. 
	*/
	// system("clear");
	clrscr();
	printf("Hello Lets play tic-tac-toe");
	printf("\n\n\n%c | %c | %c\n--|---|--\n%c | %c | %c\n--|---|--\n%c | %c | %c\n",main_array[1],main_array[2],main_array[3],main_array[4],main_array[5],main_array[6],main_array[7],main_array[8],main_array[9]);
}
void screen_refresh()
{
	/*
	This function refresh the entire
	game screen. 
	*/
	//sleep(1);
	// system("clear");
	clrscr();
	printf("Hello Lets play tic-tac-toe");
	printf("\n\n\n%c | %c | %c\n--|---|--\n%c | %c | %c\n--|---|--\n%c | %c | %c\n",main_array[1],main_array[2],main_array[3],main_array[4],main_array[5],main_array[6],main_array[7],main_array[8],main_array[9]);
	printf("\n\nThe following is all the numbers for every poistion\n");
	printf("\n\n\n%c | %c | %c\n--|---|--\n%c | %c | %c\n--|---|--\n%c | %c | %c\n",show_array[0],show_array[1],show_array[2],show_array[3],show_array[4],show_array[5],show_array[6],show_array[7],show_array[8]);
	//fflush(stdout);

}
int main (){
	int game_type=0;
	int game_state=-1;
	char player,p1,p2,computer; 
	// system("clear");
	clrscr();
	while(game_type != 1 && game_type != 2){
	    printf("WELCOME TO TIC-TAC-TOE. PRESS 1 FOR ONE PLAYER GAME AND FOR TWO PLAYER GAME \n");
		scanf("%d",&game_type); 
	}
	if(game_type == 1)
	{
		player = get_choice(); 
		if (player == 'O')
		{
			computer = 'X';
		}
		else
		{
			computer = 'O'; 

		}
		while(1) // game loop;
		{
			game_state = -1;
			screen_refresh();
			player_move(player);
			game_state = get_game_status(player,computer); 
			screen_refresh();
			if(game_state != -1) break; 
			computer_move(computer,player);
			game_state = get_game_status(player,computer); 
			if(game_state != -1) break;
		}
		screen_refresh_2();
		if (game_state == 0){ 
			printf("\n\nGame Drawn\n\n");
		}
		else if(game_state == 1){
			printf("\n\nCongrats You won the game\n\n"); 
		}
		else if (game_state == 2){
			printf("\n\nSorry! You lost the game\n\n");
		}
	       getch();
	
	}
	
	return 0;

}
