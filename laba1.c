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
    

int main(){
    float L;
    float t1;
    float t2;
    float v;
    if (setjmp(jumpBuffer) == 0) {
        L = checkInputError("L: ");
        t1 = checkInputError("t1 in minutes: ");
        t2 = checkInputError("t2 in minutes: ");
        if (t2 <= t1) {
            printf("Input error!\n");
            longjmp(jumpBuffer, 1);
        }
        t1 = t1 / 60.0; // время вводится в минутах, переводим в часы
        t2 = t2 / 60.0; 
        v = (L / t1 - L / t2) / 2;
        printf("River speed: %.2f km/h\n", v);
    } else {
        printf("Try again\n");
    }
    return 0;
}