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

typedef struct ComandaOnline {
    int id;
    int nrProduse;
    float total;
    char* client;
    char* oras;
    char tip;
} ComandaOnline;

typedef struct HeapComenzi {
    int lungime;
    int nrVizibile;
    ComandaOnline* vector;
} HeapComenzi;

ComandaOnline extrageComandaMaxima(HeapComenzi* heap);

void afiseazaTop3Comenzi(HeapComenzi* heap) {
    for (int i = 0; i < 3 && heap->nrVizibile > 0; i++) {
        ComandaOnline c = extrageComandaMaxima(heap);
        printf("%d %s %.2f\n", c.id, c.client, c.total);
    }
}

