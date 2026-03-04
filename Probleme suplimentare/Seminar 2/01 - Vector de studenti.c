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

Student* copiazaPrimeleNStudenti(Student* vector, int nrElemente, int n) {
    if (n > nrElemente) n = nrElemente;
    if (n <= 0) return NULL;

    Student* copie = (Student*)malloc(sizeof(Student) * n);
    for (int i = 0; i < n; i++) {
        copie[i] = copiazaStudent(vector[i]);
    }
    return copie;
}

void dezalocareVectorStudenti(Student** vector, int* nrElemente) {
    if (vector != NULL && *vector != NULL) {
        for (int i = 0; i < *nrElemente; i++) {
            free((*vector)[i].nume);
        }
        free(*vector);
        *vector = NULL;
        *nrElemente = 0;
    }
}

