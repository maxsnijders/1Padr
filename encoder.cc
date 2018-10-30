#include <iofstream>
#include <ofstream>
#include <string>

#include "key.h"

Encoder::Encoder(std::iofstream* send_key_file){
  this->send_key_file = send_key_file;
}

void Encoder::Encode(std::string message, std::ofsream* outfile){
  // Read the key file
  std::vector<unsigned char> buffer((
          std::istreambuf_iterator<unsigned char>(this->send_key_file)),
          (std::istreambuf_iterator<unsigned char>()));

  key_header header;
  std::copy(buffer[0], buffer[0] + sizeof(key_header), header);

  std::cout << header.length_send << std::endl;
}
