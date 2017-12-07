all:
	gcc -o control sem.c

run: all
	./control
	./control -c
	./control -c -1
	./control -c 4
	./control -v
	./control -c 3
	./control -v
	./control -r
	./control -v
	./control -r
	./control -z

clean:
	rm -f *~
	rm -f control
