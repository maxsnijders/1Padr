#ifndef ENCODER_H
#define ENCODER_H

#include <iofstream>
#include <ofstream>
#include <string>

class Encoder{
  public:
    // Create new encoder with key file
    Encoder(std::iofstream* send_key_file);

    // Write encoded message to disk
    void Encode(std::string message, std::ofsream* outfile);
  private:
    std::iofstream* send_key_file;
};

#endif
