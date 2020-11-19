CC = gcc
CFLAGS = -g
OBJ = cmdinput.o fcfs.o srtf.o rr.o analysis.o printstat.o

scheduler: $(OBJ) scheduler.c
	@echo "Creating scheduler:"
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c %.h
	@echo "Creating object files:"
	$(CC) -c $< -o $@

clean:
	@echo "Removing object and binary files:"
	rm -rvf *.o scheduler
