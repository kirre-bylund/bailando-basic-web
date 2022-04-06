#ifndef LUKES_MASS
#define LUKES_MASS

#include "JSONCompatible.h"
#include <nlohmann/json.hpp>
#include <iostream>
#include <string>

class LukesMass : JSONCompatible {
public:
    int mass;
    LukesMass(nlohmann::json fromJson) : JSONCompatible(fromJson) {
        if(fromJson.contains("mass")) {
            mass = std::stoi(fromJson["mass"].get<std::string>());
        } else {
            mass = fromJson["json"]["mass"].get<int>();
        }
    };

    nlohmann::json toJSON() const {
        return {{"mass", mass}};
    };

    std::string toJSONString() const {
        return toJSON().dump();
    }

    nlohmann::json getOriginalJSON() const {
        return _originalJSON;
    }
};

#endif //LUKES_MASS