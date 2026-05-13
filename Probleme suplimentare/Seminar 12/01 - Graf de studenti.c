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

void inserareNodStudentGraf(NodGrafStudent** graf, Student s) {
    NodGrafStudent* nou = (NodGrafStudent*)malloc(sizeof(NodGrafStudent));
    nou->info = s;
    nou->next = NULL;
    nou->vecini = NULL;

    if (*graf == NULL) {
        *graf = nou;
    } else {
        NodGrafStudent* p = *graf;
        while (p->next != NULL) p = p->next;
        p->next = nou;
    }
}

NodGrafStudent* cautaStudentGraf(NodGrafStudent* graf, int id) {
    while (graf != NULL) {
        if (graf->info.id == id) return graf;
        graf = graf->next;
    }
    return NULL;
}

void inserareVecinStudent(NodVecinStudent** lista, NodGrafStudent* vecin) {
    NodVecinStudent* nou = (NodVecinStudent*)malloc(sizeof(NodVecinStudent));
    nou->info = vecin;
    nou->next = *lista;
    *lista = nou;
}

void inserareMuchieStudent(NodGrafStudent* graf, int idStart, int idStop) {
    NodGrafStudent* start = cautaStudentGraf(graf, idStart);
    NodGrafStudent* stop = cautaStudentGraf(graf, idStop);

    if (start != NULL && stop != NULL) {
        inserareVecinStudent(&start->vecini, stop);
        inserareVecinStudent(&stop->vecini, start);
    }
}

