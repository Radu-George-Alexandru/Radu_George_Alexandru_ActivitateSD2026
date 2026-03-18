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

float calculeazaMedieRezervari(ListaDublaRezervari lista) {
    float suma = 0;
    int nr = 0;
    NodRezervare* p = lista.prim;
    while (p != NULL) {
        suma += p->info.pret;
        nr++;
        p = p->next;
    }
    return nr == 0 ? 0 : suma / nr;
}

void dezalocareListaDublaRezervari(ListaDublaRezervari* lista) {
    while (lista->prim != NULL) {
        NodRezervare* aux = lista->prim;
        lista->prim = lista->prim->next;
        free(aux->info.numeClient);
        free(aux->info.restaurant);
        free(aux);
    }
    lista->ultim = NULL;
}

