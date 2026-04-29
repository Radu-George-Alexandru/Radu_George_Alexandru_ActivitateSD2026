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
    int lungime;
    int nrElemVizibile;
    Masina* vector;
} Heap;

void filtreazaHeap(Heap heap, int pozitie) {
    int st = 2 * pozitie + 1;
    int dr = 2 * pozitie + 2;
    int max = pozitie;

    if (st < heap.nrElemVizibile && heap.vector[st].pret > heap.vector[max].pret) max = st;
    if (dr < heap.nrElemVizibile && heap.vector[dr].pret > heap.vector[max].pret) max = dr;

    if (max != pozitie) {
        Masina aux = heap.vector[max];
        heap.vector[max] = heap.vector[pozitie];
        heap.vector[pozitie] = aux;
        filtreazaHeap(heap, max);
    }
}

void afisareMasina(Masina m) {
    printf("%d %s %s %.2f\n", m.id, m.model, m.numeSofer, m.pret);
}

Masina extrageMasinaDinHeap(Heap* heap) {
    Masina rezultat;
    rezultat.id = -1;
    rezultat.model = NULL;
    rezultat.numeSofer = NULL;

    if (heap->nrElemVizibile > 0) {
        rezultat = heap->vector[0];
        heap->vector[0] = heap->vector[heap->nrElemVizibile - 1];
        heap->vector[heap->nrElemVizibile - 1] = rezultat;
        heap->nrElemVizibile--;

        for (int i = (heap->nrElemVizibile - 2) / 2; i >= 0; i--) {
            filtreazaHeap(*heap, i);
        }
    }
    return rezultat;
}

void afiseazaHeapAscuns(Heap heap) {
    for (int i = heap.nrElemVizibile; i < heap.lungime; i++) {
        afisareMasina(heap.vector[i]);
    }
}

