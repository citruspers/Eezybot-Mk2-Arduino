# Eezybot-Mk2-Arduino
Code and diagram for controlling the Eezybot mk2 using an Arduino and some basic components

![Fully Assembled](http://i.imgur.com/SRPi8C9.jpg)

**Scope/target audience:** You've just printed your eezybot mk2 and want to try it out? This code should help.
Want to write your own code? Feel free to use this as a starting point, or just a reference.

**Requirements:**

* 1x Arduino (I used the Uno)
* 3x potmeter
* 1x 1kOhm resistor
* 1x button
* 1x SG90 servo motor
* 3x MG995 Servo
* 1x breadboard
* Plenty of dupont leads (you never have enough....)
* External power supply capable of 5V, 3A (you can probably get by with 2A if you're careful and use good potmeters)

**Instructions:**

Wire everything up as described in the picture. There's also some documentation in the code regarding which pin goes where.
![wiring](http://i.imgur.com/EC3LxnJ.jpg)

**Notes:**

I've seen these servo units consume up to .6A at 5V, so make sure your power supply is up to the task. You should be alright if you only move 1 stepper at a time, but beware that cheaper potmeters can cause erratic/jittery behavior (which in turn increases power draw because the servos don't idle but jitter back and forth).
Therefore a PROPER power supply (preferrably one which shows the power draw real-time) is heavily recommended.

Please also keep in mind that your claw servo open and closed values may differ from mine depending on how you attached it.
