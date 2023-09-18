#include <iostream>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#define Port 5001
#define IPaddr "127.0.0.1"
std::string name;

class Client
{
    private:
        int sock=0,valread;
        struct sockaddr_in serv_addr;
        char buffer[100]={0};
    public:
        void validateSocket();
        void setIP();
        void validateConnection();
        void sendMsg();
        void recvMsg();
        void errorHandling(const std::string errorMessage);
};
