#include <stdio.h>
#include <stdlib.h>

void drawField(int field[3][3])
{
    printf("\n\n");
    for (int row = 0; row < 3; row++)
    {
        for (int column = 0; column < 3; column++)
        {
            printf(" %d", field[row][column]);
            if (column != 2)
            {
                printf(" |");
            }
        }
        // Add new line for row
        printf("\n");
        if (row != 2)
        {
            printf("-----------\n");
        }
    }
    printf("\n\n");
}

void newTurn(int field[3][3], int player)
{
    _Bool valid = 0;
    int row, column;
    printf("Player %i's turn. Please input field (row colum): ", player);

    do
    {
        scanf("%d %d", &row, &column);

        // check if field is free
        if (field[row][column] == 0)
        {
            valid = 1;
        }
        else
        {
            printf("Field already used. Please input another field. ");
        }
    } while (valid == 0);

    field[row][column] = player;
}

int checkWinner(int field[3][3])
{
    // Check columns
    for (int col = 0; col < 3; col++)
    {
        if ((field[0][col] == field[1][col]) && (field[1][col] == field[2][col]) && field[1][col] != 0)
        {
            printf("%d %d %d", field[0][col], field[1][col], field[2][col]);
            return field[0][col];
        }
    }

    // Check rows
    for (int row = 0; row < 3; row++)
    {
        if ((field[row][0] == field[row][1]) && (field[row][1] == field[row][2]) && field[row][1] != 0)
        {
            return field[row][0];
        }
    }

    // Check dianogals
    if ((field[0][0] == field[1][1]) && (field[1][1] == field[2][2]) && field[1][1] != 0)
    {
        return field[0][0];
    }
    else if ((field[0][2] == field[1][1]) && (field[1][1] == field[2][0]) && field[1][1] != 0)
    {
        return field[0][2];
    }

    // Check for tie
    for (int row = 0; row < 3; row++)
    {
        for (int column = 0; column < 3; column++)
        {
            if (field[row][column] == 0)
            {
                // field not completely filled yet, not a tie
                return 0;
            }
        }
    }

    // field complete, tie
    return -1;
}

int main()
{
    int field[3][3] = {0}; // initialize empty field array

    drawField(field);
    int player = 1;

    while (1 == 1)
    {
        newTurn(field, player);
        drawField(field);

        // update player
        switch (player)
        {
        case 1:
            player = 2;
            break;
        case 2:
            player = 1;
            break;
        }

        int result = checkWinner(field);

        if (result == -1)
        {
            printf("Tie!");
            break;
        }
        else if (result != 0)
        {
            printf("Player %d wins!", result);
            break;
        }
    }

    return 0;
}