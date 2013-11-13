#include "thelonious.h"
#include "elvin.h"
#include "miles.h"
#include "main.h"

using namespace thelonious;
using namespace elvin;
using namespace miles;

// Create generators and effects
auto osc1 = Sine();
auto osc2 = Sine();
auto osc3 = Sine();

void setup() {
    // Perform any setup tasks
    auto freq = 220.0;
    freq >> osc1.frequency;
    freq * 4.0 / 3.0 >> osc2.frequency;
    freq * 2.0 >> osc3.frequency;

}

void loop() {
    // Perform any repeated tasks 

}

void audio() {
    // Create audio and send it to the device
    osc1 * 0.1 + osc2 * 0.05 + osc3 * 0.05 >> device;
}
