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

typedef struct Laptop {
    int id;
    int ram;
    float pret;
    char* model;
    char* proprietar;
    char serie;
} Laptop;

void afiseazaLaptopuriCuRamPestePrag(Laptop* vector, int nrLaptopuri, int pragRam) {
    for (int i = 0; i < nrLaptopuri; i++) {
        if (vector[i].ram > pragRam) {
            printf("%d %d %.2f %s %s %c\n",
                vector[i].id, vector[i].ram, vector[i].pret,
                vector[i].model, vector[i].proprietar, vector[i].serie);
        }
    }
}

