## Making a sine wave

So we can experiment with pitch and amplitude let's create a program which generates a sine wave.  Create a copy of the template folder and call it sine.  Then open up the file called app.cc in GEdit.

To create a sine wave generator we add this code to the top of the file:

```cpp
auto osc = Sine();
```

To understand this code we can look at it in two parts.  The `Sine()` part creates a sine wave generator.  The `auto osc =` part, says that the generator should be given the name `osc`.  The semi-colon at the end of the line tells the computer that this is the end of a command.

To set the **frequency** of the generator we add this code to the setup section:

```cpp
440 >> osc.frequency;
```

This sets the frequency to 440Hz (440 complete cycles of the wave every second).

Finally to set the **amplitude** of the generator and to play it through the headphone socket we add this code to the audio section:

```cpp
osc * 0.1 >> device;
```

Here we multiply the sine wave (using `*` to mean multiply) by 0.1, reducing its *amplitude* by 10.  We then use the double-arrows (`>>`) to output the wave to the device.

Your finished program should look like this:

```cpp
// Create generators and effects
auto osc = Sine();

void setup() {
    // Perform any setup tasks
    440.0 >> osc.frequency;
}

void loop() {
    // Perform any repeated tasks 

}

void audio() {
    // Create audio and send it to the device
    osc >> device;
}

```

Try to run the program.  You should hear a constant clear sound.  If the program gives you an error double-check your code to make sure you typed everything correctly.

### Experiments

Try changing the frequency of the generator.  What is the highest and lowest frequency you can hear?

Try changing the amplitude of the generator to find a level which is comfortable to listen to.

As well as a sine wave you can generate more complex waves.  Try changing the from `Sine` to `Triangle`, `Saw` or `Pulse`.  What do you notice about the different sounds?
