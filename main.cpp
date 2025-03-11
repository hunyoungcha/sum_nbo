#include <stdio.h>
#include <stdint.h>

#define MAX_READ_SIZE 5
#define BYTE_SIZE 4
#define ERROR_CODE -1

uint32_t GetNumFromFile(char* fileName) {
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


    uint32_t value = (buf[0] << 24) | (buf[1] << 16) | (buf[2] << 8) | buf[3];
    return value;
}



int main(int argc, char *argv[]) {
    uint32_t result = 0;
	for (int i = 1; i < argc; i++) {
        uint32_t tmp = GetNumFromFile(argv[i]);   
		if (tmp == ERROR_CODE){
			printf("Wrong\n");
			return 0;
		}
		result += tmp;
    }
	printf("%u",result);

    return 0;
}