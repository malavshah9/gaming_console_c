#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include <ctype.h>
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
bool check_draw() 
{
	int i;
	for(i=1; i<=9; i++) {
		if (main_array [i] != ' ')
		{
			return false; 
		}
		return true;
	}
}
int genrate_random_move ()
{
    	int move  = 0; 
    	//long rand; 
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
bool has_won(char player)
{
	// checks if the player has won 
	if(main_array[1] == player && main_array[2] == player && main_array[3] == player){
		return true;
	}
	if(main_array[4] == player && main_array[5] == player && main_array[6] == player){
		return true;
	}
	if(main_array[7] == player && main_array[8] == player && main_array[9] == player){
		return true;
	}
	if(main_array[1] == player && main_array[4] == player && main_array[7] == player){
		return true;
	}
	if(main_array[2] == player && main_array[5] == player && main_array[8] == player){
		return true;
	}
	if(main_array[3] == player && main_array[6] == player && main_array[9] == player){
		return true;
	}
	if(main_array[1] == player && main_array[5] == player && main_array[9] == player){
		return true;
	}
	if(main_array[3] == player && main_array[5] == player && main_array[7] == player){
		return true;
	}
	return false;
}

bool put(int position,char player) 
{ 
	// This function puts the char if there is space and the input char is also valid
	if(player != 'O' && player != 'X'){
		return false;
	}
	else{ 
		if (main_array[position] != ' '){
			return false; 
		}
		else{ 
			main_array[position] = player;
			return true;
		}

	}

}

void player_move(char player){
	int pos; 		
	printf("(Please give your choice) YOUR TURN:=>  \n"); 
	scanf("%d",&pos); 
	while(put(pos,player) == false){
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