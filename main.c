#include <stdio.h>
#include <stdlib.h>
#include <process.h>

#define MAX_NUM 10;                                                     // Все возможные числа в массивах принадлежат промежутку [0, MAX_NUM)

int cmpDesOrder(const void *first, const void *second) {
    return (*(int*)first - *(int*)second);
}

int cmpAscOrder(const void *first, const void *second) {
    return (*(int*)second - *(int*)first);
}

int **createArrays (int n) {
    int **result = malloc(sizeof(int*) * n);

    int MAX_LENGTH = n;                                                 // Для наглядности
    char *checkLengthUniq = calloc(MAX_LENGTH, 1);                      // Строка для проверки уникальности длины каждого массива
    int *lengths = malloc(MAX_LENGTH * sizeof(int));                    // Массив длин каждого массива

    for (int i = 0; i < n; i++) {
        int randomLength = rand()%MAX_LENGTH;                           // Обратим внимание, что длина массива может быть равна нулю
        while (checkLengthUniq[randomLength]) randomLength = rand()%MAX_LENGTH;

        result[i] = malloc(sizeof(int) * randomLength);
        for (int j = 0; j < randomLength; j++) {
            result[i][j] = rand()%MAX_NUM;
        }

        checkLengthUniq[randomLength] = '1';
        lengths[i] = randomLength;
    }

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) qsort(result[i], lengths[i], sizeof(int), cmpDesOrder);     // Порядковый номер начинается с 0
        else qsort(result[i], lengths[i], sizeof(int), cmpAscOrder);
    }

    free(checkLengthUniq);
    free(lengths);

    return result;
}


int **createArraysWithPrint (int n) {                                       // Создание с печатью
    int **result = malloc(sizeof(int*) * n);

    int MAX_LENGTH = n;
    char *checkLengthUniq = calloc(MAX_LENGTH, 1);
    int *lengths = malloc(MAX_LENGTH * sizeof(int));

    for (int i = 0; i < n; i++) {
        int randomLength = rand()%MAX_LENGTH;
        while (checkLengthUniq[randomLength]) randomLength = rand()%MAX_LENGTH;

        result[i] = malloc(sizeof(int) * randomLength);
        for (int j = 0; j < randomLength; j++) {
            result[i][j] = rand()%MAX_NUM;
        }

        checkLengthUniq[randomLength] = '1';
        lengths[i] = randomLength;
    }

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) qsort(result[i], lengths[i], sizeof(int), cmpDesOrder);
        else qsort(result[i], lengths[i], sizeof(int), cmpAscOrder);
    }

    for (int i = 0; i < n; i++) {                       // Цикл печати
        for (int j = 0; j < lengths[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    free(checkLengthUniq);
    free(lengths);

    return result;
}

void clearArray (int **array, int length) {         // Очистка памяти
    for (int i = 0; i < length; i++) {
        free(array[i]);
    }
    free(array);
}

int main() {
    srand(_getpid());
    int n;
    scanf("%d", &n);
    int **resultArray = createArrays(n);
    return 0;
}
