// Define pins
#define RED_TOP 2
#define ORANGE_TOP 3
#define GREEN_TOP 4

#define RED_BOTTOM 10
#define ORANGE_BOTTOM 9
#define GREEN_BOTTOM 8

// Define signal states
#define RED 0
#define RED_ORANGE 1
#define GREEN 2
#define ORANGE 3

// Define state durations (in ms)
#define LONG_DURATION 3000
#define SHORT_DURATION 1000

typedef struct Signal
{
    int redLED;
    int orangeLED;
    int greenLED;
    int state; // 0: red, 1: red-orange, 2: green, 3: orange
};

// Global variables
unsigned long timestamp;
bool longDuration;
Signal topSignal;
Signal bottomSignal;

void switchTrafficLight(Signal *signal);
void updateSignalLED(Signal *signal);

void setup()
{
    // Top signal
    pinMode(RED_TOP, OUTPUT);
    pinMode(ORANGE_TOP, OUTPUT);
    pinMode(GREEN_TOP, OUTPUT);

    // Bottom signal
    pinMode(RED_BOTTOM, OUTPUT);
    pinMode(ORANGE_BOTTOM, OUTPUT);
    pinMode(GREEN_BOTTOM, OUTPUT);

    // Set initial timestamp
    timestamp = millis();
    longDuration = true;

    // Create signals and set inital state (top signal: green, bottom signal: red)
    topSignal = {RED_TOP, ORANGE_TOP, GREEN_TOP, GREEN};
    bottomSignal = {RED_BOTTOM, ORANGE_BOTTOM, GREEN_BOTTOM, RED};
    updateSignalLED(&topSignal);
    updateSignalLED(&bottomSignal);
}

void loop()
{
    // Check which duration of state is needed
    if (longDuration == true)
    {
        if (millis() - timestamp > LONG_DURATION)
        {
            timestamp = millis();
            longDuration = !longDuration;

            // Switch traffic light states
            switchTrafficLight(&topSignal);
            switchTrafficLight(&bottomSignal);
        }
    }
    else
    {
        if (millis() - timestamp > SHORT_DURATION)
        {
            timestamp = millis();
            longDuration = !longDuration;

            // Switch traffic light states
            switchTrafficLight(&topSignal);
            switchTrafficLight(&bottomSignal);
        }
    }
}

void switchTrafficLight(Signal *signal)
{
    if (signal->state == ORANGE)
    {
        signal->state = RED; // Go back to state 0
    }
    else
    {
        signal->state += 1; // Move up one state
    }
    updateSignalLED(signal);
}

void updateSignalLED(Signal *signal)
{
    // Turn all LEDs off
    digitalWrite(signal->redLED, LOW);
    digitalWrite(signal->orangeLED, LOW);
    digitalWrite(signal->greenLED, LOW);

    // Turn LEDs on according to state
    if (signal->state == RED)
    {
        digitalWrite(signal->redLED, HIGH);
    }
    else if (signal->state == RED_ORANGE)
    {
        digitalWrite(signal->redLED, HIGH);
        digitalWrite(signal->orangeLED, HIGH);
    }
    else if (signal->state == GREEN)
    {
        digitalWrite(signal->greenLED, HIGH);
    }
    else if (signal->state == ORANGE)
    {
        digitalWrite(signal->orangeLED, HIGH);
    }
}