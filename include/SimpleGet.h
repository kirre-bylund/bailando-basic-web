#ifndef SIMPLE_GET
#define SIMPLE_GET

#include "SimpleResult.h"
#include <nlohmann/json.hpp>
#include <curl/curl.h>
#include <iostream>

class SimpleGet {
    public:
        SimpleGet() = delete;

        template <class JSONCompatibleType>
        static SimpleResult<JSONCompatibleType> get(const std::string& url) {
            CURL *curl;
            CURLcode res;
            struct curl_slist *headers = NULL;
            
            curl_global_init(CURL_GLOBAL_DEFAULT);
            curl = curl_easy_init();
            if(!curl) {
                return SimpleResult<JSONCompatibleType>(-1);
            }


            headers = curl_slist_append(headers, "Accepts: application/json");
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
            curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 50L);
            curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1L);

            std::string responseString;
            std::string headerString;
            auto writeFunction = [] (void* ptr, size_t size, size_t nmemb, std::string* data) -> size_t {
                data->append((char*)ptr, size * nmemb);
                return size * nmemb;
            };
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, +writeFunction);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseString);
            curl_easy_setopt(curl, CURLOPT_HEADERDATA, &headerString);

            res = curl_easy_perform(curl);

            //std::cout << "result: " << res << std::endl;
            //std::cout << "responseString: " << responseString << std::endl;
            //std::cout << "headerString: " << headerString << std::endl;

            if(res != CURLE_OK) {
                return SimpleResult<JSONCompatibleType>(res);
            }

            curl_slist_free_all(headers);
            curl_easy_cleanup(curl);
            return SimpleResult<JSONCompatibleType>(res, JSONCompatibleType(nlohmann::json::parse(responseString)));
        };
};

#endif //SIMPLE_GET