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

Student initializareStudent(int id, int varsta, const char* nume, float medie, char grupa) {
    Student s;
    s.id = id;
    s.varsta = varsta;
    s.nume = copiazaText(nume);
    s.medie = medie;
    s.grupa = grupa;
    return s;
}

Student copiazaStudent(Student s) {
    return initializareStudent(s.id, s.varsta, s.nume, s.medie, s.grupa);
}

typedef struct NodStudent {
    Student info;
    struct NodStudent* next;
} NodStudent;

typedef struct HashStudenti {
    int dim;
    NodStudent** vector;
} HashStudenti;

HashStudenti initializareHashStudenti(int dim) {
    HashStudenti h;
    h.dim = dim;
    h.vector = (NodStudent**)malloc(sizeof(NodStudent*) * dim);
    for (int i = 0; i < dim; i++) h.vector[i] = NULL;
    return h;
}

int hashStudent(int id, int dim) {
    return id % dim;
}

void inserareStudentHash(HashStudenti h, Student s) {
    int poz = hashStudent(s.id, h.dim);
    NodStudent* nou = (NodStudent*)malloc(sizeof(NodStudent));
    nou->info = s;
    nou->next = h.vector[poz];
    h.vector[poz] = nou;
}

Student cautaStudentDupaId(HashStudenti h, int id) {
    Student rezultat;
    rezultat.id = -1;
    rezultat.nume = NULL;

    int poz = hashStudent(id, h.dim);
    NodStudent* p = h.vector[poz];
    while (p != NULL) {
        if (p->info.id == id) return copiazaStudent(p->info);
        p = p->next;
    }
    return rezultat;
}

