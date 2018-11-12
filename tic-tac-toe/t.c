#include "t.h"
void screen_refresh_2()
{

	/*
	This function refresh the entire
	game screen. 
	*/
	system("clear");

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
	system("clear");
	printf("Hello Lets play tic-tac-toe");
	printf("\n\n\n%c | %c | %c\n--|---|--\n%c | %c | %c\n--|---|--\n%c | %c | %c\n",main_array[1],main_array[2],main_array[3],main_array[4],main_array[5],main_array[6],main_array[7],main_array[8],main_array[9]);
	printf("\n\nThe following is all the numbers for every poistion\n");
	printf("\n\n\n%c | %c | %c\n--|---|--\n%c | %c | %c\n--|---|--\n%c | %c | %c\n",show_array[0],show_array[1],show_array[2],show_array[3],show_array[4],show_array[5],show_array[6],show_array[7],show_array[8]);
	//fflush(stdout);

}
int main (){
	int game_type;
	int game_state=-1;
	char player,p1,p2,computer; 
	system("clear");
	while(game_type != 1 && game_type != 2){
	    printf("WELCOME TO TIC-TAC-TOE. PRESS 1 FOR ONE PLAYER GAME AND 2 FOR TWO PLAYER GAME \n");
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
		
	
	}
	
	return 0;

}


