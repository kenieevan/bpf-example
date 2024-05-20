#include <stdio.h>
#include "bpf.h"

int main()
{
   int prog_idx = 1;

   // step 1: open the map by path
   int map_fd = bpf_obj_get("/sys/fs/bpf/jmp_table1");
   if (map_fd < 0) {
	   printf("open map failed\n");
	   return -1;
   }

   // step 2: open the prog by path
   int prog_fd = bpf_obj_get("/sys/fs/bpf/tail_call2");
   if (prog_fd < 0) {
	   printf("open prog failed\n");
	   return -1;
   }

   if (bpf_map_update_elem(map_fd, &prog_idx, &prog_fd, 0) != 0) {
      printf("add jmp table failed\n");
      return -1;
   }
}
