all : final


main : main
but : but_celebration
finalmotor : finalmotor

final : motors_mini.o but_celebration.o main.o
	gcc -o final motors_mini.o but_celebration.o main.o -lwiringPi -lwiringPiDev

finalmotor : motors_mini.o
	gcc -c finalmotor motors_mini.o -lwiringPi -lwiringPiDev

main.o : main.c
	gcc -o main.o -c main.c -lwiringPi -lwiringPiDev

motors_mini.o : motors_mini.c
	gcc -o motors_mini.o -c motors_mini.c -lwiringPi -lwiringPiDev

but_celebration.o : but_celebration.c
	gcc -o but_celebration.o -c but_celebration.c -lwiringPi -lwiringPiDev