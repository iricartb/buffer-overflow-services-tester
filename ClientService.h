#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <winsock.h>
#include "Global.h"

#define CLIENT_SERVICE_RECV_DEFAULT_SECONDS_TIMEOUT           10
#define CLIENT_SERVICE_RECV_BUFFER_SIZE                       256

using namespace std;

class ClientService {
   protected:
      string sTargetHostnameIP, sCryptographicSecurityProtocol, sLoginUsername, sLoginPassword;
      
      int nSocketId;
      unsigned int nRecvSecTimeout;
      unsigned int nTargetPort;
      unsigned int nDefaultPort, nDefaultPortSSL, nDefaultPortTLS;
      
      bool bAuthCryptographicSecurity, bAuthLoginUser;
		 
   private:
      void initializeClientService();
      virtual bool authCryptographicSecurity() = 0;
      virtual bool authLoginUser() = 0;
      
   public:
      ClientService(unsigned int nRecvSecTimeout = CLIENT_SERVICE_RECV_DEFAULT_SECONDS_TIMEOUT);
      ~ClientService();
      
      bool connectSocket(string sTargetHostnameIP, unsigned int nTargetPort = 0, string sCryptographicSecurityProtocol = GLOBAL_CRYPTOGRAPHIC_SECURITY_PROTOCOL_VALUE_NONE);
		bool disconnectSocket();
      
      bool sendSocketData(string sSocketData);
      string recvSocketData();
      
      void setLoginCredentials(string sLoginUsername, string sLoginPassword);
      
      string getTargetHostnameIP();
      string getCryptographicSecurityProtocol();
      string getLoginUsername();
      string getLoginPassword();
      
      unsigned int getTargetPort();
      unsigned int getDefaultPort();
      unsigned int getDefaultPortSSL();
      unsigned int getDefaultPortTLS();
      
      bool isConnectionKeepAlive();
      bool isAuthCryptographicSecurity();
      bool isAuthLoginUser();
};
