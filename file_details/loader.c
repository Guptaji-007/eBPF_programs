#include <stdio.h>
#include <unistd.h>
#include "fileD.skel.h"


int main() {
	struct fileD_bpf *skel;
	skel = fileD_bpf__open_and_load();
	if (!skel) {
        	fprintf(stderr, "Failed to open/load BPF skeleton\n");
        	return 1;
    	}

    	if (fileD_bpf__attach(skel)) {
        	fprintf(stderr, "Failed to attach BPF program\n");
        	return 1;
   	}	

    	printf("eBPF program loaded. Try running `ls` in another terminal.\n");

    	while (1)
        	sleep(1);

    	fileD_bpf__destroy(skel);
    	return 0;
}
