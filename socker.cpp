#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
using namespace std;
int main()
{
  struct sockaddr_in sa;
  inet_pton(AF_INET,"192.0.2.1",&(sa.sin_addr));
  
}
