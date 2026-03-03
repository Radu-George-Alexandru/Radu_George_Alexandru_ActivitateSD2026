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

NodMagazin* inserareInainteDeMagazin(NodMagazin* cap, const char* numeCautat, Magazin m) {
    if (cap == NULL || strcmp(cap->info.nume, numeCautat) == 0) {
        return inserareMagazinInceput(cap, m);
    }

    NodMagazin* anterior = NULL;
    NodMagazin* p = cap;
    NodMagazin* anteriorMax = NULL;
    int maxim = -1;

    while (p->next != NULL) {
        if (strcmp(p->next->info.nume, numeCautat) == 0 &&
            p->next->info.nrProduse > maxim) {
            maxim = p->next->info.nrProduse;
            anteriorMax = p;
        }
        p = p->next;
    }

    if (anteriorMax == NULL) {
        return inserareMagazinFinal(cap, m);
    }

    NodMagazin* nou = (NodMagazin*)malloc(sizeof(NodMagazin));
    nou->info = m;
    nou->next = anteriorMax->next;
    anteriorMax->next = nou;
    return cap;
}

