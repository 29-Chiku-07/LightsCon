String voice;
int led =12;
void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);

}

void loop() {
  
  while (Serial.available()) {
    delay(10);
    char c = Serial.read();
    if (c == '#') {
      break;
    }
    voice += c;
  }

  if (voice.length() > 0) {
    Serial.println(voice);


    if(voice == "light on" || voice == "LIGHT on" || voice == "LIGHT ON" || voice == "light ON")
    {
      digitalWrite(led,HIGH);
    }

    else if(voice == "light off" || voice == "LIGHT off" || voice == "LIGHT OFF" || voice == "light OFF")
    {
      digitalWrite(led,LOW);
    }
    else
   {
      voice = "";
   }
  }
  
}
