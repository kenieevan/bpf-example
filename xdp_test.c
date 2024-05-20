#include <linux/bpf.h>
#include <bpf_helpers.h>

SEC("xdp")
int xdp_prog_drop(struct xdp_md *ctx)
{
    return XDP_DROP;
}

char _license[] SEC("license") = "GPL";
