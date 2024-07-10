#ifndef INFO_SEND
#define INFO_SEND

#include <iostream>
#include <dirent.h>
#include <vector>
#include <algorithm>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <string>



template <typename T>
class InfoSend {           // 发送类
public:
    InfoSend(const char* IP, uint16_t p);
    int init();
    int sendMsg(T &msg);
    ~InfoSend();
private:
    int sock;
    struct sockaddr_in serverAddr;
    const char* serverIP;
    uint16_t port;
};

template <typename T>
InfoSend<T>::InfoSend(const char *IP, uint16_t p) : serverIP(IP)
{
    port = p;
}

template <typename T>
int InfoSend<T>::init()
{
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        std::cout << "sock failded\n";
    }
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    if (inet_pton(AF_INET, serverIP, &serverAddr.sin_addr) <= 0) {
        std::cout << "Error: inet_pton failed.\n";
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {
        std::cout << "Error: Connection failed.\n";
        close(sock);
        return 1;
    }
    return 0;
}

template <typename T>
int InfoSend<T>::sendMsg(T &msg)
{
    uint32_t len = sizeof(msg);
    char buf[len];
    memcpy(buf, &msg, len);
    std::vector<char> buffer(len + 8);
    buffer[0] = 'B';
    buffer[1] = 'F';
    buffer[2] = 'B';
    buffer[3] = 'F';
    buffer[4] = static_cast<unsigned char>((len) & 0xFF);
    buffer[5] = static_cast<unsigned char>((len >> 8) & 0xFF);
    buffer[6] = static_cast<unsigned char>((len >> 16) & 0xFF);
    buffer[7] = static_cast<unsigned char>((len >> 24) & 0xFF);
    std::cout << "send len: " << len << '\n';
    for (int i = 0; i < len; ++i) {
        buffer[i + 8] = buf[i];
    }

    if (send(sock, buffer.data(), buffer.size(), 0) == -1) {
        std::cout << "Error: Failed to send image data.\n";
        return -1;
    }
    return 0;
}

template <typename T>
InfoSend<T>::~InfoSend()
{
    close(this->sock);
}


#endif