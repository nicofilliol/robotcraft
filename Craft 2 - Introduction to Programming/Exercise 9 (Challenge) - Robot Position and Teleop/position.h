#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

typedef struct
{
    int x, y;
} Position;

void printPosition(Position *position);
Position *createPosition(int x, int y);
void destroyPosition(Position *position);
float distancePositions(Position position, Position target);
Position **generateArrayOfPositions(int size);
