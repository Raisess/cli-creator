#include <iostream>
#include <cstdlib>
#include <cli-creator/Cli.h>

using namespace CliCreator;

int main(int argc, char* argv[]) {
  Cli cli;

  cli.commands["--init"] = [](Arguments args) {
    auto project_name = args[0];
    std::system(("git clone https://github.com/Raisess/cpp-cli-boilerplate " + project_name).c_str());
    std::system(("cd " + project_name + " && bash setup.sh").c_str());
    return 0;
  };

  return cli.handle(argc, argv);
}
