#ifndef INSTUCTION_H
#define INSTUCTION_H
#include <string>

class instruction {

public:

  // instruction(std::string line);

   enum commandType
   {
    A_COMMAND,
    C_COMMAND,
    L_COMMAND,
    INVALID_COMMAND,
   };

    commandType Type;
    std::string symbol;
    std::string dest;
    std::string comp;
    std::string jump;
    instruction();
    void parse(std::string line);


};


#endif // INSTUCTION_H
