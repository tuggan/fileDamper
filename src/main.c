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

    if(crcCheck) {
        if(!fileName) {
            printf("No file specified!\n");
            printHelp(argv[0]);
            exit(1);
        }
        dynArray a = fileCRCTable(fileName);
        if(a == NULL) {
            printf("File could not be read!\n");
            exit(1);
        }
        if(dynA_isEmpty(a)) {
            printf("Something wierd happend :s\n");
            exit(1);
        }
        printf("Index\t\tCRC\n");
        unsigned long i;
        for(i = 0; i < dynA_size(a); i++) {
            struct crcHeader *h = (struct crcHeader*)dynA_get(a, i);
            printf("%lu\t\t%lu\n", h->chunk, h->crc);
        }
        dynA_clear(a);
    }

    if(serverMode) {
        printf("Starting server mode.\n");
        fflush(stdout);
        netSrv srv = nets_setupListen();
        printf("Bind socket.\n");
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
            buff[read] = '\0';
            printf("%s\n", buff);
            buff[0] = '\0';
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
    -c        | Run crc check on file\n";
    printf("%s", helpString);
}























