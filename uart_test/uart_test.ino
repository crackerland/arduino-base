
void setup()  
{
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  //Serial.println("Goodnight moon!");

}

void loop() // run over and over
{
  if (Serial.available()){
    Serial.write(Serial.read());
  }
}

