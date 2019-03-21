#include "stdio.h"
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define MAX_N 1024
struct stat attributes;

int main(int argc, char const *argv[]) {

  char data[MAX_N];
  if(argc != 3){
    printf("Nope\n" );
    return 0;
  }
  printf("Three arguments are given\n" );


  printf("Opening files: \n" );
  int fd = open(argv[1],O_RDONLY);
  if(fd < 0){
    printf("\tfailure\n" );
    return 0;
  }
  printf("\tsuccces\n");


  printf("Reading File: \n");
  if(read(fd, data, sizeof(data)) < 0)
   printf("\tfailure\n");
  else
    printf("\tsucces\n" );


  int index = -1;
  while(data[++index] != '\0')
    printf("%c",data[index] );

  for (size_t i = index; i < MAX_N; i++) {
    data[i] = ' ';
  }

  printf("\nFinished writing content\n");

  int fd2 = open(argv[2],O_WRONLY);
  printf("Opening second File: \n" );
  if(fd2 < 0)
  {
    printf("File not found\n" );
    printf("Creating file now: \n" );
    fd2 = creat(argv[2], S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    fd2 = open(argv[2],O_WRONLY);
    printf("%d\n",fd2 );
  }
  else{
    printf("\tsucces\nWriting content of first in second\n" );
    if(write(fd2, data, sizeof(data))< 0)
      printf("\tfailure\n" );
    else
      printf("\tsucces\n" );
  }

  close(fd2);



  return 0;
}
