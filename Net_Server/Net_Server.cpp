// Net_Server.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define _WINSOCK_DEPRECATED_NO_WARNINGS


#include <iostream>
#include <stdlib.h>
#include <string.h>


#include<winSock2.h>
#pragma comment(lib,"ws2_32.lib")

#define Buf_Size 1024
void Error(const char* msg);
void Log(const char* msg);

char strServerIP[] = "172.30.1.90";
char strPort[] = "12345";

void Server_Code();

int main()
{
    std::cout << "Server Start\n";
    Server_Code();
    return 0;
}

void Error(const char* msg)
{
    fputs(msg, stderr);
    fputc('\n', stderr);
    exit(1);
}

void Log(const char* msg)
{
    fputs(msg, stdout);
    fputc('\n', stdout);
}

void Server_Code()
{
    WSADATA wsaData;
    SOCKET serverSocket, clientSocket;
    char msg[Buf_Size];
    int strLength, i;

    SOCKADDR_IN serverAddr, clientAddr;
    int clientAddrSize;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
        Error("WSAStartup() Error");
    Log("WSAStartup() OK");

    serverSocket = socket(PF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET)
        Error("socket() error");
    Log("socket() OK");

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(atoi(strPort));

    if (bind(serverSocket, (SOCKADDR*)&serverAddr,
        sizeof(serverAddr)) == SOCKET_ERROR)
        Error("bind() Error");
    Log("bind() OK");

    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR)
        Error("listen() Error");
    Log("listen() OK");

    clientAddrSize = sizeof(clientAddr);
    for (int i = 0;i < SOMAXCONN;i++)
    {
        clientSocket = accept(serverSocket, (SOCKADDR*)&clientAddr, &clientAddrSize);
        Log("accept()....");
        if (clientSocket == SOCKET_ERROR)
            Error("accept() error");
        else
            printf("Connected client %d\n", i + 1);

        memset(msg, 0, sizeof(msg));

        while ((strLength =
            recv(clientSocket, msg, Buf_Size, 0)) != 0)
        {
            printf("%d client : %s", i + 1, msg);
            send(clientSocket, msg, strLength, 0);
            memset(msg, 0, sizeof(msg));
        }

        closesocket(clientSocket);
    }

    closesocket(serverSocket);
    WSACleanup();
    Log("Finish...");

}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
