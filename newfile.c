#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <fcntl.h>
#include <string.h>

//create new file, give read and write permissions to each permission area
//run ls -l to check permissions

int main(){
  file = open("file2",O_CREAT,0666);
  close(file);
  
  return 0;
}
