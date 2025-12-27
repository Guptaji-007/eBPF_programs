#include "vmlinux.h"
#include <bpf/bpf_helpers.h>
#include <bpf/bpf_tracing.h>

char LICENSE[] SEC("license") = "GPL";

SEC("tracepoint/syscalls/sys_enter_execve")
int hello_execve(void *ctx)
{
    bpf_printk("Hello from eBPF!\n");
    return 0;
}

