#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rand_number, usernumber = -1, max_tries = 10;

    srand(time(NULL));
    rand_number = rand() % 256 + 1; 
    printf("I have a number in my mind between 1 and 256! Can you guess it?\n");
    printf("Provide me your guess: ");

    int corr = 0;
        while(corr == 0) {

            if(scanf("%d", &usernumber) != 1) {

                printf("You are not playing with quality!\n");
                exit(1);
            }else {
                if(usernumber > 0 && usernumber <= 256) {

                    corr = 1;
                    --max_tries ;
                }else {

                    printf("Your number isn't between 0 and 256!Try again please.\n\nYour guess: ");
                }
            }
        }

    int found = 0;
        while(found == 0 && max_tries > 0) {

            if(rand_number == usernumber) {
                
                printf("Remaining tries: %d\n\nYou guessed it right after %d tries!\nMy number was [%d]!\n", max_tries, (10 - max_tries), rand_number);
                found = 1;
            }else if(usernumber > rand_number) {

                if(max_tries == 1) {

                    printf("My number is smaller than %d!\nBe careful, is your last chance!", usernumber);
                    printf("\n\nYour guess: ");
                }else {

                    printf("My number is smaller than %d!\nRemaining tries: %d", usernumber, max_tries);
                    printf("\n\nYour guess: ");
                }
            }else if(usernumber < rand_number) {

                if(max_tries == 1) {

                    printf("My number is larger than %d!\nBe careful, is your last chance!", usernumber);
                    printf("\n\nYour guess: ");
                }else {

                    printf("My number is larger than %d!\nRemaining tries: %d", usernumber, max_tries);
                    printf("\n\nYour guess: ");
                }
            }

            if(found != 1) {
                int corr = 0;
                while(corr == 0) {

                    scanf("%d", &usernumber);
                    if(usernumber >= 0 && usernumber <= 256) {

                        corr = 1;
                    }else {

                        printf("Your number isn't between 0 and 256!Try again please.\n\nYour guess: ");
                    }
                }
            }

            if(found != 1) {
                --max_tries ;
            }
        }

        if(max_tries == 0) {
            
            if(usernumber > rand_number) {
                int ans;

                printf("My number is smaller than %d!\n", usernumber);
                printf("~GAME OVER~\nYour ran out of tries!\n\nDo you want me to show you my number?If yes type '1' else type '0'.\nType here: ");
                scanf("%d", &ans);

                if(ans == 1) {

                    printf("My number was [%d]!\n", rand_number);
                }else {

                    printf("Understandable!\n");
                }
            }else if(usernumber < rand_number) {
                int ans;

                printf("My number is larger than %d !\n", usernumber);
                printf("~GAME OVER~\nYour ran out of tries!\n\nDo you want me to show you my number?If yes type '1' else type '0'.\nType here: ");
                scanf("%d", &ans);

                if(ans == 1) {

                    printf("My number was [%d]!\n", rand_number);
                }else {

                    printf("Understandable!\n");
                }
            }else if(usernumber == rand_number) {

                printf("\nYou like playing risky uh?\n");
                printf("You guessed it right after %d tries!\nMy number was [%d] !\n",(10 - max_tries), rand_number);
            }
        }else if(max_tries == 9) {

            printf("Are you an NPC ?\n");
        }

    printf("Thanks for playing with me!");
    return 0;
}