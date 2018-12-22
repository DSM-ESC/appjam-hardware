#include <pm2008_i2c.h>

PM2008_I2C pm2008_i2c;

void setup() {
  pm2008_i2c.begin();
  Serial.begin(115200);
  pm2008_i2c.command();
  delay(1000);
}

void loop() {
  uint8_t ret = pm2008_i2c.read();
  if (ret == 0) {
    Serial.print(pm2008_i2c.pm10_grimm);
    Serial.println();
  }
  delay(5000);
}
