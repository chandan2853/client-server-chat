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


class Server
{
    private:
        int sock,newsock;
        socklen_t clientAddrLen;
        char buffer[256];
        struct sockaddr_in serverAddr, clientAddr;
        int n,pid;
    public:
        void validateSocket();
        void setIP();
        void validateBind();
        void createChildProcess();
        void messageOperations(int sock);
        void errorHandling(const std::string errorMessage);

};