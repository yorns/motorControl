#include "steeringControl.h"

void SteeringControl::cmdHandler(const char &cmd) {
    switch (cmd) {
        case 'i': {
            std::cerr << "forward\n";
            wheel1->set(Motor::Direction::Clockwise, c_forwardSpeed);
            wheel2->set(Motor::Direction::Clockwise, c_forwardSpeed);
            wheel3->set(Motor::Direction::Clockwise, c_forwardSpeed);
            wheel4->set(Motor::Direction::Clockwise, c_forwardSpeed);
            break;
        }
        case 'u': {
            std::cerr << "left\n";
            wheel1->set(Motor::Direction::Clockwise, c_bendFastSpeed);
            wheel2->set(Motor::Direction::Clockwise, c_bendSlowSpeed);
            wheel3->set(Motor::Direction::Clockwise, c_bendFastSpeed);
            wheel4->set(Motor::Direction::Clockwise, c_bendSlowSpeed);
            break;
        }
        case 'o': {
            std::cerr << "right\n";
            wheel1->set(Motor::Direction::Clockwise, c_bendSlowSpeed);
            wheel2->set(Motor::Direction::Clockwise, c_bendFastSpeed);
            wheel3->set(Motor::Direction::Clockwise, c_bendSlowSpeed);
            wheel4->set(Motor::Direction::Clockwise, c_bendFastSpeed);
            break;
        }
        case 'k': {
            std::cerr << "stop\n";
            wheel1->stop();
            wheel2->stop();
            wheel3->stop();
            wheel4->stop();
            break;
        }
        default:
            std::cerr << "unknown command <"<<cmd<<">\n";
    }
}

SteeringControl::SteeringControl(boost::asio::io_service &service)
        : m_service(service)
{
    if ( wiringPiSetup() == -1 )
        return;

    wheel1 = std::make_unique<Motor>(3,0,2);
    wheel2 = std::make_unique<Motor>(12,14,13);
    wheel3 = std::make_unique<Motor>(8,9,7);
    wheel4 = std::make_unique<Motor>(6,11,10);

}
