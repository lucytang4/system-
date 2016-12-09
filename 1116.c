#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

//int execlp(const char *file, const char *arg,...);

int main(){
  execlp("ls","ls",(char*)NULL);
  return 0;
}
