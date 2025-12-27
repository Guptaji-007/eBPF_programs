#include <stdio.h>
#include <unistd.h>
#include "hello.skel.h"

int main() {
    struct hello_bpf *skel;

    skel = hello_bpf__open_and_load();
    if (!skel) {
        fprintf(stderr, "Failed to open/load BPF skeleton\n");
        return 1;
    }

    if (hello_bpf__attach(skel)) {
        fprintf(stderr, "Failed to attach BPF program\n");
        return 1;
    }

    printf("eBPF program loaded. Try running `ls` in another terminal.\n");

    while (1)
        sleep(1);

    hello_bpf__destroy(skel);
    return 0;
}
