# AquAlarm
Submission for Hack'n'Roll 2019, a 24 hour hackathon. Representing [VRMC](https://vrmc.github.io/index.html).

## Overview
An Arduino powered alarm clock contraption that **sprays water in your face if you don't wake up on time.**

Made possible by a ~haphazard~ combination of pneumatics, electromechanics, and embedded programming.

<a>
<img src="https://github.com/sp4ce-cowboy/AquAlarm/assets/19762596/3eb52954-7223-4ceb-b778-1b65cb06af59" align="center" height="380"/>
</a>
<a>
<img src="https://github.com/sp4ce-cowboy/AquAlarm/assets/19762596/68dd5610-f135-49e8-b797-5fd22a9312cc" align="center" height="380"/>
</a>

## Some Explanation
### Pneumatics
A solenoid value is hydraulically and pneumatically connected to a pressurized canister (made of PVC) containing plain water via pressure-rated polyurethane tubing. The canister itself can be pressured either via a schrader valve or a lighter valve, whereby either air or butane can act as fluid propellant. 

### Electromechanics
The solenoid valve is connected to a DC relay and Lithum-ion Polymer batteries. The DC relay is connected to an Arduino Nano board. The valve is normally closed, meaning that when no power is applied, it will stop fluid flow by default. When a power signal is sent from the Arduino to the relay, the circuit consisting of the solenoid valve and the DC relay is closed, and the pressure differential between atmospheric pressure and canister pressure causes the fluid in the canister to flow in the direction of lower pressure, through the solenoid valve.

### Software & Electronics
Powering the entire system, the Arduino is connected to a I2C 2x16 LCD board, a buzzer, an LED light system, a potentiometer, and a button. The potentiometer can be used to set the time of the alarm.

The code running on the Arduino board can be found in [this](https://github.com/sp4ce-cowboy/AquAlarm/blob/main/aqualarm/aqualarm.ino) file. The dependencies for driving the LCD display and providing for offline low level time and date functions are also included.

## Usage
1. The user positions the device pointing towards them, and sets the alarm before going to bed.
2. As the set alarm time approaches, the buzzer will begin emitting loud sounds.
4. Soon after, the LED lights will flash (together with the buzzer sounds) in the user's face.
5. If the user fails press the button to disable the alarm by now, the Arduino will send a digital output signal to the DC relay, which will open the solenoid valve causing the user to be sprayed with water (as a last resort).
6. The user can press (and hold) the button on the side of the device to disable the alarm at any time during the process.

 ## Notes
 _This project, while originally dated 2019, is being uploaded onto GitHub in 2024 as part of an ongoing attempt at consolidating my portfolio and previous projects in a publically available manner._
