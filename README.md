# gdbtrap
Launch GDB on death by signal

After `gdbtrap.so` built, gdb can be launched on signal by with

```
LD_PRELOAD=/path/to/gdbtrap.so /path/to/executable
```
