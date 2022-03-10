#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"

int main(int argc, char *argv[]){
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

  printTimer(time1,time2);

  while(*time1>0 && time2>0){
     (*time1)--;
     (*time2)--;
     printTimer(time1,time2);
     sleep(1);
  }

  free(totalTime);
  free(time1);
  free(time2);

  return 0;
}

void printTimer(int *time1, int *time2){
     printf("time1 argument supplied is %d\n", *time1);
     printf("time2 argument supplied is %d\n", *time2);


  printf("   Player 2	--------------       Player 1	\n");
  printf("	%d	--------------		%d	\n",*time1,*time2);

}
