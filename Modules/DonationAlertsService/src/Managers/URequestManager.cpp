#include "URequestMananger.h"
URequestMananger::URequestMananger()
{
	Init();
}

URequestMananger::~URequestMananger()
{
}

bool URequestMananger::sendAccessTokenRequest()
{
	//Session
	Poco::URI uri(std::string(DONATIONTOKEN));
	Poco::Net::HTTPSClientSession s(uri.getHost(), uri.getPort());

	//Request
	IProcessRequest* process = new RAccessToken();
	Poco::Net::HTTPRequest* req = process->GetRequest();
	delete process;
	//Creating data through form
	Poco::Net::HTMLForm form(*req);
	form.set("grant_type", "authorization_code");
	form.set("client_id", std::string(APPID));
	form.set("client_secret", std::string(APPCODE));
	form.set("redirect_uri", std::string(DONATIONREDIRECT));
	form.set("code", Variables::m_AccessCode);
	form.prepareSubmit(*req);
	form.write(s.sendRequest(*req));
	delete req;
	//Creating data through json
	/*
	request.setContentType("application/json");
	std::ostream& myOStream = s.sendRequest(request);
	Poco::JSON::Object::Ptr json = prs->ConstructAccessCodeRequestJson();
	json->stringify(myOStream);
	*/

	//Responce
	IResponse* rsp = new ResAccessToken(&s);

	std::istream& is = rsp->Process();
	delete rsp;
	std::string data;
	Poco::StreamCopier::copyToString(is, data);

	//Incoming message
	UtilsMessage um;
	IResponseMessage* message = um.GetResponseMessage(data);
	message->Process();
	delete message;
	return true;
}

bool URequestMananger::sendCentrifugoTokenRequest()
{

	Poco::URI uri(std::string(CENTRIFUGOTOKENENDPOINT));
	Poco::Net::HTTPSClientSession s(uri.getHost(), uri.getPort());

	IProcessRequest* process = new RCentrifugoToken();
	Poco::Net::HTTPRequest* req = process->GetRequest();
	delete process;
	s.sendRequest(*req); //TODO: ????
	delete req;
	IResponse* rsp = new ResCentrifugoToken(&s);

	std::istream& is = rsp->Process();
	delete rsp;
	std::string data;
	Poco::StreamCopier::copyToString(is, data);
	//Incoming message
	UtilsMessage um;
	IResponseMessage* message = um.GetResponseMessage(data);
	message->Process();
	delete message;
	return 1;
}


bool URequestMananger::sendCentrifugeSubscribe()
{
	//Session
	Poco::URI uri(std::string(CENTRIFUGOSUBSCRIBEENDPOINT));
	Poco::Net::HTTPSClientSession s(uri.getHost(), 443);

	//Request
	IProcessRequest* process = new RCentrifugoSubscribe();
	Poco::Net::HTTPRequest* req = process->GetRequest();
	//req->setKeepAlive(1);
	
	delete process;
	//json //TODO: i case Internal error change this!
	ICentrifugoMsg* msg = new UCentrifugoMsg2();
	std::string sJson = msg->GetMsg();
	delete msg;
	///*
	//Json from strig
	Poco::JSON::Parser prs;
	Poco::Dynamic::Var var = prs.parse(sJson);
	Poco::JSON::Object::Ptr obj = var.extract<Poco::JSON::Object::Ptr>();
	//*/

	

	/*
	Poco::JSON::Object obj;
	obj.set("name", "blah");
	obj.set("language", "english");
	*/

	/*
	//CHeck json
	std::string name = obj->getValue<std::string>("client");
	std::cout << name;
	std::cout << std::endl;
	Poco::JSON::Array::Ptr children = obj->getArray("channels");
	std::string nd = children->get(0);
	std::cout << nd;
	std::cout << std::endl;
	*/

	///*
	//stringify json 1
	std::stringstream ss;
	obj->stringify(ss);
	req->setContentLength(ss.str().size());
	//*/

	/*
	//stringify json 2
	std::ostringstream ss;
	obj.stringify(ss);
	std::string body;
	body = ss.str();
	req->setContentLength(body.length());
	std::cout << body;
	std::cout << std::endl;
	*/

	///*
	//Sending json 1 
	std::ostream& myOStream = s.sendRequest(*req);
	obj->stringify(myOStream);
	//*/
	delete req;
	/*
	//Sending json 2
	s.sendRequest(*req) << body;
	*/

	//Responce

	IResponse* rsp = new ResCentrifugoSubscribe(&s);

	std::istream& is = rsp->Process();
	delete rsp;
	std::string data;
	Poco::StreamCopier::copyToString(is, data);
	//Incoming message
	UtilsMessage um;
	IResponseMessage* message = um.GetResponseMessage(data);
	message->Process();
	delete message;
	return true;
}

bool URequestMananger::init()
{
	InitSSL();
	return true;
}

bool URequestMananger::initSSL()
{
	ptrCert = new Poco::Net::AcceptCertificateHandler(false);
	ptrContext = new Poco::Net::Context(Poco::Net::Context::TLS_CLIENT_USE, "", "", "", Poco::Net::Context::VERIFY_RELAXED, 9, false, "ALL:!ADH:!LOW:!EXP:!MD5:@STRENGTH");
	Poco::Net::SSLManager::instance().initializeClient(0, ptrCert, ptrContext);

	/*
	Poco::SharedPtr<Poco::Net::InvalidCertificateHandler> ptrCert = new Poco::Net::AcceptCertificateHandler(false);
	Poco::Net::Context::Ptr ptrContext = new Poco::Net::Context(Poco::Net::Context::TLS_CLIENT_USE, "", "", "", Poco::Net::Context::VERIFY_RELAXED, 9, false, "ALL:!ADH:!LOW:!EXP:!MD5:@STRENGTH");
	Poco::Net::SSLManager::instance().initializeClient(0, ptrCert, ptrContext);
	*/

	return true;
}


