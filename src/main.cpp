#include <iostream>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include "SimpleGet.h"
#include "SimplePost.h"
#include "SimpleResult.h"
#include "LukesMass.h"

int main(int, char**) {
    SimpleResult<LukesMass> resp = SimpleGet::get<LukesMass>("https://swapi.dev/api/people/1/");

    std::cout << "GET performed. ResultCode: " << resp.result << std::endl;

    if(0 == resp.result && resp.data) {
        LukesMass& lukesMass = resp.data.value();

        std::cout << "LukesMass as json string: " << lukesMass.toJSONString() << std::endl;

        std::cout << "Original JSON: " << lukesMass.getOriginalJSON() << std::endl;

        SimpleResult<LukesMass> postResp = SimplePost::post<LukesMass>("https://httpbin.org/post", lukesMass.toJSON());

        std::cout << "POST performed. ResultCode: " << postResp.result << std::endl;
        if(0 == postResp.result && postResp.data) {
            LukesMass& lukesMassPost = postResp.data.value();

            std::cout << "LukesMass as json string: " << lukesMassPost.toJSONString() << std::endl;

            std::cout << "Original JSON: " << lukesMassPost.getOriginalJSON() << std::endl;
        }
    }
    return 0;
}