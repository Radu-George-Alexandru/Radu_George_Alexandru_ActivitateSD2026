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

typedef struct BiletConcert {
    int cod;
    int rand;
    char* numeArtist;
    float pret;
    char zona;
} BiletConcert;

BiletConcert initializareBilet(int cod, int rand, const char* artist, float pret, char zona) {
    BiletConcert b;
    b.cod = cod;
    b.rand = rand;
    b.numeArtist = copiazaText(artist);
    b.pret = pret;
    b.zona = zona;
    return b;
}

void schimbaArtist(BiletConcert* b, const char* artistNou) {
    if (b != NULL) {
        free(b->numeArtist);
        b->numeArtist = copiazaText(artistNou);
    }
}

void aplicaReducere(BiletConcert* b, float procent) {
    if (b != NULL && procent >= 0 && procent <= 100) {
        b->pret = b->pret * (1 - procent / 100);
    }
}

float pretFinalBilet(BiletConcert b) {
    return b.pret;
}

void dezalocareBilet(BiletConcert* b) {
    if (b != NULL) {
        free(b->numeArtist);
        b->numeArtist = NULL;
    }
}

