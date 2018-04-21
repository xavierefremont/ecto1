//
// Created by julien on 18/04/18.
//



/* Pilote de base avec lecture carburant */
int main() {
    char c;
    int i;
    FILE *info = fopen("../../../GPdroitAuBut.log", "w");  /* Pour le débuggage */
    /* Lecture de la carte droit au but. */
    int tx, ty;
    int carburant;         /* carburant dans le réservoir */
    int nbrBoosts = 5;     /* Nombre de boosts au départ */
    int tour = 0;
    int accX = 1, accY = 0;
    int velX = 0, velY = 0;
    char action[100];


    nbrBoosts = nbrBoosts; /* Warning "unused variable" (LIGNE A SUPPRIMER !) */
    fscanf(stdin, "%d %d %d", &tx, &ty,
           &carburant);    /* Lecture taille et carburant au départ */
    fprintf(info, " === >Carte< === \n");
    fprintf(info, "taille %d x %d\n", tx, ty);
    fprintf(info, "Carburant de départ %d \n\n", carburant);
    while (fread(&c, sizeof(char), 1, stdin) == 1 && c != '\n') {
        /* Lire jusqu'a la fin de ligne */
    }
    for (i = 0; i < ty; i++) {           /* Lecture de la carte ligne par ligne */
        while (fread(&c, sizeof(char), 1, stdin) == 1 && c != '\n')
            fprintf(info, "%c", c);
        fprintf(info, "\n");
    }
    fflush(info);
    fprintf(info, "\n === Debut Course === \n");

    while (!feof(stdin)) {
        tour++;
        fprintf(info, "\n === Tour %d === \n", tour);
        /* Lecture des positions */
        while (fread(&c, sizeof(char), 1, stdin) == 1 && c != '\n') {
            fprintf(info, "%c", c);
        }
        fprintf(info, "\n === Action === \n");

        /* Manque la prise en compte du sable (pas de mémorisation de la carte) */
        carburant += deltaCarburantAcceleration(accX, accY, velX, velY, 0);
        velX += accX;
        velY += accY;

        /* Écriture de l'accélération. */
        sprintf(action, "%d %d", accX, accY);
        fprintf(stdout, "%s\n", action);
        fprintf(info, "%s (carburant restant %d)\n", action, carburant);
        fflush(stdout); /* Vidage du buffer nécessaire. */
        fflush(info);
    }

    return EXIT_SUCCESS;
}
