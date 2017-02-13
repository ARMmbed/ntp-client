#include "ntp-client/NTPClient.h"
#include "mbed.h"

const char* NTPClient::NIST_SERVER_ADDRESS = "pool.ntp.org";
const int NTPClient::NIST_SERVER_PORT = 123;

NTPClient::NTPClient(NetworkInterface *iface) {
    this->iface = iface;    
}

time_t NTPClient::get_timestamp(int timeout) {
    const time_t TIME1970 = 2208988800L;
    int ntp_send_values[12] = {0};
    int ntp_recv_values[12] = {0};
    
    SocketAddress nist;
    int ret_gethostbyname = iface->gethostbyname(NIST_SERVER_ADDRESS, &nist);
    
    if (ret_gethostbyname < 0) {
        // Network error on DNS lookup
        return ret_gethostbyname;
    }
    
    nist.set_port(NIST_SERVER_PORT);
    
    memset(ntp_send_values, 0x00, sizeof(ntp_send_values));
    ntp_send_values[0] = '\x1b';

    memset(ntp_recv_values, 0x00, sizeof(ntp_recv_values));
    
    UDPSocket sock;
    sock.open(iface);
    sock.set_timeout(timeout);

    int ret_send = sock.sendto(nist, (void*)ntp_send_values, sizeof(ntp_send_values));

    SocketAddress source;
    const int n = sock.recvfrom(&source, (void*)ntp_recv_values, sizeof(ntp_recv_values));
    
    if (n > 10) {
        return ntohl(ntp_recv_values[10]) - TIME1970;
    } else {
        if (n < 0) {
            // Network error
            return n;
        } else {
            // No or partial data returned
            return -1;
        }
    }
}

uint32_t NTPClient::ntohl(uint32_t x) {
    uint32_t ret = (x & 0xff) << 24;
    ret |= (x & 0xff00) << 8;
    ret |= (x & 0xff0000UL) >> 8;
    ret |= (x & 0xff000000UL) >> 24;
    return ret;
}