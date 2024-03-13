#include<stdio.h>

void main(){
    char c;
    int count = 0;
    int flag = 0;
    while((c = getchar()) != EOF){
        if(c == ' ' || c == '\n' || c == '\t'){
            flag = 0;
        }else if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            if(flag == 0){
                count++;
                flag = 1;
            }
        }
    }
    printf("N: %d\n", count);
}