#include <cstdio>

#include "httplib.h"

int main() {
  constexpr const char* kHost = "127.0.0.1";
  constexpr int kPort = 8080;

  httplib::Server svr;

  svr.Get("/health", [](const httplib::Request&, httplib::Response& res) {
    res.set_content("ok", "text/plain");
  });

  svr.Post("/predict", [](const httplib::Request&, httplib::Response& res) {
    res.set_content(R"({"result": "dummy"})", "application/json");
  });

  std::printf("Listening on http://%s:%d\n", kHost, kPort);
  if (!svr.listen(kHost, kPort)) {
    std::fprintf(stderr, "Failed to bind %s:%d (port in use?)\n", kHost, kPort);
    return 1;
  }
}
