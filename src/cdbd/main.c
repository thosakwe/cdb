#include <stdio.h>
#include <string.h>
#include "cdbd.h"

int main(int argc, const char** argv) {
  if (argc < 2) {
    printHelp();
    return 1;
  }

  const char *type = argv[1];

  if (!strcmp(type, "--help") || !strcmp(type, "-h")) {
    printHelp();
    return 0;
  }

  if (!strcmp(type, "start")) {
    return cdbd_start();
  } else if (!strcmp(type, "stop")) {
    return cdbd_stop();
  } else if (!strcmp(type, "restart")) {
    int result = cdbd_stop();

    if (result != 0) {
      return result;
    } else {
      return cdbd_start();
    }
  } else {
    return 1;
  }
}

void printHelp() {
  printf("service cdbd {start|stop|restart|status}\n");
}
