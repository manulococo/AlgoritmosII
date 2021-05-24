CC = g++
CFLAGS = -Wall -g
 
test: bignum.o cmdline.o precisionfija.o tp0.o
	$(CC) $(CFLAGS) -o test bignum.o cmdline.o precisionfija.o tp0.o

tp0.o: tp0.cpp bignum.h cmdline.h precisionfija.h 
	$(CC) $(CFLAGS) -c tp0.cpp

cmdline.o: cmdline.h
	$(CC) $(CFLAGS) -c cmdline.cpp
 
precisionfija.o: precisionfija.h
	$(CC) $(CFLAGS) -c precisionfija.cpp

bignum.o: bignum.h
	$(CC) $(CFLAGS) -c bignum.cpp

clean:
	rm *.o
	rm test