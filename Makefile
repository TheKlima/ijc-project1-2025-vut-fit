CC = gcc
CFLAGS = -O2 -g -std=c11 -pedantic -Wall -Wextra
LDLIBS = -lm

all: primes primes-i steg-decode

run: primes primes-i
	./primes
	./primes-i

# non-inline
error.o: error.c error.h
eratosthenes.o: eratosthenes.c eratosthenes.h bitset.h error.h
primes.o: primes.c eratosthenes.h bitset.h error.h
ppm.o: ppm.c ppm.h error.h
steg-decode.o: steg-decode.c ppm.h error.h eratosthenes.h bitset.h

primes: primes.o eratosthenes.o error.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)

steg-decode: steg-decode.o ppm.o eratosthenes.o error.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)

# inline
bitset-i.o: bitset.c bitset.h error.h
	$(CC) $(CFLAGS) -DUSE_INLINE -c $< -o $@

eratosthenes-i.o: eratosthenes.c eratosthenes.h bitset.h error.h
	$(CC) $(CFLAGS) -DUSE_INLINE -c $< -o $@

primes-i.o: primes.c bitset.h eratosthenes.h error.h
	$(CC) $(CFLAGS) -DUSE_INLINE -c $< -o $@

primes-i: primes-i.o eratosthenes-i.o bitset-i.o error.o
	$(CC) $(CFLAGS) -DUSE_INLINE $^ -o $@ $(LDLIBS)

pack:
	zip xklyme00 *.c *.h Makefile

clean:
	rm -f *.o primes primes-i steg-decode
