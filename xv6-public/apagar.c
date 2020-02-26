#include "types.h"
#include "stat.h"
#include "user.h"

char buf[512];

void 
cat(int fd)
{
  printf(1, "Hay nos vemos carnalito \n");
  shutdown(); //viene de user.h
  exit();
}
