/* For benchmark
 *  
 * References:
 *  - Assembly: https://forum.arduino.cc/t/intermediate-asm-code/501460/5
 *  - Speed test: https://www.instructables.com/SpeedTest-Arduinos-ESP32-8266s-STM32/
 * 
 * Simulation (Tinkercad):
 *  https://www.tinkercad.com/things/2vmFgHdwR1K 
 * 
 * Execution time: 
 *  - Tinkercad:      2778ms (NO LED), 11303ms (WITH LED)
 *  - Arduino UNO R3:    0ms (NO LED),  3379ms (WITH LED)
 */

unsigned int tic;
unsigned int tac;
boolean state = false;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  
  // No LED, 1000000 iterations
  tic = millis();
  for (unsigned long i = 0; i <= 1000000; i++){
    continue;
  }
  tac = millis();
  Serial.print(tac - tic);
  Serial.print("ms (NO LED)\n");
  
  // With LED, 1000000 iterations
  tic = millis();
  for (unsigned long i = 0; i <= 1000000; i++){
  if (i >= 500000){
    if (state){
      digitalWrite(LED_BUILTIN, HIGH);
      state = !state;
    }
    else {
      digitalWrite(LED_BUILTIN, LOW);
      state = !state;
    }
  }
  }
  tac = millis();
  Serial.print(tac - tic);
  Serial.print("ms (WITH LED)\n");
}

void loop(){}
