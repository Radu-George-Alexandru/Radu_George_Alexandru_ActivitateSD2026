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

typedef struct Carte {
    int id;
    int nrPagini;
    float pret;
    char* titlu;
    char* autor;
    char categorie;
} Carte;

typedef struct NodCarte {
    Carte info;
    struct NodCarte* next;
} NodCarte;

void inserareCarteFinal(NodCarte** cap, Carte c) {
    NodCarte* nou = (NodCarte*)malloc(sizeof(NodCarte));
    nou->info = c;
    nou->next = NULL;

    if (*cap == NULL) {
        *cap = nou;
    } else {
        NodCarte* p = *cap;
        while (p->next != NULL) p = p->next;
        p->next = nou;
    }
}

float pretMediuCarti(NodCarte* cap) {
    float suma = 0;
    int nr = 0;
    while (cap != NULL) {
        suma += cap->info.pret;
        nr++;
        cap = cap->next;
    }
    return nr == 0 ? 0 : suma / nr;
}

void dezalocareListaCarti(NodCarte** cap) {
    while (*cap != NULL) {
        NodCarte* aux = *cap;
        *cap = (*cap)->next;
        free(aux->info.titlu);
        free(aux->info.autor);
        free(aux);
    }
}

