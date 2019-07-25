typedef struct
{
    float x;
    float y;
    float theta;
} Position;

// Global variable for robot position
Position robotPosition = {0.0, 0.0, 0.0};

void setup()
{
    Serial.begin(9600);

    int r = 5;
    int b = 20;
    int C = 100; // Pulses per revolution

    int oldEncL, oldEncR;
    oldEncL = 0;
    oldEncR = 0;
    int newEncL, newEncR;
    int diffL, diffR;

    for (int i = 0; i < 10; i++)
    {
        int *encVals;
        encVals = encUpdate(i);
        newEncL = encVals[0];
        newEncR = encVals[1];

        diffL = newEncL - oldEncL;
        diffR = newEncR - oldEncR;

        oldEncL = newEncL;
        oldEncR = newEncR;

        poseUpdate(diffL, diffR, r, b, C);

        // Print robotPosition
        Serial.print("Step ");
        Serial.print(i + 1);
        Serial.print(", x: ");
        Serial.print(robotPosition.x);
        Serial.print(", y: ");
        Serial.print(robotPosition.y);
        Serial.print(", theta: ");
        Serial.println(robotPosition.theta * 180 / M_PI);
    }
}

void loop()
{
    // Code that is repeated infinitely
}

int *encUpdate(int t)
{
    static int matrix[10][2] = {
        {0, 0},
        {100, 100},
        {300, 200},
        {500, 300},
        {700, 400},
        {900, 500},
        {1000, 600},
        {1100, 700},
        {1200, 800},
        {1200, 800}};

    int *encVals;
    encVals = matrix[t];

    return encVals;
}

void poseUpdate(int NL, int NR, int r, int b, int C)
{

    float dl = (2 * M_PI * r / (float)C) * NL;
    float dr = (2 * M_PI * r / (float)C) * NR;
    float d = (dr + dl) / 2.0;

    float theta = robotPosition.theta + ((dr - dl) / (float)b);
    float x = robotPosition.x + d * cos(theta);
    float y = robotPosition.y + d * sin(theta);

    // Update robotPosition
    robotPosition.x = x;
    robotPosition.y = y;
    robotPosition.theta = theta;
}
