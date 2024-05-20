#device=lo
#sudo tc qdisc add dev $device clsact
#sudo tc filter add dev $device egress bpf da obj tc_example.o sec egress

# test load xdp_test.o without btf
sudo /usr/bin/bpftool  prog load xdp_test.o /sys/fs/bpf/xdp_test

