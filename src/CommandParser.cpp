#include <utility>
#include "CommandParser.h"

CliCreator::CommandTuples CliCreator::CommandParser::Parse(int argc, char* argv[]) {
  if (argc < 2) {
    exit(1);
  }

  CommandTuples tuples;
  for (int i = 1; i < argc; i++) {
    tuples.push_back(ParseTuple(argv[i], "="));
  }

  return tuples;
}

CliCreator::CommandTuple CliCreator::CommandParser::ParseTuple(const std::string& str, const std::string& separator) {
  size_t key_size = 0;
  for (size_t i = 0; i < str.size(); i++) {
    if (str.substr(i, separator.size()) == separator) break;
    key_size++;
  }

  const auto command = str.substr(0, key_size);
  if (command.size() == str.size()) {
    return { command, {} };
  }

  const auto value = str.substr(key_size + separator.size(), str.size());
  return { command, ParseArguments(value, ",") };
}

CliCreator::Arguments CliCreator::CommandParser::ParseArguments(const std::string& str, const std::string& separator) {
  Arguments args;

  size_t match_size = 0;
  for (size_t i = 0; i < str.size(); i++) {
    if (str.substr(i, separator.size()) == separator || i == str.size() - 1) {
      args.push_back(str.substr(i - match_size, i == str.size() - 1 ? match_size + 1 : match_size));
      match_size = 0;
      continue;
    }
    match_size++;
  }

  return args;
}
