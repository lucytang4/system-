#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
  mkfifo("mario",0644);
  int fd;
  fd=open("mario",O_WRONLY);

  printf("opened fifo\n");
  write(fd,"hello mario\n",13);
  
  return 0;
}
