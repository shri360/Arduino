// ----------- Program Developed by R.GIRISH / Homemade-circuits .com ----------- //
#include <RF24.h>
#include<SPI.h>
RF24 radio(9, 10);
int i = 0;
const byte address[6] = "00001";
const int buzzer = 8;
const int LED_full = 5;
const int LED_three_fourth = 4;
const int LED_half = 3;
const int LED_quarter = 2;
const int LED_dead = 7;
char text[32] = "";
void setup()
{
pinMode(buzzer, OUTPUT);
pinMode(LED_full, OUTPUT);
pinMode(LED_three_fourth, OUTPUT);
pinMode(LED_half, OUTPUT);
pinMode(LED_quarter, OUTPUT);
pinMode(LED_dead, OUTPUT);
digitalWrite(buzzer, HIGH);
delay(10000);
digitalWrite(buzzer, LOW);
digitalWrite(LED_full, HIGH);
delay(300);
digitalWrite(LED_three_fourth, HIGH);
delay(300);
digitalWrite(LED_half, HIGH);
delay(300);
digitalWrite(LED_quarter, HIGH);
delay(300);
digitalWrite(LED_dead, HIGH);
delay(300);
digitalWrite(LED_full, LOW);
delay(300);
digitalWrite(LED_three_fourth, LOW);
delay(300);
digitalWrite(LED_half, LOW);
delay(300);
digitalWrite(LED_quarter, LOW);
Serial.begin(9600);
digitalWrite(LED_dead, LOW);
Serial.begin(9600);
radio.begin();
radio.openReadingPipe(0, address);
radio.setChannel(100);
radio.setDataRate(RF24_250KBPS);
radio.setPALevel(RF24_PA_MAX);
radio.startListening();
}
void loop()
{
if (radio.available())
{
radio.read(&text, sizeof(text));
Serial.println(text);
if (text[0] == 'F' && text[1] == 'I' && text[2] == 'L' && text[3] == 'L')
{
digitalWrite(LED_full, HIGH);
digitalWrite(LED_three_fourth, HIGH);
digitalWrite(LED_half, HIGH);
digitalWrite(LED_quarter, HIGH);
digitalWrite(LED_dead, LOW);
for (i = 0; i < 50; i++)
{
digitalWrite(buzzer, HIGH);
delay(50);
digitalWrite(buzzer, LOW);
delay(50);
}
}
if (text[0] == 'F' && text[1] == 'U' && text[2] == 'L' && text[3] == 'L')
{
digitalWrite(LED_full, HIGH);
digitalWrite(LED_three_fourth, HIGH);
digitalWrite(LED_half, HIGH);
digitalWrite(LED_quarter, HIGH);
digitalWrite(LED_dead, LOW);
}
if (text[0] == '3' && text[1] == '/' && text[2] == '4')
{
digitalWrite(LED_full, LOW);
digitalWrite(LED_three_fourth, HIGH);
digitalWrite(LED_half, HIGH);
digitalWrite(LED_quarter, HIGH);
digitalWrite(LED_dead, LOW);
}
if (text[0] == 'H' && text [1] == 'A' && text[2] == 'L' && text[3] == 'F')
{
digitalWrite(LED_full, LOW);
digitalWrite(LED_three_fourth, LOW);
digitalWrite(LED_half, HIGH);
digitalWrite(LED_quarter, HIGH);
digitalWrite(LED_dead, LOW);
}
if (text[0] == 'L' && text[1] == 'O' && text[2] == 'W')
{
digitalWrite(LED_full, LOW);
digitalWrite(LED_three_fourth, LOW);
digitalWrite(LED_half, LOW);
digitalWrite(LED_quarter, HIGH);
digitalWrite(LED_dead, LOW);
}
if (text[0] == 'D' && text[1] == 'E' && text[2] == 'A' && text[3] == 'D')
{
digitalWrite(LED_full, LOW);
digitalWrite(LED_three_fourth, LOW);
digitalWrite(LED_half, LOW);
digitalWrite(LED_quarter, LOW);
digitalWrite(LED_dead, HIGH);
for (i = 0; i < 50; i++)
{
digitalWrite(LED_dead, HIGH);
delay(50);
digitalWrite(LED_dead, LOW);
delay(50);
}
}
}
}
// ----------- Program Developed by R.GIRISH / Homemade-circuits .com ----------- //
