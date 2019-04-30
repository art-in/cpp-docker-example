#include "users-rest.h"
#include "users-db.h"

UsersRest::UsersRest(web::uri url, UsersDb &_db) : listener{url}, db{_db} {
  listener.support(
      web::http::methods::GET,
      std::bind(&UsersRest::handle_get, this, std::placeholders::_1));
  listener.support(
      web::http::methods::POST,
      std::bind(&UsersRest::handle_post, this, std::placeholders::_1));
}

void handle(web::http::http_request req, std::function<void()> handler) {
  try {
    handler();
  } catch (std::exception &e) {
    ucerr << "Failed to handle request: " << e.what() << std::endl;
    ucerr << req.to_string() << std::endl;
    throw e;
  }
}

void UsersRest::handle_post(web::http::http_request req) {
  handle(req, [&] {
    web::json::value obj = req.extract_json().get();
    auto n = obj[U("name")].as_string();
    std::string name = utility::conversions::to_utf8string(n);

    db.add_user({name});

    req.reply(web::http::status_codes::OK);
  });
};

void UsersRest::handle_get(web::http::http_request req) {
  handle(req, [&] {
    auto users = db.get_users();
    auto resp = web::json::value::array();

    for (int i = 0; i < users.size(); i++) {
      auto s = utility::conversions::to_string_t(users[i].name);
      resp[i] = web::json::value::string(s);
    }

    req.reply(web::http::status_codes::OK, resp);
  });
};
