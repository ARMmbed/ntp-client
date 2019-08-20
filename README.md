# Mbed OS NTP Client

This library allows you to fetch time information from a NTP server.

For an example application, please see https://github.com/ARMmbed/ntp-client-example.

## Getting started

If you don't have an existing Mbed OS project, go ahead and create one.

```sh
mbed new ntp-project
cd ntp-project
```

Now add the library to your project.

```sh
mbed import https://github.com/ARMmbed/ntp-client
```

The library will now be available in your project. Please see the API documentation below for usage information.

## API

### `NTPClient(NetworkInterface *iface)` [constructor]

Create an NTP client. You need to provide a pointer to an [Mbed OS NetworkInterface](https://os.mbed.com/docs/mbed-os/v5.13/apis/network-socket.html). The interface should be connected and ready before calling `get_timestamp`.

### `time_t NTPClient::get_timestamp(int timeout)`

Return time information, typed as a [`time_t`](http://www.cplusplus.com/reference/ctime/time_t/). You can pass in an optional timeout argument (defaults to 15000 milliseconds). For information on timeout values, please see the [Mbed OS Socket documentation](https://os.mbed.com/docs/mbed-os/v5.13/apis/socket.html).

### `void set_server(char* server, int port)`

Change the NTP server and port. The default server is `2.pool.ntp.org` and the default port is `123`.
