#include "IResponse.h"

AResponse::AResponse(Poco::Net::HTTPSClientSession& rS) : s(rS)
{
}
