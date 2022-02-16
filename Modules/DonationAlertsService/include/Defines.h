#pragma once

/////////////////
//Centrifugo defs
#define CENTRIFUGOCHANNEL "$alerts:donation_" //$alerts:donation_<user_id>
#define CENTRIFUGOENDPOINT "wss://centrifugo.donationalerts.com/connection/websocket"
#define CENTRIFUGOSUBSCRIBEENDPOINT "https://www.donationalerts.com/api/v1/centrifuge/subscribe"
#define CENTRIFUGOTOKENENDPOINT "https://www.donationalerts.com/api/v1/user/oauth"
//Centrifugo defs
/////////////////


////////////////
//Donation defs
#define DONATIONAUTH "https://www.donationalerts.com/oauth/authorize"
#define DONATIONTOKEN "https://www.donationalerts.com/oauth/token"
#define DONATIONREDIRECTS "https://localhost"
#define DONATIONREDIRECT "http://localhost"
#define DONATIONCODEURL "/?code="
#define DONATIONSCOPE "oauth-user-show"
#define DONATIONSCOPE2 "oauth-donation-subscribe"
#define DONATIONIP "95.163.254.117"
#define DONATIONPORT 443
#define APPID "659"
#define USERCODE "SOZgWsh2PVNuWk5QiwhS"
#define APPCODE "ASwMxDnBrlP4CS7J1qs82KESVQHiFYEyqPwRoMCT"
#define DONATIONSOCKETUPDATERATE 0.01f
//Donation defs
///////////////

////////
//Debug

//#define DEBUG
#define G_DEBUGPARSERS


//Debug
////////