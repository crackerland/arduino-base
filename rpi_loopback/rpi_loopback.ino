

static int pins[][2] = {{2,0}, {3,0}, {4,0}, {5,0}, {6,0}, {7,0}};
static int pin_count = 6;

int read_pin(int pin){
  int val = digitalRead(pin);
  Serial.print("Pin ");
  Serial.print(pin);
  Serial.print(": ");
  Serial.println(val ? "HIGH" : "LOW");
  return val;
}

void log_all(){
    clear_monitor();
    for(int i = 0; i < pin_count; i++){
      int pin = pins[i][0];
      int val = digitalRead(pin);
      Serial.print("Pin ");
      Serial.print(pin);
      Serial.print(": ");
      Serial.println(val ? "HIGH" : "LOW");
    }
}

void clear_monitor(){
  int lines = 16;
  while(lines){
    Serial.println(""); 
    lines--;
  }
}


// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  
  /* Pins are input by default */
  for(int i = 0; i < pin_count; i++){
    //Serial.print("Setup ");
     // Serial.println(pins[i][0]);
     pinMode(pins[i][0], INPUT); 
  }

  Serial.println("Enter 2-7 or 'A' to read");
}

// the loop routine runs over and over again forever:
void loop() {
  for(int i = 0; i < pin_count; i++){
        int pin = pins[i][0];
        int &pinval = pins[i][1];
        int val = digitalRead(pin);
        if(pinval != val){
           pinval = val; 
           log_all();
        }
    }
  /*
  if(Serial.available()){
    char ch = Serial.read();
    switch(ch){
      case 'a':
      case 'A':
        clear_monitor();
        for(int i = 0; i < pin_count; i++){
            int pin = pins[i][0];
            read_pin(pin);
        }
        break;
      case '2':
        read_pin(pins[0][0]);
        break;
      case '3':
        read_pin(pins[1][0]);
        break;
      case '4':
        read_pin(pins[2][0]);
        break;
      case '5':
        read_pin(pins[3][0]);
        break;
      case '6':
        read_pin(pins[4][0]);
        break;
      case '7':
        read_pin(pins[5][0]);
        break;
      default:
        Serial.println("Invalid Option");
    }
  } 
  */
//  delay(100);
  
}



