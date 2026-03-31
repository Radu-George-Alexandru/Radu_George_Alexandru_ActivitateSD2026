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

typedef struct NodMasina {
    Masina info;
    struct NodMasina* next;
} NodMasina;

Masina copiazaMasina(Masina m) {
    Masina copie = m;
    copie.model = copiazaText(m.model);
    copie.numeSofer = copiazaText(m.numeSofer);
    return copie;
}

void pushMasina(NodMasina** varf, Masina m) {
    NodMasina* nou = (NodMasina*)malloc(sizeof(NodMasina));
    nou->info = m;
    nou->next = *varf;
    *varf = nou;
}

Masina popMasina(NodMasina** varf) {
    Masina rezultat;
    rezultat.id = -1;
    rezultat.model = NULL;
    rezultat.numeSofer = NULL;

    if (*varf != NULL) {
        NodMasina* aux = *varf;
        rezultat = aux->info;
        *varf = aux->next;
        free(aux);
    }
    return rezultat;
}

Masina getMasinaByIDDinStiva(NodMasina** varf, int id) {
    NodMasina* auxiliar = NULL;
    Masina rezultat;
    rezultat.id = -1;
    rezultat.model = NULL;
    rezultat.numeSofer = NULL;

    while (*varf != NULL && (*varf)->info.id != id) {
        pushMasina(&auxiliar, popMasina(varf));
    }

    if (*varf != NULL) {
        rezultat = copiazaMasina((*varf)->info);
    }

    while (auxiliar != NULL) {
        pushMasina(varf, popMasina(&auxiliar));
    }

    return rezultat;
}

