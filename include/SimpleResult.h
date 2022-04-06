#ifndef SIMPLE_RESULT
#define SIMPLE_RESULT

#include <string>
#include <optional>

template <class JSONCompatibleType>
struct SimpleResult  {
    public:
    SimpleResult(int emptyResponseResultCode) : data(std::nullopt), result(emptyResponseResultCode) {};
    SimpleResult(int emptyResponseResultCode, JSONCompatibleType inData) : data(std::optional(inData)), result(emptyResponseResultCode) {};
    std::optional<JSONCompatibleType> data;
    int result;
};

#endif //SIMPLE_RESULT