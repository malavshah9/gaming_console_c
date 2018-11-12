#include <unistd.h>
#include<stdlib.h>
#include<stdio.h>
int main() {
	for(int i = 0; i<10; i++){
		sleep(1);
		system("clear");
		printf("%d\n",i);
		fflush(stdout);
	}
}