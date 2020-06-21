#ifndef NEWCONNECTIONHANDLER_H_
#define NEWCONNECTIONHANDLER_H_

#include <iostream>
#include "ServerSide.h"


class ConnectHandler : public std::enable_shared_from_this<ConnectHandler>
{
private:
    boost::system::error_code m_err;
    boost::asio::ip::tcp::socket m_server_socket;
    boost::asio::streambuf m_buffer;


public:
   ConnectHandler(boost::asio::io_context& server_context):m_server_socket(server_context){}

  inline boost::asio::ip::tcp::socket& get_socket(){return m_server_socket;}

   void ready_read();

   void ready_send();


};





#endif // NEWCONNECTIONHANDLER_H_
