#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>

#include "keygen.h"
#include "inputparser.h"

int main(int argc, char * argv[])
{
  InputParser input(argc, argv);

  if(input.cmdOptionExists("-gen")){
    std::cout << "Keygen mode" << std::endl;

    std::string filename_sender  = input.getCmdOption("-s");
    std::string filename_receiver = input.getCmdOption("-r");

    if( ! (filename_sender.empty() || filename_receiver.empty()) ){
      std::ofstream file_sender;
      file_sender.open(filename_sender);

      std::ofstream file_receiver;
      file_receiver.open(filename_receiver);

      if( file_sender && file_receiver ){
        KeyGen gen = KeyGen();
        gen.generate_keys(1000, 1000, &file_sender, &file_receiver);

        std::cout << "Wrote keys to disk" << std:endl;
      }else{
        std::cout << "Either -s or -r not found" << std::endl;
        return -1;
      }
    }else{
      std::cout << "Specify both -s and -r" << std::endl;
      return -1;
    }
  }else if(input.cmdOptionExists("-enc")){
    std::cout << "Encoding mode" << std::endl;

    std::string filename_key     = input.getCmdOption("-k");
    std::string filename_message = input.getCmdOption("-m");
    std::string filename_out     = input.getCmdOption("-o");

    if( !(filename_message.empty() || filename_out.empty()) ){
      std::ifsteam

    }else{
      std::cout << "Specify both -m, -k and -o" << std::endl;
      return -1;
    }

  }else{
    std::cout << "No operation mode specified. Try -gen or -enc" << std::endl;
  }

  return 0;
}
