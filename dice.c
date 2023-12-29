// Simulation based on the game of Saotome Mary, in "Kakegurui Twin" Episode 2.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_THROWS 100000

int main(int argc, char const *argv[])
{
    srand(time(NULL));
 
    int red_dice[3]   = {2, 6, 7};
    int black_dice[3] = {3, 4, 8};
    int white_dice[3] = {1, 5, 9};

    int red_throw, black_throw, white_throw;

    int rb_av = 0;
    int bw_av = 0;
    int wr_av = 0;

    for (size_t i = 0; i < NUM_OF_THROWS; i++)
    {
        red_throw = red_dice[rand()%3];
        black_throw = black_dice[rand()%3];
        white_throw = white_dice[rand()%3];

        if (red_throw > black_throw) rb_av++;
        else rb_av--;

        if (black_throw > white_throw) bw_av++;
        else bw_av--;

        if (white_throw > red_throw) wr_av++;
        else wr_av--;
    }
    
    printf("R/B Average = %d\n", rb_av);
    printf("B/W Average = %d\n", bw_av);
    printf("W/R Average = %d\n", wr_av);

    return 0;
}
