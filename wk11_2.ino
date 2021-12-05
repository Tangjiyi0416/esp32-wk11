#include <BluetoothSerial.h>
BluetoothSerial BT;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  BT.begin("TestEsp32");//請改名
  pinMode(16,OUTPUT);
  pinMode(17,OUTPUT);
  pinMode(18,OUTPUT);
  pinMode(19,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (BT.available()) {
    //讀取藍芽資料
    String BTdata=BT.readString();
    //顯示在序列視窗
    Serial.println(BTdata);
    int iData=BTdata.toInt();
    digitalWrite(16, iData&1);
    digitalWrite(17,(iData>>1)&1);
    digitalWrite(18,(iData>>2)&1);
    digitalWrite(19,(iData>>3)&1);
  }
  delay(1);
}
