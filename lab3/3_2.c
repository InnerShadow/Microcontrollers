#include <stdio.h>

void decodeManchester2(const char* filename, int groupNumber) {
    FILE *file = fopen(filename, "r");
		char buffer[17];

    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    printf("Decoding messages from %s (Group %d):\n", filename, groupNumber);

    while (fscanf(file, "%16s", buffer) == 1) {
        printf("Decoded Message: %s\n", buffer);
    }

    fclose(file);
}

int main() {
    int groupNumber = 123; 
    decodeManchester2("Man300.ds", groupNumber);

    decodeManchester2("Man400.ds", groupNumber);

    while(true){}
}
