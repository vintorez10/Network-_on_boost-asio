#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <boost/asio.hpp>
#include <string>

const std::string IpAdress{"127.0.0.1"};

const unsigned short NumberPort{57000};


class Client
{
private:
    //this is the object providing access to the operating system
    boost::asio::io_context m_client_context;

    //this is an endpoint designating the server application
    boost::asio::ip::tcp::endpoint m_point;

    //this is the socket used for communication
    boost::asio::ip::tcp::socket m_client_socket;

    //buffer
    boost::asio::streambuf m_buffer;

public:
    //constructor initializes the destination point with the port number and ip address
    //socket object m_sock is instantiated and opened in the constructor too
    Client(const std::string& ip_adress, const unsigned short number_port):
           m_point(boost::asio::ip::address::from_string(ip_adress), number_port),
           m_client_socket(m_client_context)
           {
               m_client_socket.open(m_point.protocol());
           }

    //it performs the connection of the socket to server
    inline void connect_to(){m_client_socket.connect(m_point);}

    void close_connection();

    void send_request(const std::string& request);

    std::string get_responce();

};






#endif // CLIENT_H
