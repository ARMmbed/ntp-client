#include "mbed.h"

#define NTP_DEFULT_NIST_SERVER_ADDRESS "2.pool.ntp.org"
#define NTP_DEFULT_NIST_SERVER_PORT 123

class NTPClient {
    public:
        NTPClient(NetworkInterface *iface);
        void set_server(char* server, int port);
        time_t get_timestamp(int timeout = 15000);
        
    private:
        NetworkInterface *iface;
        uint32_t ntohl(uint32_t num);
        char* _nist_server_address;
        int _nist_server_port;
};