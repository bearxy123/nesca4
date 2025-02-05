/*
 * LIBNCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "include/utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>

char* get_local_ip(void)
{
  struct ifaddrs *ifap, *ifa;
  struct sockaddr_in *sa;
  char *localip = NULL;

  if (getifaddrs(&ifap) == -1) {
    perror("getifaddrs");
    return NULL;
  }

  for (ifa = ifap; ifa != NULL; ifa = ifa->ifa_next) {
    if (ifa->ifa_addr == NULL || ifa->ifa_addr->sa_family != AF_INET) {
      continue;
    }

    sa = (struct sockaddr_in *) ifa->ifa_addr;
    if (!(ifa->ifa_flags & IFF_LOOPBACK)) {
      localip = (char*)malloc(INET_ADDRSTRLEN);
      inet_ntop(AF_INET, &(sa->sin_addr), localip, INET_ADDRSTRLEN);
      break;
    }
  }

  freeifaddrs(ifap);
  return localip;
}
