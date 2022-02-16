#include "IStreamService.h"

//Core
#include "IApi.h"
//#include "IWebSocketManager.h"
#include "TwitchSocketManager.h"
#include "TwtichApi.h"
//~Core

class TwitchService : public IStreamService
{
private:
	ASocketManager* m_pSocketManager = nullptr;
	TwitchSocketManager m_tsm;
	TwitchApi m_api; //TODO api has const settings that needs to be passed to. CHange to non cost or pass settings to this class' constructor.

public:
	TwitchService();

	void start() override final;
	void stop() override final;
	std::thread* getThread() override final;
};