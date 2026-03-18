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

void inserareRezervareFinal(ListaDublaRezervari* lista, Rezervare r) {
    NodRezervare* nou = (NodRezervare*)malloc(sizeof(NodRezervare));
    nou->info = r;
    nou->next = NULL;
    nou->prev = lista->ultim;

    if (lista->ultim != NULL) {
        lista->ultim->next = nou;
    } else {
        lista->prim = nou;
    }
    lista->ultim = nou;
}

void afisareRezervariInvers(ListaDublaRezervari lista) {
    NodRezervare* p = lista.ultim;
    while (p != NULL) {
        printf("%d %s %s %.2f\n", p->info.id, p->info.numeClient, p->info.restaurant, p->info.pret);
        p = p->prev;
    }
}

