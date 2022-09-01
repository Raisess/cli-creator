#include "Cli.h"

CliCreator::Cli::Cli() {}
CliCreator::Cli::~Cli() {}

int CliCreator::Cli::handle(int argc, char* argv[]) {
  CommandTuples commands = CommandParser::Parse(argc, argv);

  int ret = 0;
  for (auto command : commands) {
    auto command_key = std::get<0>(command);
    ret = command_handler(command_key, std::get<1>(command));
    if (ret != 0) {
      std::cout << "Failed executing: " << command_key << std::endl
        << "Exit code: " << ret << std::endl;
      return ret;
    }
  }

  return ret;
}

int CliCreator::Cli::command_handler(
  const std::string& command_key,
  const std::vector<std::string>& command_arguments
) {
  if (commands.find(command_key) != commands.end()) {
    return commands[command_key](command_arguments);
  }

  return 1;
}
