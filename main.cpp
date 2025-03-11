#include <stdio.h>
#include <stdint.h>

#define MAX_READ_SIZE 5
#define BYTE_SIZE 4
#define ERROR_CODE -1

int GetNumFromFile(char* fileName) {
    FILE *fp;
    uint8_t buf[MAX_READ_SIZE];

    if (!(fp = fopen(fileName, "rb"))) {
        return ERROR_CODE;
    }

    size_t bytesRead = fread(buf, 1, MAX_READ_SIZE, fp);
    fclose(fp);

    if (bytesRead != BYTE_SIZE) {
        return ERROR_CODE;
    }

    int value = (buf[0] << 24) | (buf[1] << 16) | (buf[2] << 8) | buf[3];
	printf("%d\n", value);
    return value;
}



int main(int argc, char *argv[]) {
    int result = 0;
	for (int i = 1; i < argc; i++) {
        result += GetNumFromFile(argv[i]);   
    }
	printf("%d",result);

    return 0;
}