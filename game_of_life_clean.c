#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#define CURRENTOS 0
#include <windows.h>
#endif

#ifdef linux
#define CURRENTOS 1
#include <unistd.h>
#endif

#define FX 20
#define FY 15

int countNeighbors(int field[FY][FX], int y, int x)
{
    int n = 0;

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0) continue;

            // Magic to :
            // 1. Keep the indexes inbound
            // 2. Loop the field
            // 3. The `+ FY` and `+ FX` are important because the % isn't always positive
            int neighborY = (y + i + FY) % FY;
            int neighborX = (x + j + FX) % FX;

            if (field[neighborY][neighborX]) n++;
        }
    }

    return n;
}

int main()
{
    int field[FY][FX] = {};
    int neighbors[FY][FX] = {};

    // Initial state
    // field[6][10] = 1;
    // field[7][11] = 1;
    // field[8][9] = 1;
    // field[8][10] = 1;
    // field[8][11] = 1;

    // Random initial state
    srand(time(NULL));
    for (int y = 0; y < FY; y++)
        for (int x = 0; x < FX; x++)
            field[y][x] = rand() % 2;

    while (1)
    {
        // Clear the screen
        printf("\e[1;1H\e[2J");

        // Display the field
        for (int i = 0; i < FY; i++)
        {
            for (int j = 0; j < FX; j++)
            {
                printf("%c ", ".#"[field[i][j]]);
            }
            printf("\n");
        }
        
        // Computing the amount of neighbors
        for (int y = 0; y < FY; y++)
        {
            for (int x = 0; x < FX; x++)
            {
                neighbors[y][x] = countNeighbors(field, y, x);
            }
        }

        // Computing the new field
        for (int i = 0; i < FY; i++)
        {
            for (int j = 0; j < FX; j++)
            {
                if (field[i][j]) 
                    field[i][j] = (neighbors[i][j] == 2 || neighbors[i][j] == 3) ? 1 : 0;
                else
                    field[i][j] = (neighbors[i][j] == 3) ? 1 : 0;
            }
        }

        if (CURRENTOS) sleep(0.025);
        else Sleep(25);
    }
}
