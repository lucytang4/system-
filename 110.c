#include <stdio.h>
#include <stdlib.h>

int main(){
  //server side
  int sd;
  int connection;
  char buffer[200];
  sd = socket(AF_INET,SOCK_STREAM,0);
  struct sockaddr_in sock;
  sock.sin_family = AF_INET;
  sock.sin_addr.s_addr = INADDR_ANY;
  sock.sin_port = htons(9001);
  bind(sd,(struct sockaddr *)&sock,sizeof(sock));
  listen(sd,1);
  struct sockaddr_in sock1;
  unsigned int socklen = sizeof(sock1);
  connection = accept(sd,(struct sockaddr *)&sock1,&socklen);
  read(connection,buffer,sizeof(buffer));
  printf("server got: <%s>\n",buffer);
  
  //create another main file for client side
  /*
int sd;
char *host = "127.0.0.1";
  sd = socket(AF_INET,SOCK_STREAM,0);
  struct sockaddr_in sock;
  sock.sin_family = AF_INET;
  inet_aton(host,&(sock.sin_addr));
  sock.sin_port = htons(9001);
bind(sd,(struct sockaddr *)&sock,sizeof(sock));
connect(sd,(struct sockaddr *)&sock,sizeof(sock));
write(sd,"hello",6);
   */
  
  return 0;
}
