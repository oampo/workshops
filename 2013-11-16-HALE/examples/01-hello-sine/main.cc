#include <thread>

#include "main.h"

void setup();
void loop();
void audio();

thelonious::AudioDevice device(AUDIO_DEVICE, AUDIO_DEVICE);

int main() {
    setup();

    device.onAudio(audio);
    device.start();
    
    while (1) {
        loop();
        std::this_thread::yield();
    }
}
