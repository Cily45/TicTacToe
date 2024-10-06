//
// Created by cily on 05/10/24.
//
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "tic-tac-toe.h"

int main(void) {
    char grid[3][3];
    initGrid(grid);
    while (true) {
        system("clear");
        int posPlayer = 0;
        printGrid(grid);
        printf("Veuiller choisir une case où jouer: ");
        scanf("%d", &posPlayer);
        printf("\n\n\n");
        if (isValidAction(posPlayer, grid)) {
            setPos('X', posPlayer, grid);
            if (isNull(grid)) {
                printGrid(grid);
                printf("Match nul");
                break;
            }
            if (isWin('X', grid)) {
                printGrid(grid);
                printf("Félicitation, vous avez gagnez!");
                break;
            }
            if (grid[1][1] == ' ') {
                setPos('O', 4, grid);
            } else {
                int botPos = botWin(grid, 'O');

                if (botPos == 9) {
                    botPos = botWin(grid, 'X');
                }
                if (botPos == 9) {
                    botPos = botPlay(grid);
                }
                setPos('O', botPos, grid);
            }

            if (isWin('O', grid)) {
                printGrid(grid);
                printf("Dommage, vous avez perdu");
                break;
            }
            if (isNull(grid)) {
                printGrid(grid);
                printf("Match nul");
                break;
            }
        }
    }

    return 0;
}
