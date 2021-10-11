#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

// Structura pentru adresa
struct adresa
    {
        char Adresa[11];
        char domiciliu[11];
        char strada[17];
        char numar1[4];
    };

// Strucrura pentru persoana
struct persoana
{
    char CNP[14];
    char nume[10];
    char prenume[10];
    int numar;
    struct adresa adresa1;

}persoana1[1001];

//Structura pentru masina
struct masina
{
    int numar;
    char marca[15];
    char seria[19];
    char NrInmatriculare[9];
    int NrProprietar;

}masina1[1001];

//Structura pentru accidente
struct accidente
{
    int numarac;
    char data[11];
    char localitatea[15];
    int daune;
}accidente1[1001];

void meniu(int val)
{
    switch(val)
    {
        case 1:
            {
                printf("|===================START MENU==================|\n");
                printf("                   WElCOME USER !\n\n");
                printf("****Press 1 to add an accident****\n");
                printf("****Press 2 to add a car****\n");
                printf("****Press 3 to add the date of the accident****\n");
                printf("****Press 4 to add the location of the accident****\n");
                break;
            }
        case 2:
            {
                printf("|===================MENIU DE START==================|\n");
                printf("                   BINE AI VENIT !\n\n");
                printf("****Apasa tasta 1 pentru a adauga/modifica un accident****\n");
                printf("****Apasa tasta 2 pentru a adauga/modifica o masina****\n");
                printf("****Apasa tasta 3 pentru a adauga/modifica data accidentului****\n");
                printf("****Apasa tasta 4 pentru a adauga/modifica localitatea in care s-a produs accidentul****\n");
                break;
            }
        default:
            {
                printf("ATENTIE !!! DATE DE INTRARE GRESITE /// WARNNING !!! WRONG INPUT\n");
            }

    }
}

void AdaugAccident(int *nr)
{
    system("cls");

    FILE *fpt;

    fpt =fopen("Book.csv" ,"a+");
    fprintf(fpt,"\n");
    char s[50] , c[50];
    int ok1 = 0 , ok2 = 0;
    int i , x , nr1 , nrprop , nr2;
    int contor , contor2;
    bool buton = true;

    printf("Enter car chassie for checking\n");

    scanf("%s" , s);

    system("cls");

    for( i = 1; i <= *nr ; i ++)
        if(strcmp(masina1[i].seria , s) == 0)
       {
            ok1 = 1;
            contor2 = i;
            printf("The car has been found\n");

            break;
       }

        if(ok1 == 0)
        {
                printf("The car has not been found\n");
                printf("Please insert 1 if you want to continue or 2 if you want to exit\n");

                scanf("%d" , &x);
                system("cls");
                if(x > 2)
                    while(buton)
                    {
                        printf("Inccorect input // Please repeat the action\n");
                        scanf("%d" , &x);
                        if(x == 1 || x == 2) buton = false;
                        system("cls");
                    }
                if(x == 2) exit(0);
        }

            printf("Please insert the driver ID\n");

            scanf("%s" , c);
            system("cls");
            for(i = 1 ; i <= *nr ; i ++)
                if(strcmp(persoana1[i].CNP , c) == 0)
                    {
                        ok2 = 1;
                        contor = i;
                        printf("The driver has been found\n");
                        break;
                    }

            if(ok2 == 0)
            {
                printf("The driver has not been found\n");

                printf("Please insert 1 if you want to continue or 2 if you want to exit\n");

                scanf("%d" , &x);
                system("cls");
                buton = true;
                    if(x > 2)
                        while(buton)
                        {
                            printf("Inccorect input // Please repeat the action\n");
                            scanf("%d" , &x);
                            if(x == 1 || x == 2) buton = false;
                            system("cls");
                        }
                    if(x == 2) exit(0);
            }


    if(ok1 == 0 && ok2 == 0)
    {
        system("cls");
        printf("The driver info will be added now // The procces will start in five seconds\n");
        printf("Please wait\n");

        sleep(5);
        system("cls");

        *nr = *nr + 1;
        nr1 = *nr;
        printf("Please enter driver CNP\n");
        scanf("%s" , c);
        persoana1[nr1].numar = nr1;
        strcpy(persoana1[nr1].CNP , c);
        fprintf(fpt,"%d, " , nr1);
        fprintf(fpt,"%s, ", c);
        system("cls");

        printf("Please enter driver's last name\n");
        scanf("%s" , c);
        strcpy(persoana1[nr1].nume , c);
        fprintf(fpt , "%s, " , c);
        system("cls");

        printf("Please enter driver first name\n");
        scanf("%s" , c);
        strcpy(persoana1[nr1].prenume , c);
        fprintf(fpt , "%s, " , c);
        system("cls");

        printf("Please enter driver adress\n");
        scanf("%s" , c);
        strcpy(persoana1[nr1].adresa1.Adresa , c);
        fprintf(fpt , "%s, " , c);
        system("cls");

        printf("Please enter driver home adress\n");
        scanf("%s" , c);
        strcpy(persoana1[nr1].adresa1.domiciliu , c);
        fprintf(fpt , "%s, " , c);
        system("cls");

        printf("Please enter driver street\n");
        scanf("%s" , c);
        strcpy(persoana1[nr1].adresa1.strada , c);
        fprintf(fpt , "%s, " , c);
        system("cls");

        printf("Please enter driver street number\n");
        scanf("%s" , c);
        strcpy(persoana1[nr1].adresa1.numar1 , c);
        fprintf(fpt , "%s, " , c);
        system("cls");

        printf("The driver has been added to the register\n");
        printf("The car will be added to the register in five seconds\n");
        printf("Please wait\n");
        sleep(5);
        system("cls");

        printf("Please insert the car brand\n");
        masina1[nr1].numar = nr1;
        fprintf(fpt,"%d, " , nr1);
        scanf("%s" , s);
        strcpy(masina1[nr1].marca , s);
        fprintf(fpt ,"%s, ", s);
        system("cls");

        printf("Please insert car chassie\n");
        scanf("%s" , s);
        strcpy(masina1[nr1].seria , s);
        fprintf(fpt , "%s, " , s);
        system("cls");

        printf("Please insert car registration number\n");
        scanf("%s" , s);
        strcpy(masina1[nr1].NrInmatriculare , s);
        fprintf(fpt , "%s, " , s);
        system("cls");

        printf("Please insert the number of car owners\n");
        scanf("%d" , &nrprop);
        masina1[nr1].NrProprietar = nrprop;
        fprintf(fpt , "%d, ", nrprop);
        system("cls");

        printf("The car has been added to the register\n");
        printf("The accident information will be added in five seconds\n");
        printf("Please wait\n");
        sleep(5);
        system("cls");

        printf("Please insert the number of accidents\n");
        scanf("%d" , &nr2);
        accidente1[nr1].numarac = nr2;
        fprintf(fpt , "%d, " , nr2);
        system("cls");

        printf("Please insert the date of the accident\n");
        scanf("%s", s);
        strcpy(accidente1[nr1].data , s);
        fprintf(fpt , "%s, " , s);
        system("cls");

        printf("Please insert the place of the accident\n");
        scanf("%s" , s);
        strcpy(accidente1[nr1].localitatea , s);
        fprintf(fpt , "%s, " , s);
        system("cls");

        printf("Please insert the damage value\n");
        scanf("%d" , &nr2);
        accidente1[nr1].daune = nr2;
        fprintf(fpt , "%d, " , nr2);
        system("cls");

        printf("The information have been added to the register\n");
        sleep(5);
    }
    if(ok1 == 0 && ok2 == 1)
    {
        system("cls");
        printf("Driver status - Known // Car status - Unknown\n");
        printf("The car will be added to the register in five seconds\n");
        printf("Please wait\n");
        sleep(5);
        system("cls");

        *nr = *nr + 1;
        nr1 = *nr;

        persoana1[nr1].numar = nr1;
        fprintf(fpt, "%d, " , nr1);
        fprintf(fpt, "%s, " , persoana1[contor].nume);
        fprintf(fpt, "%s, " , persoana1[contor].prenume);
        fprintf(fpt, "%s, " , persoana1[contor].adresa1.Adresa);
        fprintf(fpt, "%s, " , persoana1[contor].adresa1.domiciliu);
        fprintf(fpt, "%s, " , persoana1[nr1].adresa1.numar1);
        strcpy(persoana1[nr1].nume , persoana1[contor].nume);
        strcpy(persoana1[nr1].prenume , persoana1[contor].prenume);
        strcpy(persoana1[nr1].adresa1.Adresa , persoana1[contor].adresa1.Adresa);
        strcpy(persoana1[nr1].adresa1.domiciliu , persoana1[contor].adresa1.domiciliu);
        strcpy(persoana1[nr1].adresa1.strada , persoana1[contor].adresa1.numar1);

        printf("Please insert the car brand\n");
        masina1[nr1].numar = nr1;
        scanf("%s" , s);
        fprintf(fpt , "%s, " , s);
        strcpy(masina1[nr1].marca , s);
        system("cls");

        printf("Please insert the car chassies\n");
        scanf("%s" , s);
        fprintf(fpt , "%s, " , s);
        strcpy(masina1[nr1].seria , s);
        system("cls");

        printf("Please insert the car registration number\n");
        scanf("%s" , s);
        fprintf(fpt , "%s, " , s);
        strcpy(masina1[nr1].NrInmatriculare , s);
        system("cls");

        printf("Please insert the car number of owners");
        scanf("%d" , &nr2);
        fprintf(fpt , "%d, " , nr2);
        masina1[nr1].NrProprietar = nr2;
        system("cls");

        printf("The car and owner have been added to the register\n");
        printf("Owner status - known // Car status -known\n");
        printf("The accident will be added to the register in five seconds\n");
        printf("Please wait");
        sleep(5);
        system("cls");

        printf("Please insert the number of accidents\n");
        scanf("%d" , &nr2);
        accidente1[nr1].numarac = nr2;
        fprintf(fpt , "%d, " , nr2);
        system("cls");

        printf("Please insert the date of the accident\n");
        scanf("%s" , s);
        strcpy(accidente1[nr1].data , s);
        fprintf(fpt , "%s, " , s);
        system("cls");

        printf("Please insert the place of the accident\n");
        scanf("%s" , s);
        strcpy(accidente1[nr1].localitatea , s);
        fprintf(fpt , "%s, " , s);
        system("cls");

        printf("Please insert the damage cost of the accident");
        scanf("%d" , &nr2);
        accidente1[nr1].daune = nr2;
        fprintf(fpt , "%s, " , nr2);
        system("cls");

        printf("The information have been added to the register\n");
        sleep(5);
    }

    if(ok1 == 1 && ok2 == 0)
    {
        system("cls");
        printf("Driver status - Unknown // Car status - Known\n");
        printf("The driver will be added to the register in five seconds\n");
        printf("Please wait\n");
        sleep(5);
        system("cls");

        *nr = *nr + 1;
        nr1 = *nr;

        masina1[nr1].numar = nr1;
        fprintf(fpt , "%d, " , nr1);
        strcpy(masina1[nr1].marca , masina1[contor2].marca);
        fprintf(fpt , "%s, " , masina1[contor2].marca);
        strcpy(masina1[nr1].seria, masina1[contor2].seria);
        fprintf(fpt , "%s, " , masina1[contor2].seria);
        strcpy(masina1[nr1].NrInmatriculare , masina1[contor2].NrInmatriculare);
        fprintf(fpt, "%s, " , masina1[contor2].NrInmatriculare);
        masina1[nr1].NrProprietar =  masina1[contor2].NrProprietar;

        printf("The driver will be added to the register in five seconds\n");
        printf("Please wait\n");
        sleep(5);
        system("cls");

        printf("Please insert the driver id\n");
        persoana1[nr1].numar = nr1;
        scanf("%s" , s);
        strcpy(persoana1[nr1].CNP ,s);
        fprintf(fpt , "%s, " , s);
        system("cls");

        printf("Please insert the driver's last name\n");
        scanf("%s" , s);
        strcpy(persoana1[nr1].nume , s);
        fprintf(fpt , "%s, " , s);
        system("cls");

        printf("Please insert the driver's first name\n");
        scanf("%s" , s);
        strcpy(persoana1[nr1].prenume , s);
        fprintf(fpt , "%s, " , s);
        system("cls");

        printf("Please insert the adress of the driver\n");
        scanf("%s" , s);
        strcpy(persoana1[nr1].adresa1.Adresa , s);
        fprintf(fpt , "%s, ", s);
        system("cls");

        printf("Please insert the driver home adress\n");
        scanf("%s" , s);
        strcpy(persoana1[nr1].adresa1.domiciliu , s);
        fprintf(fpt , "%s, " , s);
        system("cls");

        printf("Please insert the driver street\n");
        scanf("%s" , s);
        strcpy(persoana1[nr1].adresa1.strada , s);
        fprintf(fpt , "%s, " , s);
        system("cls");

        printf("Please insert the street number\n");
        scanf("%s" , s);
        strcpy(persoana1[nr1].adresa1.strada , s);
        fprintf(fpt , "%s, " , s);
        system("cls");

        printf("The driver has been added to the register\n");
        printf("The accident will be added to the register in five seconds\n");
        printf("Please wait\n");
        sleep(5);
        system("cls");

        printf("Please insert the number of accidents\n");
        scanf("%d" , &nr2);
        accidente1[nr1].numarac = nr2;
        fprintf(fpt , "%d, " , nr2);
        system("cls");

        printf("Please insert the date of the accident\n");
        scanf("%s" , s);
        strcpy(accidente1[nr1].data , s);
        fprintf(fpt , "%s, " , s);
        system("cls");

        printf("Please insert the place of the accident\n");
        scanf("%s" , s);
        strcpy(accidente1[nr1].localitatea , s);
        fprintf(fpt , "%s, " , s);
        system("cls");

        printf("Please insert the damage cost of the accident");
        scanf("%d" , &nr2);
        accidente1[nr1].daune = nr2;
        fprintf(fpt , "%s, " , nr2);
        system("cls");

        printf("The information have been added to the register\n");
        sleep(5);
    }

    if(ok1 == 1 && ok2 == 1)
    {
        system("cls");
        printf("Driver status - Known // Car status - Known\n");
        printf("The accident will be added in five seconds\n");
        printf("Please wait\n");
        sleep(5);
        system("cls");

        printf("Please insert the accident\n");
        scanf("%d" , &nr2);
        accidente1[contor].numarac = nr2;
        system("cls");

        printf("Please insert the date of the accident\n");
        scanf("%s" , s);
        strcpy(accidente1[contor].data , s);
        system("cls");

        printf("Please insert the place of the accident\n");
        scanf("%s" , s);
        strcpy(accidente1[contor].localitatea , s);
        system("cls");

        printf("Please insert the damage cost of the accident");
        scanf("%d" , &nr2);
        accidente1[contor].daune = nr2;
        system("cls");

        RescrieFisier(contor , nr);

        printf("The information have been added to the register\n");
        sleep(5);


    }
    fclose(fpt);
}

void RescrieFisier(int nrcont , int limita)
{
    FILE *fpt;
    fpt = fopen("Book.csv" , "w+");

    int i;
    for(i = 1; i <= limita ; i ++)
    {
        if(i == nrcont)
        {
            fprintf(fpt ,"%d, " , persoana1[nrcont].numar);
            fprintf(fpt , "%s, " , persoana1[nrcont].CNP);
            fprintf(fpt , "%s, " , persoana1[nrcont].nume);
            fprintf(fpt , "%s, " , persoana1[nrcont].prenume);
            fprintf(fpt , "%s, " , persoana1[nrcont].adresa1.Adresa);
            fprintf(fpt , "%s, " , persoana1[nrcont].adresa1.domiciliu);
            fprintf(fpt , "%s, " , persoana1[nrcont].adresa1.strada);
            fprintf(fpt , "%s, " , persoana1[nrcont].adresa1.numar1);
            fprintf(fpt , "%d, " , masina1[nrcont].numar);
            fprintf(fpt , "%s, " , masina1[nrcont].marca);
            fprintf(fpt , "%s, " , masina1[nrcont].seria);
            fprintf(fpt , "%s, " , masina1[nrcont].NrInmatriculare);
            fprintf(fpt , "%d, " , masina1[nrcont].NrProprietar);
            fprintf(fpt , "%d, " , accidente1[nrcont].numarac);
            fprintf(fpt , "%s, " , accidente1[nrcont].data);
            fprintf(fpt , "%s, " , accidente1[nrcont].localitatea);
            fprintf(fpt , "%f, " , accidente1[nrcont].daune);
        } else
        {
            fprintf(fpt ,"%d, " , persoana1[i].numar);
            fprintf(fpt , "%s, " , persoana1[i].CNP);
            fprintf(fpt , "%s, " , persoana1[i].nume);
            fprintf(fpt , "%s, " , persoana1[i].prenume);
            fprintf(fpt , "%s, " , persoana1[i].adresa1.Adresa);
            fprintf(fpt , "%s, " , persoana1[i].adresa1.domiciliu);
            fprintf(fpt , "%s, " , persoana1[i].adresa1.strada);
            fprintf(fpt , "%s, " , persoana1[i].adresa1.numar1);
            fprintf(fpt , "%d, " , masina1[i].numar);
            fprintf(fpt , "%s, " , masina1[i].marca);
            fprintf(fpt , "%s, " , masina1[i].seria);
            fprintf(fpt , "%s, " , masina1[i].NrInmatriculare);
            fprintf(fpt , "%d, " , masina1[i].NrProprietar);
            fprintf(fpt , "%d, " , accidente1[i].numarac);
            fprintf(fpt , "%s, " , accidente1[i].data);
            fprintf(fpt , "%s, " , accidente1[i].localitatea);
            fprintf(fpt , "%f, " , accidente1[i].daune);
        }
        fprintf(fpt ,"\n");
    }
  fclose(fpt);
}
int main()
{

    // Citire date din csv , pe linii  si pe coloane
    int n;
    FILE* fp = fopen("Book.csv", "r");

    if (fp == NULL)
        {
            perror("Can't open the file.");
            exit(1);
        }
    else
        {
            char buffer[1024];

            int row = 0;
            int column = 0;

            while (fgets(buffer ,sizeof(buffer) , fp))
                {
                    column = 0;
                    row ++;

                    if (row == 1) continue;

                char* value = strtok(buffer, ",");

                while (value != NULL)
                    {
                        // Adaugam datele in structura

                        if(column == 0)
                        {
                                persoana1[row - 1].numar = atoi(value);
                                n = atoi(value);
                        }
                        else
                        if(column == 1) strcpy(persoana1[row - 1].CNP , value);
                        else
                        if(column == 2) strcpy(persoana1[row - 1].nume , value);
                        else
                        if(column == 3) strcpy(persoana1[row - 1].prenume , value);
                        else
                        if(column == 4) strcpy(persoana1[row - 1].adresa1.Adresa , value);
                        else
                        if(column == 5) strcpy(persoana1[row - 1].adresa1.domiciliu , value);
                        else
                        if(column == 6) strcpy(persoana1[row - 1].adresa1.strada , value);
                        else
                        if(column == 7) strcpy(persoana1[row - 1].adresa1.numar1 , value);
                        else
                        if(column == 8) masina1[row - 1].numar = atoi(value);
                        else
                        if(column == 9) strcpy(masina1[row - 1].marca , value);
                        else
                        if(column == 10) strcpy(masina1[row - 1].seria , value);
                        else
                        if(column == 11) strcpy(masina1[row - 1].NrInmatriculare , value);
                        else
                        if(column == 12) masina1[row - 1].NrProprietar = atoi(value);


                        printf("%s ", value);
                        value = strtok(NULL, ",");
                        column++;
                    }

                printf("\n");
               }

        fclose(fp);
    }

    for(int i = 1; i <= 3; i ++)
        printf("\n");

    printf("Apasati tasta 1 sau 2 pentru a selecta limba ///// Press 1 or 2 to select the language\n\n");

    int choice;
    int val , i;
    scanf("%d" , &choice);
    if(choice == 1 || choice == 2)
    {
        system("cls");
    }
    meniu(choice);
    AdaugAccident(&n);



    return 0;
}

