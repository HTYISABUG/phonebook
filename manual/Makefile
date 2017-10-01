CC ?= gcc
CFLAGS_common ?= -Wall -std=gnu99 -g -O0

all: calculate  

calculate: calculate.c
	$(CC) $(CFLAGS_common) $^ -o $@

mode: calculate
	./calculate mod.txt bkdr.txt
	gnuplot mode.gp

size: calculate
	./calculate bkdr.txt 4k.txt 8k.txt
	gnuplot size.gp

.PHONY: clean
clean:
	$(RM) calculate output.txt mode.png size.png
