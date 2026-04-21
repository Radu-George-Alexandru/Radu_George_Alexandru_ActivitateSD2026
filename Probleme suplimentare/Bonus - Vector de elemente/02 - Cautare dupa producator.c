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

Tableta getPrimaTabletaDupaProducator(Tableta* vector, int nr, const char* producator) {
    Tableta rezultat;
    rezultat.id = -1;
    rezultat.producator = NULL;

    for (int i = 0; i < nr; i++) {
        if (strcmp(vector[i].producator, producator) == 0) {
            return copiazaTableta(vector[i]);
        }
    }
    return rezultat;
}

