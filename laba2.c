#include<stdio.h>
#include <setjmp.h>

jmp_buf jumpBuffer;

float checkInputError(char input[]) { // ТРАЙ ЭКСЕПТ НЕ ЗАВЕЗЛИ, ПРИШЛОСЬ ПИСАТЬ СВОЙ
    float number;
    printf(input);
    if (scanf("%f", &number) != 1 || number < 0) {
        printf("Input error!\n");
        longjmp(jumpBuffer, 1); 
    }
    return number;
}

int main(args){
    float sum = 0;
    float top = 3;
    float bottom = 1;
    if (setjmp(jumpBuffer) == 0) {
        int n = checkInputError("n: ");
        for (int i = 0; i < n; i++) {
            float temp = top/bottom;
            if (i%2 == 0){
                sum += temp;
            } else {
                sum -= temp;
            }
            top += 1;
            bottom += 3;  
        }
    } else {
        printf("Try again\n");
        return -1;
    }
    printf("%f", sum);
    return 0;
}