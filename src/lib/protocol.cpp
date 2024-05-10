#include "protocol.h"
using namespace std;
using namespace asio;
using namespace asio::ip;
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
    auto p = make_unique<Conn>(io_ctx_);
    acceptor_.async_accept(
        p->Socket(),
        [this, &p](error_code ec)
        {
        if(!ec){
            string uuid = "uuid";
            map[uuid] = move(p);
            map[uuid]->DoRead();
            DoAccept();
        } });
}

Conn::Conn(io_context &io_ctx) : socket_(io_ctx)
{
}
tcp::socket &Conn::Socket()
{
    return socket_;
}
Packet UnPack(array<char, 128> &arr)
{
    return Packet();
}
void Conn::DoRead()
{
    socket_.async_receive(buffer(arr),
                          [this](const error_code &ec, size_t trans)
                          {
                              if (ec)
                              {
                                  DoClose();
                                  return;
                              }
                              UnPack(arr);
                              DoRead();
                          }

    );
}

void Conn::DoWrite()
{
}

void Conn::DoClose()
{
    socket_.close();
}
void PackHello()
{
}
class Message
{
    enum Operate : char
    {
        Text,

    };
    static void PackText(string text, int n)
    {
        array<char, 1024> buffer{'a', 'b', 'c'};
        vector<int> v(n);
        buffer[4] = Operate::Text;

        char s[text.size()];
        copy(text.begin(), text.end(), buffer.begin() + 4);
    }
    static bool UnPack(array<char, 1024> buf, int t)
    {
        string head(buf.begin(), buf.begin() + 4);
        // copy(buf.begin(), buf.begin() + 3, head.begin());
        if (head != "abc")
            return false;
        int len = 100;
        switch (buf[4])
        {
        case Operate::Text:
        {
            string msg(buf.begin() + 8, buf.begin() + 8 + len);
            // copy(buf.begin()+8, buf.begin() + t, msg);
            cout << "receive msg: " << msg << endl;
            break;
        }

        default:
            break;
        }
        return true;
    };
};
struct A
{
    array<int, 3> arr;
    char c;
};

void say(std::string s)
{
    cout << s << endl;
    string s1 = "hello";
    array<char, 10> arr{'a', 's', 'l', 'o', 'o'};
    string str(arr.begin(), arr.begin() + 5);
    cout << str << endl;
}
