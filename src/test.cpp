#include <iostream>
#include <jsoncpp/json/json.h>
#include <string>
#include <sstream>
int main()
{
    Json::Value root;
    root["name"] = "John Doe";
    root["age"] = 30;
    root["city"] = "New York";
    Json::StreamWriterBuilder builder;
    std::string json_str = Json::writeString(builder, root);

    std::cout << json_str << '\n';
    std::vector<char> buffer(json_str.size());
    for (int i = 0; i < buffer.size(); ++i) {
        buffer[i] = json_str[i];
    }
    // buffer.push_back('\0');

    std::string received_json_str(buffer.size(), '0');
    // std::string received_json_str = json_str;
    for (int i = 0; i < buffer.size(); ++i) {
        received_json_str[i] = buffer[i];
    }
    std::cout << received_json_str << '\n';
    Json::Value received_root;
    Json::CharReaderBuilder reader_builder;
    std::istringstream iss(received_json_str);
    std::string parse_errors;

    if (!Json::parseFromStream(reader_builder, iss, &received_root, &parse_errors)) {
        std::cerr << "Failed to parse JSON: " << parse_errors << std::endl;
        return -1;
    }

    std::string name = received_root["name"].asString();
    int age = received_root["age"].asInt();
    std::string city = received_root["city"].asString();

    std::cout << "Name: " << name << ", Age: " << age << ", City: " << city << std::endl;


}