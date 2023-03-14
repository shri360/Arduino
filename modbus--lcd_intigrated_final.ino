#include<SimpleModbusMaster.h>
#include <LiquidCrystal.h>
//////////port infromation///////////
#define baud 9600
#define timeout 100
#define polling 100 // the scan rate
#define retry_count 10
float num;
// used to toggle the receive/transmit pin on the driver
#define TxEnablePin 8
// the total amount of avaliable memory on the master to store data
#define TOTAL_NO_OF_REGISTERS 10
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//this is the esiar way to creat new packet
//add as many as you want . TOTAL_NO_OF_PACKETS
// is automatically updated.

enum
{
  PACKET1,
  PACKET2,
  PACKET3,
  PACKET4,
  // PACKET 2,
  TOTAL_NO_OF_PACKETS //leave this last entry
};

//creat an array of packets to be configured
Packet packets[TOTAL_NO_OF_PACKETS];
//Master Register array
unsigned int regs[TOTAL_NO_OF_REGISTERS];
float num;
unsigned long temp = (unsigned long)regs[0] << 16 | regs[1];
num = *(float*)&temp;

void setup()
{
lcd.begin(16, 2);
//Initialize each packets
Serial.begin(9600);

modbus_construct(&packets[PACKET1], 2, READ_INPUT_REGISTERS, 0, 6, 0);
modbus_construct(&packets[PACKET2], 2, READ_INPUT_REGISTERS, 0, 6, 1);

//Initialize the modbus finite state machine
modbus_configure(&Serial, baud, SERIAL_8N1, timeout, polling, retry_count, TxEnablePin, packets, TOTAL_NO_OF_PACKETS, regs);


}

void loop()
{
  modbus_update();
  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.print("***************ARDUINO AS MODBUS-RTU**************");
  Serial.println("");
  Serial.println("");
  Serial.print("successful_requests:");
  Serial.print(packets[PACKET1].successful_requests );
  Serial.println("");
  lcd.print("");
  Serial.print("failed_requests: ");
  Serial.print(packets[PACKET1].failed_requests );
  Serial.println("");
  Serial.print("CURRENT_ROOM_TEMP : ");
  lcd.clear();
  lcd.print("PV-30001 : ");
  Serial.print(regs[0]*0.1);
  lcd.setCursor(2,2);
  lcd.print(regs[0]*0.1);
  if(regs[0]*0.1==3276.70){
    lcd.clear();
    lcd.blink();
    delay(1000);
    lcd.setCursor(5,2);
    lcd.print("oPEn");
  }
  Serial.println("");
  //Serial.println(regs[1]);
  delay(1000);
  }
