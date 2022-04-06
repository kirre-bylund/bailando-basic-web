include(FetchContent)

set(BUILD_CURL_EXE OFF CACHE BOOL "")
set(BUILD_SHARED_LIBS OFF CACHE BOOL "")
set(CURL_STATICLIB ON CACHE BOOL "")

FetchContent_Declare(
  extern_curl
  GIT_REPOSITORY "https://github.com/curl/curl"
  GIT_TAG 9e560d11aad028de74addc0d1edfefa5667884f4 # 7.80.0
)

add_subdirectory(curl)

FetchContent_Declare(
  extern_json
  GIT_REPOSITORY "https://github.com/nlohmann/json"
  GIT_TAG 4f8fba14066156b73f1189a2b8bd568bde5284c5 # 3.10.5
)

add_subdirectory(json)