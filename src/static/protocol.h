#include "boost/asio.hpp"
#include <unordered_map>
#include <iostream>
#include "block_quene.h"
class Conn
{
public:
  Conn(boost::asio::io_context& io_ctx);
  void DoRead();
  void DoWrite();
  void DoClose();
  boost::asio::ip::tcp::socket Socket();

private:
  RingBuffer q_;
  boost::asio::ip::tcp::socket socket_; 
};
class Server
{
public:
  Server(short port);
  void Start();
  void DoAccept();

private:
  boost::asio::io_context io_ctx_;
  boost::asio::ip::tcp::acceptor acceptor_;
  std::unordered_map<std::string, std::unique_ptr<Conn>> map;
};
void say(std::string s);