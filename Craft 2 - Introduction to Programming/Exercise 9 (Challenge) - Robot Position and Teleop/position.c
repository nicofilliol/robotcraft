#include "position.h"

void printPosition(Position *position)
{
    Position posVal = *position;
    printf("Robot Position: x = %d, y = %d\n", posVal.x, posVal.y);
}

Position *createPosition(int x, int y)
{
    Position *position = (Position *)malloc(sizeof(Position) * 2);
    (*position).x = x;
    (*position).y = y;
    return position;
}

void destroyPosition(Position *position)
{
    free(position);
}

float distancePositions(Position position, Position target)
{
    // Distance is Hypothenuse
    return sqrt(pow(position.x - target.x, 2) + pow(position.y - target.y, 2));
}

Position **generateArrayOfPositions(int size)
{
    Position **arr = (Position **)malloc(sizeof(Position) * size);

    for (int i = 0; i < size; i++)
    {
        // Set random state
        srand(time(0) + i); // HOWTO GET DIFFERENT RANDOM VALUES?
        int randX = rand() % 11;
        int randY = rand() % 11;

        Position **tempArr = arr + i;

        // Add value to array
        *tempArr = createPosition(randX, randY);
    }

    return arr;
}

void destroyArrayOfPositions(Position *arr)
{
}
