#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Select randomly a number between MIN and MAX that player must guess !*/
void    less_or_big(const int MIN, const int MAX)
{
    int    rand_nbr, pl_nbr, i;

    rand_nbr = pl_nbr = i = 0;
    srand(time(NULL));
    rand_nbr = (rand() % (MAX - MIN + 1)) + MIN;

    do
    {
        printf("Choose a number between %d and %d to find the random number : ", MIN, MAX);
        scanf("%d", &pl_nbr);
        printf("\n");
        ++i;

        if(pl_nbr < rand_nbr)
            printf("%d is too small.\n", pl_nbr);
        else if(pl_nbr > rand_nbr)
            printf("%d is too big.\n", pl_nbr);
    } while(pl_nbr != rand_nbr);
    printf("Congratulation you find %d in %d beats!\n", rand_nbr, i);
}

/*One player choose a number the other try to guess it !*/
void     two_players(void)
{
        int    mystery_nbr = 0, pl_nbr = 0, i = 0;

            printf("Put a nbr : ");
            scanf("%d", &mystery_nbr);
            printf("\n");

            do
            {
                printf("Guess the number choosen by your partner : ");
                scanf("%d", &pl_nbr);
                printf("\n");
                ++i;

                if(pl_nbr < mystery_nbr)
                    printf("%d is too small\n", pl_nbr);
                else if(pl_nbr > mystery_nbr)
                    printf("%d is too big\n");
            } while(mystery_nbr != pl_nbr);
            printf("Congratulation you find %d in %d beats", mystery_nbr, i);
}

/*Just a main loop with menu, use and re-use tmp for menu choices and navigation*/
int    main()
{
    int    tmp = 0;

    do
    {
        printf("(1) One player\n(2) Two players\nChoose : ");
        scanf("%d", &tmp);
        printf("\n");

        switch(tmp)
        {
            case 1:
                printf("(1) Easy\n(2) Normal\n(3) Hard\nChoose : ");
                scanf("%d", &tmp);

                switch(tmp)
                {
                    case 1:
                        less_or_big(1, 100);
                        break;
                        
                    case 2:
                        less_or_big(1, 1000);
                        break;

                    case 3:
                        less_or_big(1, 10000);
                        break;

                    default:
                        printf("Error must be 1, 2 or 3\n");
                }
                break;

            case 2:
                two_players();
                break;

            default:
                printf("Error must be 1 or 2\n");
        }
    printf("(0) leave (>0) stay\nDo you want to play another game ? : ");
    scanf("%d", &tmp);
    printf("\n");
    } while(tmp);

    printf("Come back another time !\n");
    return 0;
}