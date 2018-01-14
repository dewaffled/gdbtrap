all:
	$(CC) -g -fpic -shared -nostartfiles -o gdbtrap.so gdbtrap.c
clean:
	rm -f gdbtrap.so
