#define GPI_LOW_PIN   32
#define GPI_NUM_PINS  8

#define PWM_PIN_LOW   2
#define PWM_NUM_PINS  12


void setup() {

  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  for (int pin=PWM_PIN_LOW; pin<(PWM_PIN_LOW +PWM_NUM_PINS) ; pin++){
    pinMode(pin, OUTPUT);
  }

  for (int pin=GPI_LOW_PIN; pin<(GPI_LOW_PIN +GPI_NUM_PINS) ; pin++){
    pinMode(pin, INPUT_PULLUP);
  }

  Serial.println("Starting ...");
}


void loop() {
  unsigned char val=0;

  
  //delay(1000);

  //for (int pin=GPI_LOW_PIN; pin<(GPI_LOW_PIN +GPI_NUM_PINS) ; pin++){
    //Serial.print(pin);
    //Serial.print("=");
    //Serial.print(digitalRead(pin));
    //Serial.print(" ");
  //}
  //Serial.println("");


                              // Camera 1
  if (digitalRead(32) == 0)
    RGB_color(2, 128, 0, 0);           // Red
  else if (digitalRead(36) == 0)
    RGB_color(2, 0, 5, 0);           // Green
  else
    RGB_color(2, 0, 0, 1);            // Blue

                              // Camera 2
  if (digitalRead(33) == 0)
    RGB_color(5, 128, 0, 0);           // Red
  else if (digitalRead(37) == 0)
    RGB_color(5, 0, 5, 0);            // Green
  else
    RGB_color(5, 0, 0, 1);            // Blue


                              // Camera 3
  if (digitalRead(34) == 0)
    RGB_color(8, 128, 0, 0);           // Red
  else if (digitalRead(38) == 0)
    RGB_color(8, 0, 5, 0);            // Green
  else
    RGB_color(8, 0, 0, 1);            // Blue

                              // Camera 4
  if (digitalRead(35) == 0)
    RGB_color(11, 128, 0, 0);           // Red
  else if (digitalRead(39) == 0)
    RGB_color(11, 0, 5, 0);            // Green
  else
    RGB_color(11, 0, 0, 1);            // Blue
}


void RGB_color(int base_pin, int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(base_pin,     red_light_value);
  analogWrite(base_pin +1,  green_light_value);
  analogWrite(base_pin +2,  blue_light_value);
}
