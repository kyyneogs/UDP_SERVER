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
    recvLen = sizeof(clientAddr);

    if (bind(serverSock, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1)
        ErrorHandling("udp socket bind failed.");
}

void UdpServer::recvMessage(unsigned char* recvBuff) {
    int msgLen = recvfrom(serverSock, (char*)recvBuff, RECV_BUFF, 0,
                    (struct sockaddr*)&clientAddr, &recvLen);

    if (msgLen == -1) {
        std::cout << "recive Failed.";
        return;
    }
    recvBuff[msgLen] = '\0';
}