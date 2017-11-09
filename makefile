sygwork: syg_null.o
	gcc -o sygwork syg_null.o

syg_null.o:
	gcc -c syg_null.c

run: sygwork
	./sygwork
