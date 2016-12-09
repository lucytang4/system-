#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
  char a[] = "hell";
  char b[] = "hell";
  char c[] = "help";
  char d[] = "had";
  printf("compare a and b: %d\n", strcmp(a,b)); //0
  printf("compare a and c: %d\n", strcmp(a,c)); //<0
  printf("compare a and d: %d\n", strcmp(a,d)); //>0
  printf("compare a and c for first 2 chars: %d\n", strncmp(a,c,2)); //0
  printf("compare a and d for first 3 chars: %d\n", strncmp(a,d,3)); //>0
  return 0;
}
