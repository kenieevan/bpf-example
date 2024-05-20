#!/usr/bin/env bash
clang -O2  -g  -I../kernel-header/ -I../libbpf/src  -Wall -target bpf -c tail_call_bpf.c -o tail_call_bpf.o
clang -O2  -g  -I../kernel-header/ -I../libbpf/src  -Wall -target bpf -c tail_call_bpf2.c -o tail_call_bpf2.o

#apt install -y libbpf-dev
g++ tail_call_user.cpp -o tail_call_user  -I../libbpf/src -L/usr/lib/x86_64-linux-gnu -lbpf
