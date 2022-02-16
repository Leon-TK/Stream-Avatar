#pragma once

#include <fstream>




#include <Poco/StreamCopier.h>
#include "Poco/Net/HTTPSClientSession.h"
#include "Poco/Net/HTTPSessionFactory.h"
#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/Net/HTMLForm.h"
#include "Poco/JSON/Object.h"
#include "Poco/StreamCopier.h"
#include "Poco/Path.h"
#include "Poco/URI.h"
#include "Poco/Exception.h"
#include "Poco/SharedPtr.h"
#include "Poco/Net/SSLManager.h"
#include "Poco/Net/KeyConsoleHandler.h"
#include "Poco/Net/ConsoleCertificateHandler.h"
#include "Poco/Net/AcceptCertificateHandler.h"

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



