#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

class UdpServer {
private:
    int port;
    int serverSock;
    int messageSize;
    struct sockaddr_in serverAddr, clientAddr;

public:
    UdpServer(int port);
    ~UdpServer();
    void init();
    void recvMessage();
};