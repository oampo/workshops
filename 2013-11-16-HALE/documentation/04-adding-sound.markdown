## Adding sounds

So far we have seen how to create a sine wave and some other simple types of waveform.  But how are these related to the complex sounds which we hear every da?  The answer came from the French mathematician Joseph Fourier.  He discovered that any sound can be constructed by adding together a series of sine waves.

Musicians used this idea of adding together waves with different frequencies to create more complex sounds.  They called it **additive synthesis**.  So, let's write a simple additive synthesizer which combines three sine waves.

First we need to create our three sine waves:

```cpp
auto osc1 = Sine();
auto osc2 = Sine();
auto osc3 = Sine();
```

Then we set the frequency of each wave:

```cpp
auto freq = 220.0;
freq >> osc1;
freq * 4.0 / 3.0 >> osc2;
freq * 2.0 >> osc3;
```

Notice how we give the name `freq` to the frequency of the first sine wave.  We multiply and divide this to set the frequency of the other waves.

Finally we set the amplitude of the three waves and add them together.

```cpp
(osc1 * 0.1 + osc2 * 0.05 + osc3 * 0.05) >> device;
```

Your finished program should look something like this:

```cpp
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
```

### Experiment

Try changing the frequencies of the three generators.  See what happens when you don't use whole numbers for the multipliers.

Change the amplitudes of the generators.  What do you notice about the sounds?

Try using different types of wave.  Can you come up with combinations that you like or dislike?




