.PHONY: all clean run

INCLUDE_DIR = .

C_FLAGS = -I$(INCLUDE_DIR) -Wall -Wextra

all: main

clean:
	rm *.o main

run: main
	./main

main.o: main.c
	gcc -c main.c -lm $(C_FLAGS)

funcs.o: funcs.c
	gcc -c funcs.c -lm $(C_FLAGS)

main: main.o funcs.o
	gcc main.o funcs.o -o main
