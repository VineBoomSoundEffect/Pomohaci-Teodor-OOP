#include <stdio.h>
#include <stdlib.h>

int split(char **words, char *input){
    int words_index = 0;
    int word_start = 0;
    for(int i=0;;i++) {
        if(input[i] == ' ' || input[i] == '\0') {
            words[words_index] = (char *)malloc((i-word_start+1) * sizeof(char));
            for(int j=0;j<i-word_start;j++) {
                words[words_index][j] = input[word_start+j];
                words[words_index][i-word_start] = '\0';
            }
            words_index++;
            word_start = i+1;
            if(input[i] == '\0') break;
        }
    }
    return words_index;
};

int wordLen(char *input) {
    int count = 0;
    for(int i=0;input[i] != '\0';i++) count++;
    return count;
}

void sort(char **words, int nr_words) {
    int max;
    char *aux;
    for(int i=0;i<nr_words-1;i++) {
        max = i;
        for(int j=i+1;j<nr_words;j++) {
            if(wordLen(words[max]) < wordLen(words[j])) max = j;
            else if(wordLen(words[max]) == wordLen(words[j])) {
                int letter = 0;
                while(words[max][letter] == words[j][letter] && words[max][letter] != '\0') letter++;
                if(words[max][letter] < words[j][letter]) max = j;
            }
        }
        if(max != i) {
            aux = words[i];
            words[i] = words[max];
            words[max] = aux;
        }
    }
}

int main() {
    char *input = (char *)malloc(100 * sizeof(char));
    char **words = (char **)malloc(20 * sizeof(char *));
    scanf("%[^\n]", input);
    int nr_words = split(words, input);
    for(int i=0;i<nr_words;i++){
        printf("%s: %d\n", words[i], wordLen(words[i]));
    }
    printf("\n");
    sort(words, nr_words);
    for(int i=0;i<nr_words;i++){
        printf("%s: %d\n", words[i], wordLen(words[i]));
    }
    return 0;
}
