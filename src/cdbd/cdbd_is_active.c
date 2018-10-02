#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "cdbd.h"

bool cdbd_is_active() {
  // cdbd info will be contained in ~/.cdbd
  if (access(CDBD_PATH, F_OK | R_OK) != 0) {
    return false;
  }

  return true;
}

int cdbd_get_active_pid() {
  // Next, read the contents of said file.
  FILE *file = fopen(CDBD_PATH, "r");

  if (file == NULL) {
    return -1;
  }
  
  if (fseek(file, 0, SEEK_END) != 0) {
    fclose(file);
    return -1;
  }

  long int length = ftell(file);
  rewind(file);

  if (length == -1L) {
    fclose(file);
    return -1;
  }

  char* text = (char*) malloc(sizeof(char) * length);

  if (text == NULL) {
    fclose(file);
    return -1;
  }

  size_t nRead = fread(text, 1, length, file);

  if (nRead != length) {
    free(text);
    fclose(file);
    return -1;
  }

  fclose(file);

  // Now that we've read the file, parse it.
  long int pid = strtol(text, NULL, 10);
  free(text);
  return pid;
}
