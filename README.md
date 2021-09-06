<div>
  <div align="center" style="display: block; text-align: center;">
    <img src="./assets/walsingham.jpg" width="120" />
  </div>
  <h1 align="center">Walsingham</h1>
  <h4 align="center">A packet sniffer.</h4>
</div>

A socket with no address pointed used in `recvfrom` function,
will receive packets from all available sources/network interfaces.

This project focuses on receiving these packets, and read it's
contents.

## Usage

```bash
# build the source code using gcc
gcc ./src/main.c

# run the executable providing sudo
# sudo is required to bind to a Unix socket
sudo ./a.out
```

In this version the expected output is the length of
bytes received:

```log
Received 60 bytes
Received 52 bytes
Received 4148 bytes
Received 1349 bytes
Received 371 bytes
Received 104 bytes
Received 52 bytes
Received 759 bytes
Received 119 bytes
Received 118 bytes
Received 118 bytes
Received 52 bytes
```

## Motivation

As part of writing C for exploration and also give a try on Linux
libraries. Im writing this Packet Sniffer.

## About the name

The name is inspired by Francis Walsingham, the _master of spies_
for Queen's Elizabeth I.

Read more about him here: [History of espionage | Early Modern Europe](https://en.wikipedia.org/wiki/History_of_espionage#Early_Modern_Europe)
