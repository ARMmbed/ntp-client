#include "mbed.h"

class NTPClient {
    public:
        NTPClient(NetworkInterface *iface);
        time_t get_timestamp(int timeout = 15000);
        
        static const char* NIST_SERVER_ADDRESS;
        static const int NIST_SERVER_PORT;
        
    private:
        NetworkInterface *iface;
        uint32_t ntohl(uint32_t num);
};