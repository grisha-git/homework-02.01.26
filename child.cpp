#include <iostream>
#include <cassert>

int main(int argc, char** argv)
{
  assert(argc == 2);
  int err = 0;
  int rd = std::atoi(argv[1]);
  assert(rd > 0);
}