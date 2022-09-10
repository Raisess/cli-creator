#include <iostream>
#include <cli-creator/Cli.h>

using namespace CliCreator;

int main(int argc, char* argv[]) {
  Cli cli;

  cli.commands["--hello"] = [](Arguments) {
    std::cout << "Hello, world!" << std::endl;
    return 0;
  };

  return cli.handle(argc, argv);
}
