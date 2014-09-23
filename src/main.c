#include "main.h"

int main(int argc, char *argv[]) {
    char* fileName = NULL, *crcSaveFile = NULL, *loadFile = NULL;
    int validate = 0;
    int crcCheck = 0;
    int serverMode = 0;
    int opt;
    while((opt = getopt(argc, argv, "hcVf:s:l:S")) != -1) {
        switch(opt) {
        case 'h':
            printHelp(argv[0]);
            exit(0);
            break;
        case 'f':
            fileName = optarg;
            break;
        case 's':
            crcSaveFile = optarg;
            break;
        case 'l':
            loadFile = optarg;
            break;
        case 'V':
            validate = 1;
            break;
        case 'c':
            crcCheck = 1;
            break;
        case 'S':
            serverMode = 1;
            break;
        }
    }

    if(serverMode) {
        printf("Starting server mode.\n");
        fflush(stdout);
        netSrv srv = nets_setupListen();
        printf("Bind socket.");
        fflush(stdout);
        nets_bindSocket(srv);
        printf("Listen for new com\n");
        fflush(stdout);
        int soc = nets_listenForNew(srv);
        int buffsize = 65355;
        int read;
        char* buff = malloc(buffsize*sizeof(char));
        printf("Read inc traffic or something.\n");
        fflush(stdout);
        while((read = nets_rec(soc, buff, buffsize)) > 0) {
            printf("%s\n", buff);
        }
        printf("Quitting!\n");
        fflush(stdout);
        free(buff);
        nets_close(srv);
    }

    return 0;
}

void printHelp(char* progName) {
    printf("%s [options]\n", progName);
    char* helpString = "\
    -h        | Print help and quit\n\
    -f <file> | File to read?\n\
    -s <file> | Save crc to this file.\n\
    -l <file> | Load crc from file\n\
    -V        | Validate the file\n\
    -c        | run crc check on file\n";
    printf("%s", helpString);
}























