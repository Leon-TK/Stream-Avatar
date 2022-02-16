#pragma once

#include <fstream>




#include <Poco/StreamCopier.h>
#include "thirdparty/Poco/Net/HTTPSClientSession.h"
#include "thirdparty/Poco/Net/HTTPSessionFactory.h"
#include "thirdparty/Poco/Net/HTTPRequest.h"
#include "thirdparty/Poco/Net/HTTPResponse.h"
#include "thirdparty/Poco/Net/HTMLForm.h"
#include "thirdparty/Poco/JSON/Object.h"
#include "thirdparty/Poco/StreamCopier.h"
#include "thirdparty/Poco/Path.h"
#include "thirdparty/Poco/URI.h"
#include "thirdparty/Poco/Exception.h"
#include "thirdparty/Poco/SharedPtr.h"
#include "thirdparty/Poco/Net/SSLManager.h"
#include "thirdparty/Poco/Net/KeyConsoleHandler.h"
#include "thirdparty/Poco/Net/ConsoleCertificateHandler.h"
#include "thirdparty/Poco/Net/AcceptCertificateHandler.h"

#include "Incl.h"
#include "IProcessMessage.h"
#include "Responses.h"
#include "UtilsMessage.h"
#include "InMessages.h"
#include "CentrifugoInclude.h"
#include "Requests.h"
#include "Variables.h"
#include "Defines.h"

class URequestMananger
{
private:
	Poco::SharedPtr<Poco::Net::InvalidCertificateHandler> m_pCert;
	Poco::Net::Context::Ptr m_pContext;

public:
	URequestMananger();
	~URequestMananger();

	bool sendCentrifugoTokenRequest();
	bool sendAccessTokenRequest();
	bool sendCentrifugeSubscribe();
	bool init();
	bool initSSL();
};



