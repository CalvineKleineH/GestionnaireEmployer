#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>

using namespace std;

constexpr int MAX_EMPLOYER = 100; // Nombre maximum d'employés

int salaires[MAX_EMPLOYER] = {0}; 
string noms[MAX_EMPLOYER] = {""};
int nbEmployers = 0; // Initialisation du nombre d'employés

void ajouterEmployer(string nomEmployer, int salaireEmployer)
{
    /*Cette fonction gère l'ajout des employers, elle prend en pramètre, le nom de l'employer, le salaire de l'empoyer, 
    les tableaux qui permettrons de stocker les noms et les salaires, l'indice d'un nom dans son tableau est le même que celui du 
    tableau où se trouve son salaire.
    ATTENTION ! : string nom[MAX_EMPLOYER], int salaire[MAX_EMPLOYER] , int nbEmbloyer, sont des paramètres qui vont prendre en entrées
    des variables définie localement dans la boucle principale
    */
    for ( int i = (nbEmployers - 1); i < MAX_EMPLOYER; i++)
    {   
        /*Cette boucle nous permet de parcourir les tableaux stockant les noms et les salaires , elle commence par la première place
        libre dans les tablaux, si le nom est vide est ajoute le nom, si le salaire est à 0, valeur par défaut elle arrêtre la boule 
        pour éviter de parcouri tout le reste des tableaux
        */
        if (noms[i] == "") 
        {
            noms[i] = nomEmployer;
            salaires[i] = salaireEmployer;
            break; 
        }
    
    }
}

void afficherDetailsEmployer(string nomEmployer)
{
    bool estEmployer = false;
    for ( int i = 0; i < nbEmployers; i++)
    {   
	// Si l'employé est dans la base donnée on affiche ses informations 
        if ( nomEmployer == noms[i]) 
        {
            cout << "\nEmployer " << i + 1 << " : " << noms[i] << endl;
            cout << "Son salaire est de : " << salaires[i] << " euros\n" << endl;
            estEmployer = true;
            break;
        }

    }
    // Si l'employé n'est dans la base donnée on affiche un message d'erreur
    if (!estEmployer)
    {
        cout << "L'employer " << nomEmployer << " n'est pas dans votre base de donnée !" << endl;
    }
    
}

void calculerMoyenneSalaires()
{
    /*Cette fonction affiche la moyenne des salaires des employés*/
    int totalEmployers = nbEmployers;

    int salaireTotal = 0;
    for (int i = 0; i < totalEmployers; i++)
    {
        salaireTotal += salaires[i];
    }

    float moyenne = (salaireTotal/totalEmployers);

    cout << "\nLa moyenne des salaires vaut : " << moyenne << " euros\n" << endl;

}

int main()
{   
    SetConsoleOutputCP(CP_UTF8);// Permet l'utilisation des accents dans l'invites des commandes 
    bool is_on = true; //Permet l'exécution continue du programme
    int salaire; // Permet l'entrée des salaires qui ne sont pas encore dans la base de donnée
    string nom; // Permet l'entrée des noms qui ne sont pas encore dans la base de donnée
    /*salaires et noms, sont les tableaux qui vont permettre de sauvegarder les informations des salariers
    Il sont définie or de la boucle pour éviter qui soint rénitialiser à chaque itérations.*/
    string choix;
    
    while (is_on)
    {   
        cout << "---------------------------------------------- Gestionnaire d'employés ----------------------------------------------" << endl;
        cout << "Que voulez vous faire :  \n1.Entrez un nouvel employer.\n2.voir les informations d'un employer.\n3.Afficher la moyenne des salaires.\n4.Quitter le gestionnaire." << endl;
        cout << "Choix : "; cin >> choix;

        if (choix == "1") //Permet d'ajouter un employé dans la base de donnée
        {  
             system("cls");
            cout << "\nEntrez le nom de l'employer à ajouter : "; cin >> nom;
            cout << "Entrez son salaire : "; cin >> salaire;
            cout << "" << endl;
            if (salaire > 0 && nom != "") //Lorsque on n'a un salaire strictement possitif on est sur qu'un employé a été rentrer
            {
                nbEmployers += 1;
                ajouterEmployer(nom, salaire);
                /*------------------------------------------------------*/
            }
	    /*Message d'erreur au cas au l'utilisateur rentre un salaire nul ou négatif*/
            else if (nom.size() == 0)
            {
                cout << "Erreur au niveau du nom rentré !\n" << endl;
            }
            else if (salaire <= 0)
            {
                cout << "Erreur au niveau du salaire rentré !\n" << endl;
            }
                
        }
        else if (choix == "2") // Affichage des détails d'un enmployé
        {  
	    system("cls");
            string employer;
            cout << "\nEntrer le nom de l'employer : "; cin >> employer;
            afficherDetailsEmployer(employer);
        }
        else if (choix == "3")//Affichage de la moyenne des salaires 
        {   system("cls");
            calculerMoyenneSalaires();
            
        }
        else if (choix == "4")//Quitte le programme
        {
            is_on = false;
        }
        else 
        {   system("cls");// Message d'erreur si l'utilisateur rentre une entrée invalide 
            cout << "Entrez un nombre valide !\n" << endl;
            
        }
       
        


    }


    return 0;
}
