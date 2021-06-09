all : final

motors : motors_mini

final : motors_mini.o but_celebration.o main.o
	gcc -o final motors_mini.o but_celebration.o main.o

main.o : main.c
	gcc -o main.o -c main.c

motors_mini.o : motors_mini.c
	gcc -o motors_mini.o -c motors_mini.c

but_celebration.o : but_celebration.c
	gcc -o but_celebration.o -c but_celebration.c