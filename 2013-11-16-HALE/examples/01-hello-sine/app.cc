#include "thelonious.h"
#include "elvin.h"
#include "miles.h"
#include "main.h"

using namespace thelonious;
using namespace elvin;
using namespace miles;

// Create generators and effects
auto sine = Sine();


void setup() {
    // Perform any setup tasks

}

void loop() {
    // Perform any repeated tasks 

}

void audio() {
    // Create audio and send it to the device
    sine * 1.f >> device;
}
