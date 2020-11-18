CC = gcc
CFLAGS = -g
OBJ = cmdinput.o rr.o fcfs.o srtf.o printstat.o analysis.o

scheduler: $(OBJ) scheduler.c
	@echo "Creating scheduler:"
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c %.h
	@echo "Creating object files:"
	$(CC) -c $< -o $@

clean:
	@echo "Removing object and binary files:"
	rm -rvf *.o scheduler
