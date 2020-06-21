#include "ServerSide.h"


void Server::incomming_connection()
{
    //creating a new instance of the "ConnectHandler
   //and wrapped in "shared_ptr"
   //passing an instance "io_context" as a constructor parameter
   auto handler_ptr = std::make_shared<ConnectHandler>(m_server_acceptor.get_executor().context());


   //"M_server_acceptor" calls the async_accept member function
   //on the acceptor to listen for new incoming connections and accept them
   m_server_acceptor.async_accept(handler_ptr->get_socket(),
                                 [this, handler_ptr](const boost::system::error_code& err){

                                  if(err){
                                    std::cerr << "failed to accept connection! " << std::endl;
                                  }
                                  else{

                                    handler_ptr->ready_read();

                                    incomming_connection();
                                  }

                                  });



}
