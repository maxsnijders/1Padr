#ifndef INPUTPARSER_H
#define INPUTPARSER_H

#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

class InputParser{
    public:
        InputParser (int &argc, char **argv);
        const std::string& getCmdOption(const std::string &option);
        bool cmdOptionExists(const std::string &option);
    private:
        std::vector <std::string> tokens;
};


#endif
