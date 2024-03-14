#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define RECV_BUFF 1024

class UdpServer {
private:
    int port;
    int serverSock;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t recvLen;

public:
    UdpServer(int port);
    ~UdpServer();
    void init();
    void recvMessage(unsigned char* recvBuff);
};