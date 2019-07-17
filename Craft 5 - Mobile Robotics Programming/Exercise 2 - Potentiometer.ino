// Define PIN Ports
#define POT A0
#define BUTTON 2
#define LED 3

// Global Variables
unsigned long timestamp;

void setup()
{
    // Setup pins
    pinMode(POT, INPUT);
    pinMode(BUTTON, INPUT);
    pinMode(LED, OUTPUT);

    // Set starting timestamp
    timestamp = millis();

    // Setup Serial
    Serial.begin(9600);
}

void loop()
{
    // Read values of potentiometer and button
    int potVal = analogRead(POT);
    int buttonState = digitalRead(BUTTON);

    // Set blinking rate according to potVal
    int blinkingRate = potVal / 1023.0 * 1000;

    if (millis() - timestamp > blinkingRate)
    {
        timestamp = millis();
        if (buttonState == HIGH)
        {
            digitalWrite(LED, !digitalRead(LED));
        }
        else
        {
            // Turn LED off when button not pressed
            digitalWrite(LED, LOW);
        }
    }
}