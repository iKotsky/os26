all: mem mem2 mem3

mem: mem.c
	gcc -c -O0 -m32 -gdwarf -masm=intel mem.c -o mem.o
	gcc -m32 mem.o -o mem

mem2: mem2.c
	gcc -c -O0 -m32 -gdwarf -masm=intel mem2.c -o mem2.o
	gcc -m32 mem2.o -o mem2

mem3: mem3.c
	gcc -c -O0 -m32 -gdwarf -masm=intel mem3.c -o mem3.o
	gcc -m32 mem3.o -o mem3

clean:
	rm -f mem mem2 mem3 *.o
