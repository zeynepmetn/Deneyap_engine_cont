#include "BluetoothSerial.h"
BluetoothSerial Serial_BT;      
  
    // Motor 1
int pwmPin = 31, // pwn pin sanırım bu (d0)
    d1 = 30, 
    d2 = 29;

int speed = 255

int data;

void setup(){
  // motor pinlerini ayarlanması
  pinMode(pwmPin, OUTPUT);
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);

  digitalWrite(pwmPin, HIGH);
  digitalWrite(d1, LOW);   
  digitalWrite(d2, LOW);

  // Ekrana yazdırma ile bluetooth aktifliğini kontrolü
  Serial.begin(9600);
  if (!Serial_BT.begin("Hamal")){
    Serial.println("Kullanım dışı ....");
    while(1);
  }
  Serial.println("Bağlantı Hazır ....");
}

void moveForward(){
  digitalWrite(d1, HİGH)
  digitalWrite(d2, LOW)
  analogWrite(pwmPin, speed)
  Serial.println(-------İleri gidiyor-------)
}
void moveBackward(){
  digitalWrite(d1, LOW)
  digitalWrite(d2, HİGH)
  analogWrite(pwmPin, speed)
  Serial.println(-------Geri gidiyor-------)
}
void stopMotor(){
  digitalWrite(d1, LOW)
  digitalWrite(d2, LOW)
  analogWrite(pwmPin, 0)
  Serial.println(------Motor durdu-------)
}

void loop(){
  if (Serial_BT.available()){
    data = Serial_BT.read();
    if (data == 'F'){
      moveForward();
    }
    else if (data == 'B'){
      moveBackward();
    }
    else if (data == '0'){
      stopMotor();
    }
  }
}