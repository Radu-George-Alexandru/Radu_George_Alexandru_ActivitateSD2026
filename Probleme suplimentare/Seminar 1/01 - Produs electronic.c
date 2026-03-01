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

typedef struct ProdusElectronic {
    int id;
    int stoc;
    char* denumire;
    float pret;
    char clasaEnergetica;
} ProdusElectronic;

ProdusElectronic initializareProdusElectronic(int id, int stoc, const char* denumire, float pret, char clasa) {
    ProdusElectronic p;
    p.id = id;
    p.stoc = stoc;
    p.denumire = copiazaText(denumire);
    p.pret = pret;
    p.clasaEnergetica = clasa;
    return p;
}

void afisareProdusElectronic(ProdusElectronic p) {
    printf("ID: %d\nStoc: %d\nDenumire: %s\nPret: %.2f\nClasa: %c\n\n",
        p.id, p.stoc, p.denumire, p.pret, p.clasaEnergetica);
}

void modificaDenumireProdus(ProdusElectronic* p, const char* denumireNoua) {
    if (p != NULL) {
        free(p->denumire);
        p->denumire = copiazaText(denumireNoua);
    }
}

float valoareTotalaStoc(ProdusElectronic p) {
    return p.stoc * p.pret;
}

void dezalocareProdusElectronic(ProdusElectronic* p) {
    if (p != NULL) {
        free(p->denumire);
        p->denumire = NULL;
    }
}

