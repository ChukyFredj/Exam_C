#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {DIVERS, VETEMENT, NOURRITURE, LIVRE} Type;

typedef struct {
    char a_nom[256];
    float a_prix;
    char a_description[1024];
    Type a_type;
} Article;

Article* creer_Article() {
    Article *article = (Article*) malloc(sizeof(Article));
    if (article == NULL) {
        printf("Erreur : Impossible de créer l'article.\n");
        exit(1);
    }
    strcpy(article->a_nom, "Nom par défaut");
    article->a_prix = 0.0;
    strcpy(article->a_description, "Description par défaut");
    article->a_type = DIVERS;
    return article;
}

void afficher_Article(const Article *article) {
    printf("Nom : %s\n", article->a_nom);
    printf("Prix : %f\n", article->a_prix);
    printf("Description : %s\n", article->a_description);
    switch(article->a_type) {
        case VETEMENT:
            printf("Type : Vetement\n");
            break;
        case NOURRITURE:
            printf("Type : Nourriture\n");
            break;
        case LIVRE:
            printf("Type : Livre\n");
            break;
        default:
            printf("Type : Divers\n");
            break;
    }
}

void modifier_Article(Article *article) {
    printf("Modifier l'article :\n");
    printf("Nom : ");
    scanf("%s", article->a_nom);
    printf("Prix : ");
    scanf("%f", &article->a_prix);
    printf("Description : ");
    getchar();  // vider le tampon d'entrée
    fgets(article->a_description, 1024, stdin);
    printf("Type (0:Divers, 1:Vetement, 2:Nourriture, 3:Livre) : ");
    scanf("%d", &article->a_type);
}


void liberer_Article(Article **article) {
    free(*article);
    *article = NULL;
}

void save_Article(const Article *article, const char* nomFichier) {
    FILE *fichier = fopen(nomFichier, "w");
    if (fichier == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier.\n");
        exit(1);
    }
    fprintf(fichier, "%s\n%f\n%s\n%d\n", article->a_nom, article->a_prix, article->a_description, article->a_type);
    fclose(fichier);
}

void load_Article(Article *article, FILE *fichier) {
    fread(article, sizeof(Article), 1, fichier);
}

int main_Article() {
    int nbArticleMax = 2;
    Article *tab_Article[nbArticleMax];

    for (int i = 0; i < nbArticleMax; i++) {
        tab_Article[i] = creer_Article();
        afficher_Article(tab_Article[i]);
        modifier_Article(tab_Article[i]);
        afficher_Article(tab_Article[i]);
        save_Article(tab_Article[i], "Article.txt");
        liberer_Article(&tab_Article[i]);
    }

    FILE *fichier = fopen("Article.txt", "r");
    if (fichier == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier.\n");
        exit(1);
    }

    for (int i = 0; i < nbArticleMax; i++) {
        tab_Article[i] = creer_Article();
        load_Article(tab_Article[i], fichier);
        afficher_Article(tab_Article[i]);
        liberer_Article(&tab_Article[i]);
    }

    fclose(fichier);
    return 0;
}
