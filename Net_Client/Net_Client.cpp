// Net_Client.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <string.h>


#include<winSock2.h>
#pragma comment(lib,"ws2_32.lib")

#define Buf_Size 1024

char strServerIP[] = "172.30.1.90";
char strPort[] = "12345";

void Client_Code();
void Error(const char* msg);
void Log(const char* msg);

int main()
{
    std::cout << "Client Start!\n";
    Client_Code();
}

void Client_Code()
{
    WSADATA wsaData;
    SOCKET serverSocket;
    char msg[Buf_Size];
    int strLength;
    SOCKADDR_IN serverAddr;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
        Error("WSAStartup() error");
    Log("Start....");

    serverSocket = socket(PF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET)
        Error("socket() error");
    Log("socket() OK");

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.S_un.S_addr = inet_addr(strServerIP);
    serverAddr.sin_port = htons(atoi(strPort));

    if (connect(serverSocket, (SOCKADDR*)&serverAddr,
        sizeof(serverAddr)) == SOCKET_ERROR)
        Error("connected() error");
    Log("Connected....");

    while (1)
    {
        fputs("Input Message(Q to quit) :", stdout);
        fgets(msg, Buf_Size, stdin);
        if (!strcmp(msg, "q\n") || !strcmp(msg, "Q\n"))
            break;
        send(serverSocket, msg, strlen(msg), 0);
        strLength = recv(serverSocket, msg, Buf_Size - 1, 0);
        msg[strLength] = 0;
        printf("Message from Server : %s\n", msg);
    }
    closesocket(serverSocket);
    WSACleanup();
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

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
