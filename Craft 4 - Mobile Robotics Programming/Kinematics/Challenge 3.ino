typedef struct
{
    float x;
    float y;
    float theta;
} Position;

typedef struct
{
    float lin_vel;
    float ang_vel;
    float left_wheel;
    float right_wheel;
} Speed;

void cmd_vel2wheels(Speed *speed, int r, int b, int C);
Speed cmd_vel(float lin_vel, float ang_vel, int r, int b, int C);
void poseUpdate(Speed *realSpeed, int NL, int NR, int r, int b, int C, unsigned long *timestamp);

// Global variable for robot position
Position robotPosition = {0.0, 0.0, 0.0};

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

void poseUpdate(Speed *realSpeed, int NL, int NR, int r, int b, int C, unsigned long *timestamp)
{
    unsigned long newtime = millis();
    float timeDiff = float(newtime - *timestamp) / 1000.0;

    float dl = (2 * M_PI * r / (float)C) * NL;
    float dr = (2 * M_PI * r / (float)C) * NR;
    float d = (dr + dl) / 2.0;

    realSpeed->lin_vel = 2 * M_PI * r / C * (NR + NL) / 2.0 / timeDiff;
    realSpeed->ang_vel = 2 * M_PI * r / C * (NR - NL) / b / timeDiff;
    cmd_vel2wheels(realSpeed, r, b, C);

    float theta = robotPosition.theta + ((dr - dl) / (float)b);
    float x = robotPosition.x + d * cos(theta);
    float y = robotPosition.y + d * sin(theta);

    // Update robotPosition
    robotPosition.x = x;
    robotPosition.y = y;
    robotPosition.theta = theta;

    *timestamp = newtime;
}

void cmd_vel2wheels(Speed *speed, int r, int b, int C)
{
    /**
  Converts the linear and angular velocities to wheels
  angular velocities
  *speed: Speed structure that contains linear and angular velocities to convert
  *r: wheel radius
  *b: wheel distance
  *C: encoder pulses per revolution
  */
    float v = speed->lin_vel;
    float w = speed->ang_vel;

    float wr = (v + w * (b / 2)) / r;
    float wl = (v - w * (b / 2)) / r;

    speed->left_wheel = wl;
    speed->right_wheel = wr;
}

Speed cmd_vel(float lin_vel, float ang_vel, int r, int b, int C)
{
    /**
  Returns the desired linear and angular velocities 
  (at this point, you can add constant values at will)
  */
    Speed desired;
    desired.lin_vel = lin_vel;
    desired.ang_vel = ang_vel;
    cmd_vel2wheels(&desired, r, b, C);

    return desired;
}

/*float *poseUpdate(NL, NR, r,b, C){
  /**
  Besides returning the new position of the robot,
  also returns the real angular velocities of the wheels 
  */
//}*/

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

    // SPEED VARIABLES
    Speed desiredSpeed = cmd_vel(0.5, 0.0, r, b, C);
    Speed realSpeed = {0.0, 0.0, 0.0, 0.0};

    unsigned long timestamp;

    for (int i = 0; i < 10; i++)
    {
        timestamp = millis() - 1000; // fake 1Hz frequency
        int *encVals;
        encVals = encUpdate(i);
        newEncL = encVals[0];
        newEncR = encVals[1];

        diffL = newEncL - oldEncL;
        diffR = newEncR - oldEncR;

        oldEncL = newEncL;
        oldEncR = newEncR;

        poseUpdate(&realSpeed, diffL, diffR, r, b, C, &timestamp);

        // Print robotPosition
        Serial.print("Step ");
        Serial.print(i + 1);
        Serial.print(", x: ");
        Serial.print(robotPosition.x);
        Serial.print(", y: ");
        Serial.print(robotPosition.y);
        Serial.print(", theta: ");
        Serial.println(robotPosition.theta * 180 / M_PI);
        Serial.print("Real linear speed: ");
        Serial.print(realSpeed.lin_vel);
        Serial.print(", real angular speed: ");
        Serial.println(realSpeed.ang_vel);

        delay(100);
    }
}

void loop()
{
    // Code that is repeated infinitely
}
