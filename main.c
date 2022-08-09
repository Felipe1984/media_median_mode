#include <stdio.h>

#define SIZE_RESPONSE 99
#define SIZE_FREQUENCY 10

void mean(const int answer[]);
void median(int answer[]);
void mode(int freq[], const int answer[]);
void bubbleSort(int a[]);
void printArray(const int a[]);

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
    median(response);
    mode(frequency, response);

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

void median(int answer[]) {
    printf(
        "\n%s\n%s\n%s\n%s",
        "******************************",
        " Mediana",
        "******************************",
        "O array de respostas, não ordenado, é"
    );

    printArray(answer);
    bubbleSort(answer);

    printf(
        "\n\vA mediana é o elemento %d do\n"
        "array ordenado de %d elementos.\n"
        "Para essa execução, a mediana é %d\n\n",
        SIZE_RESPONSE / 2, SIZE_RESPONSE, answer[SIZE_RESPONSE / 2]
    );
}

void mode(int freq[], const int answer[]) {
    int rating, j, h, largest = 0, modeValue = 0;

    printf(
        "\n%s\n%s\n%s\n",
        "******************************",
        " Moda",
        "******************************"
    );

    for (j = 0; j < SIZE_RESPONSE; j++) {
        ++freq[answer[j]];
    }

    printf(
        "%s%11s%19s\n\n%54s\n%54s\n\n",
        "Resposta",
        "Frequência",
        "Histograma",
        "1  1   2   2",
        "5  0   5   0   5"
    );

    for (rating = 1; rating < SIZE_FREQUENCY; rating++) {
        printf("%8d%11d", rating, freq[rating]);

        if (freq[rating] > largest) {
            largest = freq[rating];
            modeValue = rating;
        }

        for (h = 1; h <= freq[rating]; h++) {
            printf("*");
        }

        printf("\n");

        printf(
            "A moda é o valor mais frequente. \n"
            "Para essa execução, a moda é %d, que ocorreu"
            "%d vezes.\n",
            modeValue,
            largest
        );
    }
}   

void bubbleSort(int a[]) {
    int pass, j, hold;

    for (pass = 1; pass < SIZE_RESPONSE; pass++) {
        for (j = 0; j < SIZE_RESPONSE - 1; j++) {
            if (a[j] > a[j + 1]) {
                hold = a[j];
                a[j] = a[j + 1];
                a[j + 1] = hold;
            }
        }
    }
}

void printArray(const int a[]) {
    int j;

    for (j = 0; j < SIZE_RESPONSE; j++) {
        if (j % 20 == 0) {
            printf("\n");
        }

        printf("%2d", a[j]);
    }
}