#pragma once

#include <iostream>
#include <fstream>
#include <vector>

namespace CliCreator { 

namespace Util {

class File {
public:
  File(const std::string& path);
  ~File();

  const std::string read();
  void write(const std::string& data);

private:
  std::fstream _fstream;
  std::string _path;
  std::string _content;
  bool _is_valid = false;
};

}

}
