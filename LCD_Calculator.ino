#include<Wire.h>
#include<LiquidCrystal_I2C.h>
#define lcdAddress 0x27  //Run the Find_I2C_Address.ino program first and get the correct address of your display.
LiquidCrystal_I2C lcd(lcdAddress,16,2);
float nr1,nr2, rez;
String op;  
void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
 
lcd.setCursor(0,0);
lcd.print("Please enter");
lcd.setCursor(0,1);
lcd.print("your 1st number:");
while(Serial.available()==0){}
nr1=Serial.parseFloat();
lcd.clear();
lcd.print("Please enter");
lcd.setCursor(0,1);
lcd.print("your 2nd number:");
while(Serial.available()==0){}
nr2=Serial.parseFloat();
lcd.clear();
lcd.print("Enter your");
lcd.setCursor(0,1);
lcd.print("operator");
lcd.print("(+,-,*,/)");
while(Serial.available()==0){}
op=Serial.readString();
if(op=="+")
{rez=nr1+nr2;}
if(op=="-")
{rez=nr1-nr2;}
if(op=="*")
{rez=nr1*nr2;}
if(op=="/")
{rez=nr1/nr2;}
lcd.clear();
lcd.print(nr1);
lcd.print(op);
lcd.print(nr2);
lcd.print(" = ");
lcd.setCursor(0,1);
lcd.print(rez);
delay(6000);
lcd.clear();


}
