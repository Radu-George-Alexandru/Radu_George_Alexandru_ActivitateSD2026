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

typedef struct Medicament {
    int id;
    int cantitate;
    char* denumire;
    float pretUnitar;
    int retetaNecesara;
} Medicament;

Medicament initializareMedicament(int id, int cantitate, const char* denumire, float pret, int reteta) {
    Medicament m;
    m.id = id;
    m.cantitate = cantitate;
    m.denumire = copiazaText(denumire);
    m.pretUnitar = pret;
    m.retetaNecesara = reteta;
    return m;
}

void modificaPretMedicament(Medicament* m, float pretNou) {
    if (m != NULL && pretNou > 0) {
        m->pretUnitar = pretNou;
    }
}

void modificaDenumireMedicament(Medicament* m, const char* denumireNoua) {
    if (m != NULL) {
        free(m->denumire);
        m->denumire = copiazaText(denumireNoua);
    }
}

float valoareTotalaMedicament(Medicament m) {
    return m.cantitate * m.pretUnitar;
}

void dezalocareMedicament(Medicament* m) {
    if (m != NULL) {
        free(m->denumire);
        m->denumire = NULL;
    }
}

