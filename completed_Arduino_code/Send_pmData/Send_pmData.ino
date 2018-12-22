#include <pm2008_i2c.h>
#include <SoftwareSerial.h>
SoftwareSerial Serial1(3,2);
PM2008_I2C pm2008_i2c;

void setup() {
  // put your setup code here, to run once:
  pm2008_i2c.begin();
  pm2008_i2c.command();
  delay(1000);

  Serial1.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
   uint8_t ret = pm2008_i2c.read();
   int pm = pm2008_i2c.pm1p0_grimm;
   
   if(ret == 0)
   {
      Serial1.println(pm);
   }
   delay(10000);
}
