#include<stdio.h>

// В длинном целом числе N поменять местами нулевой разряд с первым
// разрядом, второй разряд с третьим разрядом и т.д.


long swapAdjacentDigits(long n) {
    long result = 0;
    long place = 1;
    
    while (n > 9) { 
        long digit1 = n % 10; // Последняя цифра
        n /= 10;
        long digit2 = n % 10; // Предпоследняя цифра
        n /= 10;
        

        result += place * (10 * digit1 + digit2);
        place *= 100;
    }
    
    if (n > 0) {
        result += place * n;
    }
    
    return result;
}

int main(){
    long n;
    printf("N: ");
    scanf("%ld", &n);
    
    long swapped = swapAdjacentDigits(n);
    printf("swapped: %ld\n", swapped);
    
    return 0;
}