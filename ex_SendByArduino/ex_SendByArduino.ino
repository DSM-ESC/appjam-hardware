#include <SoftwareSerial.h>
String str;
int i = 0;
SoftwareSerial Serial1(3, 2); // RX, TX
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial1.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  str =String("Hello World!") + String(i);
  Serial.println(str);
  Serial1.println(str);
  i++;
  delay(5000);
}
