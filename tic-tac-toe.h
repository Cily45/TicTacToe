#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#endif //TIC_TAC_TOE_H

// corriger le bot tricheur
void initGrid(char grid[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid[i][j] = ' ';
        }
    }
}

bool isWin(char player, char grid[3][3]) {
    //check line
    for (int i = 0; i < 3; i++) {
        int count = 0;
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] == player) {
                count++;
            }
        }
        if (count == 3) {
            return true;
        }
    }
    //check column
    for (int j = 0; j < 3; j++) {
        int count = 0;
        for (int i = 0; i < 3; i++) {
            if (grid[i][j] == player) {
                count++;
            }
        }
        if (count == 3) {
            return true;
        }
    }
    //check diagonal left
    if (grid[0][0] == player && grid[1][1] == player && grid[2][2] == player) {
        return true;
    }
    //check diagonal right
    if (grid[0][2] == player && grid[1][1] == player && grid[2][0] == player) {
        return true;
    }

    return false;
}

void printGrid(char grid[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 2) {
                printf(" %c \n", grid[i][j]);
            } else {
                printf(" %c |", grid[i][j]);
            }
        }
        if (i != 2) {
            printf("-----------\n");
        }
    }
    printf("\n\n\n");
}

bool isValidAction(int pos, char grid[3][3]) {
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (pos == count && grid[i][j] == ' ') {
                return true;
            }
            count++;
        }
    }
    return false;
}

bool isNull(char grid[3][3]) {
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] == ' ') {
                count++;
            }
        }
    }
    return count == 0;
}

int botWin(char grid[3][3], char player) {
    // line
    int command[3][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};

    //line
    for (int i = 0; i < 3; i++) {
        int empty = 0;
        int count = 0;
        int emptyPos = 0;
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] == player) {
                count++;
            } else if (grid[i][j] == ' ') {
                empty++;
                emptyPos = command[i][j];
            }
        }
        if (count == 2 && empty == 1) {
            return emptyPos;
        }
    }

    // column
    for (int j = 0; j < 3; j++) {
        int empty = 0;
        int count = 0;
        int emptyPos = 0;
        for (int i = 0; i < 3; i++) {
            if (grid[i][j] == player) {
                count++;
            } else if (grid[i][j] == ' ') {
                empty++;
                emptyPos = command[i][j];
            }
        }
        if (count == 2 && empty == 1) {
            return emptyPos;
        }
    }
    // diagonal left
    int empty = 0;
    int pos = 0;
    int count = 0;
    if (grid[0][0] == player) {
        count++;
    } else if (grid[0][0] == ' ') {
        empty++;
        pos = command[0][0];
    }
    if (grid[1][1] == player) {
        count++;
    } else if (grid[1][1] == ' ') {
        empty++;
        pos = command[1][1];
    }
    if (grid[2][2] == player) {
        count++;
    } else if (grid[2][2] == ' ') {
        empty++;
        pos = command[2][2];
    }
    if (count == 2 && empty == 1) {
        return pos;
    }
    // diagonal right
    count = 0;
    empty = 0;
    if (grid[0][2] == player) {
        count++;
    } else if (grid[0][2] == ' ') {
        empty++;
        pos = command[0][2];
    }
    if (grid[1][1] == player) {
        count++;
    } else if (grid[1][1] == ' ') {
        empty++;
        pos = command[1][1];
    }
    if (grid[2][0] == player) {
        count++;
    } else if (grid[2][0] == ' ') {
        empty++;
        pos = command[2][0];
    }
    if (count == 2 && empty == 1) {
        return pos;
    }
    return 9;
}


int botPlay(char grid[3][3]) {
    int pos = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] == ' ') {
                return pos;
            }
            pos++;
        }
    }
    return 9;
}

void setPos(char player, int pos, char grid[3][3]) {
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (count == pos) {
                grid[i][j] = player;
            }
            count++;
        }
    }
}
