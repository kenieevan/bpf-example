#include <linux/bpf.h>
#include <linux/pkt_cls.h>
#include <bpf_helpers.h>

#define bpf_debug(fmt, ...)						\
		({							\
			char ____fmt[] = fmt;				\
			bpf_trace_printk(____fmt, sizeof(____fmt),	\
				     ##__VA_ARGS__);			\
		})

/* installed as tail call */
SEC("xdp")
int xdp_prog(struct __sk_buff *skb)
{
   bpf_debug("The chained tc bpf prog\n");
   return TC_ACT_OK;
}

char _license[] SEC("license") = "GPL";
