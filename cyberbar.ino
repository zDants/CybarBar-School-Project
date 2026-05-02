#include <Stepper.h>

Stepper motoresElevacion(200, 9, 10, 11, 12);
Stepper motorDesplazamiento(200, 5, 6, 7, 8);

void setup() {
  Serial.begin(38400); 
  motoresElevacion.setSpeed(120);   
  motorDesplazamiento.setSpeed(180); 
}

void liberarMotores() {
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
}

void servirShot() {
  motoresElevacion.step(2400);  
  delay(2700);                  
  motoresElevacion.step(-2400); 
  delay(500);
  liberarMotores();
}

void mover(int pasos) {
  motorDesplazamiento.step(pasos);
  delay(800); 
  liberarMotores();
  delay(200); 
}

void loop() {
  if (Serial.available() > 0) {
    char seleccion = Serial.read(); 

    if (seleccion == 'A') { 
      mover(1600); servirShot(); mover(-1600); 
      mover(1066); servirShot(); mover(-1066); 
      mover(533);  servirShot(); mover(-533); 
      servirShot(); 
    }
    
    else if (seleccion == 'B') { 
      mover(1600); servirShot(); servirShot(); mover(-1600); 
      mover(533);  servirShot(); servirShot(); mover(-533); 
    }
    
    else if (seleccion == 'C') { 
      mover(1066); servirShot(); servirShot(); mover(-1066); 
      mover(533);  servirShot(); mover(-533); 
      servirShot(); 
    }
    
    else if (seleccion == 'D') { 
      mover(533);  servirShot(); servirShot(); mover(-533); 
      servirShot(); servirShot(); 
    }
  } 
}