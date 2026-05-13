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

int gradNodStudent(NodGrafStudent* graf, int id) {
    NodGrafStudent* nod = cautaStudentGraf(graf, id);
    if (nod == NULL) return -1;

    int grad = 0;
    NodVecinStudent* p = nod->vecini;
    while (p != NULL) {
        grad++;
        p = p->next;
    }
    return grad;
}

