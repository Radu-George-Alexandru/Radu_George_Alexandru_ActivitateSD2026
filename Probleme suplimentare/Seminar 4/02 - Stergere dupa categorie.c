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

void stergeCartiDupaCategorie(NodCarte** cap, char categorie) {
    while (*cap != NULL && (*cap)->info.categorie == categorie) {
        NodCarte* aux = *cap;
        *cap = (*cap)->next;
        free(aux->info.titlu);
        free(aux->info.autor);
        free(aux);
    }

    NodCarte* p = *cap;
    while (p != NULL && p->next != NULL) {
        if (p->next->info.categorie == categorie) {
            NodCarte* aux = p->next;
            p->next = aux->next;
            free(aux->info.titlu);
            free(aux->info.autor);
            free(aux);
        } else {
            p = p->next;
        }
    }
}

