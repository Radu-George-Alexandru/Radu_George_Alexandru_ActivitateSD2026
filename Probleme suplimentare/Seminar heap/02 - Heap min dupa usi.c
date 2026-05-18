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

void filtreazaHeapMinUsi(Heap heap, int pozitie) {
    int st = 2 * pozitie + 1;
    int dr = 2 * pozitie + 2;
    int min = pozitie;

    if (st < heap.nrMasini && heap.vector[st].nrUsi < heap.vector[min].nrUsi) min = st;
    if (dr < heap.nrMasini && heap.vector[dr].nrUsi < heap.vector[min].nrUsi) min = dr;

    if (min != pozitie) {
        Masina aux = heap.vector[min];
        heap.vector[min] = heap.vector[pozitie];
        heap.vector[pozitie] = aux;
        filtreazaHeapMinUsi(heap, min);
    }
}

