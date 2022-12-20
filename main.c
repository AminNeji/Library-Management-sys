#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct adherant {
    char nom[20];
    char prenom[20];
    int id;
    char addresse[20];
    char type[20];
    int nbemp;
    int duree;
};
struct date{
    short jj;
    short mm;
    short yy;
};
struct localisation{
    int salle;
    int rayon;
};

struct articles{
    char nom_auteur[10];
    char date_pub[10];
};
struct livres{
    char nom_auteur[10];
    char nom_editeur[10];
    char date_edit[10];
};
struct magazines {
    int frequence;
};
struct nombre_doc{
    int nb;
};
struct documents{
    char titre[20];
    struct localisation loc;
    int code;
    int nbexemp;
    char type[20];
    struct articles art;
    struct livres liv;
    struct magazines mag;
};
struct retardataire{
    int idretar;
};
struct emprunt{
    int id;
    int code;
    int nbempadh;
    int nbempdoc;
    int rendu;
    struct retardataire reta;
    struct date dateemp;
    struct date dateren;
    struct documents doc;
    struct adherant adh;
};
int nb=-1;
int nbad=-1;
struct documents t[];
struct adherant ta[];
struct emprunt te[];

int emprun_effectue(){

}




// MESSAGE //
void headMessage()
{
    system("cls");
    printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############        Bienvenue dans la bibliotheque             ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printf("                                Made by Med Amin Neji                                  ");
    printf("\n\t\t\t----------------------------------------------------------------------------\n");
}

// MAIN MENU //
void menu(){

    system("cls");
    fflush(stdin);

    int number;

    printf("----------------------------------\n");
    printf(">>> Library Management System <<< \n");
    printf("----------------------------------\n\n");
    printf("> 1. Management d'Adherants  \n");
    printf("> 2. Management des Documents \n");
    printf("> 3. Management des Emprunts \n\n");
    printf("> Choisissez votre choix : ");
    scanf("%d",&number);

    fflush(stdin);

    switch(number)
    {
        case 1:
            userMenu();
            break;
        case 2:
            documentMenu();
            break;
        case 3:
            empruntMenu();
            break;
        default:
            printf("\n>>> Invaild Input! <<<");
            Sleep(2000);
            menu();
    }
}
// MENU DE EMPRUNTER //
void empruntMenu(){

    system("cls");
    fflush(stdin);

    int number;

    printf("-----------------------------------------------\n");
    printf(">>> Library Management System - User Panel <<< \n");
    printf("-----------------------------------------------\n\n");
    printf("> 1. Ajouter un Emprunteur \n");
    printf("> 2. List Emprunteur \n");
    printf("> 3. Ouvrir Main Menu \n");
    printf("> 4. Fermer Le Programme ... \n\n");

    printf("> Entrer votre choix : ");
    scanf("%d",&number);

    fflush(stdin);

    switch(number)
    {
        case 1:
            ajoutemp();
            break;
        case 2:
            emp_aff();
            break;
        case 3:
            menu();
            break;
        case 4:
            endScreen();
            break;
        default:
            printf("Invaild Input!");
            Sleep(2000);
            empruntMenu();
    }
}
void ajoutemp(){}
// MENU D'ADHERANTS //
void userMenu(){

    system("cls");
    fflush(stdin);

    int number;

    printf("-----------------------------------------------\n");
    printf(">>> Library Management System - User Panel <<< \n");
    printf("-----------------------------------------------\n\n");
    printf("> 1. Ajouter un Adherant  \n");
    printf("> 2. Modifier Adherant \n");
    printf("> 3. List Adherant \n");
    printf("> 4. Rechercher Adherant \n");
    printf("> 5. Supprimer Adherant \n");
    printf("> 6. Ouvrir Main Menu \n");
    printf("> 7. Fermer Le Programme ... \n\n");

    printf("> Entrer votre choix : ");
    scanf("%d",&number);

    fflush(stdin);

    switch(number)
    {
        case 1:
            ajoutUser();
            break;
        case 2:
            modifierUser();
            break;
        case 3:
            listUser();
            break;
        case 4:
            rechercherUser();
            break;
        case 5:
            SupprimerUser();
            break;
        case 6:
            menu();
            break;
        case 7:
            endScreen();
            break;
        default:
            printf("Invaild Input!");
            Sleep(2000);
            userMenu();
    }
}
void ajoutUser(){
    char rep[3];
    fflush(stdin);
    do{
            nbad++;
            fflush(stdin);
         do{
            printf("  Donner le nom de l'Adherant :  ");
            gets(ta[nbad].nom);
         }
         while(strlen(ta[nbad].nom)>10);
         do{
            printf("  Donner le prenom de l'Adherant :   ");
            scanf("%s",&ta[nbad].prenom);
         }
         while(strlen(ta[nbad].prenom)>10);
         ta[nbad].id=nbad;
         fflush(stdin);
         do{
            printf("  Donner l'addresse de l'Adherant  :   ");
            scanf("%s",&ta[nbad].addresse);
         }
         while(strlen(ta[nbad].addresse)<0 || strlen(ta[nbad].addresse)>8);
        do{
                printf("  Donner le type de l'Adherant :   ");
                scanf("%s",&ta[nbad].type);
        }
        while(strcmp(ta[nbad].type,"etudiant")!=0 && strcmp(ta[nbad].type,"enseignant")!=0 && strcmp(ta[nbad].type,"visiteur")!=0);
            if(strcmp(ta[nbad].type,"etudiant")==0){
                    ta[nbad].nbemp=2;
                    ta[nbad].duree=14;
            }
            else if(strcmp(ta[nbad].type,"enseignant")==0){
                    ta[nbad].nbemp=4;
                    ta[nbad].duree=21;
            }
            else if(strcmp(ta[nbad].type,"visiteur")==0){
                    ta[nbad].nbemp=1;
                    ta[nbad].duree=7;
            }
            printf("  Voulez-Vous Ajouter Un Nouveau Adherant ? :  ");
            scanf("%s",&rep);
    }
         while(strcmp(rep,"non")!=0);
         printf("\n > Voulez-vous retourner au Menu precedant ? : ");
         scanf("%s",rep);
         if(strcmp(rep,"oui")==0){
           system("cls");
           userMenu();
           }
        else{
                endScreen();
        }
}
// Modifier un Adherant //
void modifierUser(){
    int choix;
    int id;
    int i=0;
    system("cls");
    printf("\n> <<<               MENU DE MODIFICATION               >>> :  ");
    printf("\n1.<< Code >>\n");
    printf("\n2.<< Go back to the previous menu >>\n");
    printf("\nVotre Choix : ");
    scanf("%d",&choix);
    switch(choix){
        case 1:
            printf("\n Donner l'identifiant de l'adherant a modifier ");
            scanf("%d",&id);
            int test=0;
            fflush(stdin);
            while(i<nbad+1 || test==0){
               if(ta[i].id==id){
                    printf("\n Adherant Trouve ! \n");
                    fflush(stdin);
                    do{
                      printf("  Donner le nouveau nom de l'Adherant :  ");
                      gets(ta[i].nom);
                      }
                    while(strlen(ta[i].nom)>10);
                    do{
                       printf("  Donner le nouveau prenom de l'Adherant :   ");
                       scanf("%s",&ta[i].prenom);
                       }
                    while(0>ta[i].prenom>100);
                    ta[i].id=i;
                    fflush(stdin);
                    do{
                       printf("  Donner la nouveau addresse de l'Adherant  :   ");
                       scanf("%s",&ta[i].addresse);
                       }
                    while(strlen(ta[i].addresse)<0 || strlen(ta[i].addresse)>8);
                    fflush(stdin);
                    do{
                       printf("  Donner le nouveau type de l'Adherant :   ");
                       scanf("%s",&ta[i].type);
                       }
                    while(strcmp(ta[i].type,"etudiant")!=0 && strcmp(ta[i].type,"enseignant")!=0 && strcmp(ta[i].type,"visiteur")!=0);
                    if(strcmp(ta[i].type,"etudiant")==0){
                        ta[i].nbemp=2;
                        ta[i].duree=14;
                        }
                    else if(strcmp(ta[i].type,"enseignant")==0){
                        ta[i].nbemp=4;
                        ta[i].duree=21;
                        }
                    else if(strcmp(ta[i].type,"visiteur")==0){
                        ta[i].nbemp=1;
                        ta[i].duree=7;
                        }
                        test=1;
               }
               i++;
            }
         system("cls");
         if(test==1){
            printf("\n La modification effectue avec succes... ");
            printf("\n Going Back to the principal Menu ...");
            sleep(3);
            system("cls");
            userMenu();
         }
         else{
            printf("\n La modification a echoue ...\n");
            sleep(3);
            printf("\n Going Back to the principal Menu ...");
            sleep(3);
            userMenu();
         }
         break;
         case 2:
             printf("NO WAY BRUH COME ON !!! ");
             sleep(2);
             system("cls");
             userMenu();
    }
}

// Affichage Toutes les Adherants //
void listUser(){
    int i;
    for(i=0;i<nbad+1;i++){
            printf("\n*le nom de l'Adherant est :  %s",ta[i].nom);
            printf("\n*le prenom de l'Adherant est : %s ",ta[i].prenom);
            printf("\n*l'identifiant de l'Adherant est : %d ",ta[i].id);
            printf("\n*l'Addresse de l'Adherant est :  %s",ta[i].addresse);
            printf("\n*le type de l'Adherant est : %s   ",ta[i].type);
            printf("\n*le nombres de documents empruntables sont : %d ",ta[i].nbemp);
            printf("\n*le duree de pret de le document de l'Adherant est : %d ",ta[i].duree);
            printf("\n");
           }
    int rep[3];
    printf("\n\n***Voulez vous revenir au Menu Precedante");
    scanf("%s",&rep);
    if(strcmp(rep,"oui")==0){
        system("cls");
        fflush(stdin);
        userMenu();
    }
}


//rechercher d'un Adherant //
void rechercherUser(){
    fflush(stdin);
    int j=0;
    int id;
    char rep[3];
    int choix;
    int test=0;
    system("cls");
    printf("\n<<<<           MENU DE RECHERCHE            >>>>:  ");
    printf("\n1.<< Idantifiant >>\n");
    printf("\n2.<< Go Back to Main Menu >>\n");
    printf("\nVotre Choix : ");
    scanf("%d",&choix);
    switch (choix) {
        case 1:
            printf("\n>> Donner l'identifiant de l'adherant a rechercher : ");
            scanf("%d",&id);
            do{
                if(id==ta[j].id){
                    test=1;
                }
                else{
                        j++;
                }
            }
            while(j<nbad+1 && test!=1);
            if(test==1){
                printf("L'Adherant existe \n");
                printf("Voulez-vous l'afficher ? => ");
                scanf("%s",&rep);
                if(strcmp(rep,"oui")==0){
                    system("cls");
                    printf("L'Adherant Ayant l'idantifiant : %d ",ta[j].id);
                    printf("\n*le nom de l'Adherant est :  %s",ta[j].nom);
                    printf("\n*le prenom de l'Adherant est : %s ",ta[j].prenom);
                    printf("\n*l'Addresse de l'Adherant est :  %s",ta[j].addresse);
                    printf("\n*le type de l'Adherant est : %s   ",ta[j].type);
                    printf("\n*le nombres de documents empruntables sont : %d ",ta[j].nbemp);
                    printf("\n*le duree de pret de le document de l'Adherant est : %d ",ta[j].duree);
                }
                else{
                    system("cls");
                    printf("L'Adherant n'existe pas ");
                    printf("\n Going back to the previous Menu.. \n\n");
                    sleep(5);
                    system("cls");
                    userMenu();
                    break;
                }
        case 2:
            printf("\n Go back to Main Menu ?");
            scanf("%s",&rep);
            if(strcmp(rep,"oui")==0){
                printf("\nWaiting ...");
                sleep(5);
                system("cls");
                userMenu();
            }
            break;
    }
}
}

// Supprimer un Adherant //
void SupprimerUser(){
    fflush(stdin);
    system("cls");
    int choix;
    char rep[3];
    int id;
    int i;
    int j=0;
    int test=0;
    printf("\n<<<<         MENU DE SUPPRESSION          >>>> ");
    printf("\n1.<< Identifiant >>\n");
    printf("\n2.<< Go Back to Main Menu >>\n");
    printf("\nVotre Choix : ");
    scanf("%d",&choix);
    switch(choix){
        case 1:
            printf("\n>> Donner l'identifiant de l'Adherant a Supprimer  : ");
            scanf("%d",&id);
            do{
                if(id==ta[j].id){
                    test=1;
                }
                else{
                        j++;
                }
            }
            while(j<nbad+1 && test!=1);
            if(test==1){
                printf("L'Adherant existe \n");
                printf("Voulez Vous le Supprimer ? : ");
                scanf("%s",&rep);
                if(strcmp(rep,"oui")==0){
                    system("cls");
                    printf("\nL'Adherant Ayant l'identifiant (%d) est en cours de Suppression ... ",ta[j].id);
                    for(i=j;i<nbad+1;i++){
                        ta[i]=ta[i+1];
                    }
                    system("cls");
                    printf("\n La suppression est effectue avec success ...");
                    nbad--;
                    printf("\n Going Back to the Main Menu ");
                    sleep(2);
                    userMenu();
                    }
        case 2:
            printf("\n Go back to Main Menu ?");
            scanf("%s",&rep);
            if(strcmp(rep,"oui")==0){
                printf("\nWaiting ...");
                sleep(2);
                system("cls");
                userMenu();
            }
            break;
}
    }
}
void ajout(){
    char rep[3];
    fflush(stdin);
    do{
            nb++;
            fflush(stdin);
         do{
            printf("  Donner le titre de document :  ");
            gets(t[nb].titre);
         }
         while(strlen(t[nb].titre)>10);
         do{
            printf("  Donner la salle du document :   ");
            scanf("%d",&t[nb].loc.salle);
         }
         while(0>t[nb].loc.salle>100);
         do{
            printf("  Donner le rayon du document :   ");
            scanf("%d",&t[nb].loc.rayon);
         }
         while(0>t[nb].loc.rayon>100);
         do{
            printf("  Donner le code du document  :   ");
            scanf("%d",&t[nb].code);
         }
         while(t[nb].code<0);
         do{
             printf("  Donner le nombre d'exemplaires du document  :   ");
             scanf("%d",&t[nb].nbexemp);
         }
         while(t[nb].nbexemp<0);
            do{
                 printf("  Donner le type de document :   ");
                 scanf("%s",&t[nb].type);
            }
            while(strcmp(t[nb].type,"article")!=0 && strcmp(t[nb].type,"livres")!=0 && strcmp(t[nb].type,"magazines")!=0);
            if(strcmp(t[nb].type,"article")==0){
                do{
                    printf("  Donner le nom de l'auteur :  ");
                    scanf("%s",&t[nb].art.nom_auteur);
                }
                while(strlen(t[nb].art.nom_auteur)>10);
                do{
                    printf("  Donner le date de publication de document :   ");
                    scanf("%s",&t[nb].art.date_pub);
                }
                while(valid(t[nb].art.date_pub)==0);

            }
            else if (strcmp(t[nb].type,"livres")==0){
                do{
                    printf("  Donner le nom de l'auteur :   ");
                    scanf("%s",&t[nb].liv.nom_auteur);
                }
                while(strlen(t[nb].liv.nom_auteur)>10);
                do{
                    printf("  Donner le nom de l'editeur  :    ");
                    scanf("%s",&t[nb].liv.nom_editeur);
                }
                while(strlen(t[nb].liv.nom_editeur)>10);
                do{
                    printf("  Donner le date d'edition de livre :    ");
                    scanf("%s",&t[nb].liv.date_edit);
                }
                while(valid(t[nb].liv.date_edit)==0);
            }
            else if(strcmp(t[nb].type,"magazines")==0){
                do{
                    printf("  Donner le frequence de magazines :    ");
                    scanf("%d",&t[nb].mag.frequence);
                }
                while(t[nb].mag.frequence>10);
            }
            printf("  Voulez-Vous Ajouter Un Nouveau Document ? :  ");
            scanf("%s",&rep);
         }
         while(strcmp(rep,"non")!=0);
         if(strcmp(rep,"non")==0){
            system("cls");
            documentMenu();
         }
}
void documentMenu(){

    system("cls");
    fflush(stdin);

    int number;

    system("cls");
    printf("-----------------------------------------------\n");
    printf(">>> Library Management System - Documents Panel <<< \n");
    printf("-----------------------------------------------\n\n");
    printf("> 1. Ajouter un Document \n");
    printf("> 2. Modifier un Document \n");
    printf("> 3. Documents List \n");
    printf("> 4. Rechercher un Document \n");
    printf("> 5. Supprimer un Document \n");
    printf("> 6. Ouvrir Main Menu \n");
    printf("> 7. Fermer le Programme ... \n");

    printf("\nEntrer Votre choix : ");
    scanf("%d",&number);

    fflush(stdin);

    switch(number)
        {
        case 1:
            ajout();
            break;
        case 2:
            modifier();
            break;
        case 3:
            documentslist();
            break;
        case 4:
            rechercher();
            break;
        case 5:
            supprimer();
            break;
        case 6:
            menu();
            break;
        case 7:
            endScreen();
            break;
            default:
            printf("Invaild Input!");
            Sleep(2000);
         }
}
void endScreen(){

    system("cls");
    fflush(stdin);
    exit(0);
}

//fonction valider la date :
int valid(char *date){
    if(strlen(date)!=10){
        return 0;
    }
    int month=(date[0]-'0')*10+(date[1]-'0');
    if(month<1 || month > 12){
        return 0;
    }
    if(date[2]!='/' || date[5]!='/'){
        return 0;
    }
    int day=(date[3]-'0')*10+(date[4]-'0');
    if(day <1 || day >31){
        return 0;
    }
    int year=(date[6]-'0')*1000+(date[7]-'0')*1000+(date[8]-'0')*10+(date[9]-'0');
    if(year <1 || year >9999){
        return 0;
    }
    return 1;
}
// Modification d'un document //
void modifier(){
    fflush(stdin);
    int i=0;
    int choix;
    char type[8];
    int code;
    char titre[10];
    int salle;
    int rayon;
    int nbexemp;
    char nom_auteur[10];
    char nom_editeur[10];
    char date_edit[10];
    char date_pub[10];
    int frequence;
    system("cls");
    printf("\n<<<<              MENU DE MODIFICATION           >>>>   ");
    printf("\n1.<< Code Et Type >>\n");
    printf("\n2.<< Go back to the previois MENU >>\n");
    printf("\nVotre Choix : ");
    scanf("%d",&choix);
    switch(choix){
        case 1:
            printf("\n Donner le Code du Document a modifier ");
            scanf("%d",&code);
            int test=0;
            fflush(stdin);
            while(i<nb+1 || test==0){
               if(t[i].code==code){
                    printf("\nLe document est trouve ..\n");
                    do{
                      printf("\n Donner Le type de Document a modifier : ");
                      scanf("%s",type);
                    }
                    while(strcmp(type,"article")!=0 && strcmp(type,"livres")!=0 && strcmp(type,"magazines")!=0);
                    if(strcmp(type,"article")==0 && strcmp(t[i].type,"article")==0){
                      fflush(stdin);
                      do{
                        printf(">Donner le nouveau titre de document :  ");
                        gets(t[i].titre);
                     }
                     while(strlen(t[i].titre)>10);
                     do{
                         printf(">Donner la nouveau salle du document :   ");
                         scanf("%d",&salle);
                     }
                     while(0>salle>100);
                     t[i].loc.salle=salle;
                     do{
                         printf(">Donner le rayon du document :   ");
                         scanf("%d",&rayon);
                     }
                     while(0>rayon>100);
                     t[i].loc.rayon=rayon;
                     do{
                         printf(">Donner le nombre d'exemplaires du document  :   ");
                         scanf("%d",&nbexemp);
                     }
                     while(nbexemp<0);
                     t[i].nbexemp=nbexemp;
                     do{
                         printf(">Donner le nom de l'auteur :  ");
                         scanf("%s",&t[i].art.nom_auteur);
                     }
                     while(strlen(t[i].art.nom_auteur)>10);
                     do{
                         printf(">Donner le date de publication de document :   ");
                         scanf("%s",&t[i].art.date_pub);
                     }
                     while(valid(t[i].art.date_pub)==0);
                     test=1;
                 }
                 else if(strcmp(type,"livres")==0 && strcmp(t[i].type,"livres")==0){
                        fflush(stdin);
                     do{
                         printf(">Donner le nouveau titre de document :  ");
                         gets(t[i].titre);
                     }
                     while(strlen(t[i].titre)>10);
                     do{
                         printf(">Donner la nouveau salle du document :   ");
                         scanf("%d",&salle);
                     }
                     while(0>salle>100);
                     t[i].loc.salle=salle;
                     do{
                         printf(">Donner le rayon du document :   ");
                         scanf("%d",&rayon);
                     }
                     while(0>rayon>100);
                     t[i].loc.rayon=rayon;
                     do{
                         printf(">Donner le nombre d'exemplaires du document  :   ");
                         scanf("%d",&nbexemp);
                     }
                     while(nbexemp<0);
                     t[i].nbexemp=nbexemp;
                     do{
                         printf(">Donner le nouveau nom de l'auteur :   ");
                         scanf("%s",&t[i].liv.nom_auteur);
                     }
                     while(strlen(t[i].liv.nom_auteur)>10);
                     do{
                         printf(">Donner le nouveau nom de l'editeur  :    ");
                         scanf("%s",&t[i].liv.nom_editeur);
                     }
                     while(strlen(t[i].liv.nom_editeur)>10);
                     do{
                         printf(">Donner la nouveau date d'edition de livre :    ");
                         scanf("%s",&t[i].liv.date_edit);
                     }
                     while(valid(t[i].liv.date_edit)==0);
                     }
                     else if(strcmp(type,"magazines")==0 && strcmp(t[i].type,"magazines")==0){
                        fflush(stdin);
                         do{
                           printf(">Donner le nouveau titre de document :  ");
                           gets(t[i].titre);
                         }
                         while(strlen(t[i].titre)>10);
                         do{
                           printf(">Donner la nouveau salle du document :   ");
                           scanf("%d",&salle);
                         }
                         while(0>salle>100);
                         t[i].loc.salle=salle;
                         do{
                            printf(">Donner le rayon du document :   ");
                            scanf("%d",&rayon);
                         }
                         while(0>rayon>100);
                         t[i].loc.rayon=rayon;
                         do{
                            printf(">Donner le nombre d'exemplaires du document  :   ");
                            scanf("%d",&nbexemp);
                         }
                         while(nbexemp<0);
                         t[i].nbexemp=nbexemp;
                         do{
                            printf(">Donner le frequence de magazines :    ");
                            scanf("%d",&frequence);
                         }
                         while(frequence>10);
                         t[i].mag.frequence=frequence;
                     }
                     test=1;
               }
               i++;
         }
         system("cls");
         if(test==1){
            printf("\n La modification effectue avec succes... ");
            printf("\n Going Back to the principal Menu ...");
            sleep(3);
            system("cls");
            documentMenu();
         }
         else{
            printf("\n La modification a echoue ...\n");
            sleep(3);
            printf("\n Going Back to the principal Menu ...");
            sleep(3);
            documentMenu();
         }
         break;
         case 2:
             printf("NO WAY BRUH COME ON !!! ");
             sleep(2);
             system("cls");
             documentMenu();
    }
}

// Recherche des Documents //
void rechercher(){
    fflush(stdin);
    int j=0;
    int code;
    char rep[3];
    int choix;
    int test=0;
    system("cls");
    printf("\n>Donner Selon Quoi Vous Voulez Rechercher :  ");
    printf("\n1.<< Code Et Type >>\n");
    printf("\n2.<< Go Back to Main Menu >>\n");
    printf("\nVotre Choix : ");
    scanf("%d",&choix);
    switch (choix) {
        case 1:
            printf("\n>> Donner le code du document a rechercher : ");
            scanf("%d",&code);
            do{
                if(code==t[j].code){
                    test=1;
                }
                else{
                        j++;
                }
            }
            while(j<nb+1 && test!=1);
            if(test==1){
                printf("Le Document existe :D\n");
                printf("Voulez-vous l'afficher ? => ");
                scanf("%s",&rep);
                if(strcmp(rep,"oui")==0){
                    system("cls");
                    printf("Le Document Ayant le Code : %d ",t[j].code);
                             if(strcmp(t[j].type,"article")==0){
                                 printf("\n*le titre de l'article est :  %s",t[j].titre);
                                 printf("\n*l'article se trouve dans la salle : %d ",t[j].loc.salle);
                                 printf("\n*l'article se trouve En rayon : %d ",t[j].loc.rayon);
                                 printf("\n*le nombre d'exemplaires de l'article est  %d :  ",t[j].nbexemp);
                                 printf("\n*le nom d'auteur de l'article est  : %s",t[j].art.nom_auteur);
                                 printf("\n*le date de publication de l'article est  : %s ",t[j].art.date_pub);
                                 }
                             else if(strcmp(t[j].type,"livres")==0){
                                 printf("\n*le titre du livre est :  %s",t[j].titre);
                                 printf("\n*le livre  se trouve dans la salle en rayon : %d  ",t[j].loc.salle);
                                 printf("\n*le livre se trouve En rayon : %d ",t[j].loc.rayon);
                                 printf("\n*le nombre d'exemplaires de le livre  est : %d  ",t[j].nbexemp);
                                 printf("\n*le nom d'auteur de livre est :  %s ",t[j].liv.nom_auteur);
                                 printf("\n*le nom de l'editeur du livre est : %s ",t[j].liv.nom_editeur);
                                 printf("\n*la date d'edition de livre est : %s  ",t[j].liv.date_edit);
                                 }
                            else if(strcmp(t[j].type,"magazines")==0){
                                  printf("\n*le titre de la magazine est :  %s",t[j].titre);
                                  printf("\n*la magazine  se trouve dans la salle en rayon : %d ",t[j].loc.salle);
                                  printf("\n*le magazine se trouve En rayon : %d ",t[j].loc.rayon);
                                  printf("\n*le nombre d'exemplaires de la magazine  est : %d  ",t[j].nbexemp);
                                  printf("\n*le frequence de magazines est egales a  : %d ",t[j].mag.frequence);
                                  }
                                  }
                                  sleep(5);
                                  }
                else{
                    system("cls");
                    printf("Le document n'existe pas ");
                    printf("\n Going back to the previous Menu.. \n\n");
                    sleep(5);
                    system("cls");
                    documentMenu();
                    break;
                }
        case 2:
            printf("\n Go back to Main Menu ?");
            scanf("%s",&rep);
            if(strcmp(rep,"oui")==0){
                printf("\nWaiting ...");
                sleep(5);
                system("cls");
                documentMenu();
            }
            break;
    }
}

//Suppression des documents //
void supprimer(){
    fflush(stdin);
    system("cls");
    int choix;
    char rep[3];
    int code;
    int i;
    int j=0;
    int test=0;
    printf("\n>Donner Selon Quoi Vous Voulez Supprimer : ");
    printf("\n1.<< Code Et Type >>\n");
    printf("\n2.<< Go Back to Main Menu >>\n");
    printf("\nVotre Choix : ");
    scanf("%d",&choix);
    switch(choix){
        case 1:
            printf("\n>> Donner le code du document a Supprimer  : ");
            scanf("%d",&code);
            do{
                if(code==t[j].code){
                    test=1;
                }
                else{
                        j++;
                }
            }
            while(j<nb+1 && test!=1);
            if(test==1){
                printf("Le Document existe \n");
                printf("Voulez Vous le Supprimer ? : ");
                scanf("%s",&rep);
                if(strcmp(rep,"oui")==0){
                    system("cls");
                    printf("\nLe Document Ayant le Code (%d) est en cours de Suppression ... ",t[j].code);
                    for(i=j;i<nb+1;i++){
                        t[i]=t[i+1];
                    }
                    system("cls");
                    printf("\n La suppression est effectue avec success ...");
                    nb--;
                    printf("\n Going Back to the Main Menu ");
                    sleep(2);
                    documentMenu();
                    }
        case 2:
            printf("\n Go back to Main Menu ?");
            scanf("%s",&rep);
            if(strcmp(rep,"oui")==0){
                printf("\nWaiting ...");
                sleep(2);
                system("cls");
                documentMenu();
            }
            break;
}
    }
}


// affichage du documents //
void documentslist (){
    int i;
    for(i=0;i<nb+1;i++){
        fflush(stdin);
        printf("\n\n>>> Document n°: %d",i);
        if(strcmp(t[i].type,"article")==0){
            printf("\n*le titre de l'article est :  %s",t[i].titre);
            printf("\n*l'article se trouve dans la salle : %d ",t[i].loc.salle);
            printf("\n*l'article se trouve En rayon %d :",t[i].loc.rayon);
            printf("\n*le code de l'article est :  %d",t[i].code);
            printf("\n*le nombre d'exemplaires de l'article est : %d   ",t[i].nbexemp);
            printf("\n*le nom d'auteur de l'article est  : %s",t[i].art.nom_auteur);
            printf("\n*le date de publication de l'article est  : %s ",t[i].art.date_pub);
           }
        else if(strcmp(t[i].type,"livres")==0){
            printf("\n*le titre du livre est :  %s",t[i].titre);
            printf("\n*le livre  se trouve dans la salle en rayon %d : ",t[i].loc.salle);
            printf("\n*le livre se trouve En rayon %d :",t[i].loc.rayon);
            printf("\n*le code de le livre  est :  %d",t[i].code);
            printf("\n*le nombre d'exemplaires de le livre  est %d :  ",t[i].nbexemp);
            printf("\n*le nom d'auteur de livre est :  %s ",t[i].liv.nom_auteur);
            printf("\n*le nom de l'editeur du livre est : %s ",t[i].liv.nom_editeur);
            printf("\n*la date d'edition de livre est : %s  ",t[i].liv.date_edit);
        }
        else if(strcmp(t[i].type,"magazines")==0){
            printf("\n*le titre de la magazine est :  %s",t[i].titre);
            printf("\n*la magazine  se trouve dans la salle en rayon %d : ",t[i].loc.salle);
            printf("\n*le magazine se trouve En rayon %d :",t[i].loc.rayon);
            printf("\n*le code de la magazine  est :  %d",t[i].code);
            printf("\n*le nombre d'exemplaires de la magazine  est %d :  ",t[i].nbexemp);
            printf("\n*le frequence de magazines est egales a  : %d ",t[i].mag.frequence);
        }
    }
    int rep[3];
    printf("\n\n***Voulez vous revenir au Menu Precedante");
    scanf("%s",&rep);
    if(strcmp(rep,"oui")==0){
        system("cls");
        fflush(stdin);
        documentMenu();
    }
}































void emp_aff(){
    int i;
    int empe;
    int empc;
    int empd;
    int id;
    for(i=0;i<nbad+1;i++){
        te[i].id=ta[i].id;
    }
    for(i=0;i<nb+1;i++){
        te[i].code=t[i].code;
    }
    system("cls");
    printf("\n> Donner l'identifiant de l'Emprenteur : ");
    scanf("%d",&id);
    int test=0;
    do{

            if(te[i].id==id){
                test=1;
            }
            i++;
    }
    while(test!=1 || i<nbad+1);
    if(test==1){
        printf("> L'emprunteur a l'ID : %d",te[i].id);
        printf("\n*le nom de l'Emprunteur est :  %s",ta[i].nom);
        printf("\n*le prenom de l'Emprunteur est : %s ",ta[i].prenom);
        printf("\n*l'Addresse de l'Emprunteur est :  %s",ta[i].addresse);
        printf("\n*le type de l'Emprunteur est : %s   ",ta[i].type);
    }
}





/*// emprunter management
time_t now = time(NULL);
struct tm *date_now = gmtime(&now);
struct tm *cur_time = localtime(&now);
char *st = asctime(cur_time);

typedef struct
{
    int id;
    int iddoc;
    char typedoc;
    int valid;
} back;
back tb[10];
int taille_b = 0;

int taille_emp = 0;

// emprunt article
int emprunt_check(int x)
{
    int i;
    while (i<taille_b)
    {
        if (tb[i].id == x)
        {
            if (tb[i].valid == 0)
            {
                return 0;
            }
        }
        i++;
    }
    return 1;
}
int visiteur(int id1){
    int test = 0;
    for(int i = 0;i<taille_art;i++){
        if (T[i].id == id1){
            if (strcmp(T[i].type,"visiteur") ==0){
                test = 1;break;
            }
        }
    }
    if (test == 1){
        return 1;
    }
    else{
        return 0;
    }
}
int etudiant(int id1){
    int test = 0;
    for(int i = 0;i<taille_art;i++){
        if (T[i].id == id1){
            if (strcmp(T[i].type,"etudiant") ==0){
                test = 1;break;
            }
        }
    }
    if (test == 1){
        return 1;
    }
    else{
        return 0;
    }
}
int limit(int id1){
    int test = 0;
    for(int i = 0;i<taille_user;i++){
        if(T[i].limit > 0){
            test = 1;break;
        }
    }
    return test;
}
void loan_article(){
    system("cls");
    int id1,code1;
    printf("Enter your id :");
    scanf("%d",&id1);
    printf("\nEnter article code :");
    scanf("%d",&code1);
    if((loan_check(id1)==0)){
        printf("Sorry ! you have already a document on loan !");
    }
    while((limit(id1)==1)&&(exist_in_user(id1)==1)){
        TE[taille_emp].id = id1;
        TE[taille_emp].iddoc = code1;
        //date systeme
        TE[taille_emp].datedeb.day = date_now->tm_mday;
        TE[taille_emp].datedeb.month = date_now->tm_mon;
        TE[taille_emp].datedeb.year = (date_now->tm_year) + 1900;
        if(etudiant(id1) == 1){
        TE[taille_emp].datefin.day = (date_now->tm_mday) + 14;
        TE[taille_emp].datefin.month = date_now->tm_mon;
        TE[taille_emp].datefin.year = (date_now->tm_year) + 1900;
        }
        else if(visiteur(id1) == 1){
            TE[taille_emp].datedeb.day = date_now->tm_mday + 7;
            TE[taille_emp].datedeb.month = date_now->tm_mon;
            TE[taille_emp].datedeb.year = (date_now->tm_year) + 1900;
        }else{
            TE[taille_emp].datedeb.day = (date_now->tm_mday) + 21;
            TE[taille_emp].datedeb.month = date_now->tm_mon;
            TE[taille_emp].datedeb.year = (date_now->tm_year) + 1900;
        }
        strcpy(TE[taille_emp].typedoc,"article");
    }
}

// loan book
void loan_book(){
    system("cls");
    int id1,code1;
    printf("Enter your id :");
    scanf("%d",&id1);
    printf("\nEnter book code :");
    scanf("%d",&code1);
    if((loan_check(id1)==0)){
        printf("Tu as deja un document emprunté !");
    }
    while((limit(id1)==1)&&(exist_in_user(id1)==1)){
        te[taille_emp].id = id1;
        te[taille_emp].iddoc = code1;

        te[taille_emp].datedeb.day = date_now->tm_mday;
        te[taille_emp].datedeb.month = date_now->tm_mon;
        te[taille_emp].datedeb.year = (date_now->tm_year) + 1900;
        if(etudiant(id1) == 1){
        te[taille_emp].datefin.day = (date_now->tm_mday) + 14;
        te[taille_emp].datefin.month = date_now->tm_mon;
        te[taille_emp].datefin.year = (date_now->tm_year) + 1900;
        }
        else if(visiteur(id1) == 1){
            te[taille_emp].datedeb.day = date_now->tm_mday + 7;
            te(taille_emp].datedeb.month = date_now->tm_mon;
            te[taille_emp].datedeb.year = (date_now->tm_year) + 1900;
        }else{
            te[taille_emp].datedeb.day = (date_now->tm_mday) + 21;
            te[taille_emp].datedeb.month = date_now->tm_mon;
            te[taille_emp].datedeb.year = (date_now->tm_year) + 1900;
        }
        strcpy(te[taille_emp],"livre");
    }
}
// emprunt magazines
void loan_magazine(){
    system("cls");
    int id1,code1;
    printf("Enter your id :");
    scanf("%d",&id1);
    printf("\nEnter magazine code :");
    scanf("%d",&code1);
    if((loan_check(id1)==0)){
        printf("Sorry ! you have already a document on loan !");
    }
    while((limit(id1)==1)&&(exist_in_user(id1)==1)){
        te[taille_emp].id = id1;
        te[taille_emp].iddoc = code1;

        te[taille_emp].datedeb.day = date_now->tm_mday;
        te[taille_emp].datedeb.month = date_now->tm_mon;
        te[taille_emp].datedeb.year = (date_now->tm_year) + 1900;
        if(etudiant(id1) == 1){
        te[taille_emp].datefin.day = (date_now->tm_mday) + 14;
        te[taille_emp].datefin.month = date_now->tm_mon;
        te[taille_emp].datefin.year = (date_now->tm_year) + 1900;
        }
        else if(visiteur(id1) == 1){
            te[taille_emp].datedeb.day = date_now->tm_mday + 7;
            te[taille_emp].datedeb.month = date_now->tm_mon;
            te[taille_emp].datedeb.year = (date_now->tm_year) + 1900;
        }else{
            te[taille_emp].datedeb.day = (date_now->tm_mday) + 21;
            te[taille_emp].datedeb.month = date_now->tm_mon;
            te[taille_emp].datedeb.year = (date_now->tm_year) + 1900;
        }
        strcpy(te[taille_emp],"magazines");
    }
}
*/ // Ne marche pas parce qu'il est incomplete /.


int main(){
	menu();
	return 0;
}
