#ifndef MOTORCONTROL_STEERINGCONTROL_H
#define MOTORCONTROL_STEERINGCONTROL_H

#include <memory>
#include <boost/asio.hpp>
#include <iostream>
#include "pi_includes.h"
#include "motor.h"

class SteeringControl {

    boost::asio::io_service& m_service;

    std::unique_ptr<Motor> wheel1; // rechts vorn
    std::unique_ptr<Motor> wheel2; // links vorn
    std::unique_ptr<Motor> wheel3; // rechts hinten
    std::unique_ptr<Motor> wheel4; // links hinten

    static const int c_forwardSpeed {60};
    static const int c_bendFastSpeed {80};
    static const int c_bendSlowSpeed {20};

public:
    SteeringControl() = delete;
    explicit SteeringControl(boost::asio::io_service& service);

    ~SteeringControl() = default;

    void cmdHandler(const char& cmd);

};


#endif //MOTORCONTROL_STEERINGCONTROL_H
