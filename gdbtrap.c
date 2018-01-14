// gcc -g -fpic -shared -nostartfiles -o gdbtrap.so gdbtrap.c
// LD_PRELOAD=/path/to/gdbtrap.so /path/to/executable

#include <signal.h>
#include <unistd.h>
#include <sys/prctl.h>
#include <stdlib.h>
#include <stdio.h>

void launch_gdb(int sig)
{
    system("exec gdb -p \"$PPID\"");
    _exit(128 + sig);
}

void _init()
{
    signal(SIGABRT, launch_gdb);
    signal(SIGBUS,  launch_gdb);
    signal(SIGFPE,  launch_gdb);
    signal(SIGILL,  launch_gdb);
    signal(SIGQUIT, launch_gdb);
    signal(SIGSEGV, launch_gdb);
    signal(SIGSYS,  launch_gdb);
    signal(SIGTRAP, launch_gdb);
    signal(SIGXCPU, launch_gdb);
    signal(SIGXFSZ, launch_gdb);
}
