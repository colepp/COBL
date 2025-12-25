#ifndef COBL_SEVER_H
#define COBL_SEVER_H

#define DEFUALT_PORT_NUMBER 8080


#if defined(_WIN32) || defined(_WIN64)
    #define OS_WINDOWS
    #include  <winsock2.h>
    #include <ws2tcpip.h>
    #include <psdk_inc/_wsadata.h>
    #pragma comment(lib, "ws2_32.lib")

    void init_server();
    void server_start();
    

#elif defined(__APPLE__) || defined(__MACH__)
    #define OS_MAC
    #include <netinet/in.h> //structure for storing address information
    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/socket.h> //for socket APIs
    #include <sys/types.h>
    void init_server();
#elif defined(__linux__)
    #define OS_LINUX
#else
    #define OS_UNKNOWN
#endif

#endif // OS_CHECK_H
