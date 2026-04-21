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

typedef struct Tableta {
    int id;
    int memorie;
    char* producator;
    float pret;
    char serie;
} Tableta;

Tableta copiazaTableta(Tableta t) {
    Tableta copie = t;
    copie.producator = copiazaText(t.producator);
    return copie;
}

void filtreazaTableteScumpe(Tableta* vector, int nr, float prag, Tableta** rezultat, int* dim) {
    *dim = 0;
    for (int i = 0; i < nr; i++) {
        if (vector[i].pret > prag) (*dim)++;
    }

    *rezultat = (Tableta*)malloc(sizeof(Tableta) * (*dim));
    int k = 0;
    for (int i = 0; i < nr; i++) {
        if (vector[i].pret > prag) {
            (*rezultat)[k++] = copiazaTableta(vector[i]);
        }
    }
}

