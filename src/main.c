#include "main.h"

int main(int argc, char *argv[]) {
    if(argc == 1)
        return 1;

    printf("Reading file \"%s\"\n", argv[1]);
    dynArray head = fileCRCTable(argv[1]);

    printf("Replaying crc table\n");
    unsigned long i;
    for(i = 0; i < dynA_size(head); i++) {
        tableNode tn = dynA_get(head, i);
        printf("Chunk: %lu Size: %d CRC: %lu\n", tn->chunk, tn->bytesLong, tn->crc);
    }

    printf("Validating file...\n");
    dynArray unvalid = validateFile(argv[1], head);
    if(unvalid == NULL) {
        printf("File valid!\n");
    } else {
        for(i = 0; i < dynA_size(unvalid); i++) {
            tableNode tn = dynA_get(unvalid, i);
            printf("Chunk: %lu Size: %d CRC: %lu\n", tn->chunk, tn->bytesLong, tn->crc);
        }
    }

    printf("Test done.\n");

    dynA_clear(head);
    return 0;
}























