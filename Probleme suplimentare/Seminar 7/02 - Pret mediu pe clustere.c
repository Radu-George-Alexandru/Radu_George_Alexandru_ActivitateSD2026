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

typedef struct ElementHash {
    float pret;
} ElementHash;

typedef struct Nod {
    ElementHash info;
    struct Nod* next;
} Nod;

typedef struct HashTable {
    int dim;
    Nod** vector;
} HashTable;

float* calculeazaPreturiMediiPerClustere(HashTable ht, int* nrClustere) {
    *nrClustere = 0;
    for (int i = 0; i < ht.dim; i++) {
        if (ht.vector[i] != NULL) (*nrClustere)++;
    }

    if (*nrClustere == 0) return NULL;

    float* medii = (float*)malloc(sizeof(float) * (*nrClustere));
    int k = 0;

    for (int i = 0; i < ht.dim; i++) {
        Nod* p = ht.vector[i];
        if (p != NULL) {
            float suma = 0;
            int nr = 0;
            while (p != NULL) {
                suma += p->info.pret;
                nr++;
                p = p->next;
            }
            medii[k++] = suma / nr;
        }
    }

    return medii;
}

