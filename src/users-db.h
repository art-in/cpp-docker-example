#pragma once

#include <sqlite3.h>
#include <functional>
#include <string>
#include <vector>

#include "db.h"
#include "user.h"

class UsersDb : Db {
 public:
  UsersDb(std::string db_path);
  ~UsersDb();

  void add_user(User user);
  std::vector<User> get_users();
};