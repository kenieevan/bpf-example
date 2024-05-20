#include <linux/bpf.h>
#include <linux/pkt_cls.h>
#include <bpf_helpers.h>

#define bpf_debug(fmt, ...)						\
		({							\
			char ____fmt[] = fmt;				\
			bpf_trace_printk(____fmt, sizeof(____fmt),	\
				     ##__VA_ARGS__);			\
		})

struct {
   __uint(type, BPF_MAP_TYPE_PROG_ARRAY);
   __uint(max_entries, 100);
   __type(key, __u32);
   __type(value, __u32);
   __uint(pinning, LIBBPF_PIN_BY_NAME);
} jmp_table1 SEC(".maps");

SEC("xdp")
int xdp_test(struct __sk_buff *skb)
{
   bpf_debug("The first bpf prog \n");
   bpf_tail_call(skb, &jmp_table1, 1);

   bpf_debug("Pass through as jmp table is empty\n");
   return TC_ACT_OK;
}

char _license[] SEC("license") = "GPL";
