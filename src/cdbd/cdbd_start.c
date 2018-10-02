#include <stdio.h>
#include "cdbd.h"

int cdbd_start() {
  if (cdbd_is_active()) {
    printf("cdbd is already active\n");
    return 0;
  }

  // TODO: Start daemon
  return 0;
}
