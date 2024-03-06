#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void simple(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}

void bubble(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++)        
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

void insertion(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

double timer(int arr[], int n, void (*func)(int*, int)) {
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    func(arr, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

void fillArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }
}

int main() {
    int arr[SIZE];
    double simple_time, bubble_time, insertion_time, best_time;
    srand(time(0)); // инициализация

    fillArray(arr, SIZE);
    simple_time = timer(arr, SIZE, simple);
    printf("Simple sort took %f seconds.\n", simple_time);

    fillArray(arr, SIZE);
    bubble_time = timer(arr, SIZE, bubble);
    printf("Bubble sort took %f seconds.\n", bubble_time);

    fillArray(arr, SIZE);
    insertion_time = timer(arr, SIZE, insertion);
    printf("Insertion sort took %f seconds.\n", insertion_time);

    best_time = simple_time < bubble_time ? (simple_time < insertion_time ? simple_time : insertion_time) : (bubble_time < insertion_time ? bubble_time : insertion_time);
    printf("Best time: %f seconds.\n", best_time);

    return 0;
}