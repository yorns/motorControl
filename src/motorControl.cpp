#include "steeringControl.h"
#include <snc/client.h>

int main()
{
    /* initialisation */

    boost::asio::io_service service;

//    boost::asio::io_service::work worker(service);
    snc::Client client("steeringControl", service, "127.0.0.1", 12001);

    SteeringControl steeringControl(service);

    client.receiveHandler([&steeringControl](const std::string& nick, const std::string& msg){ steeringControl.cmdHandler(msg[0]);}  );

    service.run();
}

