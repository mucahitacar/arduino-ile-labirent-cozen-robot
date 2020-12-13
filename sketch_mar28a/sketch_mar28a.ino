#define onechoPin 12 //Ultrasonik sensÃ¶rÃ¼n echo pini Arduino'nun 12.pinine
#define ontrigPin 13
#define solechoPin 11 //Ultrasonik sensÃ¶rÃ¼n echo pini Arduino'nun 12.pinine
#define soltrigPin 10
#define sagechoPin 2 //Ultrasonik sensÃ¶rÃ¼n echo pini Arduino'nun 12.pinine
#define sagtrigPin 8//Ultrasonik sensÃ¶rÃ¼n trig pini Arduino'nun 13.pinine tanÄ±mlandÄ±.
#define MotorR1 4
#define MotorR2 3
#define MotorRE 5  // Motor pinlerini tanÄ±mlÄ±yoruz.
#define MotorL1 6
#define MotorL2 7
#define MotorLE 9



long sure,sure3,sure2, uzaklik , uzaklik2 , uzaklik3; //sÃ¼re ve uzaklÄ±k diye iki deÄŸiÅŸken tanÄ±mlÄ±yoruz.

void setup() {


  // ultrasonik sensÃ¶r Trig pininden ses dalgalarÄ± gÃ¶nderdiÄŸi iÃ§in OUTPUT (Ã‡Ä±kÄ±ÅŸ),
  // bu dalgalarÄ± Echo pini ile geri aldÄ±ÄŸÄ± iÃ§in INPUT (GiriÅŸ) olarak tanÄ±mlanÄ±r.
  pinMode(onechoPin, INPUT);
  pinMode(ontrigPin, OUTPUT);
  pinMode(solechoPin, INPUT);
  pinMode(soltrigPin, OUTPUT);
  pinMode(sagechoPin, INPUT);
  pinMode(sagtrigPin, OUTPUT);

  pinMode(MotorL1, OUTPUT);
  pinMode(MotorL2, OUTPUT);
  pinMode(MotorLE, OUTPUT); //MotorlarÄ±mÄ±zÄ± Ã§Ä±kÄ±ÅŸ olarak tanÄ±mlÄ±yoruz.
  pinMode(MotorR1, OUTPUT);
  pinMode(MotorR2, OUTPUT);
  pinMode(MotorRE, OUTPUT);


  Serial.begin(9600);

}

void loop() {

  

  digitalWrite(ontrigPin, LOW); //sensÃ¶r pasif hale getirildi
  delayMicroseconds(5);
  digitalWrite(ontrigPin, HIGH); //Sensore ses dalgasÄ±nÄ±n Ã¼retmesi iÃ§in emir verildi
  delayMicroseconds(10);
  digitalWrite(ontrigPin, LOW); //Yeni dalgalarÄ±n Ã¼retilmemesi iÃ§in trig pini LOW konumuna getirildi

  sure = pulseIn(onechoPin, HIGH); //ses dalgasÄ±nÄ±n geri dÃ¶nmesi iÃ§in geÃ§en sure Ã¶lÃ§Ã¼lÃ¼yor
  uzaklik = sure / 29.1 / 2; //Ã¶lÃ§Ã¼len sÃ¼re uzaklÄ±ÄŸa Ã§evriliyor

  digitalWrite(soltrigPin, LOW); //sensÃ¶r pasif hale getirildi
  delayMicroseconds(5);
  digitalWrite(soltrigPin, HIGH); //Sensore ses dalgasÄ±nÄ±n Ã¼retmesi iÃ§in emir verildi
  delayMicroseconds(10);
  digitalWrite(soltrigPin, LOW); //Yeni dalgalarÄ±n Ã¼retilmemesi iÃ§in trig pini LOW konumuna getirildi

  sure2 = pulseIn(solechoPin, HIGH); //ses dalgasÄ±nÄ±n geri dÃ¶nmesi iÃ§in geÃ§en sure Ã¶lÃ§Ã¼lÃ¼yor
  uzaklik2 = sure2 / 29.1 / 2; //Ã¶lÃ§Ã¼len sÃ¼re uzaklÄ±ÄŸa Ã§evriliyor

  digitalWrite(sagtrigPin, LOW); //sensÃ¶r pasif hale getirildi
  delayMicroseconds(5);
  digitalWrite(sagtrigPin, HIGH); //Sensore ses dalgasÄ±nÄ±n Ã¼retmesi iÃ§in emir verildi
  delayMicroseconds(10);
  digitalWrite(sagtrigPin, LOW); //Yeni dalgalarÄ±n Ã¼retilmemesi iÃ§in trig pini LOW konumuna getirildi

  sure3 = pulseIn(sagechoPin, HIGH); //ses dalgasÄ±nÄ±n geri dÃ¶nmesi iÃ§in geÃ§en sure Ã¶lÃ§Ã¼lÃ¼yor
  uzaklik3 = sure3 / 29.1 / 2; //Ã¶lÃ§Ã¼len sÃ¼re uzaklÄ±ÄŸa Ã§evriliyor
  Serial.println(uzaklik);
  
  
  if(uzaklik > 10){ // UzaklÄ±k 15'den kÃ¼Ã§Ã¼k ise,
   ileri();
  //delay(100);
  }
    else{
    if(uzaklik2 < 20){
     
      sag();
      delay(500);
    } 
      else{
      sol();
      delay(500);
      }
    } 
  
  
  }





void ileri(){  // Robotun ileri yÃ¶nde hareketi iÃ§in fonksiyon tanÄ±mlÄ±yoruz.

  digitalWrite(MotorR1, HIGH); // SaÄŸ motorun ileri hareketi aktif
  digitalWrite(MotorR2, LOW); // SaÄŸ motorun geri hareketi pasif
  analogWrite(MotorRE, 115 ); // SaÄŸ motorun hÄ±zÄ± 150

  digitalWrite(MotorL1, HIGH); // Sol motorun ileri hareketi aktif
  digitalWrite(MotorL2, LOW); // Sol motorun geri hareketi pasif
  analogWrite(MotorLE, 100); // Sol motorun hÄ±zÄ± 150
  
  
}


void sag(){ // Robotun saÄŸa dÃ¶nme hareketi iÃ§in fonksiyon tanÄ±mlÄ±yoruz.

  digitalWrite(MotorR1, HIGH); // SaÄŸ motorun ileri hareketi aktif
  digitalWrite(MotorR2, LOW); // SaÄŸ motorun geri hareketi pasif
  analogWrite(MotorRE, 0); // SaÄŸ motorun hÄ±zÄ± 0 (Motor duruyor)

  digitalWrite(MotorL1, HIGH); // Sol motorun ileri hareketi aktif
  digitalWrite(MotorL2, LOW); // Sol motorun geri hareketi pasif
  analogWrite(MotorLE, 160); // Sol motorun hÄ±zÄ± 150
  
  
}
void sol(){ // Robotun saÄŸa dÃ¶nme hareketi iÃ§in fonksiyon tanÄ±mlÄ±yoruz.

  digitalWrite(MotorR1, HIGH); // SaÄŸ motorun ileri hareketi aktif
  digitalWrite(MotorR2, LOW); // SaÄŸ motorun geri hareketi pasif
  analogWrite(MotorRE, 180); // SaÄŸ motorun hÄ±zÄ± 0 (Motor duruyor)

  digitalWrite(MotorL1, HIGH); // Sol motorun ileri hareketi aktif
  digitalWrite(MotorL2, LOW); // Sol motorun geri hareketi pasif
  analogWrite(MotorLE, 0); // Sol motorun hÄ±zÄ± 150
  
  
}


void geri(){ // Robotun geri yÃ¶nde hareketi iÃ§in fonksiyon tanimliyoruz.

  digitalWrite(MotorR1, LOW); // SaÄŸ motorun ileri hareketi pasif
  digitalWrite(MotorR2, HIGH); // SaÄŸ motorun geri hareketi aktif
  analogWrite(MotorRE, 0); // SaÄŸ motorun hÄ±zÄ± 150

  digitalWrite(MotorL1, LOW); // Sol motorun ileri hareketi pasif
  digitalWrite(MotorL2, HIGH); // Sol motorun geri hareketi aktif
  analogWrite(MotorLE, 0); // Sol motorun hÄ±zÄ± 150
  }
