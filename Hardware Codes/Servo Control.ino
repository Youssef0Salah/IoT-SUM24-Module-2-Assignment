
#include <Keypad.h>
#include <ESP32Servo.h>
#include <LiquidCrystal_I2C.h>

int pos = 0;  
int servoPin=13;
int ind = 0;
int intr_in = 8;
int customArray[] ={0,0,0};
char buttons[4][4] ={{'1','2','3','A'},
                     {'4','5','6','B'},
                     {'7','8','9','C'},
                     {'*','0','#','D'}};
byte rowPins[4] = {12,11,10,9};
byte colPins[4] = {8,7,6,5};
bool customAngle = false;

Servo myservo;  
LiquidCrystal_I2C lcd(0x27,16,2);
Keypad myKeypad = Keypad(makeKeymap(buttons),rowPins,colPins,4,4);

int formAngle(int *arr){
int final = arr[0]*100+arr[1]*10+arr[2];

return final;
}
void interupts(){
   char customKey = myKeypad.getKey();
  if (customKey == '*'){myservo.detach();myservo.attach(servoPin);}
}


void setup() {
  myservo.attach(servoPin);
  lcd.init();
  lcd.backlight();
  attachInterrupt(digitalPinToInterrupt(intr_in), interupts, CHANGE);
}



void loop() {
 char customKey = myKeypad.getKey();
  if (customKey){
    int angle = 0;
    if (!customAngle){
      switch (customKey){
        case '1':
          angle = 20;break;
        case '2':
          angle = 40;break;
        case '3':
          angle = 60;break;
        case '4':
          angle = 80;break;
        case '5':
          angle = 100;break;
        case '6':
          angle = 120;break;
        case '7':
          angle = 140;break;
        case '8':
          angle = 160;break;
        case '9':
          angle = 180;break;
        case '0':
          angle = 0;break;
        case 'C':
          angle= pos; customAngle = true;break;
        default:
          angle = pos; break;
        
      }
      pos = angle;
      lcd.clear();
      lcd.home();
      lcd.print("Angle is: ");
      lcd.setCursor(11,0);
      lcd.print(angle);
      myservo.write(pos);
    }
    else{
      switch (customKey){
        case '1':
          customArray[ind] = 1;break;
        case '2':
          customArray[ind] = 2;break;
        case '3':
          customArray[ind] = 3;break;
        case '4':
          customArray[ind] = 4;break;
        case '5':
          customArray[ind] = 5;break;
        case '6':
          customArray[ind] = 6;break;
        case '7':
          customArray[ind] = 7;break;
        case '8':
          customArray[ind] = 8;break;
        case '9':
          customArray[ind] = 9;break;
        case '0':
          customArray[ind] = 0;break;
        case 'C':
          customAngle = false;break;
        case 'A':
          myservo.write(formAngle(customArray));ind=-1;break;
        default:
          ind -=1; break;
        
      }
      ind = (ind+1) % 3;
      lcd.clear();
      lcd.home();
      lcd.print("Custom Angle: ");
      lcd.setCursor(0,1);
      int newAngle = formAngle(customArray);
      if (newAngle < 100)
      {
        lcd.print("0");
        lcd.setCursor(1,1);
      }
      if (newAngle<10){
        lcd.print("0");
        lcd.setCursor(2,1);  
      }
      lcd.print(formAngle(customArray));
    }
  }

}
