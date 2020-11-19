# Alex Weeden
# COMP 3500 Project 5
# Makefile
# Youtube tutorials, starter Makefile provided by Dr. Qin referenced and used
# Compilation instructions commented in scheduler.h
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
