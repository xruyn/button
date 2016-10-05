#include <Arduino.h>

int regim=0;
int flag=0;
int val=0;
long prevMillis = 0;

void setup()
{
        Serial.begin(9600);
        pinMode(13,OUTPUT);
        //pinMode(9,OUTPUT);12

}

void loop(){
        if (regim == 0) {
                digitalWrite(13,HIGH);
                delay(1000);
                digitalWrite(13,LOW);
                delay(1000);
                digitalWrite(13,HIGH);
                Serial.println("Основной режим");
        }


        if(digitalRead(2)==HIGH&&flag==0)//если кнопка нажата
        // и перемення flag равна 0 , то ...
        {
                regim++;
                flag=1;




                //это нужно для того что бы с каждым нажатием кнопки
                //происходило только одно действие
                // плюс защита от "дребезга"  100%

                if(regim>2)//ограничим количество режимов
                {
                        regim=0;//так как мы используем только одну кнопку,
                                // то переключать режимы будем циклично
                }

        }
        

        if(digitalRead(2)==LOW&&flag==1)//если кнопка НЕ нажата
        //и переменная flag равна - 1 ,то ...
        {

                flag=0;//обнуляем переменную "knopka"
        }




        if(regim==1)//первый режим
        {
                digitalWrite(13,LOW);
                Serial.println("1 режим");


        }
        if(regim==2)//второй режим
        {
                digitalWrite(13,HIGH);//выключаем все светодиоды
                Serial.println("2 режим");


        }



}
