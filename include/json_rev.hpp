#ifndef JSON_REV
#define JSON_REV

#include <iostream>
#include <vector>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <string>
#include <jsoncpp/json/json.h>
#include <sstream>


class JsonRev
{
public:
    JsonRev(uint16_t p);
    int init();
    Json::Value run();
    ~JsonRev();
private:
    uint16_t port;
    int serverSock, newSocket;
    struct sockaddr_in serverAddr;
    struct sockaddr_storage serverStorage;
    socklen_t addr_size;
};

JsonRev::JsonRev(uint16_t p) 
{
    port = p;
}

int JsonRev::init()
{
    // 创建 TCP 套接字
    serverSock = socket(AF_INET, SOCK_STREAM, 0);

    // 设置服务器地址
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // 绑定套接字
    bind(serverSock, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
    // 监听传入的连接
    if (listen(serverSock, 10) == 0) {
        std::cout << "Listening for incoming connections..." << '\n';
    } else {
        std::cout << "Failed to listen" << '\n';
        return -1;
    }
    // 等待客户端连接
    addr_size = sizeof(serverStorage);
    newSocket = accept(serverSock, (struct sockaddr *) &serverStorage, &addr_size);
    std::cout << "Client connected" << '\n';
    return 0;
}

Json::Value JsonRev::run()
{
    uint32_t len;
    int ret = 0;
    std::vector<char> head(8);
    for (int i = 0; i < 8; ++i) {
        char s;
        ret = recv(newSocket, &s, 1, 0);
        if (ret <= 0) {
            std::cout << "rev head failed\n";
        }
        head[i] = s;
    }
    std::cout << "rev head successfully\n";
    len = (static_cast<uint16_t>(head[7]) << 24) | (static_cast<uint16_t>(head[6]) << 16) | (static_cast<uint16_t>(head[5]) << 8) | static_cast<uint16_t>(head[4]);
    char buffer[len];
    std::cout << "rev len: " << len << '\n';
    for (int i = 0; i < len; ++i) {
        char s;
        ret = recv(newSocket, &s, 1, 0);
        if (ret <= 0) {
            std::cout << "rev content failed\n";
        }
        buffer[i] = s;
    }
    std::string revJsonStr(len, '0');
    for (int i = 0; i < len; ++i) {
        revJsonStr[i] = buffer[i];
    }
    std::cout << revJsonStr << '\n';
    Json::Value msg;
    Json::CharReaderBuilder readerBuilder;
    std::istringstream iss(revJsonStr);
    std::string parse_errors;

    if (!Json::parseFromStream(readerBuilder, iss, &msg, &parse_errors)) {
        std::cerr << "Failed to parse JSON: " << parse_errors << std::endl;
        return -1;
    }
    return msg;

}

JsonRev::~JsonRev()
{
    close(newSocket);
    close(serverSock);
}

#endif