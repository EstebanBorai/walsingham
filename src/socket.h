#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>

/**
 * Buffer size to store data received from socket as
 * packets
 */
static const int BUFFER_SIZE = 66000;

/**
 * Type definition for `<sys/socket.h>` `sockaddr`
 */
typedef struct sockaddr SockAddr;

/**
 * Type definition for `<sys/socket.h>` `in_addr`
 */
typedef struct in_addr InAddr;

/**
 * A `Buffer` to store packet's bytes
 */
typedef void* Buffer;

/**
 * Dynamically allocates `BUFFER_SIZE` bytes and
 * retrieves it's pointer as an intance of `Buffer`
 */
Buffer new_buffer(int size) {
    return (Buffer) malloc(size);
}

/**
 * Type definition of `int` intended as a `RawSocket`
 * binding result
 */
typedef int RawSocket;

/**
 * Creates a new `RawSocket` by binding to system's
 * network interfaces with IPv4 internet protocol.
 * 
 * Also use raw network protocol access to have all
 * available details from the socket.
 * 
 * Also makes use of TCP stream sockets.
 */
RawSocket new_raw_socket() {
    int raw_socket = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);

    if (raw_socket < 0) {
        printf("Failed to create new raw socket\n Received: %d", raw_socket);
        printf("Make sure you have the right permissions. Run this file using `sudo <filename>`");
        return 1;
    }

    return raw_socket;
}

/**
 * Receive packets from the provided `RawSocket` and store
 * received bytes into the provided `Buffer`
 */
int receive_from_raw_socket(RawSocket raw_socket, Buffer buffer, int buffer_size, SockAddr addr, int addr_size) {
    return recvfrom(raw_socket, buffer, buffer_size, 0, &addr, &addr_size);
}

/**
 * Creates a `RawSocket` instance which is used along with
 * `recvfrom` which receives all incoming packets.
 * 
 * The `RawSocket` is not bound to a particular address, thus
 * any package will be received in this stream.
 */
int sniff() {
    SockAddr saddr;
    int data_size = 1;
    int addr_size = sizeof(saddr);

    Buffer buf = new_buffer(BUFFER_SIZE);
    RawSocket socket = new_raw_socket();

    if (socket == 0) {
        return 1;
    }

    while (1) {
        int bytes_received = receive_from_raw_socket(socket, buf, BUFFER_SIZE, saddr, addr_size);

        if (bytes_received < 0) {
            printf("Unable to receive bytes from socket.\n");
            printf("Make sure you have the correct permissions.\n");
            return 1;
        }

        printf("Received %d bytes\n", bytes_received);
    }
}
