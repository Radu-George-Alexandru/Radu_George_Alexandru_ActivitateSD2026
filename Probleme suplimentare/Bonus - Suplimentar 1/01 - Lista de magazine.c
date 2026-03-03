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

typedef struct Magazin {
    char* nume;
    int nrProduse;
} Magazin;

typedef struct NodMagazin {
    Magazin info;
    struct NodMagazin* next;
} NodMagazin;

NodMagazin* inserareMagazinInceput(NodMagazin* cap, Magazin m) {
    NodMagazin* nou = (NodMagazin*)malloc(sizeof(NodMagazin));
    nou->info = m;
    nou->next = cap;
    return nou;
}

NodMagazin* inserareMagazinFinal(NodMagazin* cap, Magazin m) {
    NodMagazin* nou = (NodMagazin*)malloc(sizeof(NodMagazin));
    nou->info = m;
    nou->next = NULL;

    if (cap == NULL) return nou;

    NodMagazin* p = cap;
    while (p->next != NULL) p = p->next;
    p->next = nou;
    return cap;
}

float medieProduseMagazine(NodMagazin* cap) {
    int nr = 0;
    int suma = 0;
    while (cap != NULL) {
        suma += cap->info.nrProduse;
        nr++;
        cap = cap->next;
    }
    return nr == 0 ? 0 : (float)suma / nr;
}

