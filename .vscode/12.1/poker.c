#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Card(int num){
    char* topleft = "┌";
    char* topright = "┐";
    char* bottomleft = "└";
    char* bottomright = "┘";
    char* horizontal = "─";
    char* vertical = "│";
    char* space = " ";
    char* spade = "♠";
    char* clover = "♣";
    char* diamond = "◆";
    char* heart = "♥";
    char* ace = "A";
    int i, j;
    int pattern = num / 10;
    int number = num % 10 + 1;

    printf("%s", topleft);
    for (i = 0; i < 9; i++){
        printf("%s", horizontal);
    }
    printf("%s\n", topright);

    for (i = 0; i < 9; i++){
        printf("%s", vertical);
        for (j = 0; j < 9; j++){
            if(number == 1 && ((i == 0 && j == 0) || (i == 8 && j == 8)))
                printf("%s", ace);
            else if ((number >= 2 && number <= 9) && ((i == 0 && j == 0) || (i == 8 && j == 8)))
                printf("%d", number);
            else if(number == 10 && ((i == 0 && j == 0) || (i == 8 && j == 7)))
                printf("1");
            else if(number == 10 && ((i == 0 && j == 1) || (i == 8 && j == 8)))
                printf("0");
            else if (number == 1 && (i == 4 && j == 4))
                printf("%s", spade);
            else if (number == 2 && ((i == 1 && j == 4) || (i == 7 && j == 4)))
                printf("%s", spade);
            else if (number == 3 && ((i == 1 && j == 4) || (i == 4 && j == 4) || (i == 7 && j == 4)))
                printf("%s", spade);
            else if (number == 4 && ((i == 1 && j == 2) || (i == 1 && j == 6) || (i == 7 && j == 2) || (i == 7 && j == 6)))
                printf("%s", spade);
            else if (number == 5 && ((i == 1 && j == 2) || (i == 1 && j == 6) || (i == 4 && j == 4) || (i == 7 && j == 2) || (i == 7 && j == 6)))
                printf("%s", spade);
            else if (number == 6 && ((i == 1 && j == 2) || (i == 1 && j == 6) || (i == 4 && j == 2) || (i == 4 && j == 6) || (i == 7 && j == 2) || (i == 7 && j == 6)))
                printf("%s", spade);
            else if (number == 7 && ((i == 1 && j == 2) || (i == 1 && j == 6) || (i == 2 && j == 4) || (i == 4 && j == 2) || (i == 4 && j == 6) || (i == 7 && j == 2) || (i == 7 && j == 6)))
                printf("%s", spade);
            else if (number == 8 && ((i == 1 && j == 2) || (i == 1 && j == 6) || (i == 2 && j == 4) || (i == 4 && j == 2) || (i == 4 && j == 6) || (i == 6 && j == 4) || (i == 7 && j == 2) || (i == 7 && j == 6)))
                printf("%s", spade);
            else if (number == 9 && ((i == 1 && j == 2) || (i == 1 && j == 6) || (i == 3 && j == 2) || (i == 3 && j == 6) || (i == 4 && j == 4) || (i == 5 && j == 2) || (i == 5 && j == 6) || (i == 7 && j == 2) || (i == 7 && j == 6)))
                printf("%s", spade);
            else if (number == 10 && ((i == 1 && j == 2) || (i == 1 && j == 6) || (i == 2 && j == 4) || (i == 3 && j == 2) || (i == 3 && j == 6) || (i == 5 && j == 2) || (i == 5 && j == 6) || (i == 6 && j == 4) || (i == 7 && j == 2) || (i == 7 && j == 6)))
                printf("%s", spade);
            else
                printf("%s", space);
        }
        printf("%s\n", vertical);
    }

    printf("%s", bottomleft);
    for (i = 0; i < 9; i++){
        printf("%s", horizontal);
    }
    printf("%s\n", bottomright);
}

int main(){
    srand(time(NULL));
    int usr[3];
    int cpt[3];

    while(1){
        usr[0] = rand() % 10 + 10;
        usr[1] = rand() % 10 + 10;
        usr[2] = rand() % 10 + 10;

        cpt[0] = rand() % 10 + 10;
        cpt[1] = rand() % 10 + 10;
        cpt[2] = rand() % 10 + 10;

        if(usr[0] == usr[1] || usr[0] == usr[2] || usr[0] == cpt[0] || usr[0] == cpt[1] || usr[0] == cpt[2] || usr[1] == usr[2] || usr[1] == cpt[0] || usr[1] == cpt[1] || usr[1] == cpt[2] || usr[2] == cpt[0] || usr[2] == cpt[1] || usr[2] == cpt[2] || cpt[0] == cpt[1] || cpt[0] == cpt[2] || cpt[1] == cpt[2]){
            continue;
        }
        else
            break;
    }

    Card(usr[0]);
    Card(usr[1]);
    Card(usr[2]);
    Card(cpt[0]);
    Card(cpt[1]);
    Card(cpt[2]);
    printf("usr: %d %d %d\n", usr[0], usr[1], usr[2]);
    printf("cpt: %d %d %d\n", cpt[0], cpt[1], cpt[2]);

    return 0;
}