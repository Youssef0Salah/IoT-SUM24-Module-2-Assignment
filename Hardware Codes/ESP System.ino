int IR_sensor = 13;
const int LEDs_number = 9;
int LEDs[LEDs_number] = {23, 1, 3, 19, 18, 5, 16, 4, 15};
int LED1 = 12;
int button = 14;
int buzzer = 27;
int LED2 = 26;
int LDR = 25;

void setup() {
Serial.begin(115200);
pinMode(IR_sensor, INPUT);
for (int i = 0; i < LEDs_number; i++) {
  pinMode(LEDs[i], OUTPUT);
}
pinMode(LED1, OUTPUT);
pinMode(button, INPUT);
pinMode(buzzer, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(LDR, INPUT);
}

void loop() {
int bar_progress = map(analogRead(IR_sensor), 0, 4095, 0 , LEDs_number);
Serial.println(bar_progress);
for(int i = 0; i < LEDs_number; i++) {
  if (i < bar_progress) {
    digitalWrite(LEDs[i], HIGH);
  } else {
    digitalWrite(LEDs[i], LOW);
  }
}

int button_state = digitalRead(button);
digitalWrite(LED1, button_state);

int resistance = analogRead(LDR);
Serial.println(resistance);
if (resistance < 2000) {
  digitalWrite(buzzer, HIGH);
  digitalWrite(LED2, HIGH);
} else {
  digitalWrite(buzzer, LOW);
  digitalWrite(LED2, LOW);
}

delay(50);
}
