#include <filesystem>
#include <future>
#include <iostream>
#include <string>
#include <vector>

#include "cpprest/http_listener.h"
#include "cpprest/json.h"
#include "user.h"
#include "users-db.h"
#include "users-rest.h"

constexpr auto ADDR = "http://0.0.0.0:8080";
constexpr auto DB_FILE = "/data/users.db";

int main(int argc, char *argv[]) {
  std::string db_path =
      std::filesystem::path(argv[0]).parent_path().u8string() + DB_FILE;

  UsersDb db{db_path};

  web::uri url(utility::conversions::to_string_t(ADDR));

  UsersRest users_rest{url, db};
  users_rest.open().wait();

  ucout << U("Listening at: ") << url.to_string() << std::endl;

  // freeze main thread
  std::string s;
  std::cin >> s;
}