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

typedef struct ComandaOnline {
    int id;
    int nrProduse;
    float total;
    char* client;
    char* oras;
    char tip;
} ComandaOnline;

typedef struct NodCoada {
    ComandaOnline info;
    struct NodCoada* next;
    struct NodCoada* prev;
} NodCoada;

typedef struct Coada {
    NodCoada* first;
    NodCoada* last;
} Coada;

void enqueue(Coada* coada, ComandaOnline c) {
    NodCoada* nou = (NodCoada*)malloc(sizeof(NodCoada));
    nou->info = c;
    nou->next = NULL;
    nou->prev = coada->last;

    if (coada->last != NULL) coada->last->next = nou;
    else coada->first = nou;

    coada->last = nou;
}

ComandaOnline dequeue(Coada* coada) {
    ComandaOnline rezultat;
    rezultat.id = -1;
    rezultat.client = NULL;
    rezultat.oras = NULL;

    if (coada->first != NULL) {
        NodCoada* aux = coada->first;
        rezultat = aux->info;
        coada->first = aux->next;
        if (coada->first != NULL) coada->first->prev = NULL;
        else coada->last = NULL;
        free(aux);
    }
    return rezultat;
}

float valoareTotalaCoada(Coada coada) {
    float suma = 0;
    NodCoada* p = coada.first;
    while (p != NULL) {
        suma += p->info.total;
        p = p->next;
    }
    return suma;
}

