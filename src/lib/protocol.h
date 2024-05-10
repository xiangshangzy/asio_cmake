#include "asio.hpp"
#include <unordered_map>
#include <iostream>
#include "block_quene.h"
#include <array>
class Packet
{
  char head[4]{'h', 'e', 'a', 'd'};

};
class Conn
{
public:
  Conn(asio::io_context &io_ctx);
  void DoRead();
  void DoWrite();
  void DoClose();
  asio::ip::tcp::socket &Socket();

private:
  RingBuffer q_;
  asio::ip::tcp::socket socket_;
  std::array<char, 128> arr;
};
class Server
{
public:
  Server(short port);
  void Start();
  void DoAccept();

private:
  asio::io_context io_ctx_;
  asio::ip::tcp::acceptor acceptor_;
  std::unordered_map<std::string, std::unique_ptr<Conn>> map;
};
void say(std::string s);