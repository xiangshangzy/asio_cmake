#include "protocol.h"
using namespace std;
using namespace boost::asio;
using namespace boost::asio::ip;
Server::Server(short port) : io_ctx_(1), acceptor_(io_ctx_, tcp::v4(), port)
{
}
void Server::Start()
{
    DoAccept();
    io_ctx_.run();
}

void Server::DoAccept()
{
    string uuid = "uuid";
    map[uuid] = make_unique<Conn>(io_ctx_);

    /* acceptor_.async_accept(
        map[uuid]->Socket(),
        [this, uuid](boost::system::error_code &ec,size_t transfferd)
        {
        if(!ec){
            string uuid = "uuid";
            map[uuid] = make_unique<Conn>(io_ctx_);
            map[uuid]->DoRead();
            DoAccept();
        } }); */
}

Conn::Conn(io_context &io_ctx) : socket_(io_ctx)
{
}
tcp::socket Conn::Socket()
{
}
void Conn::DoRead()
{
}

void Conn::DoWrite()
{
}

void Conn::DoClose()
{
}

void say(std::string s)
{
}
void B(unique_ptr<tcp::socket> p)
{
    p->close();
}
void A()
{
    io_context io_ctx;
    tcp::socket sock(io_ctx);
    auto p = make_unique<tcp::socket>(io_ctx);
    p->close();
    B(std::move(p));
    string s("hello");
    vector<string> v;
    v.push_back(std::move(s));
}
