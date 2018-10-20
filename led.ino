#include <SoftwareSerial.h>

class LED{
   const int redPin = 6;
   const int greenPin = 5;
   const int bluePin = 9;
   int redBrightness;
   int blueBrightness;
   int greenBrightness;
   
  public:
    LED(){
     pinMode(redPin, OUTPUT);
     pinMode(greenPin, OUTPUT);
     pinMode(bluePin, OUTPUT);
     for(int i=200;i>=0;i-=1){
      setColor('r',i);  
      setColor('g',i);  
      setColor('b',i);  
      delay(1);
     }
    }
    
    void setColor(char color,int brightness){
      switch(color){
        case 'r':
          redBrightness=max(min(brightness,255),0);
          analogWrite(redPin, redBrightness);
          break;         
        case 'g':
          greenBrightness=max(min(brightness,255),0);
          analogWrite(greenPin, greenBrightness);
          break; 
        case 'b':
          blueBrightness=max(min(brightness,255),0);
          analogWrite(bluePin, blueBrightness);
          break;         
    }
    }
    
    int GetColorComponent(char color){
      switch(color){
        case 'r': return redBrightness; break;
        case 'g': return greenBrightness; break;
        case 'b': return blueBrightness; break;
        default: return -1;
      }      }  
};

SoftwareSerial bt (10,11);
LED *led;

void setup() {
  led=new LED();
  bt.begin(9600);
}
   
void loop() {
  if(bt.available() >= 2){
    char color=bt.read();
    int value=bt.parseInt();
    led->setColor(color,value);
  }
}
 
