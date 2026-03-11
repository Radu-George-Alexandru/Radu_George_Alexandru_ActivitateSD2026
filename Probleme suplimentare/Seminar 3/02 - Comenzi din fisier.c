#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char* copiazaText(const char* text) {
    if (text == NULL) return NULL;
    char* copie = (char*)malloc(strlen(text) + 1);
    strcpy(copie, text);
    return copie;
}

typedef struct Comanda {
    int id;
    int nrProduse;
    float total;
    char* numeClient;
    char* oras;
    char tip;
} Comanda;

float calculeazaTotalComenzi(Comanda* vector, int nrComenzi) {
    float suma = 0;
    for (int i = 0; i < nrComenzi; i++) {
        suma += vector[i].total;
    }
    return suma;
}

void dezalocareComenzi(Comanda** vector, int* nrComenzi) {
    if (*vector != NULL) {
        for (int i = 0; i < *nrComenzi; i++) {
            free((*vector)[i].numeClient);
            free((*vector)[i].oras);
        }
        free(*vector);
        *vector = NULL;
        *nrComenzi = 0;
    }
}

