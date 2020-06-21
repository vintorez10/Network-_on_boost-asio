#include "ServerSide.h"


int main()
{
    try{
        boost::asio::io_context server_context;

        Server my_server(server_context, NumberPort);

        server_context.run();

    }catch(std::exception& err){

        std::cout << err.what() << std::endl;
    }


    return 0;
}
