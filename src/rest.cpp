#include <exception>

#include "rest.h"

void Rest::handle_request(web::http::http_request req,
                          std::function<void()> handler) {
  try {
    handler();
  } catch (std::exception &e) {
    ucerr << "Failed to handle request: " << e.what() << std::endl;
    ucerr << req.to_string() << std::endl;
    throw e;
  }
}