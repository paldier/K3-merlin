#!/bin/sh

if [ -n `nvram get et2macaddr` ]; then
    MAC_ADDR=$(nvram get et2macaddr)
else
    MAC_ADDR=$(nvram get et0macaddr)
fi

echo K3
echo A1
echo 20171218
echo $MAC_ADDR
