#pragma once
class Api
{
public:
    std::string api;
    std::string apiKey;
    Api() {};
    Api(std::string api) : api(api) {};
    Api(std::string api, std::string apiKey) : api(api), apiKey(apiKey) {};
};

