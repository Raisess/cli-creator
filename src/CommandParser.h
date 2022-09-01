#pragma once

#include <iostream>
#include <tuple>
#include <vector>

namespace CliCreator {

using Arguments = std::vector<std::string>;
using CommandTuple = std::tuple<std::string, Arguments>;
using CommandTuples = std::vector<CommandTuple>;

class CommandParser {
public:
  static CommandTuples Parse(int argc, char* argv[]);

private:
  static CommandTuple ParseTuple(const std::string& str, const std::string& separator);
  static Arguments ParseArguments(const std::string& str, const std::string& separator);
};

}
