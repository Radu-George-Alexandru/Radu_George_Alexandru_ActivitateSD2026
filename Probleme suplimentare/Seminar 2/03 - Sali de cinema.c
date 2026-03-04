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

typedef struct SalaCinema {
    int id;
    int nrLocuri;
    char* nume;
    float suprafata;
    int etaj;
} SalaCinema;

SalaCinema copiazaSala(SalaCinema s) {
    SalaCinema copie = s;
    copie.nume = copiazaText(s.nume);
    return copie;
}

void copiazaSaliMari(SalaCinema* vector, int nrElemente, float prag,
    SalaCinema** rezultat, int* dimensiune) {

    *dimensiune = 0;
    for (int i = 0; i < nrElemente; i++) {
        if (vector[i].suprafata > prag) {
            (*dimensiune)++;
        }
    }

    *rezultat = NULL;
    if (*dimensiune > 0) {
        *rezultat = (SalaCinema*)malloc(sizeof(SalaCinema) * (*dimensiune));
        int k = 0;
        for (int i = 0; i < nrElemente; i++) {
            if (vector[i].suprafata > prag) {
                (*rezultat)[k++] = copiazaSala(vector[i]);
            }
        }
    }
}

SalaCinema getPrimaSalaDupaNume(SalaCinema* vector, int nrElemente, const char* nume) {
    SalaCinema rezultat;
    rezultat.id = -1;
    rezultat.nume = NULL;

    for (int i = 0; i < nrElemente; i++) {
        if (strcmp(vector[i].nume, nume) == 0) {
            return copiazaSala(vector[i]);
        }
    }
    return rezultat;
}

