int m1a = 12;
int m1b = 11;
int m2a = 10;
int m2b = 9;// usamos un pin de salida al LED
char state; // Variable lectrura serial
 
void setup() {
    pinMode( m1a, OUTPUT); 
    pinMode(m1b, OUTPUT); 
    pinMode(m2b, OUTPUT); 
    pinMode(m2a, OUTPUT); //Declara pin de Salida
       digitalWrite(m1a, LOW);
       digitalWrite(m1b, LOW);
       digitalWrite(m2a, LOW);
       digitalWrite(m2b, LOW); //Normalmente Apagado
    Serial.begin(9600);
}
 
void loop() {
 //si el modulo a manda dato, guardarlo en estado.
 if(Serial.available()){
       state = (char)Serial.read();
       if (state=='s'){
       digitalWrite(m1a, HIGH);
       digitalWrite(m1b, LOW);
       digitalWrite(m2a, HIGH);
       digitalWrite(m2b, LOW);
         delay(20);
       digitalWrite(m1a, LOW);
       digitalWrite(m1b, LOW);
       digitalWrite(m2a, LOW);
       digitalWrite(m2b, LOW);
                  
                  state='t'; 
        }
       else if(state=='w'){ 
       digitalWrite(m1a, LOW);
       digitalWrite(m1b, HIGH);
       digitalWrite(m2a, LOW);
       digitalWrite(m2b, HIGH);
                  state='t';  
                    delay(20);
       digitalWrite(m1a, LOW);
       digitalWrite(m1b, LOW);
       digitalWrite(m2a, LOW);
       digitalWrite(m2b, LOW);
          }
          else if(state=='a'){ 
       digitalWrite(m1a, LOW);
       digitalWrite(m1b, HIGH);
       digitalWrite(m2a, HIGH);
       digitalWrite(m2b, LOW);
                  state='t';  
                    delay(20);
       digitalWrite(m1a, LOW);
       digitalWrite(m1b, LOW);
       digitalWrite(m2a, LOW);
       digitalWrite(m2b, LOW);
          }
          else if(state=='d'){ 
       digitalWrite(m1a, HIGH);
       digitalWrite(m1b, LOW);
       digitalWrite(m2a, LOW);
       digitalWrite(m2b, HIGH);
         delay(20);
       digitalWrite(m1a, LOW);
       digitalWrite(m1b, LOW);
       digitalWrite(m2a, LOW);
       digitalWrite(m2b, LOW);
                  state='t';  
          }
         else{ 
          delay(20);
       digitalWrite(m1a, LOW);
       digitalWrite(m1b, LOW);
       digitalWrite(m2a, LOW);
       digitalWrite(m2b, LOW);
                  state='Y';  
          }
 }delay(20);
        Serial.flush();
    Serial.println(5);
 // delay(20);
  
}
