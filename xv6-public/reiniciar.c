#include "types.h"
#include "stat.h"
#include "user.h"

char buf[512];

void 
cat(int fd)
{
  printf(1, "Reiniciando carnalito \n");
  reboot(); //viene de user.h
  exit();
}