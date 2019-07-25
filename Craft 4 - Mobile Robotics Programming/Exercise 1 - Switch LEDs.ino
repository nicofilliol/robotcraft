// Global variables
int timestamp;

void setup()
{
    DDRD = B11111100;
    PORTD = B00000000;
    DDRB = B00000011;
    PORTB = B00000000;
    timestamp = millis();
}

void loop()
{
    if (millis() - timestamp > 500)
    {
        timestamp = millis();
        // Change LEDs
        goLeft();
    }
}

void goLeft()
{
    if (PORTD == B00000000 && (PORTB != B00000001 && PORTB != B00000010))
    {
        // Initial state
        PORTD = B00000100;
        PORTB = B00000000;
    }
    else if (PORTD == B10000000)
    {
        // Switch to Port B
        PORTB = B00000001;
        PORTD = B00000000;
    }
    else if (PORTB == B00000000 && PORTD != B00000000)
    {
        // Update Port D
        PORTD *= 2;
    }
    else if (PORTD == B00000000 && PORTB != B00000000)
    {
        // Update Port B
        PORTB *= 2;
    }
}