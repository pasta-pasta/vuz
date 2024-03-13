#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
// В символьной строке удалить все слова, которые содержат буквы, не
// входящие в разрешенный набор символов.


char* readLine(void) { // ДИНАМИЧЕСКИЕ МАССИВЫ НЕ ЗАВЕЗЛИ, ПРИШЛОСЬ ПИСАТЬ СВОИ
    int bufferSize = 10; 
    char *buffer = malloc(bufferSize * sizeof(char));
    if (buffer == NULL) {
        return NULL;
    }

    char c; 
    int length = 0; 

    while ((c = getchar()) != '\n' && c != EOF) {
        buffer[length] = c;
        length++;

        if (length == bufferSize) {
            bufferSize += 10; 
            char *newBuffer = realloc(buffer, bufferSize * sizeof(char));
            if (newBuffer == NULL) {
                free(buffer);
                return NULL;
            }
            buffer = newBuffer;
        }
    }

    buffer[length] = '\0'; 
    return buffer; 
}

int contains(char not_allowed[], char c){
    for(int i = 0; i < 100; i++){
        if(not_allowed[i] == c){
            return 1;
        }
    }
    return 0;
}

int main(){
    char c;
    int flag = 0;
    char not_allowed[32];
    printf("Enter not allowed characters: ");
    fgets(not_allowed, 32, stdin);
    fflush(stdin);
    char *line = readLine();
    if (line == NULL) {
        printf("Memory allocation error\n");
        return -1;
    }

    char **words = malloc(100 * sizeof(char*)); 
    if (words == NULL) {
        printf("Memory allocation error\n");
        return -1;
    }
    
    char *wordBuffer = malloc(101 * sizeof(char));
    int j = 0;
    int k = 0;
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == ' ' || line[i] == '\0') {
            if (k > 0) { 
                wordBuffer[k] = '\0'; 
                words[j] = strdup(wordBuffer); 
                j++;
                k = 0; 
            }
        } else {
            wordBuffer[k++] = line[i]; 
        }
    }
    if (k > 0) { // Добавляем последнее слово, если оно есть
        wordBuffer[k] = '\0';
        words[j] = strdup(wordBuffer);
        j++;
    }

    free(wordBuffer);
    free(line);

    for (int i = 0; i < j; i++) {
        int cnt = 0;
        char *word = malloc(100 * sizeof(char)); 
        memset(word, 0, 100 * sizeof(char)); 
        bool containsNotAllowed = false; 

        for (int k = 0; words[i][k] != '\0'; k++) {
            if (contains(not_allowed, words[i][k])) {
                containsNotAllowed = true; 
                break; 
            } else {
                word[cnt++] = words[i][k]; 
            }
        }
        
        if (!containsNotAllowed) {
            printf("%s ", word); 
        }

        free(word); 
    }

    for (int i = 0; i < j; i++) {
        free(words[i]);
    }
    return 0;
}