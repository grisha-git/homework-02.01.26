#include <iostream>
#include <unistd.h>
#include <cassert>

size_t recv(int& err, int rd, char* b, size_t k) {
  size_t r = 0;
  while (r < k) {
  err = read(rd, b + r, k - r);
  if (err < 0)
  { 
    break;
  }
  r += err;
  }
  return r;
}

int main(int argc, char** argv) {
  assert(argc == 2);
  int err = 0;
  int rd = std::atoi(argv[1]);
  assert(rd > 0);
  char p[9] = {};
  recv(err, rd, p, 8);
}