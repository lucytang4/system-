#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>


/*
semaphore control program
determined by command line argument
-create a semaphore and set an initial value
-view the current value
-remove the semaphore
*/
/*union semun{
  int val;
  struct semid_ds *buf;
  unsigned short *array;
  struct seminfor *_buf;
};
int main(int argc, char *argv[]){
  int semid;
  int key = ftok("makefile" , 22);
  int sc;
  if (strncmp(argv[1], "-c", strlen(argv[1])) == 0){
    semid = semget(key, 1, IPC_CREAT | IPC_EXCL| 0644);
    if (semid >= 0){
      printf("semaphore created %d\n", semid);
      union semun su;
      su.val = 1;
      //setting semaphore value
      sc = semctl(semid, 0, SETVAL, su);
      printf("value set: %d\n", sc);
    }
    else{
      printf("semaphore already created\n");
    }
  }
  else if (strncmp(argv[1], "-v", strlen(argv[1])) == 0){
    semid = semget(key, 1, 0);
    //getting the value of a semaphore
    sc = semctl(semid, 0, GETVAL);
    printf("semaphore value: %d\n",sc);
  }
  else if(strncmp(argv[1], "-r", strlen(argv[1])) == 0){
    semid = semget(key, 1, 0);
    //removing a semaphore
    sc = semctl(semid, 0, IPC_RMID);
    printf("semaphore removed: %d\n", sc);
  }
  return 0;

}
*/

int main(){
  srand(time(NULL));
  int x = random( )% 10;

  int semid = semget(ftok("makefile",22),1,0);
  printf("[%d] Before access %dn",getpid(),x);

  struct sembuf sb;
  sb.sem_num = 0;
  sb.sem_flg = SEM_UNDO;
  sb.sem_op = -1;

  semop(semid,&sb,1);
  printf("[%d] I'm in!\n",getpid());

  sleep(x);

  sb.sem_op = 1;
  semop(semid, &sb,1);

  printf("[%d] I'm done!\n",getpid());
  return 0;
}
