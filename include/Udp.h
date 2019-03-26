#ifndef UDP_H
#define UDP_H

#include <SFML/Network.hpp>
#include <iostream>


class Udp
{
    public:
        Udp();
        virtual ~Udp();

        void runUdpServer(unsigned short port);
        void runUdpClient(unsigned short port);

    protected:

    private:
};

#endif // UDP_H
