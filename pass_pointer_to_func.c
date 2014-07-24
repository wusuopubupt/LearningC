#include <stdio.h>
#include <stdlib.h>

void func(int **a) {
    *a = (int *)malloc(sizeof(int));
}
int main() {
    int *p = NULL;
    func(&p);
    *p = 6;
    printf("%d\n", *p);
    return 0;
}


/* gcc -g pass_pointer_to_func.c -o test */

/*
dash@linux:~/cDev/memory$ gdb test
GNU gdb (Ubuntu/Linaro 7.4-2012.04-0ubuntu2.1) 7.4-2012.04
Copyright (C) 2012 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
For bug reporting instructions, please see:
<http://bugs.launchpad.net/gdb-linaro/>...
Reading symbols from /home/dash/cDev/memory/test...done.
(gdb) list
warning: Source file is more recent than executable.
1	#include <stdio.h>
2	#include <stdlib.h>
3	
4	void func(int **a) {
5	    *a = (int *)malloc(sizeof(int));
6	}
7	int main() {
8	    int *p = NULL;
9	    func(&p);
10	    *p = 6;
(gdb) break 9
Breakpoint 1 at 0x40058e: file pass_pointer_to_func.c, line 9.
(gdb) run
Starting program: /home/dash/cDev/memory/test 
warning: no loadable sections found in added symbol-file system-supplied DSO at 0x7ffff7ffa000

Breakpoint 1, main () at pass_pointer_to_func.c:9
9	    func(&p);
(gdb) step
func (a=0x7fffffffe178) at pass_pointer_to_func.c:5
5	    *a = (int *)malloc(sizeof(int));
(gdb) next
6	}
(gdb) print *a
$1 = (int *) 0x602010
(gdb) next
main () at pass_pointer_to_func.c:10
10	    *p = 6;
(gdb) i locals
p = 0x602010
(gdb) next
11	    printf("%d\n", *p);
(gdb) i locals
p = 0x602010
(gdb) print *p
$2 = 6
(gdb) next
12	    return 0;
(gdb) 


 */
