#include <Stepper.h>

Stepper motoresElevacion(200, 9, 10, 11, 12);
Stepper motorDesplazamiento(200, 5, 6, 7, 8);

int posicionActual = 0; 

void setup() {
  Serial.begin(38400); 
  motoresElevacion.setSpeed(120);   
  motorDesplazamiento.setSpeed(180); 
}

void liberarMotores() {
  for (int i = 5; i <= 12; i++) {
    digitalWrite(i, LOW);
  }
}

void servirShot() {
  motoresElevacion.step(2400);  
  delay(2700);                  
  motoresElevacion.step(-2400); 
  delay(500);
  liberarMotores();
}

void irA(int nuevaPosicion) {
  int pasosAMover = nuevaPosicion - posicionActual;
  motorDesplazamiento.step(pasosAMover);
  posicionActual = nuevaPosicion; 
  delay(800);
  liberarMotores();
  delay(200);
}

void loop() {
  if (Serial.available() > 0) {
    char seleccion = Serial.read(); 

    if (seleccion == 'A') { 
      irA(1600); servirShot(); 
      irA(1066); servirShot(); 
      irA(533);  servirShot(); 
      irA(0);    servirShot(); 
    }
    
    else if (seleccion == 'B') { 
      irA(1600); servirShot(); servirShot(); 
      irA(533);  servirShot(); servirShot(); 
      irA(0); 
    }
    
    else if (seleccion == 'C') { 
      irA(1066); servirShot(); servirShot(); 
      irA(533);  servirShot();                
      irA(0);    servirShot();                
    }
    
    else if (seleccion == 'D') { 
      irA(533);  servirShot(); servirShot(); 
      irA(0);    servirShot(); servirShot(); 
    }
  } 
}