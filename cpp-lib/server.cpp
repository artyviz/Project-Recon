#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include <iostream>

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

void handle_get(http_request request) {
    json::value response;
    response[U("message")] = json::value::string(U("Hello from Recon Backend!"));
    request.reply(status_codes::OK, response);
}

int main() {
    http_listener listener(U("http://localhost:8080"));

    listener.support(methods::GET, handle_get);

    try {
        listener.open().wait();
        std::wcout << L"Server is running at http://localhost:8080" << std::endl;
        std::wcin.get(); // Wait for user input to exit
    }
    catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
