int sensor1 = A0; //Input Photodioda 1
int sensor2 = A1; //Input Photodioda 2
int sensor3 = A2; //Input Photodioda 3
int sensor4 = A3; //Input Photodioda 4
int sensor5 = A4; //Input Photodioda 5
int sensor6 = A5; //Input Photodioda 6
int baca_sensor[6]; 

int pinEnable = 4; //Aktifkan motor kiri
int pinEnable2 = 2; //Aktifkan motor kanan

int motor_L1 = 5; //Input motor kiri
int motor_L2 = 6; //Input motor kiri

int motor_R1 = 3; //Input motor kanan
int motor_R2 = 11; //Input motor kanan

void setup()
{
  //Set photodioda sebagai input
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(sensor5, INPUT);
  pinMode(sensor6, INPUT);
  
  //Set motor kanan & kiri sebagai output
  pinMode(pinEnable, OUTPUT);
  pinMode(pinEnable2, OUTPUT);

  pinMode(motor_L1, OUTPUT);
  pinMode(motor_L2, OUTPUT);
  
  pinMode(motor_R1, OUTPUT);
  pinMode(motor_R2, OUTPUT);

  Serial.begin(9600);
}

void readsensor(){
  baca_sensor[0] = analogRead(sensor1);
  baca_sensor[1] = analogRead(sensor2);
  baca_sensor[2] = analogRead(sensor3);
  baca_sensor[3] = analogRead(sensor4);
  baca_sensor[4] = analogRead(sensor5);
  baca_sensor[5] = analogRead(sensor6);
  
  Serial.println(baca_sensor[0]);
 
}

void loop()
{
 readsensor();
  //Bila mana sensor 1 & 2 mendeteksi gelap maka motor kanan nyala
  if (baca_sensor[0] < 1 && baca_sensor[1] < 1 && baca_sensor[2] >= 1 && baca_sensor[3] >= 1 && baca_sensor[4] >= 1 && baca_sensor[5] >= 1)
  {
    digitalWrite(pinEnable, HIGH);
    digitalWrite(motor_L1, LOW);
    digitalWrite(motor_L2, LOW);
    digitalWrite(pinEnable2, HIGH);
    digitalWrite(motor_R1, HIGH);
    digitalWrite(motor_R2, LOW);
  }
  //Bila mana sensor 3 & 4 mendeteksi gelap maka ke dua motor akan nyala
  if (baca_sensor[0] >= 1 && baca_sensor[1] >= 1 && baca_sensor[2] < 1 && baca_sensor[3] < 1 && baca_sensor[4] >= 1 && baca_sensor[5] >= 1)
  {
    digitalWrite(pinEnable, HIGH);
    digitalWrite(motor_L1, HIGH);
    digitalWrite(motor_L2, LOW);
    digitalWrite(pinEnable2, HIGH);
    digitalWrite(motor_R1, HIGH);
    digitalWrite(motor_R2, LOW);
  }
  //Bila mana sensor 5 & 6 mendeteksi gelap maka motor kiri nyala
  if (baca_sensor[0] >= 1 && baca_sensor[1] >= 1 && baca_sensor[2] >= 1 && baca_sensor[3] >= 1 && baca_sensor[4] < 1 && baca_sensor[5] < 1)
  {
    digitalWrite(pinEnable, HIGH);
    digitalWrite(motor_L1, HIGH);
    digitalWrite(motor_L2, LOW);
    digitalWrite(pinEnable2, HIGH);
    digitalWrite(motor_R1, LOW);
    digitalWrite(motor_R2, LOW);
  }
  //Bila mana semua sensor mendeteksi gelap maka ke dua motor tidak akan nyala
  else {
    digitalWrite(pinEnable, HIGH);
    digitalWrite(motor_L1, LOW);
    digitalWrite(motor_L2, LOW);
    digitalWrite(pinEnable2, HIGH);
    digitalWrite(motor_R1, LOW);
    digitalWrite(motor_R2, LOW);
  }
}
