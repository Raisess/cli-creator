#pragma once

#include <iostream>
#include <functional>
#include <unordered_map>
#include <vector>
#include "CommandParser.h"

namespace CliCreator {

using Command = std::function<int(Arguments)>;
using Commands = std::unordered_map<std::string, Command>;

class Cli {
public:
  Commands commands;

  Cli();
  ~Cli();

  int handle(int argc, char* argv[]);

private:
  int command_handler(const std::string& command_key, const std::vector<std::string>& command_arguments);
};

}
