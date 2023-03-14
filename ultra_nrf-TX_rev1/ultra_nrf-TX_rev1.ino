#include <Wire.h>
// ----------- Program Developed by R.GIRISH / Homemade-circuits .com ----------- //
#include <RF24.h>
#include<SPI.h>
RF24 radio(9, 10);
const byte address[6] = "00001";
const int trigger = 9;
const int echo = 10;
const char text_0[] = "FILL";
const char text_1[] = "FULL";
const char text_2[] = "3/4";
const char text_3[] = "HALF";
const char text_4[] = "LOW";
const char text_5[] = "DEAD";
long Time;
float distanceCM = 0;
float distanceM = 0;
float resultCM = 0;
float resultM = 0;
float actual_distance = 0;
float compensation_distance = 0;
// ------- CHANGE THIS -------//
float water_hold_capacity = 1.60; // Enter in Meters.
float full_height = 1.81; // Enter in Meters.
// ---------- -------------- //
void setup()
{
Serial.begin(9600);
pinMode(trigger, OUTPUT);
pinMode(echo, INPUT);
digitalWrite(trigger, LOW);
radio.begin();
radio.openWritingPipe(address);
radio.setChannel(100);
radio.setDataRate(RF24_250KBPS);
radio.setPALevel(RF24_PA_MAX);
radio.stopListening();
}
void loop()
{
delay(2000);
digitalWrite(trigger, HIGH);
delayMicroseconds(10);
digitalWrite(trigger, LOW);
Time = pulseIn(echo, HIGH);
distanceCM = Time * 0.034;
resultCM = distanceCM / 2;
resultM = resultCM / 100;
Serial.print("Normal Distance: ");
Serial.print(resultM);
Serial.println(" M");
compensation_distance = full_height - water_hold_capacity;
actual_distance = resultM - compensation_distance;
actual_distance = water_hold_capacity - actual_distance;
if (actual_distance < 0)
{
Serial.print("Water Level:");
Serial.println(" 0.00 M (UP)");
}
else
{
Serial.print("Water Level: ");
Serial.print(actual_distance);
Serial.println(" M (UP)");
}
Serial.println("============================");
if (actual_distance >= 1.50)
{
radio.write(&text_0, sizeof(text_0));
}
if (actual_distance > 1.20 && actual_distance <= 1.50)
{
radio.write(&text_1, sizeof(text_1));
}
if (actual_distance > 0.80 && actual_distance <= 1.20)
{
radio.write(&text_2, sizeof(text_2));
}
if (actual_distance > 0.40 && actual_distance <= 0.80)
{
radio.write(&text_3, sizeof(text_3));
}
if (actual_distance > 0.08 && actual_distance <= 0.40)
{
radio.write(&text_4, sizeof(text_4));
}
if (actual_distance < 0.08)
{
radio.write(&text_5, sizeof(text_5));
}
}
// ----------- Program Developed by R.GIRISH / Homemade-circuits .com ----------- //
