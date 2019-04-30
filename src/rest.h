#include <functional>

#include "cpprest/http_msg.h"

class Rest {
 protected:
  Rest() {}
  void handle_request(web::http::http_request req,
                      std::function<void()> handler);
};