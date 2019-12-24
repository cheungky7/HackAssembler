#ifndef PARSER_H
#define PARSER_H
#include <fstream>
#include <iostream>
#include <string>
#include "instruction.h"

void readfile(const char* filename);
bool has_only_spaces(const std::string& str);
void removeFromString(std::string &str, std::string tofind);
std::string removeCommentAndWhiteSpace(std::string& str);

#endif

