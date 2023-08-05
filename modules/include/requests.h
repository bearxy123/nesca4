/*
 * NESCA4
 * by oldteam & lomaster
 * license GPL-3.0
 * - Сделано от души 2023.
*/

#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <cstring>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <poll.h>
#include <cstdio>
#include <unistd.h>
#include "../../include/callbacks.h"
#include "../../ncsock/include/socket.h"

#define HTTPREQUEST_ERROR "HTTPREQUEST: error"

std::string
send_http_request_no_curl(const std::string& node, std::string path, int port);

#endif
