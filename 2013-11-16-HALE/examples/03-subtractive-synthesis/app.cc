#include "thelonious.h"
#include "elvin.h"
#include "miles.h"
#include "main.h"

using namespace thelonious;
using namespace elvin;
using namespace miles;

// Create generators and effects
auto osc = Pulse();
auto filter = LowPassFilter();

void setup() {
    // Perform any setup tasks
    220.0 >> osc.frequency;
    880.0 >> filter.frequency;
}

void loop() {
    // Perform any repeated tasks 
}

void audio() {
    // Create audio and send it to the device
    osc * 0.2 >> filter >> device;
}
