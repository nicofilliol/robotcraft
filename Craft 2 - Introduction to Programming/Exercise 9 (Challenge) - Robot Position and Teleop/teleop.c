#include <stdio.h>
#include <stdlib.h>
#include "position.h"
#define MAP_DIM 25

void drawMap(int **map)
{
    //printf("\033[H\033[J");
    system("clear");
    for (int i = 0; i < MAP_DIM; i++)
    {
        for (int j = 0; j < MAP_DIM; j++)
        {
            if (map[i][j] == 8)
            {
                printf("\033[0;31m");
                printf("8 ");
                printf("\033[0m");
            }
            else if (map[i][j] == 1)
            {
                printf("\033[0;33m");
                printf("1 ");
                printf("\033[0m");
            }
            else
            {
                printf("%d ", map[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n\n");
}

int **createMap()
{
    srand(time(0));
    int **map = (int **)malloc(sizeof(int *) * MAP_DIM);

    for (int i = 0; i < MAP_DIM; i++)
    {
        map[i] = (int *)malloc(sizeof(int) * MAP_DIM);
    }

    for (int i = 0; i < MAP_DIM; i++)
    {
        for (int j = 0; j < MAP_DIM; j++)
        {
            int num = rand() % 100;

            if (num < 20)
            {
                map[i][j] = 1;
            }
            else
            {
                map[i][j] = 0;
            }
        }
    }

    return map;
}

Position *initalizeRobot(int **map)
{
    int randRow, randColumn;
    srand(time(0));

    do
    {
        randRow = rand() % MAP_DIM;
        randColumn = rand() % MAP_DIM;
    } while (map[randRow][randColumn] == 1); // check for wall

    map[randRow][randColumn] = 8;
    Position *position = createPosition(randColumn, randRow);

    drawMap(map);
    return position;
}

void moveRobotToPosition(int **map, Position old, Position new)
{
    map[old.y][old.x] = 0;
    map[new.y][new.x] = 8;
}

void moveUp(int **map, Position *pos)
{
    Position *newPos = createPosition(pos->x, pos->y - 1);
    if (newPos->y >= 0 && map[newPos->y][newPos->x] != 1)
    {
        moveRobotToPosition(map, *pos, *newPos);
        pos->y -= 1; // Update pointer
    }
}

void moveDown(int **map, Position *pos)
{
    Position *newPos = createPosition(pos->x, pos->y + 1);
    if (newPos->y < MAP_DIM && map[newPos->y][newPos->x] != 1)
    {
        moveRobotToPosition(map, *pos, *newPos);
        pos->y += 1; // Update pointer
    }
}

void moveRight(int **map, Position *pos)
{
    Position *newPos = createPosition(pos->x + 1, pos->y);
    if (newPos->x < MAP_DIM && map[newPos->y][newPos->x] != 1)
    {

        moveRobotToPosition(map, *pos, *newPos);
        pos->x += 1; // Update pointer
    }
}

void moveLeft(int **map, Position *pos)
{
    Position *newPos = createPosition(pos->x - 1, pos->y);
    if (newPos->x >= 0 && map[newPos->y][newPos->x] != 1)
    {

        moveRobotToPosition(map, *pos, *newPos);
        pos->x -= 1; // Update pointer
    }
}