const int sensorPin = A0;
const int sensorVerm = A1;
const int sensorAmar = A2;
const int sensorVerd = A3;

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}
void loop() {
  int sensorDeAgua = analogRead(sensorPin);
  int sensorVermelho = analogRead(sensorVerm);
  int sensorVerde = analogRead(sensorVerd);
  int sensorAmarelo = analogRead(sensorAmar);
  Serial.print("Retorno do sensor de agua: ");
  Serial.println(sensorDeAgua);
  Serial.print("Retorno Led Verde: ");
  Serial.println(sensorVerde);
  Serial.print("Retorno Led Amarela: ");
  Serial.println(sensorAmarelo);
  Serial.print("Retorno Led Vermelha: ");
  Serial.println(sensorVermelho);
  if(sensorDeAgua > 300 and sensorDeAgua <= 700){
    digitalWrite(4, LOW);
  	digitalWrite(3, HIGH);
    digitalWrite(2, LOW);
  }else if(sensorDeAgua > 700){
  	digitalWrite(3, LOW);
    digitalWrite(2, LOW);
  	digitalWrite(4, HIGH);
  }else{
  	digitalWrite(3, LOW);
    digitalWrite(2, HIGH);
  	digitalWrite(4, LOW);
  }
  
  if(sensorVermelho > 500 and sensorVerde > 500 and sensorAmarelo > 500){
  	Serial.println("LED QUEBROU! ");
  }else{
  	Serial.println("LED FUNCIONANDO! ");
  }
  delay(1000);
}
