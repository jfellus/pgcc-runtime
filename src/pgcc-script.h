#include "pgcc.h"
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void init();
void process();
void deinit();

static bool __stop = false;

void on_stop (int signo) {
  __stop = true;
}

void main(int argc, char** argv) {
  signal(SIGINT, on_stop);
  init();
  try {
    while(!__stop) {
      process();
    }
  } catch(e) {  }
  deinit();
}
