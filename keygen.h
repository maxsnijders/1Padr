#ifndef KEYGEN_H
#define KEYGEN_H

class KeyGen {
  public:
    // Writes a generated key to the specified file
    void generate_keys(unsigned int send_length, unsigned int receive_length, std::ofstream* file_sender, std::ofstream* file_receiver);
};

#endif
