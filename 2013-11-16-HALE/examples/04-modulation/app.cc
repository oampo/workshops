#include "thelonious.h"
#include "elvin.h"
#include "miles.h"
#include "main.h"

using namespace thelonious;
using namespace elvin;
using namespace miles;

// Create generators and effects
auto osc = Saw();
auto lfo = Triangle();


void setup() {
    // Perform any setup tasks
    0.5 >> lfo.frequency;

}

void loop() {
    // Perform any repeated tasks 

}

void audio() {
    // Create audio and send it to the device
    lfo * 100 + 220 >> osc.frequency;
    osc * 0.1 >> device;
}
