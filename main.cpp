#include <iostream>
#include "Poco/Net/HTTPClientSession.h"
#include "Poco/Net/HTTPMessage.h"
#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/StreamCopier.h"
#include "Poco/URI.h"

using Poco::Net::HTTPClientSession;
using Poco::Net::HTTPRequest;
using Poco::Net::HTTPResponse;
using Poco::Net::HTTPMessage;
using Poco::StreamCopier;
using Poco::URI;


int main() {
    URI uri("http://httpbin.org/ip");
    std::string path(uri.getPathAndQuery());

    HTTPClientSession session(uri.getHost(), uri.getPort());
    HTTPRequest request(HTTPRequest::HTTP_GET, path, HTTPMessage::HTTP_1_1);
    HTTPResponse response;

    session.sendRequest(request);
    std::istream& rs = session.receiveResponse(response);
    std::cout << response.getStatus() << " " << response.getReason() << std::endl;
    StreamCopier::copyStream(rs, std::cout);
}
