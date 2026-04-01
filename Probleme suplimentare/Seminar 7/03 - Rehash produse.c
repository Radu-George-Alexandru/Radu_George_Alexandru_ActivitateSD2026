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

typedef struct ProdusHash {
    int id;
    char* denumire;
    float pret;
} ProdusHash;

typedef struct NodProdusHash {
    ProdusHash info;
    struct NodProdusHash* next;
} NodProdusHash;

typedef struct HashProduse {
    int dim;
    NodProdusHash** vector;
} HashProduse;

int hashProdus(int id, int dim) {
    return id % dim;
}

void inserareProdusHash(HashProduse h, ProdusHash p) {
    int poz = hashProdus(p.id, h.dim);
    NodProdusHash* nou = (NodProdusHash*)malloc(sizeof(NodProdusHash));
    nou->info = p;
    nou->next = h.vector[poz];
    h.vector[poz] = nou;
}

HashProduse rehashProduse(HashProduse h) {
    HashProduse nou;
    nou.dim = h.dim * 2;
    nou.vector = (NodProdusHash**)malloc(sizeof(NodProdusHash*) * nou.dim);
    for (int i = 0; i < nou.dim; i++) nou.vector[i] = NULL;

    for (int i = 0; i < h.dim; i++) {
        NodProdusHash* p = h.vector[i];
        while (p != NULL) {
            ProdusHash copie = p->info;
            copie.denumire = copiazaText(p->info.denumire);
            inserareProdusHash(nou, copie);
            p = p->next;
        }
    }
    return nou;
}

