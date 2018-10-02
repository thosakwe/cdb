#ifndef CDBD_H
#define CDBD_H
#include <stdbool.h>

const char* CDBD_PATH = "~/.cdbd";

void printHelp();

bool cdbd_is_active();

int cdbd_get_active_pid();

int cdbd_start();

int cdbd_stop();

#endif
