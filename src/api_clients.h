#pragma once
#include <string>

class APIClient {
public:
    explicit APIClient(const std::string& base_url);
    std::string post_nlq(const std::string& text, const std::string& db = "");
private:
    std::string base;
};