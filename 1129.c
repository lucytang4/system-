#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>

int main(){
  int sd;
  int *a;
  int status;
  int tmp = 2;

  sd = shmget(24601,4,IPC_CREAT|0644);
  printf("PARENT sd: %d\n",sd);
  
  int pid = fork();
  if (pid==0){
    a = shmat(sd,0,0);
    *a = -362;
    //tmp = 5;
    printf("CHILD: %p\n",a);
    printf("CHILD: %d\n",*a);
    //printf("tmp : %d\n",tmp);    
  }
  else{
    wait(&status);
    a = shmat(sd,0,0);
    printf("PARENT: %p\n",a);
    printf("PARENT: %d\n",*a);
    //printf("tmp : %d\n",tmp);
  }
  
  return 0;
}
