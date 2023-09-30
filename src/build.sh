#!/bin/sh

g++ -I/usr/local/include/ -L/usr/local/lib/raylib/ $1 -lraylib && ./a.out
