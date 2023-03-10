#include <stdio.h>
#include <stdlib.h>
#include "../header/exo2.h"
#include <time.h>

typedef double ElementTableau;
typedef ElementTableau *Tableau;

void permuter(ElementTableau *a, ElementTableau *b) {
    ElementTableau temp = *a;
    *a = *b;
    *b = temp;
}

void permuter_Tableau(Tableau tab, unsigned size) {
    unsigned i;
    for (i = 0; i < size/2; i++) {
        permuter(&tab[i], &tab[size-1-i]);
    }
}

Tableau cree_tableau(unsigned size) {
    Tableau tab = (Tableau)malloc(size * sizeof(ElementTableau));
    if (tab == NULL) {
        printf("Erreur : Impossible de créer le tableau.\n");
        exit(1);
    }
    unsigned i;
    srand(time(NULL));
    for (i = 0; i < size; i++) {
        tab[i] = (double)rand()/(double)RAND_MAX;
    }
    return tab;
}

void liberer_Tableau(Tableau *tab) {
    free(*tab);
    *tab = NULL;
}

void afficher(const Tableau tab, unsigned size) {
    unsigned i;
    for (i = 0; i < size; i++) {
        printf("Tab[%u] : %f \n", i, tab[i]);
    }
    printf("\n");
}

void exo2() {
    unsigned size = 10;
    Tableau tab = cree_tableau(size);
    printf("Tableau initial : \n\n");
    afficher(tab, size);
    permuter_Tableau(tab, size);
    printf("Tableau permuté : \n\n");
    afficher(tab, size);
    liberer_Tableau(&tab);
}
