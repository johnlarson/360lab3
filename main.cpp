#include <sys/stat.h>
#include <string>
#include "utils.h"
#include "server.h"

using namespace std;

#define ERROR -1

int main(int argc, char** argv) {
        if(argc != 4) {
                errorOut("Usage: server port num-threads directory");
        }
        int port = atoi(argv[1]);
        if(port < 1) {
                errorOut("The port must be an integer greater than zero");
        }
	int threads = atoi(argv[2]);
	if(threads < 1) {
		errorOut("The number of threads must be an integer greater than zero");
	}
        string directory = string(argv[3]);
        struct stat filestat; 
        if(stat(directory, filestat) == ERROR) {
                errorOut("Couldn't find the given directory");
        }           
        if(S_ISREG(filestat.st_mode)) {
                errorOut("The given directory is actually a regular file");
        }           
        runServer(port, threads, directory);
}

