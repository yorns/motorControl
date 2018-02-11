#ifndef MOTORCONTROL_WIRINGPI_H
#define MOTORCONTROL_WIRINGPI_H

#ifdef WORK_ON_PI
#include <wiringPi.h>
#include <softPwm.h>
#else
#warning creating dummy code

#include <iostream>

#define OUTPUT 0
#define INPUT 1

static int softPwmCreate (int pin, int initValue, int range) {
    std::cerr << "dummy: init pin <"<<pin<<"> with initValue <"<<initValue<<"> and a range of 0-"<<range<<"\n";
    return 0;
}

static int wiringPiSetup() {
    std::cerr << "dummy: initializing pi\n";
    return 0;
}

static int pinMode(int pin, int mode)
{
    std::cerr << "dummy: setting pin <"<<pin<<"> to mode "<<(mode==OUTPUT?"OUTPUT":"INPUT")<<"\n";
    return 0;
}

static int softPwmWrite(int pwm_pin, int speed)
{
   std::cerr << "dummy: set pwm on pin <"<<pwm_pin<<"> to speed <"<<speed<<">\n";
    return 0;
}

static int digitalWrite(int pin, int value)
{
    std::cerr << "dummy: set pin <"<<pin << "> to "<<(value==0?"OFF":"ON")<<"\n";
    return 0;
}


#endif

#endif //MOTORCONTROL_WIRINGPI_H
