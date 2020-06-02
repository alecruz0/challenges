make:
	gcc -c utilities.c
	gcc -c matrix.c
	gcc -c main.c
	gcc -o rotation matrix.o main.o utilities.o
	
clean:
	rm main.o
	rm matrix.o
	rm utilities.o
	rm rotation
