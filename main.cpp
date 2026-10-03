#include <iostream>
#include <unistd.h>
#include <cassert>

int main () {
  int pps[2] = {};
  int err = pipe(pps);
  assert(!err);
  int rd = pps[0], wd = pps[1];
  pid_t pid = fork();
  assert(pid >= 0);
  if (!pid) {
    err = close(wd);
    assert(!err);
    char p[100] = {};
    err = sprintf(p, "%d", rd);
    assert(err > 0);
    execl("child", "child", p, NULL);
    assert(0);
  }
  err = close(rd);
  assert(!err);
}