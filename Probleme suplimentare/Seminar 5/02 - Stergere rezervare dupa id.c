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

typedef struct Rezervare {
    int id;
    int nrPersoane;
    float pret;
    char* numeClient;
    char* restaurant;
    char zona;
} Rezervare;

typedef struct NodRezervare {
    Rezervare info;
    struct NodRezervare* next;
    struct NodRezervare* prev;
} NodRezervare;

typedef struct ListaDublaRezervari {
    NodRezervare* prim;
    NodRezervare* ultim;
} ListaDublaRezervari;

void stergeRezervareDupaId(ListaDublaRezervari* lista, int id) {
    NodRezervare* p = lista->prim;
    while (p != NULL && p->info.id != id) {
        p = p->next;
    }

    if (p == NULL) return;

    if (p->prev != NULL) p->prev->next = p->next;
    else lista->prim = p->next;

    if (p->next != NULL) p->next->prev = p->prev;
    else lista->ultim = p->prev;

    free(p->info.numeClient);
    free(p->info.restaurant);
    free(p);
}

