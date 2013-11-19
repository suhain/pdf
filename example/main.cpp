#include <iostream>
#include <fstream>
#include <string>

#include <StreamReader.h>

int main () {
    pdf::reader r("/home/hus/cpp/files/simple/Hello.pdf", 1024);
    while(r())
    {
        for (size_t i = 0; i != r.length(); i++) 
        {
//            std::cout << std::hex << int(r[i]) << " ";
//            std::cout << char(r[i]);
        }
    }
    return 0;
}
