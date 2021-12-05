#include <BluetoothSerial.h>
BluetoothSerial BT;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  BT.begin("TestEsp32");//請改名
  pinMode(13,OUTPUT);
}
bool led=false;
void loop() {
  // put your main code here, to run repeatedly:
  while (BT.available()) {
    //讀取藍芽資料
    String BTdata=BT.readString();
    //顯示在序列視窗
    Serial.println(BTdata);
    if(BTdata=="a"){
      led=!led;
    }
    digitalWrite(13, led?HIGH:LOW);
  }
  delay(1);
}
