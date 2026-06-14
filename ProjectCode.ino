int moisturesensor = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int rawValue = analogRead(moisturesensor);

  Serial.print("Sensor value: ");
  Serial.print(rawValue);
  Serial.print("   ");

  // category and watering advice
  if(rawValue == 0){
    Serial.println("Nothing Detected!");
  }
  else if (rawValue >= 1 && rawValue <= 150) {
    Serial.print("Too dry! ");
    Serial.println(" Add plenty of water (the soil is very dry).");
  }
  else if (rawValue >= 150 && rawValue < 200) {
    Serial.print("Slightly dry. ");
    Serial.println(" Add a small amount of water.");
  }
  else if (rawValue >= 200 && rawValue <= 300) {
    Serial.print("Perfectly watered! ");
    Serial.println(" No watering needed.");
  }
  else if (rawValue > 300 && rawValue < 800) {
    Serial.print("Moist soil. ");
    Serial.println(" Avoid watering for now.");
  }
  else {
    Serial.print("Over-watered! ");
    Serial.println(" Stop watering immediately and let the soil dry.");
  }

  delay(5000);
}

