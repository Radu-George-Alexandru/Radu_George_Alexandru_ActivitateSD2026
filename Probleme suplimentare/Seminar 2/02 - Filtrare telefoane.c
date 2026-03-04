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

typedef struct Telefon {
    int id;
    int ram;
    char* producator;
    float pret;
    char serie;
} Telefon;

Telefon copiazaTelefon(Telefon t) {
    Telefon copie = t;
    copie.producator = copiazaText(t.producator);
    return copie;
}

void copiazaTelefoaneScumpe(Telefon* vector, int nrElemente, float pretMinim,
    Telefon** rezultat, int* dimensiune) {

    *dimensiune = 0;
    for (int i = 0; i < nrElemente; i++) {
        if (vector[i].pret >= pretMinim) {
            (*dimensiune)++;
        }
    }

    *rezultat = NULL;
    if (*dimensiune > 0) {
        *rezultat = (Telefon*)malloc(sizeof(Telefon) * (*dimensiune));
        int k = 0;
        for (int i = 0; i < nrElemente; i++) {
            if (vector[i].pret >= pretMinim) {
                (*rezultat)[k++] = copiazaTelefon(vector[i]);
            }
        }
    }
}

Telefon getPrimulTelefonByProducator(Telefon* vector, int nrElemente, const char* producator) {
    Telefon rezultat;
    rezultat.id = -1;
    rezultat.producator = NULL;

    for (int i = 0; i < nrElemente; i++) {
        if (strcmp(vector[i].producator, producator) == 0) {
            return copiazaTelefon(vector[i]);
        }
    }
    return rezultat;
}

