#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getAdresse (long ip[], int i, FILE* fichier){
    char adresse[18];
    printf("Entrez l'adresse IP au format X.X.X.X/X : ");
    fgets(adresse, 18, stdin);
    adresse[(strlen(adresse) - 1)] = '\0';
    for(int i=0; i< strlen(adresse); i++){
        if( !(adresse[i] > '0' || adresse[i] < '9' || adresse[i] == '.' || adresse[i] == '/')){
            printf("Type d'adresse non valide : format\n");
            getAdresse(ip, i, fichier);
        }
    }

    fprintf(fichier, "%s est une adresse ", adresse);

    char *finChaine = NULL;
    finChaine = strchr(adresse, '\n');
    if (finChaine != NULL){
        *finChaine = '\0';
    }
    // Découpe de l'adressage IP
    char * pch;
    pch = strtok (adresse," ,.-/");
    i = 0;
    while (pch != NULL){
        ip[i] = strtol(pch, NULL, 10);
        i++;
        pch = strtok (NULL," ,.-/");
    }
    if(ip[0]>255 || ip[0]<1 || ip[1]>255 || ip[1]<1 || ip[2]>255 || ip[2]<1 || ip[3]>255 || ip[3]<1 ){
        printf("Type d'adresse non valide : valeur\n");
        getAdresse(ip, i, fichier);
    }
    //
}

void getClass (long ip[], int i, FILE* fichier){
    int var = ip[i];
    int mask = 128;
    int res = 1;
    while (res != 0){
        res = var & mask;
        if (!(res == 0)){
            mask /= 2;
        }
    }
    switch (mask){
    case 128:
        printf("de classe A\n");
        fprintf(fichier, "de classe A.\n");
        break;
    case 64:
        printf("de classe B\n");
        fprintf(fichier, "de classe B.\n");
        break;
    case 32:
        printf("de classe C\n");
        fprintf(fichier, "de classe C.\n");
        break;
    case 16:
        printf("de classe D\n");
        fprintf(fichier, "de classe D.\n");
        break;
    default:
        printf("de classe E\n");
        fprintf(fichier, "de classe E.\n");
        break;
    }
}

void getTypeAdresse (long ip[], int i, FILE* fichier){
    if(ip[0]==10 && ip[1]>=1 && ip[1]<=255 && ip[2]>=1 && ip[2]<=255 && ip[3]>=1 && ip[3]<=255){
        printf("privee ");
        fprintf(fichier, "privee ");
    }else if(ip[0]==127 && ip[1]>=1 && ip[1]<=255 && ip[2]>=1 && ip[2]<=255 && ip[3]>=1&& ip[3]<=255){
        printf("localhost ");
        fprintf(fichier, "localhost ");
    }else if(ip[0]==172 && ip[1]>=16 && ip[1]<=31 && ip[2]==99 && ip[3]>=1 && ip[3]<=255){
        printf("privee ");
        fprintf(fichier, "privee ");
    }else if(ip[0]==192 && ip[1]==88 && ip[2]>=1 && ip[2]<=255 && ip[3]>=1 && ip[3]<=255){
        printf("6to4 anycast ");
        fprintf(fichier, "6to4 anycast ");
    }else if(ip[0]==192 && ip[1]==168 && ip[2]>=1&& ip[2]<=255 && ip[3]>=1 && ip[3]<=255){
        printf("privee ");
        fprintf(fichier, "privee ");
    }else if(ip[0]>=224 && ip[0]<=239 && ip[1]>=1 && ip[1]<=255 && ip[2]>=1 && ip[2]<=255 && ip[3]>=1 && ip[3]<=255){
        printf("multicast ");
        fprintf(fichier, "multicast ");
    }else if(ip[0]==255 && ip[1]==255 && ip[2]==255 && ip[3]==255){
        printf("broadcast ");
        fprintf(fichier, "broadcast ");
    }else{
        printf("publique ");
        fprintf(fichier, "publique ");
    }
}


void getReseau(long ip[], int i, FILE* fichier){
    switch (ip[4]) {
        case 8:
            printf("@réseau : %d.0.0.0 , @hote : 0.%d.%d.%d\n16 777 214 machines connectables\n", ip[0], ip[1], ip[2], ip[3]);
            fprintf(fichier,"@réseau : %d.0.0.0 , @hote : 0.%d.%d.%d\n16 777 214 machines connectables\n\n", ip[0], ip[1], ip[2], ip[3]);
            break;
        case 16:
             printf("@réseau : %d.%d.0.0  , @hote : 0.0.%d.%d\n65 534 machines connectables\n", ip[0], ip[1], ip[2], ip[3]);
            fprintf(fichier,"@réseau : %d.%d.0.0  , @hote : 0.0.%d.%d\n65 534 machines connectables\n\n", ip[0], ip[1], ip[2], ip[3]);
            break;
        case 24:
             printf("@réseau : %d.%d.%d.0 , @hote : 0.0.0.%d\n254 machines connectables\n", ip[0], ip[1], ip[2], ip[3]);
            fprintf(fichier,"@réseau : %d.%d.%d.0 , @hote : 0.0.0.%d\n254 machines connectables\n\n", ip[0], ip[1], ip[2], ip[3]);
            break;
    }
}

void main (){
    long ip[5];
    char octet[8];
    int i;
    FILE* fichier = fopen("resultat.txt", "a");
    if (fichier != NULL){
        getAdresse(ip, i, fichier);
        printf("C'est une adresse ");
        getTypeAdresse(ip, i, fichier);
        getClass(ip, 0, fichier);
        getReseau(ip, i, fichier);
        fclose(fichier);
    } else {
        printf("Erreur dans l'ouverture fichier");
    }

}
