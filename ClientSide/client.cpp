#include "client.h"


void Client::close_connection()
{
    //shuts the connection down and closes the socket
    m_client_socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both);

    m_client_socket.close();
}

void Client::send_request(const std::string& request)
{
    boost::asio::write(m_client_socket, boost::asio::buffer(request));
}

std::string Client::get_responce()
{
    //The response message sent by the server may differ in length, but must end as follows:
    // '\n' so we use this character as a separator when calling the function
    boost::asio::read_until(m_client_socket, m_buffer, '\n');

    //putting the received data from the buffer into the stream
    std::istream input(& m_buffer);

    std::string answer;

    //Extracts characters from the stream and saves them as a string
    std::getline(input, answer);

    return answer;
}

