#ifndef SERVERSIDE_H_
#define SERVERSIDE_H_

#include <iostream>
#include <boost/asio.hpp>
#include <memory>
#include <string>
#include <boost/system/error_code.hpp>
#include "NewConnectionHandler.h"


const unsigned short NumberPort{57000};


class Server
{
private:
    //A acceptor class use to listen for and accept incoming connections
    boost::asio::ip::tcp::acceptor m_server_acceptor;

public:
    //The constructor initializes the acceptor with a local TCP
    //endpoint on the unspecified IPv4 address and a specific port
    Server(boost::asio::io_context& server_context, const unsigned short number_port):
           m_server_acceptor(server_context,
           boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), number_port)){

               std::cout << "Server start on port: " << number_port << std::endl;

               incomming_connection();

           }

    ~Server(){};

    void incomming_connection();

};

#endif // SERVERSIDE_H_
