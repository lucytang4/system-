#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
  int fds[2];
  char s[20];
  pipe(fds);
  int f = fork();
  if (f == 0){
    clse(fds[1]);
    printf("child listening\n");
    read(fds[0],s,sizeof(s));
    printf("[child] recieved: %s\n",s);
  }
  else{
    close(fds[0]);
    printf("parent sleeping\n");
    sleep(3);
    write(fds[1],"hello child",12);
  }
  return 0;
}
