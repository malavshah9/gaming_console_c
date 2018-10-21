#include <stdio.h>
#include<stdlib.h>
char main_array[10] = " XOXXOOXOOXXX"; 

void screen_refresh(){
	/*
	This function refresh the entire
	game screen. 
	*/
	system("clear");

	printf("Hello Lets play tic-tac-toe");
	printf("\n\n\n%c | %c | %c\n--|---|--\n%c | %c | %c\n-   -|---|--\n%c | %c | %c\n",main_array[1],main_array[2],main_array[3],main_array[4],main_array[5],main_array[6],main_array[7],main_array[8],main_array[9]);

}
void main()
{
	printf("hey\n");
	screen_refresh();
}




