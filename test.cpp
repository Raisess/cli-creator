#include <iostream>
#include <cli-creator/Cli.h>
#include <cli-creator/util/FileSystem.h>

int main(int argc, char* argv[]) {
  CliCreator::Cli cli;

  cli.commands["hello"] = [](CliCreator::Arguments) {
    std::cout << "Hello!" << std::endl;
    return 0;
  };

  cli.commands["sum"] = [](CliCreator::Arguments args) {
    std::cout << std::stoi(args[0]) + std::stoi(args[1]) << std::endl;
    return 0;
  };

  cli.commands["sub"] = [](CliCreator::Arguments args) {
    std::cout << std::stoi(args[0]) - std::stoi(args[1]) << std::endl;
    return 0;
  };

  cli.commands["file"] = [](CliCreator::Arguments) {
    CliCreator::Util::File file("./test-generated-file");
    file.write("test-generated-file");
    std::cout << file.read() << std::endl;
    return 0;
  };

  cli.commands["fail"] = [](CliCreator::Arguments) {
    return 1;
  };

  return cli.handle(argc, argv);
}
