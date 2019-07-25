void setup()
{
    Serial.begin(9600);

    float length1, length2;

    configure(&length1, &length2);
    float coord[2];

    // Sample call with 45°
    forwardKin(length1, length2, M_PI / 4, M_PI / 4, coord);

    Serial.print("x: ");
    Serial.println(coord[0]);
    Serial.print("y: ");
    Serial.println(coord[1]);

    // Inverse
    float t1, t2;
    inverseKin(length1, length2, coord, &t1, &t2);

    Serial.print("t1: ");
    Serial.println(t1 * 180 / M_PI);
    Serial.print("t2: ");
    Serial.println(t2 * 180 / M_PI);
}

void loop()
{
}

void configure(float *p1, float *p2)
{

    // Length 1
    Serial.println("Enter value for length 1: ");
    while (Serial.available() == 0)
    {
    }

    float val = Serial.parseFloat(); //read int or parseFloat for ..float...

    Serial.println(val);
    *p1 = val;

    // Length 2
    Serial.println("Enter value for length 2: ");
    while (Serial.available() == 0)
    {
    }

    float val2 = Serial.parseFloat(); //read int or parseFloat for ..float...

    Serial.println(val2);
    *p2 = val2;
}

void forwardKin(float l1, float l2, float t1, float t2, float *coord)
{
    float x, y;

    x = l1 * cos(t1) + l2 * cos(t1 + t2);
    y = l1 * sin(t1) + l2 * sin(t1 + t2);

    coord[0] = x;
    coord[1] = y;
}

void inverseKin(float l1, float l2, float coordEnd[2], float *t1, float *t2)
{
    float x = coordEnd[0];
    float y = coordEnd[1];
    float distance = sqrt(pow(x, 2) + pow(y, 2));

    float q2 = atan2(sqrt(1 - pow((pow(x, 2) + pow(y, 2) - pow(l1, 2) - pow(l2, 2)) / (2 * l1 * l2), 2)),
                     ((pow(x, 2) + pow(y, 2) - pow(l1, 2) - pow(l2, 2)) / (2 * l1 * l2)));
    float q1 = atan2(y, x) - atan2(l2 * sin(q2), l1 + l2 * cos(q2));

    *t1 = q1;
    *t2 = q2;
}