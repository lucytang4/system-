#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define READ 0
#define WRITE 1

int main(){
  int fds[2];
  char s[20];
  pipe(fds);
  int f = fork();
  if (f == 0){
    close(fds[WRITE]);
    printf("child listening\n");
    /*int x;
    read(fds[0],&x,sizeof(x));
    printf("[child] recieved: %s\n",x);*/
    read(fds[READ],s,sizeof(s));
    printf("[child] recieved: %s\n",s);
  }
  else{
    close(fds[READ]);
    printf("parent sleeping\n");
    sleep(3);
    /*int a = -793;
      write(fds[1],&a,sizeof(a));*/
    write(fds[WRITE],"hello there",12);
  }
  return 0;
}
