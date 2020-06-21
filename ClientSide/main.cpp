#include <iostream>
#include "client.h"


int main()
{

    try{
            std::string msg_to_server{"HELLO FROM CLIENT!"};

            std::string answer;

            msg_to_server.insert(msg_to_server.end(), '\n');


            Client my_client(IpAdress, NumberPort);

            my_client.connect_to();

            my_client.send_request(msg_to_server);

            answer = my_client.get_responce();

            std::cout << answer << std::endl;

            my_client.close_connection();


        }catch(boost::system::system_error& err){

            std::cout << "Error occured! Error code = " << err.code()
                      << "Message: " << err.what() << std::endl;

             return err.code().value();
        }


    return 0;
}
