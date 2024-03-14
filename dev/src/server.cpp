#include <iostream>
#include <server.h>

void ErrorHandling(std::string msg) {
    std::cout << msg;
    exit(1);
}

UdpServer::UdpServer(int port) {
    memset(&serverAddr, 0, sizeof(serverAddr));
    memset(&clientAddr, 0, sizeof(clientAddr));
    this->port = port;
}

UdpServer::~UdpServer() {
    close(serverSock);
}

/*
    * initialize socket information
*/
void UdpServer::init() {
    serverSock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (serverSock == -1)
        ErrorHandling("udp socket create failed.");
    
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(port);

    if (bind(serverSock, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1)
        ErrorHandling("udp socket bind failed.");
}

void UdpServer::recvMessage() {
    char buff[1024];
    socklen_t recvLen;

    recvLen = sizeof(clientAddr);
    messageSize = recvfrom(serverSock, buff, sizeof(buff), 0,
                    (struct sockaddr*)&clientAddr, &recvLen);

    if (messageSize == -1){
        std::cout << "recive Failed.";
    }

    switch(messageSize){
        case -1:
            std::cout << "recieve Failed.";
            close(serverSock);
            exit(1);
            break;
        
        case 0:
            break;
        
        default:
            buff[messageSize] = '\0';
            std::cout << buff << "\n";
    }
}