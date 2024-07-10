#include "json_rev.hpp"
#include "info_send.hpp"

struct reply{
    char c[3];
};
int main()
{
    JsonRev JR(12345);          // 接收数据对象，端口
    JR.init();
    const char *ip = "127.0.0.1";

    usleep(2000000);                  // 需要等待一小段时间，等待对方启动接收连接服务
    InfoSend<reply> IS(ip, 12346);  // 发送回复对象
    IS.init();
    int count = 0;
    reply r;                           // 回复对象
    r.c[0] = 'O';
    r.c[1] = 'K';

    Json::Value received_root;
    while (1) {
        received_root = JR.run();                    // 接收到数据
        if (IS.sendMsg(r) != 0) {           // 发送回复
            std::cout << "send rev failed\n";
        }
        ++count;
        std::string name = received_root["name"].asString();
        int age = received_root["age"].asInt();
        std::string city = received_root["city"].asString();

        std::cout << "Name: " << name << ", Age: " << age << ", City: " << city << std::endl;
        std::cout << "******************count:" << count << '\n';
    }
}