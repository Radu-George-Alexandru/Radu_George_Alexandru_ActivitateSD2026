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

typedef struct NodArboreStudent {
    Student info;
    struct NodArboreStudent* stanga;
    struct NodArboreStudent* dreapta;
} NodArboreStudent;

void inserareStudentArbore(NodArboreStudent** radacina, Student s) {
    if (*radacina == NULL) {
        NodArboreStudent* nou = (NodArboreStudent*)malloc(sizeof(NodArboreStudent));
        nou->info = s;
        nou->stanga = NULL;
        nou->dreapta = NULL;
        *radacina = nou;
    } else if (s.id < (*radacina)->info.id) {
        inserareStudentArbore(&(*radacina)->stanga, s);
    } else if (s.id > (*radacina)->info.id) {
        inserareStudentArbore(&(*radacina)->dreapta, s);
    }
}

Student cautaStudentArbore(NodArboreStudent* radacina, int id) {
    Student rezultat;
    rezultat.id = -1;
    rezultat.nume = NULL;

    if (radacina == NULL) return rezultat;
    if (radacina->info.id == id) return copiazaStudent(radacina->info);
    if (id < radacina->info.id) return cautaStudentArbore(radacina->stanga, id);
    return cautaStudentArbore(radacina->dreapta, id);
}

int numarNoduriStudenti(NodArboreStudent* radacina) {
    if (radacina == NULL) return 0;
    return 1 + numarNoduriStudenti(radacina->stanga) + numarNoduriStudenti(radacina->dreapta);
}

int inaltimeArboreStudenti(NodArboreStudent* radacina) {
    if (radacina == NULL) return 0;
    int st = inaltimeArboreStudenti(radacina->stanga);
    int dr = inaltimeArboreStudenti(radacina->dreapta);
    return 1 + (st > dr ? st : dr);
}

