#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include <stdlib.h>
#include<time.h>

void draw_1();
void draw_2();
void draw_3();
void draw_4();
void draw_5();
void draw_6();
void draw_7();
void draw_8();
void draw_animation();
void draw_lines_for_no_of_words(int length);
void start_game();
void get_word(char *word);
int no_of_steps_performed=0;

	void main()
	{
	int gdriver = DETECT,gmode;
	time_t t;	
	srand((unsigned) time(&t)); 		//Initialized Random Number
	initgraph(&gdriver,&gmode,"C:\\TC\\BGI"); //Initialized Graphics Driver
	start_game();
	getch();
	}
void get_word(char *word)
{
	int no=rand()%60000;
	char *str;
	int cnt=0;
	FILE *fp=fopen("words.txt","r");
	while(cnt!=no)
	{
		fscanf(fp,"%s",str);
		cnt++;
	}
	strcpy(word,str);
	fclose(fp);
}
void start_game()
{
		char *our_word;
		int len;
		get_word(our_word);
		len=strlen(our_word);
		draw_lines_for_no_of_words(len);
		printf("\n%s",our_word);
}
void draw_lines_for_no_of_words(int length)
{
	int j=0;
	int x=10,y=10;
	int temp_x=0;
	while(j<length)
	{

		temp_x=x+5;
		while(x<temp_x)
		{
			putpixel(x,y,RED);
			x=x+1;
		}
		temp_x=x+5;
		while(x<temp_x)
		{
			putpixel(x,y,WHITE);
			x=x+1;
		}
		j++;
	}
}
void draw_animation()
{
	if(no_of_steps_performed==0)
	{
		draw_1();
	}
	else if(no_of_steps_performed==1)
	{
		draw_2();
	}

	else if(no_of_steps_performed==2)
	{
		draw_3();
	}

	else if(no_of_steps_performed==3)
	{
		draw_4();
	}
	else if(no_of_steps_performed==4)
	{
		draw_5();
	}
	else if(no_of_steps_performed==5)
	{
		draw_6();
	}
	else if(no_of_steps_performed==6)
	{
		draw_7();
	}
	else if(no_of_steps_performed==7)
	{
		draw_8();
		printf("GAME OVER");
	}
	else
	{
		printf("GAME OVER");
	}
}
void draw_1()
{
	int i=0,j=250;
	int d=10;
	int gdriver = DETECT,gmode;
	initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
	//Verticle Line
	for(i=40;i<400;i++)
	{
		 putpixel(j,i,3);
		 putpixel(j+1,i,2);
		 putpixel(j+2,i,4);
		 delay(d);
	}
	//Horizontal Line
	for(i=250;i<400;i++)
	{
		putpixel(i,40,1);
		putpixel(i,40,2);
		putpixel(i,40,3);
		delay(d);
	}
	//Left Cross Line
	i=400;
	for(j=200;j<=250;j++,i--)
	{
		putpixel(j,i,1);
		putpixel(j,i+1,2);
		putpixel(j,i+2,3);
		delay(d);
	}
	//Right Cross Line
	for(j=250;j<=300;j++)
	{
		putpixel(j,i,1);
		putpixel(j,i+1,2);
		putpixel(j,i+2,3);
		delay(d);
		i++;
	}
	no_of_steps_performed++;
}

void draw_2()
{
	//Draws Thread
	int d=10;
	int i=400,j=400;
	for(i=40;i<150;i++)
	{
		putpixel(j,i,6);
		putpixel(j+1,i,7);
		putpixel(j+2,i,8);
		delay(d);
	}
	no_of_steps_performed++;
}
void draw_3()
{
	//Draws Face
	circle(400,180,30);
	no_of_steps_performed++;
}
void draw_4()
{
	//Draws Nack and body
	int x=400,y=210;
	int d=10;
	for(y=210;y<=300;y++)
	{
		putpixel(x,y,WHITE);
		putpixel(x+1,y,WHITE);
		putpixel(x-1,y,WHITE);
		delay(d);
	}
	no_of_steps_performed++;
}
void draw_5()
{
	//Draws Left Lag
	int y=450,x=350;
	int d=10;
	for(y=350;y>=300;y--,x++)
	{
		putpixel(x,y,WHITE);
		putpixel(x+1,y,WHITE);
		putpixel(x-1,y,WHITE);
		delay(d);
	}
	no_of_steps_performed++;
}
void draw_6()
{
	//Draws Right Lag
	int y=300,x=300,d=10;
	for(x=400;x<=450;x++,y++)
	{
		putpixel(x,y,WHITE);
		putpixel(x+1,y,WHITE);
		putpixel(x-1,y,WHITE);
		delay(d);
	}
	no_of_steps_performed++;
}
void draw_7()
{
	//Draws Left Hand
	int y=400,x=350;
	int d=10;
	for(y=270;y>=220;y--,x++)
	{
		putpixel(x,y,WHITE);
		putpixel(x+1,y,WHITE);
		putpixel(x-1,y,WHITE);
		delay(d);
	}
	no_of_steps_performed++;
}
void draw_8()
{
	//Draws Right Hand
	int y=220,x=75,d=10;
	for(x=400;x<=450;x++,y++)
	{
		putpixel(x,y,WHITE);
		putpixel(x+1,y,WHITE);
		putpixel(x-1,y,WHITE);
		delay(d);
	}
	no_of_steps_performed++;
}