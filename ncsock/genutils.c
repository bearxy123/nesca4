/*
 * LIBNCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "include/strbase.h"

u16 generate_rare_port(void)
{
  return(random_num(49151, 65535));
}

u32 generate_seq(void)
{
  return(random_num(1, 4294967294));
}

const char* generate_ipv4(void)
{
  static char ip[16];
  mt19937_seed(generate_seed());

  snprintf(ip, sizeof(ip), "%u.%u.%u.%u",
      mt19937_random() % 256, mt19937_random() % 256,
      mt19937_random() % 256, mt19937_random() % 256);

  return ip;
}

u32 random_num(unsigned int min, unsigned int max)
{
  if (min > max)
    return -1;

  mt19937_seed(generate_seed());
  unsigned int range = max - min + 1;
  unsigned int random_value = min + (unsigned int)(mt19937_random() % range);

  return random_value;
}

u32 generate_ident(void)
{
  mt19937_seed(generate_seed());
  return (uint16_t)(mt19937_random() % 229444421);
}
