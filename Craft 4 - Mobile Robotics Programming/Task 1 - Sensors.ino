// Define the infrared sensors' pins
#define IR_LEFT A2
#define IR_FRONT A3
#define IR_RIGHT A4

// Define other constants
#define UPDATE_FREQUENCY 10 // in Hz
#define SAMPLE_SIZE 25

// Global variables
unsigned long timestamp;

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    timestamp = millis();
}

void loop()
{
    // put your main code here, to run repeatedly:

    // Read sensor values in UPDATE_FREQUENCY
    if (millis() - timestamp >= 1000 / UPDATE_FREQUENCY)
    {
        timestamp = millis();

        int rangeLeft = sensL();
        int rangeFront = sensF();
        int rangeRight = sensR();

        // Print all values
        Serial.print("Sensor Left: ");
        Serial.println(rangeLeft);
        Serial.print("Sensor Front: ");
        Serial.println(rangeFront);
        Serial.print("Sensor Right: ");
        Serial.println(rangeRight);
        Serial.println("\n");
    }
}

int sensL()
{
    int distance = getDistance(IR_LEFT);
    return distance;
}
int sensF()
{
    int distance = getDistance(IR_FRONT);
    return distance;
}
int sensR()
{
    int distance = getDistance(IR_RIGHT);
    return distance;
}

// Helper functions to get distance and reduce sensor noise

int getDistance(int ir_pin)
{
    /*
   * int ir_pin: Analog pin number of IR sensor
   * Returns distance in mm (and cuts off at 100mm and 800mm because range of sensor is 10-80cm)
   */

    int ir_val[SAMPLE_SIZE];

    // Collect samples from IR sensor
    for (int i = 0; i < SAMPLE_SIZE; i++)
    {
        // Read analog value
        ir_val[i] = analogRead(ir_pin);
    }

    // Sort array of sensor values
    sortArray(ir_val, SAMPLE_SIZE);

    // Use median value for further caluclations -> ir_val[SAMPLE_SIZE/2]
    float distance_cm = 4800.0 / (ir_val[SAMPLE_SIZE / 2] - 20.0);
    // Alternative formulas found in experiments
    //5177 / (ir_val[SAMPLE_SIZE/2] -19.54) - 1.28;
    //4213 / (ir_val[SAMPLE_SIZE/2] -41.64);

    // Check if distance inside range that can be measured by sensor (10-80cm), otherwise cut value off
    if (distance_cm > 80.0)
        distance_cm = 80.0;
    else if (distance_cm < 10.0)
        distance_cm = 10.0;
    return (int)(distance_cm * 10.0); // return in mm
}

// Helper function to sort array
void sortArray(int a[], int size)
{
    for (int i = 0; i < (size - 1); i++)
    {
        bool flag = true;
        for (int o = 0; o < (size - (i + 1)); o++)
        {
            if (a[o] > a[o + 1])
            {
                int t = a[o];
                a[o] = a[o + 1];
                a[o + 1] = t;
                flag = false;
            }
        }
        if (flag)
            break;
    }
}