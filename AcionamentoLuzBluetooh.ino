#define rele 4
#define RX 11
#define TX 10
#include <SoftwareSerial.h>

SoftwareSerial bluetooth(TX, RX);

void setup() 
{  
  Serial.begin(9600);
  pinMode(rele, OUTPUT);
  //Comecar desligado
  digitalWrite(rele,HIGH);
  
  //comunicação bluetooh
  bluetooth.begin(9600);
  bluetooth.println("Digite 0 para acionar o interruptor");  
}

void loop() 
{  
  bluetooh();
}

void bluetooh()
{
    byte BluetoothData;
  if (bluetooth.available() > 0) {
    BluetoothData=bluetooth.read();
      switch (BluetoothData) {
      case '0':
        digitalWrite(rele,digitalRead(rele)^1);
        bluetooth.println("botao pressionado");
        break;
      default:
        bluetooth.println("Mensagem invalida");
        bluetooth.println("Digite 0 para ligar ou desligar o rele");
    }
  }
  delay(100);
}

