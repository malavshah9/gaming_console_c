#include<stdio.h>
//#include<conio.h>
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
void draw_header();
void game_over(char *);
void game_won(char *);
void draw_animation();
void draw_lines_for_no_of_words(int length);
void start_game();
void get_word(char *word);
int search_char(char *string,char input);
int no_of_steps_performed=0;
char wrong_chars[25];
char wrong_chars_index=0;
struct matching_char_map
{
	int index;
	char ch;
};
struct matching_char_map arr[25];
int matching_arr_index=0;
	void main()
	{
	int gdriver = DETECT,gmode;
	time_t t;
	initgraph(&gdriver,&gmode,"C:\\TC\\BGI"); //Initialized Graphics Driver
	srand((unsigned) time(&t)); 		//Initialized Random Number
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
int search_char(char *string,char input){
	int i=0,j=0;
	int f=0;
	int contained_in_arr=0;
	for(i=0;i<strlen(string);i++){
		if(string[i]==input){
			for(j=0;j<matching_arr_index;j++){
				if(arr[j].index==i && arr[j].ch==input){
					contained_in_arr=1;
						}
			}
			if(!contained_in_arr){
				arr[matching_arr_index].ch=input;
				arr[matching_arr_index].index=i;
				matching_arr_index++;
				f=1;
			}
			else{
			contained_in_arr=0;
			}
		}
	}
	return f;
}
void draw_chars(){
   int i=0;
   int x=20;
   int diff=20;
   char *str;
   for(i=0;i<wrong_chars_index;i++)
   {
	str[0]=wrong_chars[i];
	str[1]='\0';
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	outtextxy(x,125,str);
	x=x+diff;
   }
}

void draw_right_chars(int length)
{
	int i=0,j=0;
	int x=0,y=20,text_x=0;
	int diff=20;
	int f=0;
	char *str;
	for(i=0;i<matching_arr_index;i++)
	{
		    str[0]=arr[i].ch;
		    str[1]='\0';
		    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
		    outtextxy(x,65,str);
		    x=x+diff;
	}
	while(j<length)
	{
		   settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
		    outtextxy(text_x,y,"__");
		    text_x=text_x+40;
		    for(i=0;i<matching_arr_index;i++)
		    {
				if(arr[i].index==j)
				{
					f=1;
					break;
				}
		    }
		    if(f==1)
		    {
			f=0;
			str[0]=arr[i].ch;
			str[1]='\0';
			outtextxy(text_x-40,y-10,str);
		    }
		    j++;
	}
}
void start_game()
{
		char *our_word;
		int len=0;
		char input;
		get_word(our_word);
		len=strlen(our_word);
//		printf("\n%s",our_word);
		draw_lines_for_no_of_words(len);
		draw_header();
		    settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
		    outtextxy(0,40,"Right");
			settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
		    outtextxy(0,100,"Wrong");
		while(matching_arr_index<len && no_of_steps_performed<8){
			input=getch();
			if(!search_char(our_word,input)){
				wrong_chars[wrong_chars_index]=input;
				wrong_chars_index++;
				draw_chars();
				draw_animation();
				draw_chars();
				   settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
				    outtextxy(0,40,"Right");
				settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
				    outtextxy(0,100,"Wrong");
				    draw_right_chars(len);
				    draw_header();
			}
			else{
				draw_right_chars(len);
			}
		}
		if(no_of_steps_performed<8){
			game_won(our_word);
		}else{
			game_over(our_word);
		}
}
void draw_lines_for_no_of_words(int length)
{
	int j=0;
	int x=0,y=20;
	while(j<length)
	{
		   settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
		    outtextxy(x,y,"__");
		    x=x+40;
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
  //		printf("GAME OVER");
	}
	else
	{
//		printf("GAME OVER");
	}
}
void draw_1()
{
	int i=0,j=250;
	int d=5;
	int gdriver = DETECT,gmode;
	initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
	//Verticle Line
	for(i=40;i<400;i++)
	{
		 putpixel(j,i,3);
		 putpixel(j+1,i,2);
		 putpixel(j+2,i,4);
		 putpixel(j-1,i,1);
		 putpixel(j-2,i,5);
		 delay(d);
	}
	//Horizontal Line
	for(i=250;i<400;i++)
	{
		putpixel(i,40,1);
		putpixel(i,40+1,2);
		putpixel(i,40+2,3);
		putpixel(i,38,4);
		putpixel(i,39,5);
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
void game_over(char *str){
			char *text="GAME OVER !!!";
			char *word="Right Word is ";
			settextstyle(10,HORIZ_DIR,3);
		    outtextxy(0,getmaxy()-120,text);
			strcat(word,str);
			settextstyle(10,HORIZ_DIR,3);
		    outtextxy(0,getmaxy()-60,word);
}
void game_won(char *str){
			char *text="YOU WON !!!";
			char *word="Right Word is ";
			settextstyle(10,HORIZ_DIR,3);
		    outtextxy(0,getmaxy()-120,text);
			strcat(word,str);
			settextstyle(10,HORIZ_DIR,3);
		    outtextxy(0,getmaxy()-60,word);
}
void draw_header(){
	settextstyle(10,VERT_DIR,6);
	outtextxy(getmaxx()-100,0,"HANGMAN");
}