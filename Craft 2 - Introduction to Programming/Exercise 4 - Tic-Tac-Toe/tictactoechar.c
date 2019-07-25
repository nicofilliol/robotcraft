#include <stdio.h>
#include <stdlib.h>

char board[3][3];

void initializeBoard()
{
    /* initialize matrix */
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            board[x][y] = ' ';
        }
    }
}

void drawBoard()
{
    printf("\n\n");
    for (int row = 0; row < 3; row++)
    {
        for (int column = 0; column < 3; column++)
        {
            printf(" %c", board[row][column]);
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

void newTurn(int player)
{
    _Bool valid = 0;
    int row, column;
    printf("Player %i's turn. Please input board (row colum): ", player);

    do
    {
        scanf("%d %d", &row, &column);

        // check if board is free
        if (board[row][column] == ' ')
        {
            valid = 1;
        }
        else
        {
            printf("board already used. Please input another board. ");
        }
    } while (valid == 0);

    if (player == 1)
    {
        board[row][column] = 'X';
    }
    else if (player == 2)
    {
        board[row][column] = 'O';
    }
    // Update board
}

int checkWinner()
{
    // Check columns
    for (int col = 0; col < 3; col++)
    {
        if ((board[0][col] == board[1][col]) && (board[1][col] == board[2][col]) && board[1][col] != ' ')
        {
            printf("%d %d %d", board[0][col], board[1][col], board[2][col]);
            return board[0][col];
        }
    }

    // Check rows
    for (int row = 0; row < 3; row++)
    {
        if ((board[row][0] == board[row][1]) && (board[row][1] == board[row][2]) && board[row][1] != ' ')
        {
            return board[row][0];
        }
    }

    // Check dianogals
    if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && board[1][1] != ' ')
    {
        return board[0][0];
    }
    else if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && board[1][1] != ' ')
    {
        return board[0][2];
    }

    // Check for tie
    for (int row = 0; row < 3; row++)
    {
        for (int column = 0; column < 3; column++)
        {
            if (board[row][column] == ' ')
            {
                // board not completely filled yet, not a tie
                return 0;
            }
        }
    }

    // board complete, tie
    return -1;
}

void startGame()
{
    int player = 1;

    while (1 == 1)
    {
        newTurn(player);
        drawBoard();

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

        int result = checkWinner(board);

        if (result == -1)
        {
            printf("Tie!");
            break;
        }
        else if (result != 0)
        {
            printf("Player %c wins!", result);
            break;
        }
    }
}

int main()
{
    initializeBoard();
    drawBoard();

    startGame();

    return 0;
}