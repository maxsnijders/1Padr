#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <climits>
#include <algorithm>
#include <functional>
#include <iterator>
#include <string>

#include "keygen.h"
#include "key.h"

using random_bytes_engine = std::independent_bits_engine<std::default_random_engine, CHAR_BIT, unsigned char>;

void KeyGen::generate_keys(unsigned int send_length, unsigned int receive_length, std::ofstream* file_sender, std::ofstream* file_receiver){
  key_header header_sender;
  header_sender.total_length = (send_length + receive_length);
  header_sender.length_send = send_length;
  header_sender.length_receive = receive_length;
  header_sender.index_send = 0;

  key_header header_receiver;
  header_sender.total_length = (send_length + receive_length);
  header_sender.length_send = receive_length;
  header_sender.length_receive = send_length;
  header_sender.index_send = 0;

  file_sender->write((char*)&header_sender, sizeof(key_header));
  file_sender->write((char*)&header_receiver, sizeof(key_header));

  file_receiver->write((char*)&header_receiver, sizeof(key_header));
  file_receiver->write((char*)&header_sender, sizeof(key_header));

  random_bytes_engine rbe;
  std::vector<unsigned char> data(send_length + receive_length);
  std::generate(begin(data), end(data), std::ref(rbe));

  file_sender->write((char*)&data[0], data.size() * sizeof(unsigned char));
  file_receiver->write((char*)&data[send_length],receive_length * sizeof(unsigned char));
  file_receiver->write((char*)&data[0],send_length * sizeof(unsigned char));
}
