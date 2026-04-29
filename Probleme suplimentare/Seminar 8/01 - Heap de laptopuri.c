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

typedef struct Laptop {
    int id;
    int ram;
    float pret;
    char* model;
    char* proprietar;
    char serie;
} Laptop;

typedef struct HeapLaptop {
    int lungime;
    int nrVizibile;
    Laptop* vector;
} HeapLaptop;

void filtreazaHeapLaptop(HeapLaptop h, int pozitie) {
    int st = 2 * pozitie + 1;
    int dr = 2 * pozitie + 2;
    int max = pozitie;

    if (st < h.nrVizibile && h.vector[st].pret > h.vector[max].pret) max = st;
    if (dr < h.nrVizibile && h.vector[dr].pret > h.vector[max].pret) max = dr;

    if (max != pozitie) {
        Laptop aux = h.vector[max];
        h.vector[max] = h.vector[pozitie];
        h.vector[pozitie] = aux;
        filtreazaHeapLaptop(h, max);
    }
}

void construiesteHeapLaptop(HeapLaptop h) {
    for (int i = (h.nrVizibile - 2) / 2; i >= 0; i--) {
        filtreazaHeapLaptop(h, i);
    }
}

