#pragma once

#include <iostream>
#include <functional>
#include <unordered_map>
#include <vector>

namespace CliCreator {

using Arguments = std::vector<std::string>;
using Command = std::function<int(Arguments)>;
using Commands = std::unordered_map<std::string, Command>;

class Cli {
public:
  Commands commands;

  Cli();
  ~Cli();

  int handle(int argc, char* argv[]);

private:
  int command_handler(
    const std::string& command_key,
    const Arguments& command_arguments
  );
};

}
