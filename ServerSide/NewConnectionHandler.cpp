#include "NewConnectionHandler.h"

using namespace boost::asio;


void ConnectHandler::ready_read()
{
    //returns a shared pointer using the reference counting block of the old
   auto this_class_ptr(shared_from_this());

   //The response message sent by the server may differ in length, but must end as follows:
   // '\n' so we use this character as a separator when calling the function
   async_read_until(m_server_socket, m_buffer, '\n',
                   [this_class_ptr](const boost::system::error_code& err, size_t sz){

                if (!err || err == boost::asio::error::eof){

                    std::string msg_from_client;

                    //putting the received data from the buffer into the stream
                    std::istream input(&this_class_ptr->m_buffer);

                    //Extracts characters from the stream and saves them as a string
                    std::getline(input, msg_from_client);

                    this_class_ptr->ready_send();

                    std::cout << msg_from_client << std::endl;

                    if(!err){
                        this_class_ptr->ready_read();
                    }

                 }
                else{
                std::cerr << "Error receiving data from client :" << err.message() << std::endl;
               }

               });
}

 void ConnectHandler::ready_send()
 {

   std::string msg_to_server {"HELLO FROM SERVER!"};

   msg_to_server.insert(msg_to_server.end(), '\n');

   auto this_class_ptr(shared_from_this());

   async_write(m_server_socket, buffer(msg_to_server, msg_to_server.length()),
              [this_class_ptr](const boost::system::error_code& err, size_t sz){

                 if(err){

                    if(err == boost::asio::error::eof){

                       this_class_ptr->m_server_socket.close();

                 }
                 std::cerr << "Error receiving data from client :"
                           << err.message() << std::endl;

                 }

                 });

 }
