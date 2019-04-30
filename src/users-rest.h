#pragma once

#include <sys/time.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

#include "cpprest/asyncrt_utils.h"
#include "cpprest/containerstream.h"
#include "cpprest/filestream.h"
#include "cpprest/http_listener.h"
#include "cpprest/json.h"
#include "cpprest/producerconsumerstream.h"
#include "cpprest/uri.h"

#include <ctime>
#include <locale>
#include "rest.h"
#include "users-db.h"

class UsersRest : Rest {
 public:
  UsersRest(web::uri url, UsersDb &_db);
  ~UsersRest() { close(); }

  pplx::task<void> open() { return listener.open(); }
  pplx::task<void> close() { return listener.close(); }

 protected:
 private:
  web::http::experimental::listener::http_listener listener;
  UsersDb db;

  void handle_get(web::http::http_request req);
  void handle_post(web::http::http_request req);
};
