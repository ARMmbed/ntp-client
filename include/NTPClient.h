/* Copyright (c) 2019 ARM, Arm Limited and affiliates.
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "mbed.h"

#define NTP_DEFULT_NIST_SERVER_ADDRESS "2.pool.ntp.org"
#define NTP_DEFULT_NIST_SERVER_PORT 123

class NTPClient {
    public:
        explicit NTPClient(NetworkInterface *interface = NULL);
        void set_server(char* server, int port);
        time_t get_timestamp(int timeout = 15000);
        void network(NetworkInterface *interface);

    private:
        NetworkInterface *iface;
        char* nist_server_address;
        int nist_server_port;

        uint32_t ntohl(uint32_t num);
};
