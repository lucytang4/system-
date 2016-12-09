#include <stdio.h>
#include <stdlib.h>

void print(){
  printf("hey\n");
}

int strSize(char a[]){
  int ctr = 0;
  while (a[ctr] != 0)
    ctr++;
  return ctr;
}

int main(){
  int a = 5;
  /*int b[4];
  int sizea = sizeof(a);
  int sizeb = sizeof(b);
  printf("a = %d\n", sizea);
  printf("b = %d\n", sizeb);
  */
  //print();
  /* char arr[10]; */
  /* char s[] = "Tuesday"; */
  /* arr[0] = 5; */
  /* arr[1] = 0; */
  /* printf("arr = %s\n", arr); */
  /* printf("strSize = %d\n", strSize(s)); //7 */
  /* printf("strSize = %d\n", strSize(arr)); //1 */

  printf("a>>1 = %d\n", a>>1);
  printf("a<<1 = %d\n", a<<1);
  
  return 0;
}
