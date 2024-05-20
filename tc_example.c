#include <linux/bpf.h>
#include <linux/pkt_cls.h>
#include <bpf_helpers.h>

#ifndef __section
# define __section(NAME)                  \
   __attribute__((section(NAME), used))
#endif


__section("egress")
int tc_egress(struct __sk_buff *skb)
{
    bpf_printk("Hello, world\n");
    return TC_ACT_OK;
}

char __license[] __section("license") = "GPL";
