#define GPI_LOW_PIN   30
#define GPI_NUM_PINS  8

#define PWM_PIN_LOW   2
#define PWM_NUM_PINS  12


void setup() {

  for (int pin=GPI_LOW_PIN; pin<(GPI_LOW_PIN +GPI_NUM_PINS) ; pin++){
    pinMode(pin, INPUT);           // set pin to input
    digitalWrite(pin, HIGH);       // turn on pullup resistor
  }

  for (int pin=PWM_PIN_LOW; pin<(PWM_PIN_LOW +PWM_NUM_PINS) ; pin++){
    pinMode(pin, OUTPUT);
  }

}


void loop() {
                              // Camera 1
  if (digitalRead(30) == 0)
    RGB_color(2, 256, 0, 0);           // Red
  else if (digitalRead(31) == 0)
    RGB_color(2, 0, 0, 16);            // Green
  else
    RGB_color(2, 0, 16, 0);            // Blue

                              // Camera 2
  if (digitalRead(32) == 0)
    RGB_color(5, 256, 0, 0);           // Red
  else if (digitalRead(33) == 0)
    RGB_color(5, 0, 0, 16);            // Green
  else
    RGB_color(5, 0, 16, 0);            // Blue


                              // Camera 3
  if (digitalRead(34) == 0)
    RGB_color(8, 256, 0, 0);           // Red
  else if (digitalRead(35) == 0)
    RGB_color(8, 0, 0, 16);            // Green
  else
    RGB_color(8, 0, 16, 0);            // Blue



                              // Camera 4
  if (digitalRead(36) == 0)
    RGB_color(11, 256, 0, 0);           // Red
  else if (digitalRead(37) == 0)
    RGB_color(11, 0, 0, 16);            // Green
  else
    RGB_color(11, 0, 16, 0);            // Blue
}


void RGB_color(int base_pin, int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(base_pin,     red_light_value);
  analogWrite(base_pin +1,  green_light_value);
  analogWrite(base_pin +2,  blue_light_value);
}
