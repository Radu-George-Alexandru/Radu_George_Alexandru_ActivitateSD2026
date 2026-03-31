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

typedef struct Document {
    int id;
    int nrPagini;
    float dimensiuneMB;
    char* titlu;
    char* autor;
    char tip;
} Document;

typedef struct NodDocument {
    Document info;
    struct NodDocument* next;
} NodDocument;

void pushDocument(NodDocument** varf, Document d) {
    NodDocument* nou = (NodDocument*)malloc(sizeof(NodDocument));
    nou->info = d;
    nou->next = *varf;
    *varf = nou;
}

Document popDocument(NodDocument** varf) {
    Document rezultat;
    rezultat.id = -1;
    rezultat.titlu = NULL;
    rezultat.autor = NULL;

    if (*varf != NULL) {
        NodDocument* aux = *varf;
        rezultat = aux->info;
        *varf = aux->next;
        free(aux);
    }
    return rezultat;
}

int emptyStack(NodDocument* varf) {
    return varf == NULL;
}

int sizeStack(NodDocument* varf) {
    int nr = 0;
    while (varf != NULL) {
        nr++;
        varf = varf->next;
    }
    return nr;
}

