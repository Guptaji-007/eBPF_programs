#include "vmlinux.h"
#include <bpf/bpf_helpers.h>
#include <bpf/bpf_tracing.h>

char LICENSE[] SEC("license") = "GPL";

SEC("tracepoint/syscalls/sys_enter_execve")
int fileD(struct trace_event_raw_sys_enter *ctx)
{
    u32 pid = bpf_get_current_pid_tgid() >> 32;
    char comm[16];
    char filename[256];

    bpf_get_current_comm(&comm, sizeof(comm));

    bpf_probe_read_user_str(filename, sizeof(filename), (void *)ctx->args[0]);

    bpf_printk("execve: pid=%d comm=%s file=%s", pid, comm, filename);

    return 0;
}

