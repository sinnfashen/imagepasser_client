//
// Created by 54926 on 2017/1/24.
//
#include <cstdio>
#include <fstream>
#include <winsock2.h>

int main()
{
    WSADATA wsaData;
    WSAStartup(0x202,&wsaData);

    SOCKET mysocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(23213);
    serveraddr.sin_addr = inet_addr("127.0.0.1");
    memset(serveraddr.sin_zero, 0x00, 8);

    connect(mysocket, (struct sockaddr*)&serveraddr, sizeof(serveraddr));

    std::ifstream inf("", std::ios::binary);
    char buffer[256];
    while(!inf.eof())
    {
        inf.read(buffer, 256);
        send(mysocket,buffer,256,0);
    }

    closesocket(mysocket);
    WSACleanup();

    return 0;
}