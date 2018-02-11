#ifndef MOTORCONTROL_MOTOR_H
#define MOTORCONTROL_MOTOR_H

#include "pi_includes.h"
#include <iostream>

#include <boost/asio.hpp>

// cat /proc/device-tree/model

class Motor {

    int m_pwm_pin {-1};
    int m_motor1_pin {-1};
    int m_motor2_pin {-1};

public:

    enum class Direction {
        Clockwise,
        CounterClockwise
    };

    explicit Motor(int pwm_pin, int motor1_pin, int motor2_pin, bool exchange = false)
            : m_pwm_pin(pwm_pin),
              m_motor1_pin(exchange?motor2_pin:motor1_pin),
              m_motor2_pin(exchange?motor1_pin:motor2_pin)
    {
        // first motor
        if (softPwmCreate (pwm_pin, 0 /* initial value */, 100 /* range */) < 0 ) {
            std::cerr << "error creating soft PWM on pin "<<pwm_pin<<"\n";
            return;
        }

        /* START/STOP */
        pinMode(motor1_pin, OUTPUT);

        /* clockwise/counterclockwise */
        pinMode(motor2_pin, OUTPUT);
    }

    void set(Direction direction, int speed) {
        softPwmWrite(m_pwm_pin, speed);
        digitalWrite(m_motor1_pin, direction==Direction::Clockwise?1:0);
        digitalWrite(m_motor2_pin, direction==Direction::Clockwise?0:1);
    }

    void stop() {
        softPwmWrite(m_pwm_pin, 0);
        digitalWrite(m_motor1_pin, 0);
        digitalWrite(m_motor2_pin, 0);
    }

};


#endif //MOTORCONTROL_MOTOR_H
