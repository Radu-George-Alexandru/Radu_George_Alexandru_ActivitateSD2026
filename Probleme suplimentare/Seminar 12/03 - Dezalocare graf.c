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

typedef struct Student {
    int id;
    int varsta;
    char* nume;
    float medie;
    char grupa;
} Student;

typedef struct NodGrafStudent NodGrafStudent;
typedef struct NodVecinStudent NodVecinStudent;

struct NodGrafStudent {
    Student info;
    NodGrafStudent* next;
    NodVecinStudent* vecini;
};

struct NodVecinStudent {
    NodGrafStudent* info;
    NodVecinStudent* next;
};

NodGrafStudent* cautaStudentGraf(NodGrafStudent* graf, int id) {
    while (graf != NULL) {
        if (graf->info.id == id) return graf;
        graf = graf->next;
    }
    return NULL;
}

void dezalocareGrafStudenti(NodGrafStudent** graf) {
    while (*graf != NULL) {
        NodGrafStudent* nod = *graf;
        *graf = (*graf)->next;

        NodVecinStudent* vecin = nod->vecini;
        while (vecin != NULL) {
            NodVecinStudent* auxVecin = vecin;
            vecin = vecin->next;
            free(auxVecin);
        }

        free(nod->info.nume);
        free(nod);
    }
}

