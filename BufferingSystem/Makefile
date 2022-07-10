CC = time gcc
CFLAGS = -pthread

buffer: bufferingSystem.c buffer.o buffer.h
	@echo "Compiling files.c"
	@$(CC) $(CFLAGS) -o $@ $^  

.PHONY: clean
clean:
	rm *.o buffer 