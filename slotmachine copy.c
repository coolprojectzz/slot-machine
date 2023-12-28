#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>



float slotmachine(float *money, float *minimum);
float horseracing(float *money, float *minimum);
float rewards(float *money, float *minimum);
//Horse races, prizes make different combos of winning orders
//make money a pointer and minimum and balance a pointer

int main(void){

    float *money, balance, *minimum;
    char choice;


    printf("||--------------------------------------||\n");
    printf("||                                      ||\n");
    printf("||                                      ||\n");
    printf("||                                      ||\n");
    printf("||         SLOT MACHINE MANIA           ||\n");
    printf("||                                      ||\n");
    printf("||                                      ||\n");
    printf("||                                      ||\n");
    printf("||______________________________________||\n");
    
    printf("\n\n\n WELCOME PLEASE ENTER SOME MONEY: ");
    scanf("\n%f", money);

    printf("\n Set Min bet amount\n ");
    scanf("\n%f", minimum);

    
    
    while (choice != 'Q'){

        printf("\n\nChoose a choice, R = Rewards, H = Race Horses P = Play Slots, C = Check Balance, Q = Cash Out: ");

        scanf("\n %c", &choice);

            if (choice == 'R'){
                rewards(money, minimum);
                
            }


        
            if (choice == 'H' && *money >= *minimum){
                horseracing(money, minimum);
                
            }
           
        
            if (choice == 'P' && *money >= *minimum){
                slotmachine(money, minimum);
                
            }


            if (choice == 'C'){
                printf("\n\nYou have a Balance of %.2f Dollar(s)\n ", *money);
            }

    }   

    printf("\n\nGOODBYE Degenerate! See you soon!");

return 0;
}


float slotmachine(float *money, float *minimum){

    char slot_choice;

    printf("Time to Gamble!!");
    printf("\n\nYou have a Balance of %.2f Dollar(s)\n ", *money);
    
    srand(time(0));

    

        while (slot_choice!= 'Q'){

            printf("\n\nChoose a choice P = Play, Q = Quit to Home: ");

            scanf("\n %c", &slot_choice);

            
            if (slot_choice == 'P' && *money >= *minimum){
                *money = *money - *minimum;
                
            

                int num1 = (rand() % 20) + 1;
                int num2 = (rand() % 20) + 1;
                int num3 = (rand() % 20) + 1;

                
                printf("\n     |%d| |%d| |%d|  \n", num1, num2, num3);
                if (num1 == num2 && num2 == num3)
                    *money += *minimum * 20;

                if (num1 == num2 || num2 == num3 || num1 == num3)
                    *money += *minimum * 5;

                if (num1 == 10 || num2 == 10 || num3 == 10)
                    *money += *minimum * 1.5;

                if (num1 == 10 && num2 == 10 && num3 == 10)
                    *money += *minimum * 10;

                if (num1 == 20 && num2 == 20 && num3 == 20)
                    *money += *minimum * 50;

                printf("\n\nYou have a Balance of %.2f Dollar(s)\n ", *money);
                printf("\n\n");
            }
    }


    return *money;
    
  
}


float horseracing(float *money, float *minimum){

    char horse_choice;
    int horse_bet_on;

    printf("\n\nLets race some horses!\n ");
    printf("\n\nYou have a Balance of %.2f Dollar(s)\n ", *money);

    srand(time(0));

    
    

        while (horse_choice!= 'Q'){

            printf("\n\nChoose a choice P = Play, Q = Quit to Home: ");

            scanf("\n %c", &horse_choice);

            
            if (horse_choice == 'P' && *money >= *minimum){
                *money = *money - *minimum;
                
                printf("\nPick a Horse to bet on 1-5:  ");
                scanf("%d", &horse_bet_on);

                int num = (rand() % 5) + 1;
                
                    if (horse_bet_on == num)
                        *money += *minimum * 10;

                
                printf("\n\n The correct Horse was Horse %d ", num);

                printf("\n\nYou have a Balance of %.2f Dollar(s)\n ", *money);
                printf("\n\n");
            }
    }


    return *money;
    

}


float rewards(float *money, float *minimum){

    printf("Here are the prizes! ");
    printf("\n\nYou have a Balance of %.2f Dollar(s)\n ", *money);
    exit(0);

}