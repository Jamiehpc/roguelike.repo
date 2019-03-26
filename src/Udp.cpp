#include "Udp.h"

Udp::Udp()
{
    //ctor
}

Udp::~Udp()
{
    //dtor
}

//launches server, wait for message, send answer
void Udp::runUdpServer(unsigned short port)
{
    //creates socket to recieve a message
    sf::UdpSocket socket;

    // listen for message
    if (socket.bind(port) != sf::Socket::Done)
        return;

    std::cout << "Server is listening to port " << port << ", waiting for a message..." << std::endl;

    //wait for message
    char dataIn[256];
    std::size_t received;
    sf::IpAddress sender;
    unsigned short senderPort;
    if (socket.receive(dataIn, sizeof(dataIn), received, sender, senderPort) != sf::Socket::Done)
        return;

    std::cout << "Message recieved from client " << sender << ", \"" << dataIn << " \"" << std::endl;

    //send an answer
    char dataOut[256] = dataIn;
    if (socket.send(dataOut, sizeof(dataOut), sender, senderPort) != sf::Socket::Done)
        return;

    std::cout << "Message sent to the client: \"" << dataOut << "\"" <<std::endl;
}

void Udp::runUdpClient(unsigned short port)
{
    //ask for server address
    sf::IpAddress server;

    do
    {

        std::cout << "Type the address or name of the server to connect to: ";
        std::cin >> server;
    }
    while (server == sf::IpAddress::None);

    //create a socket to communicate with server
    sf::UdpSocket socket;

    //send a message
    const char dataOut[256] = "The Client";
    if (socket.send(dataOut, sozeof(dataOut), server, port) != sf::Socket::Done)
        return;

    std::cout << "Message sent to the sever: \"" << dataOut << "\"" << std::endl;

    //receive an answer
    char dataIn[256];
    std::size_t recieved;
    sf::IpAddress sender;
    unsigned short senderPort;
    if (socket.receive(dataIn, sizeof(dataIn), recieved, sender, senderPort) != sf::Socket::Done)
        return;

    std::cout << "Message recieved from " << sender << ": \"" << dataIn << "\"" << std::endl;
}
