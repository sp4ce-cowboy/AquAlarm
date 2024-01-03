# AquAlarm
Team project for Hack'n'Roll 2019.

### Overview
An Arduino powered alarm clock that sprays water in your face if you don't wake up on time. Made possible by a ~haphazard~ combination of pneumatics, electromechanics, and embedded programming.

<a>
<img src="https://github.com/sp4ce-cowboy/AquAlarm/assets/19762596/3eb52954-7223-4ceb-b778-1b65cb06af59" align="center" height="400"/>
</a>
<a>
<img src="https://github.com/sp4ce-cowboy/AquAlarm/assets/19762596/68dd5610-f135-49e8-b797-5fd22a9312cc" align="center" height="400"/>
</a>

#### Pneumatics
A solenoid value is hydraulically and pneumatically connected to a pressurized canister containing plain water via pressure-rated polyurethane tubing. The canister itself can be pressured either via a schrader valve or a lighter valve, whereby either air or butane can act as fluid propellant. 

#### Electromechanics
The solenoid valve is connected to a DC relay and Lithum-ion Polymer batteries. The DC relay is connected to an Arduino Nano board. The valve is normally closed, meaning that when no power is applied, it will stop fluid flow by default. When a power signal is sent from the Arduino to the relay, the circuit consisting of the solenoid valve and the DC relay is closed, and the pressure differential between atmospheric pressure and canister pressure causes the fluid in the canister to flow in the direction of lower pressure, through the solenoid valve.

#### Software & Electronics
Powering the entire system, the Arduino is connected to a I2C 2x16 LCD board, a buzzer, an LED light system, a potentiometer, and a button. The potentiometer can be used to set the time of the alarm.

#### Usage
The user positions the device pointing towards them, and sets the alarm before going to bed. As the set alarm time approaches, the buzzer will start making loud noises. Soon after, the LED lights will flash. Finally, if the user has yet to press the button to disable the alarm, the Arduino will send a digital output signal to the DC relay, which will open the solenoid valve causing the user's to be sprayed with water.

 ### Notes
 This project, while originally dated 2019, is being uploaded onto GitHub in 2024 as part of an ongoing attempt at consolidating my portfolio and previous projects in a publically available manner.
