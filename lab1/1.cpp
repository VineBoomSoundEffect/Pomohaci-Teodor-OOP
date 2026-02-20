#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f = fopen("in.txt", "rb+");
    char *input;
    fseek(f, 0, SEEK_END);
    int input_len = ftell(f);
    fseek(f, 0, SEEK_SET);
    input = (char *)malloc(input_len+1 * sizeof(char));
    fread(input, sizeof(char), input_len, f);
    input[input_len] = '\0'; // De orice eventualitate
    printf("%s\n", input);
    int sum = 0;
    int digit;
    int number;
    for(int i=0;i<input_len;i++) {
        if(input[i] >= '0' && input[i] <= '9') {
            number = 0;
            while(input[i] >= '0' && input[i] <= '9' && i<input_len) {
                digit = input[i] - '0';
                number = (number*10)+digit;
                i++;
            }
            sum += number;
        }
    }
    printf("sum is %d", sum);
    return 0;
}
