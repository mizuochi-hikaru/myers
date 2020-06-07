# クソダサMakefile


all: myers

myers: bin/myers.o bin/myerslib.o
	gcc -o bin/myers bin/myers.o bin/myerslib.o

test: bin/myers.test.o bin/myerslib.o
	gcc -o bin/myers.test bin/myers.test.o bin/myerslib.o

bin/myers.o: myers.c
	gcc -c myers.c -o bin/myers.o

bin/myers.test.o: myers.test.c
	gcc -c myers.test.c -o bin/myers.test.o

bin/myerslib.o: myerslib.c
	gcc -c myerslib.c -o bin/myerslib.o

.PHONY: clean
clean:
	rm -f bin/*


