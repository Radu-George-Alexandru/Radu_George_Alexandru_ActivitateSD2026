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

typedef struct ProdusABC {
    int cod;
    int stoc;
    float pret;
    char* denumire;
} ProdusABC;

typedef struct NodProdusABC {
    ProdusABC info;
    struct NodProdusABC* stanga;
    struct NodProdusABC* dreapta;
} NodProdusABC;

int numarFrunzeProduse(NodProdusABC* radacina) {
    if (radacina == NULL) return 0;
    if (radacina->stanga == NULL && radacina->dreapta == NULL) return 1;
    return numarFrunzeProduse(radacina->stanga) + numarFrunzeProduse(radacina->dreapta);
}

float pretMaximProduse(NodProdusABC* radacina) {
    if (radacina == NULL) return 0;
    float max = radacina->info.pret;
    float st = pretMaximProduse(radacina->stanga);
    float dr = pretMaximProduse(radacina->dreapta);
    if (st > max) max = st;
    if (dr > max) max = dr;
    return max;
}

float pretTotalProduse(NodProdusABC* radacina) {
    if (radacina == NULL) return 0;
    return radacina->info.pret
        + pretTotalProduse(radacina->stanga)
        + pretTotalProduse(radacina->dreapta);
}

void afisareProduseStocPestePrag(NodProdusABC* radacina, int prag) {
    if (radacina != NULL) {
        afisareProduseStocPestePrag(radacina->stanga, prag);
        if (radacina->info.stoc > prag) {
            printf("%d %s %d %.2f\n", radacina->info.cod, radacina->info.denumire,
                radacina->info.stoc, radacina->info.pret);
        }
        afisareProduseStocPestePrag(radacina->dreapta, prag);
    }
}

