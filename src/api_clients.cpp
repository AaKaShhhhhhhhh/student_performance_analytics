#include "api_clients.h"

APIClient::APIClient(const std::string& base_url) : base(base_url) {}

std::string APIClient::post_nlq(const std::string& text, const std::string& db) {
    // send HTTP POST to /nlq and return response
    return {};
}