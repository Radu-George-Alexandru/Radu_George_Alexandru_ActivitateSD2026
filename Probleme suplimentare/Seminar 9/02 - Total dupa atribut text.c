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

typedef struct Nod {
    Masina info;
    struct Nod* stanga;
    struct Nod* dreapta;
} Nod;

float pretTotalMasiniSoferArbore(Nod* radacina, const char* numeSofer) {
    if (radacina == NULL) return 0;

    float suma = pretTotalMasiniSoferArbore(radacina->stanga, numeSofer)
        + pretTotalMasiniSoferArbore(radacina->dreapta, numeSofer);

    if (strcmp(radacina->info.numeSofer, numeSofer) == 0) {
        suma += radacina->info.pret;
    }
    return suma;
}

