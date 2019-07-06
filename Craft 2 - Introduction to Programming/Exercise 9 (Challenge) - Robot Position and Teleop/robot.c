#include <stdio.h>
#include <stdlib.h>
#include "position.h"
#include "teleop.h"

int main()
{

    /*
    Position *position = createPosition(50, 100);
    printPosition(position);

    printPosition(position);

    Position *target = createPosition(50, 50);
    printf("%.2f\n", distancePositions(*position, *target));

    Position **arr;

    arr = generateArrayOfPositions(10);

    for (int i = 0; i < 10; i++)
    {
        printPosition(*(arr + i));
    }

    destroyPosition(position);
    */

    int **map = createMap();

    Position *robotPosition = initalizeRobot(map);

    for (int i = 0; i < 1000; i++)
    {
        char inp;
        inp = getc(stdin);

        switch (inp)
        {
        case 'w':
            moveUp(map, robotPosition);
            break;
        case 'd':
            moveRight(map, robotPosition);
            break;
        case 's':
            moveDown(map, robotPosition);
            break;
        case 'a':
            moveLeft(map, robotPosition);
            break;
        default:
            break;
        }
        drawMap(map);
    }

    moveUp(map, robotPosition);

    return 0;
}