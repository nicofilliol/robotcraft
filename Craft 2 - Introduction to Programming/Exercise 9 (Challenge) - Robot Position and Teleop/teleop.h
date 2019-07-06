int **createMap();
void drawMap(int **map);
Position *initalizeRobot(int **map);
void moveRobotToPosition(int **map, Position old, Position new);
void moveUp(int **map, Position *pos);
void moveDown(int **map, Position *pos);
void moveRight(int **map, Position *pos);
void moveLeft(int **map, Position *pos);
