/**
 * @file restclient.h
 * @brief libcurl wrapper for REST calls
 * @author Daniel Schauenberg <d@unwiredcouch.com>
 * @version
 * @date 2010-10-11
 */

#ifndef INCLUDE_REST_H_
#define INCLUDE_REST_H_

#include <string>
#include <map>
#include <cstdlib>
#include <stdexcept>
#include <curl/curl.h>

#include "restclient-cpp/version.h"
#include "restclient-cpp/connection.h"

/**
 * @brief namespace for all rest definitions
 */
namespace util_rest {

  /**
    * public data definitions
    */
  typedef std::map<std::string, std::string> HeaderFields;

  /** @struct Response
    *  @brief This structure represents the HTTP response data
    *  @var Response::code
    *  Member 'code' contains the HTTP response code
    *  @var Response::body
    *  Member 'body' contains the HTTP response body
    *  @var Response::headers
    *  Member 'headers' contains the HTTP response headers
    */
  typedef struct {
    int code;
    std::string body;
    HeaderFields headers;
  } Response;

// init and disable functions
  int init() {
    CURLcode res = curl_global_init(CURL_GLOBAL_ALL);
    if (res == CURLE_OK) {
      return 0;
    } else {
      return 1;
    }
  };

  void disable() {
    curl_global_cleanup();
  };

  void check_header(std::vector<std::string> &headers) {
    if (headers.size() % 2 != 0) {
      throw std::invalid_argument("Rest Error: Header vector needs to be in pairs.");
    }
  };

  /**
    * public methods for the simple API. These don't allow a lot of
    * configuration but are meant for simple HTTP calls.
    *
    */
  int get(const std::string &url, std::vector<std::string> &headers, std::string &response_body) {
    RestClient::Response ret;
    RestClient::Connection *conn = new RestClient::Connection("");

    check_header(headers);
    for (int i = 0; i < headers.size(); i = i + 2) {
      conn->AppendHeader(headers[i], headers[i + 1]);
    }

    ret = conn->get(url);
    delete conn;

    response_body = ret.body;
    return ret.code;
  };

  int post(const std::string &url, const std::string &data, std::vector<std::string> &headers, std::string &response_body) {
    RestClient::Response ret;
    RestClient::Connection *conn = new RestClient::Connection("");

    check_header(headers);
    for (int i = 0; i < headers.size(); i = i + 2) {
      conn->AppendHeader(headers[i], headers[i + 1]);
    }

    ret = conn->post(url, data);
    delete conn;

    response_body = ret.body;
    return ret.code;
  };

  int put(const std::string &url, const std::string &data, std::vector<std::string> &headers, std::string &response_body) {
    RestClient::Response ret;
    RestClient::Connection *conn = new RestClient::Connection("");

    check_header(headers);
    for (int i = 0; i < headers.size(); i = i + 2) {
      conn->AppendHeader(headers[i], headers[i + 1]);
    }

    ret = conn->put(url, data);
    delete conn;

    response_body = ret.body;
    return ret.code;
  };



  int patch(const std::string &url, const std::string &data, std::vector<std::string> &headers, std::string &response_body) {
    RestClient::Response ret;
    RestClient::Connection *conn = new RestClient::Connection("");

    check_header(headers);
    for (int i = 0; i < headers.size(); i = i + 2) {
      conn->AppendHeader(headers[i], headers[i + 1]);
    }

    ret = conn->patch(url, data);
    delete conn;

    response_body = ret.body;
    return ret.code;
  };


  int del(const std::string &url, std::vector<std::string> &headers, std::string &response_body) {
    RestClient::Response ret;
    RestClient::Connection *conn = new RestClient::Connection("");

    check_header(headers);
    for (int i = 0; i < headers.size(); i = i + 2) {
      conn->AppendHeader(headers[i], headers[i + 1]);
    }

    ret = conn->del(url);
    delete conn;

    response_body = ret.body;
    return ret.code;
  };

} // namespace util_rest

#endif // INCLUDE_REST_H_