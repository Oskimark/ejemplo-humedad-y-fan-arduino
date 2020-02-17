#include <DHT.h> //libreria para el lector de humedad
#define DHTPIN 2 //el pin en el que leemos el valor
#define DHTTYPE DHT11 
#define tomarmedida 4 //en este pin va un transistor a modo de rele que activa un divisor de tension para medir la bateria
float humedad;  //variable para la humedad

DHT dht(DHTPIN, DHTTYPE); //creamos un objeto del tipo DHT llamado dht muy original


void setup() {
dht.begin(); //iniciamos el sensor


}
void loop() {    //este sera el loop de nuestro programa
  leer_voltios()  //primero antes de medir la humedad y prender el ventilador medimos la bateria por las dudas, la funcion esta al final
 delay(2000);
 //me falta un if para decidir dependiendo de la bateria si continuamos o no.
 //aca continua nomas
dht.readHumidity(humedad);//lee la humedad y la pasa a la variable
if (humedad>70) //si es mas que un valor determinado que es fijo pero se podria regular externamente  

{digitalWrite(5, HIGH);//prendemos el ventilador
delay(10000); //durante 10 segundos
}
//regresamos al inicio cuantas veces sea necesario mientras tengamos bateria
 
}

void leer_voltios()//es una funcion para leer la carga de la bateria para cuando llega a un nivel no continuar gastando bateria y poder dar un aviso sonoro
{
 
digitalWrite(tomarmedida,HIGH);
float  voltios;
voltios= (analogRead(A0))*0,004887585533*4.9000;
if (voltios<=2.50)

{tone(6, 400, 10);//esto hace sonar un tono de 400hz durante 10 milisegundos
}
}
