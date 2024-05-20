#!/usr/bin/env bash

# load the bpf prog
sudo /usr/bin/bpftool prog load tail_call_bpf.o
sudo /usr/bin/bpftool prog load tail_call_bpf2.o /sys/fs/bpf/tail_call2

# chain them
sudo ./tail_call_user

# attach to dev
sudo ip link set dev lo xdp pinned /sys/fs/bpf/tail_call
