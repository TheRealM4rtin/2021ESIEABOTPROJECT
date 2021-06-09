all : final

motors : motors_mini
main : main
but : but_celebration

final : motors_mini.o but_celebration.o main.o
	gcc -o final motors_mini.o but_celebration.o main.o -lcd -lwiringPi

finalmotor : motors_mini.o
	gcc -c finalmotor motors_mini.o -lcd -lwiringPi

main.o : main.c
	gcc -o main.o -c main.c -lcd -lwiringPi

motors_mini.o : motors_mini.c
	gcc -o motors_mini.o -c motors_mini.c -lcd -lwiringPi

but_celebration.o : but_celebration.c
	gcc -o but_celebration.o -c but_celebration.c -lcd -lwiringPi