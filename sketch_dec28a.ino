

#include <Keypad.h>


const byte satir = 4;
const byte sutun = 4;

char tus_takimi[satir][sutun] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}

};

byte satir_pinleri[satir] = {9, 8, 7, 6};
byte sutun_pinleri[sutun] = {5, 4, 3, 2};

Keypad kasa = Keypad(makeKeymap(tus_takimi), satir_pinleri, sutun_pinleri, satir, sutun);

String girilen_sifre="";
String sifre="1234#";

#define kirmizi 10    // ledlerin ve buzzerın pin değerleri 
#define yesil 11
#define buzzer 12

int control=0;
int ldr=A0;

void setup() {
  
  Serial.begin(9600);
  pinMode(kirmizi,OUTPUT);
  pinMode(yesil,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(A0,INPUT);


}

void loop() {
 
 int ldrdeger=analogRead(ldr);

while(1){
 if(ldrdeger<800) // burada değeri ölçtüğün değere göre değiştir
 control=1;
 if(control==1)
 {
   digitalWrite(kirmizi,HIGH);
   digitalWrite(buzzer,HIGH);

  }

  char tus = kasa.getKey();

   if (tus != NO_KEY)
  {
    girilen_sifre = girilen_sifre+tus;
  }
   if(tus == '#') // #'i Enter tuşu gibi düşünebiliriz
   {
     if(girilen_sifre==sifre){
       digitalWrite(yesil,HIGH);
       digitalWrite(kirmizi,LOW);
       digitalWrite(buzzer,LOW);
       delay(1000);
       digitalWrite(yesil,LOW);
       control=0;
     }

   }     
}

}
