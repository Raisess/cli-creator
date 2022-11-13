#include "Cli.h"

void CliCreator::Cli::ValidateCommandArgsSize(const Arguments& args, size_t min_size) {
  if (args.size() < min_size) {
    std::cerr << "Invalid arguments" << std::endl;
    exit(1);
  }
}

CliCreator::Cli::Cli() {}
CliCreator::Cli::~Cli() {}

int CliCreator::Cli::handle(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "No command provided" << std::endl;
    return 1;
  }

  std::string command = argv[1];
  Arguments args;
  for (int i = 2; i < argc; i++) {
    args.push_back(argv[i]);
  }

  int ret = this->command_handler(command, args);
  if (ret != 0) {
    std::cout << "Failed executing: " << command << std::endl
      << "Exit code: " << ret << std::endl;
  }

  return ret;
}

int CliCreator::Cli::command_handler(
  const std::string& command_key,
  const Arguments& command_arguments
) {
  if (commands.find(command_key) != commands.end()) {
    return commands[command_key](command_arguments);
  }

  return 1;
}
