#include <Keypad.h>
#include <Keyboard.h>

const byte ROWS = 4;
const byte COLS = 4;
int ledpin1 = 6;
int ledpin2 = 7;

char klavesy[ROWS][COLS] = {
  {'f', 'e','d', 'c'},
  {'b', 'a','9', '8'},
  {'7', '6','5', '4'},
  {'3', '2','1', '0'},
};
byte colPins[COLS] = {18,19,20,21};
byte rowPins[ROWS] = {15,14,16,10};

const int NUM_SLIDERS = 1;
const int analogInputs[NUM_SLIDERS] = {A9};

int analogSliderValues[NUM_SLIDERS];


Keypad klavesnice = Keypad( makeKeymap(klavesy), rowPins, colPins, ROWS, COLS);

int dt = 120;

void setup() {
  Keyboard.begin();
  pinMode(ledpin1, OUTPUT);
  pinMode(ledpin2, OUTPUT);
  
  
  digitalWrite(ledpin1, LOW);
  digitalWrite(ledpin2, LOW);
  for (int i = 0; i < NUM_SLIDERS; i++) {
    pinMode(analogInputs[i], INPUT);
  }
  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  updateSliderValues();
  sendSliderValues(); 
  char customKey = klavesnice.getKey();
   if (customKey) {
      switch (customKey) {
        case '0'://chrome
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press(KEY_LEFT_ALT);
          Keyboard.write('h');
          Keyboard.releaseAll();
          //Serial.println("0");
          break;
        case '1'://spotify
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press(KEY_LEFT_ALT);
          Keyboard.write('g');
          Keyboard.releaseAll();
          //Serial.println("1");
          break;
        case '2'://code
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press(KEY_LEFT_ALT);
          Keyboard.write('j');
          Keyboard.releaseAll();
          //Serial.println("2");
          break;
       case '3'://discord
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press(KEY_LEFT_ALT);
          Keyboard.write('k');
          Keyboard.releaseAll();
         //Serial.println("3");
         break;
        case '4'://youtube
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press(KEY_LEFT_ALT);
          Keyboard.write('l');
          Keyboard.releaseAll();
         //Serial.println("4");
         break;
        case '5'://twitch
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press(KEY_LEFT_ALT);
          Keyboard.write('p');
          Keyboard.releaseAll();
         //Serial.println("5");
         break;
        case '6'://cmd
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press(KEY_LEFT_ALT);
          Keyboard.write('o');
          Keyboard.releaseAll();
         //Serial.println("6");
         break;
        case '7':
         //Serial.println("7");
         break;
        case '8':
         //Serial.println("8");
         break;
        case '9':
         //Serial.println("9");
         break;
        case 'a':
         //Serial.println("a");
         break;
        case 'b':
         //Serial.println("b");
         break;
         case 'c':
         //Serial.println("c");
         break;
         case 'd':
         //Serial.println("d");
         break;
         case 'e':
         //Serial.println("e");
         break;
         case 'f':
         //Serial.println("f");
        break;
      }
   }
   delay(10);
}

void updateSliderValues() {
  for (int i = 0; i < NUM_SLIDERS; i++) {
     analogSliderValues[i] = analogRead(analogInputs[i]);
  }
}

void sendSliderValues() {
  String builtString = String("");

  for (int i = 0; i < NUM_SLIDERS; i++) {
    builtString += String((int)analogSliderValues[i]);

    if (i < NUM_SLIDERS - 1) {
      builtString += String("|");
    }
  }
  
  Serial.println(builtString);
}

void printSliderValues() {
  for (int i = 0; i < NUM_SLIDERS; i++) {
    String printedString = String("Slider #") + String(i + 1) + String(": ") + String(analogSliderValues[i]) + String(" mV");
    Serial.write(printedString.c_str());

    if (i < NUM_SLIDERS - 1) {
      Serial.write(" | ");
    } else {
      Serial.write("\n");
    }
  }
}
