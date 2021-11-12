#include <DHT.h>
#include <DHT_U.h>
#include DHT11PIN 2
dht11 DHT11;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int chk = DHT11.read(DHT11PIN);

  Serial.print("Humidity (%): ");
  Serial.print((float)DHT11.temperature, 2);

  Serial.print("Temperature (Fahrenheit): ");
  Serial.println(DHT11.fahrenheit(), 2);

  Serial.print("Temperature (Kelvin): ");
  Serial.println(DHT11.kelvin(), 2);

  Serial.print("Dew point: ");
  Serial.println(DHT11.dewPoint(), 2);
}
