#include <stdio.h>

#define SIZE_RESPONSE 99
#define SIZE_FREQUENCY 10

void mean(const int answer[]);
// void median(int answer[]);
// void mode(int freq[], const int answer[]);
// void bubbleSort(int a[]);
// void printArray(const int a[]);

int main() {
    int frequency[SIZE_FREQUENCY] = { 0 };
    int response[SIZE_RESPONSE] = {
        6, 7, 8, 9, 8, 7, 8, 9, 8, 9,
        7, 8, 9, 5, 9, 8, 7, 8, 7, 8,
        6, 7, 8, 9, 3, 9, 8, 7, 8, 7,
        7, 8, 9, 8, 9, 8, 9, 7, 8, 9,
        6, 7, 8, 7, 8, 7, 9, 8, 9, 2,
        7, 8, 9, 8, 9, 8, 9, 7, 5, 3,
        5, 6, 7, 2, 5, 3, 9, 4, 6, 4,
        7, 8, 9, 6, 8, 7, 8, 9, 7, 8,
        7, 4, 4, 2, 5, 3, 8, 7, 5, 6,
        4, 5, 6, 1, 6, 5, 7, 8, 7
    };

    mean(response);
    // median(response);
    // mode(frequency, response);

    return 0;
}

void mean(const int answer[]) {
    int j, total = 0;
    
    printf(
        "%s\n%s\n%s\n",
        "******************************",
        " Média",
        "******************************"
    );

    for (j = 0; j < SIZE_RESPONSE; j++) {
        total += answer[j];
    }

    printf(
        "A média é o valor médio dos itens de dados.\n"
        "A média é igual ao total de todos\n"
        "os itens de dados divididos pelo número\n"
        "de itens de dados ( %d ). O valor médio para esta\n"
        "execução é: %d / %d = %.4f\n\n",
        SIZE_RESPONSE,
        total,
        SIZE_RESPONSE,
        (double) total / SIZE_RESPONSE
    );
}