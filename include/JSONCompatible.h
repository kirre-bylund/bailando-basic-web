#ifndef JSON_COMPATIBLE
#define JSON_COMPATIBLE

#include <string>
#include <nlohmann/json.hpp>

class JSONCompatible {
    protected:
        nlohmann::json _originalJSON;
    public:
        JSONCompatible(nlohmann::json fromJson) : _originalJSON(fromJson) {};

        virtual nlohmann::json toJSON() const = 0;

        virtual std::string toJSONString() const = 0;
};

#endif //JSON_COMPATIBLE