all:
	gcc ls.c -o ls
	gcc date.c -o date
	gcc cat.c -o cat
	gcc rm.c -o rm
	gcc mkdir.c -o mkdir
	gcc shell.c -o shell
run:
	./shell

clean:
	rm -rf shell *.o
	rm -rf cat *.o
	rm -rf ls *.o
	rm -rf date *.o
	rm -rf rm *.o
	rm -rf mkdir *.o

