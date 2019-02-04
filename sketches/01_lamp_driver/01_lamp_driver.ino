#include <Adafruit_NeoPixel.h>
#include <CapacitiveSensor.h>

#define PIN_DATA 4          // DIN to Neo Pixels
#define PIN_LED 1           // LED on Model B=PIN0, LED on Model A=PIN1
#define PIN_SENSE_READ 0    // Read for capacitive sensor
#define PIN_SENSE_DRIVE 2   // Drive V for capacitive sensor

#define N_PIXELS 4

// threshold to detect a capacitive touch (0-999)
#define CAP_THRESHOLD 50 

// number of samples for capacitive sensor
#define CAP_NUM_SAMPLES 10 

// debounce timing (ms)
#define DEBOUNCE_MS 250 

// colors
const uint32_t pixel_colors[] = {
  0x7F0000, // red
  0x6F3F00, // orange
  0x5F5F00, // yellow
  0x007F00, // green
  0x00007F, // blue
  0x3F006F, // indigo
  0x4F2F4F  // violet
};
uint8_t const num_colors = sizeof(pixel_colors)/sizeof(uint32_t);
int8_t current_color = 0;

Adafruit_NeoPixel pixels (N_PIXELS,PIN_DATA,NEO_GRBW+NEO_KHZ800);
CapacitiveSensor cap_sensor (PIN_SENSE_DRIVE, PIN_SENSE_READ);

bool cap_button_clicked() {
  long const val = cap_sensor.capacitiveSensor(CAP_NUM_SAMPLES); 
  return (val > CAP_THRESHOLD);
}

void change_color(int8_t step) {
  current_color += step;
  if (current_color >= num_colors) {
    current_color = 0;
  } else if (current_color < 0) {
    current_color = num_colors - 1;
  }
  for (int p = 0; p < N_PIXELS; ++p) {
    pixels.setPixelColor(p,pixel_colors[current_color]);
  }
  pixels.show();
}


void setup() {
  pinMode(PIN_LED, OUTPUT); 
  pinMode(PIN_SENSE_READ, INPUT);
  pinMode(PIN_SENSE_DRIVE, OUTPUT);
  pixels.begin();
  delay(500);
  for (int p = 0; p < N_PIXELS; ++p) {
    pixels.setPixelColor(p,0);
  }
  pixels.show();

}

uint8_t toggle = 0;
void loop() {
    if (cap_button_clicked()) {
      change_color(1);
    }

    digitalWrite(PIN_LED, toggle);
    toggle = (toggle == 0 ? 1 : 0);
    delay(DEBOUNCE_MS);

    
}
