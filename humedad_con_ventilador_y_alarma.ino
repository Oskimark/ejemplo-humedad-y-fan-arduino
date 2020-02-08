// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

// REQUIRES the following Arduino libraries:
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor

#include "DHT.h"

#define DHTPIN 2     // Digital pin connected to the DHT sensor

#define DHTTYPE DHT11   // DHT 11

// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.


DHT dht(DHTPIN, DHTTYPE); //creas un objeto del tipo DHT llamado dht, al que l epasas dos constantes que son el pin al que se conecta y el tipo de modulo usado.

void setup() {
  Serial.begin(9600);  //inicias la comunicacion serial por usb
  Serial.println(F("DHTxx test!")); //mandas una linea de texto con salto de linea por eso es println

  dht.begin();  //este comando inicia el sensor
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);//haces una espera de  2 segundos para que el sensor se estabilice y las medidas no peguen saltos

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();//lees el valor de humedad y lo guardas en una variable h
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature(); //lees la temperatura y la guardas en la variable t
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));//el sensor puede dar valores incorrectos por mala coneccion o por baja bateria  o otro problema, si esto ocurre lo reporta por serial
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));

//aca es donde tendrias que comparar el valor con la humedad que vos queres seteary actuar acorde. 
if h > 60 (
    sonar alarma durante 5 segundos
    pinmode(3, high);
    delay(5000);
    pinmode(3, low);
    //prender el ventilador por x segundos
    pinmode(4, high);
    delay(xsegundos);
    pinmode(4, low);

    //ahora podes optar por chequear otra vez l ahumedad y repetir el ciclo o ir directo a reposo profundo durante unos minutos ...
    
    
    
    
    deepsleep(200000)
    

  
}
