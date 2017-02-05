CFLAGS = -std=gnu99

INCLUDE_PATH = ../src

kmemproxy.o: kmemproxy.c
	$(CC) $(CFLAGS) -c -I$(INCLUDE_PATH) $<

.PHONY: clean
clean:
	rm -rf kmemproxy.o
