#include "FileSystem.h"

namespace CliCreator {

Util::File::File(const std::string& path) : _path(path) {}

Util::File::~File() {}

const std::string Util::File::read() {
  if (_is_valid) return _content;

  _fstream.open(_path, std::ios_base::in);
  std::string tmp;
  while (std::getline(_fstream, tmp)) {
    _content += tmp;
  }
  _fstream.close();
  _is_valid = true;

  return _content;
}

void Util::File::write(const std::string& data) {
  _fstream.open(_path, std::ios_base::out);
  _fstream << data << std::endl;
  _fstream.close();
  _is_valid = false;
}

}
