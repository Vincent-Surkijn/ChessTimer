#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "main.h"

/*Global variables*/
int turn1 = true;  // Player 1 starts


int main(int argc, char *argv[]){
  pthread_t inputThread;

  int *totalTime = malloc(sizeof(int));
  int *time1 = malloc(sizeof(int));
  int *time2 = malloc(sizeof(int));

  if( argc == 2 ) {
     *totalTime = atoi(argv[1]);
     printf("The argument supplied is %d\n", *totalTime);
  }
  else if( argc > 2) {
     fprintf(stderr,"Error: Too many arguments supplied.\n");
     free(totalTime);
     return -1;
  }
  else if(argc <2) {
     fprintf(stderr,"Error: Not enough arguments supplied.\n");
     free(totalTime);
     return -1;
  }

  printf("This is a chess timer.\n");
  printf("Press any button to start.\n");

  *time1 = *totalTime;
  *time2 = *totalTime;

  if(pthread_create( &inputThread, NULL, &readInput, NULL ) != 0) printf("Can't create input thread\n");

  printTimer(time1,time2);

  while(*time1>0 && *time2>0){
     if(turn1){
	printf("turn1:%d\n",turn1);
        (*time1)--;
     }
     else{
	printf("turn2:%d\n",turn1);
        (*time2)--;
     }
     printTimer(time1,time2);
     sleep(1);
  }


  if(pthread_join(inputThread, NULL) !=0) printf("can't join input thread\n\n");

  free(totalTime);
  free(time1);
  free(time2);

  return 0;
}

void printTimer(int *time1, int *time2){
  printf("   Player 1	--------------       Player 2	\n");
  printf("	%d	--------------		%d	\n",*time1,*time2);
}

void *readInput(){
  while(true){
     char *s = malloc(10);
     scanf("%s",s);
     printf("input: %s\n",s);
     turn1 = turn1 == false ? true : false;
  }
}
