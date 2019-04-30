#pragma once

#include <string>

struct User {
  int id;
  std::string name;

  User(int _id, std::string _name) : id{_id}, name{_name} {}
  User(std::string _name) : name{_name} {}
};