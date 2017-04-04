all: sha2

sha2:
	gcc sha2.c sha2t.c -o sha2

clean:
	-rm -rf *.o sha2

