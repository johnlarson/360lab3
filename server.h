#ifndef SERVER_H
#define SERVER_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <dirent.h>
#include <string>
#include <iostream>
#include <sstream>
#include "utils.h"

using namespace std;

void runServer(int port, int numThreads, string dir);

#endif

