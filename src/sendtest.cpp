#include "json_send.hpp"
#include "info_rev.hpp"
struct reply{
    char c[3];
};

int main()
{   
    const char *ip = "127.0.0.1";
    JsonSend JS(ip, 12345);           // 数据发送对象
    JS.init();
    Json::Value root;

    InfoRev<reply> IR(12346);          // 回复发送对象
    IR.init();
    reply r;


    root["name"] = "John Doe";
    root["age"] = 30;
    root["city"] = "New York";
    int count = 0;
    while (1) {
        if (JS.sendMsg(root) != 0) {        // 发送数据
            std::cout << "send failed\n";
        }
        r = IR.run();                   // 接收回复
        if (r.c[0] != 'O' || r.c[1] != 'K') {
            std::cout << "rev replt failed\n";
        }
        usleep(20000);  
        ++count;
        std::cout << "**************count:" << count << '\n'; 

    }
}