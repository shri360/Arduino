#include <RF24.h>
#include<SPI.h>
#include <LiquidCrystal.h>
RF24 radio(9, 10);
const byte address[6] = "00001";
char text[32] = "";
LiquidCrystal lcd (6,5,4,3,2,7);
byte block[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};
int con = 8;
void setup()
{
  lcd.begin(16,2);
  lcd.createChar(0, block);
  lcd.clear();
  lcd.print("  REAL TIME ");
  lcd.setCursor(0, 1);
  lcd.print("  WATER LEVEL");
  delay(4000);
  lcd.clear();
  lcd.print("LOADING...");
  delay(1000);
  lcd.clear();
Serial.begin(9600);
radio.begin();
radio.openReadingPipe(0, address);
radio.setChannel(100);
radio.setDataRate(RF24_250KBPS);
radio.setPALevel(RF24_PA_MAX);
radio.startListening();
pinMode(con, OUTPUT);
}
void loop()
{
if (radio.available())
{
radio.read(&text, sizeof(text));
Serial.println(text);
if (text[0] == 'F' && text[1] == 'I' && text[2] == 'L' && text[3] == 'L')
{
  lcd.setCursor(0, 0);
  lcd.write(byte(0));
  lcd.setCursor(1, 0);
  lcd.write(byte(0));
  lcd.setCursor(2, 0);
  lcd.write(byte(0));
  lcd.setCursor(3, 0);
  lcd.write(byte(0));
  lcd.setCursor(4, 0);
  lcd.write(byte(0));
  lcd.setCursor(5, 0);
  lcd.write(byte(0));
  lcd.setCursor(6, 0);
  lcd.write(byte(0));
  lcd.setCursor(7, 0);
  lcd.write(byte(0));
  lcd.setCursor(8, 0);
  lcd.write(byte(0));
  lcd.setCursor(9, 0);
  lcd.write(byte(0));
  lcd.setCursor(10, 0);
  lcd.write(byte(0));
  lcd.setCursor(11, 0);
  lcd.write(byte(0));
  lcd.setCursor(12, 0);
  lcd.write(byte(0));
  lcd.setCursor(13, 0);
  lcd.write(byte(0));
  lcd.setCursor(14, 0);
  lcd.write(byte(0));
  lcd.setCursor(15, 0);
  lcd.write(byte(0));
  lcd.setCursor(16, 0);
  lcd.write(byte(0));
  lcd.setCursor(0, 1);
    lcd.print("Level: ");
  lcd.print(text);
  delay(5000);
  lcd.clear();
  digitalWrite(con,HIGH);
  delay(60000);
}
else if (text[0] == 'F' && text[1] == 'U' && text[2] == 'L' && text[3] == 'L')
{

  lcd.setCursor(0, 0);
  lcd.write(byte(0));
  lcd.setCursor(1, 0);
  lcd.write(byte(0));
  lcd.setCursor(2, 0);
  lcd.write(byte(0));
  lcd.setCursor(3, 0);
  lcd.write(byte(0));
  lcd.setCursor(4, 0);
  lcd.write(byte(0));
  lcd.setCursor(5, 0);
  lcd.write(byte(0));
  lcd.setCursor(6, 0);
  lcd.write(byte(0));
  lcd.setCursor(7, 0);
  lcd.write(byte(0));
  lcd.setCursor(8, 0);
  lcd.write(byte(0));
  lcd.setCursor(9, 0);
  lcd.write(byte(0));
  lcd.setCursor(10, 0);
  lcd.write(byte(0));
  lcd.setCursor(11, 0);
  lcd.write(byte(0));
  lcd.setCursor(12, 0);
  lcd.write(byte(0));
  lcd.setCursor(13, 0);
  lcd.write(byte(0));
  lcd.setCursor(14, 0);
  lcd.write(byte(0));
  lcd.setCursor(0, 1);
    lcd.print("Level: ");
  lcd.print(text);
  delay(5000);
  lcd.clear();
    digitalWrite(con,LOW);
    delay(500);
}
else if (text[0] == '3' && text[1] == '/' && text[2] == '4')
{
  lcd.setCursor(0, 0);
  lcd.write(byte(0));
  lcd.setCursor(1, 0);
  lcd.write(byte(0));
  lcd.setCursor(2, 0);
  lcd.write(byte(0));
  lcd.setCursor(3, 0);
  lcd.write(byte(0));
  lcd.setCursor(4, 0);
  lcd.write(byte(0));
  lcd.setCursor(5, 0);
  lcd.write(byte(0));
  lcd.setCursor(6, 0);
  lcd.write(byte(0));
  lcd.setCursor(7, 0);
  lcd.write(byte(0));
  lcd.setCursor(8, 0);
  lcd.write(byte(0));
  lcd.setCursor(9, 0);
  lcd.write(byte(0));
  lcd.setCursor(10, 0);
  lcd.write(byte(0));
  lcd.setCursor(0, 1);
  lcd.print("Level: ");
  lcd.print(text);
  delay(5000);
  lcd.clear();
}
else if (text[0] == 'H' && text [1] == 'A' && text[2] == 'L' && text[3] == 'F')
{
  lcd.setCursor(0, 0);
  lcd.write(byte(0));
  lcd.setCursor(1, 0);
  lcd.write(byte(0));
  lcd.setCursor(2, 0);
  lcd.write(byte(0));
  lcd.setCursor(3, 0);
  lcd.write(byte(0));
  lcd.setCursor(4, 0);
  lcd.write(byte(0));
  lcd.setCursor(5, 0);
  lcd.write(byte(0));
  lcd.setCursor(6, 0);
  lcd.write(byte(0));
  lcd.setCursor(7, 0);
  lcd.write(byte(0));
  lcd.setCursor(0, 1);
    lcd.print("Level: ");
  lcd.print(text);
  delay(5000);
  lcd.clear();
}
else if (text[0] == 'L' && text[1] == 'O' && text[2] == 'W')
{
  lcd.setCursor(0, 0);
  lcd.write(byte(0));
  lcd.setCursor(1, 0);
  lcd.write(byte(0));
  lcd.setCursor(2, 0);
  lcd.write(byte(0));
  lcd.setCursor(3, 0);
  lcd.write(byte(0));
  lcd.setCursor(0, 1);
    lcd.print("Level: ");
  lcd.print(text);
  delay(5000);
  lcd.clear();
}
else if (text[0] == 'D' && text[1] == 'E' && text[2] == 'A' && text[3] == 'D')
{
lcd.setCursor(0, 0);
  lcd.write(byte(0));
  lcd.setCursor(0, 1);
    lcd.print("Level: ");
  lcd.print(text);
  delay(5000);
  lcd.clear();
}
}}
