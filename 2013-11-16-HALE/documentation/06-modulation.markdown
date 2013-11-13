## Modulation

When you listen to music you often don't hear constant tones.  Instead, the sounds change over time.  This change is called **modulation**.  We can use modulation to vary the frequency and amplitude of a wave we generate.

To try out modulating sound let's use a **low frequency oscillator** (LFO) to change the frequency of the wave.  An LFO is simply another wave running at a frequency low enough that we can't hear it.

First we need to create our wave generator and our LFO.

```cpp
auto osc = Saw();
auto lfo = Triangle();
```

Next we can set the frequency of the LFO.

```cpp
0.5 >> lfo.frequency;
```

Finally we can use the lfo to control the frequency of the generator.

```cpp
lfo * 100 + 220 >> osc;
osc * 0.1 >> output;
```

Notice how we multiply the LFO by 100.  This sets the **depth** of the LFO meaning it changes the frequency by up to 100Hz.  We then add 220 to the LFO.  This sets the frequency of the wave generator.  This means that the final frequency will range between 120Hz (220Hz - 100Hz)and 320Hz (220Hz + 100Hz).

Your finished program should look something like this:

```cpp
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
```

### Experiment

- Try altering the modulation depth.
- Try changing the frequency of the LFO to something in the hearable range.
- Try using different waves to modulate the sound.
- Try modulating the amplitude of a wave.  (Hint: Your modulator will need to range between 0 and 1 rather than 120 and 330)
- Try creating a filter and modulating its frequency.
- 
