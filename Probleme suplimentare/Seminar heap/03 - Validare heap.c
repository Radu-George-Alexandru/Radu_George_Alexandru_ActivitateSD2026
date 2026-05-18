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

typedef struct Masina {
    int id;
    int nrUsi;
    float pret;
    char* model;
    char* numeSofer;
    unsigned char serie;
} Masina;

typedef struct Heap {
    int nrMasini;
    Masina* vector;
} Heap;

int esteHeapMaxPret(Heap heap) {
    for (int i = 0; i < heap.nrMasini; i++) {
        int st = 2 * i + 1;
        int dr = 2 * i + 2;

        if (st < heap.nrMasini && heap.vector[i].pret < heap.vector[st].pret) return 0;
        if (dr < heap.nrMasini && heap.vector[i].pret < heap.vector[dr].pret) return 0;
    }
    return 1;
}

