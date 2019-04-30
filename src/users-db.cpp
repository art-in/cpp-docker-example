#include <sqlite3.h>
#include <stdio.h>
#include <functional>
#include <iostream>
#include <stdexcept>
#include <string>

#include "db.h"
#include "user.h"
#include "users-db.h"

static int callback(void* NotUsed, int argc, char** argv, char** azColName);

UsersDb::UsersDb(std::string db_path) : Db(db_path) {
  std::string query =
      "CREATE TABLE IF NOT EXISTS USERS("
      "ID   INTEGER  PRIMARY KEY AUTOINCREMENT,"
      "NAME TEXT NOT NULL);";

  exec_query(query);
}

UsersDb::~UsersDb() { sqlite3_close(db); }

void UsersDb::add_user(User user) {
  exec_query("INSERT INTO USERS(NAME) VALUES('" + user.name + "')");
}

std::vector<User> UsersDb::get_users() {
  std::vector<User> res;

  exec_query("SELECT ID, NAME FROM USERS", [&](auto stmt) {
    int id = sqlite3_column_int(stmt, 0);
    std::string name{
        reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1))};
    res.push_back({id, name});
  });

  return res;
}
