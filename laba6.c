#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>

#define WALL 1
#define FREE 0
#define START 2
#define END 3
//Задать лабиринт в виде двумерного целочисленного массива размера N на K,
// где, например, стены определяются единицами, а проходы - нулями.
// Программа должна находить выход из заданной точки лабиринта любым
// способом. Вариант отображения маршрута выбирается студентом по
// желанию.

int** parseLabyrinth(int n, int k){
    int** labyrinth = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++){
        labyrinth[i] = (int*)malloc(k * sizeof(int));
        for (int j = 0; j < k; j++){
            scanf("%d", &labyrinth[i][j]);
        }
    }
    return labyrinth;
}

bool makeRoute(int** labyrinth, int n, int k, int x, int y, int** visited) { // вспомогательная функция, поиск в глубину

    if(x < 0 || x >= n || y < 0 || y >= k || labyrinth[x][y] == WALL || visited[x][y]) {
        return false;
    }

    visited[x][y] = 1;

    if(labyrinth[x][y] == END) {
        return true;
    }

    if(makeRoute(labyrinth, n, k, x+1, y, visited) || 
        makeRoute(labyrinth, n, k, x-1, y, visited) || 
        makeRoute(labyrinth, n, k, x, y+1, visited) || 
        makeRoute(labyrinth, n, k, x, y-1, visited)) {
        return true;
    }
    visited[x][y] = 0;
    return false;
}

int** solveLabyrinth(int** labyrinth, int n, int k) {
    int** visited = (int**)malloc(n * sizeof(int*));

    for(int i = 0; i < n; i++) {
        visited[i] = (int*)malloc(k * sizeof(int));
        for(int j = 0; j < k; j++) {
            visited[i][j] = 0;
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            if(labyrinth[i][j] == START) {
                if(makeRoute(labyrinth, n, k, i, j, visited)) {
                    printf("Path found.\n");
                    return visited;
                } else {
                    printf("No path exists.\n");
                    return NULL;
                }
                
            }
        }
    }
}

int main(){
    int n, k;
    printf("Enter the size of the labyrinth: ");
    scanf("%d %d", &n, &k);
    printf("Enter the labyrinth. 0 is a traversable, 1 is a wall, 2 is a starting point and 3 is an ending point: \n");
    int** labyrinth = parseLabyrinth(n, k);
    int** route = solveLabyrinth(labyrinth, n, k);
    if (route != NULL){
        for (int i = 0; i < k; i++){
                for (int j = 0; j < n; j++){
                    printf("%d ", route[i][j]);
                }
                printf("\n");
            }
    }
    for (int i = 0; i < n; i++){
        free(route[i]);
    }
    for (int i = 0; i < n; i++){
        free(labyrinth[i]);
    }
    return 0;
}