#include <thread>

#include "main.h"

void setup();
void loop();
void audio();

thelonious::AudioDeviceN<0, 1> device(AUDIO_DEVICE, AUDIO_DEVICE);

int main() {
    setup();

    device.onAudio(audio);
    device.start();
    
    while (1) {
        loop();
        std::this_thread::yield();
    }
}
