#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <unistd.h>
#include <lcd.h>
#include "motors_mini.h"
#include "but_celebration.h"

#define BACKLIGHT_OFF			0

int A = 25;			//GPIO26, entree A du decodeur
int B = 2;			//GPIO27, entree B du decodeur
int C = 21;			//GPIO5, entree C du decodeur
int D = 22;			//GPIO6, entree D du decodeur
	
int rs = 1;			//GPIO18, pin RS de l'ecran LCD
int e = 16;			//GPIO15, pin E de l'ecran LCD
int D4 = 15;			//GPIO14, pin D4 de l'ecran LCD
int D5 = 9;			//GPIO3, pin D5 de l'ecran LCD
int D6 = 8;			//GPIO2, pin D6 de l'ecran LCD
int D7 = 12;			//GPIO10, pin D7 de l'ecran LCD
char *team = "Incroyable SILMI";
int fd;			//valeur de retour de l'initialisation du LCD (-1 si erreur )

void lcd_but(){
	lcdPosition(fd, 0, 1);
	lcdPuts(fd, "GOGOGOOOAAL !");
}

void lcd_victoire(){
	lcdPosition(fd, 0, 0);
	lcdPuts(fd, "VICTOIRE !");
	lcdPosition(fd, 0, 1);
	lcdPuts(fd, "WELL PLAYED :) ");
}


void aff_7seg_but(int nb_goal){
	if( (nb_goal) == 0){
		digitalWrite(A,0);
		digitalWrite(B,0);
		digitalWrite(C,0);
		digitalWrite(D,0);
	}
	if( (nb_goal) == 1){
		digitalWrite(A,1);
		digitalWrite(B,0);
		digitalWrite(C,0);
		digitalWrite(D,0);
	}
	if( (nb_goal) == 2){
		digitalWrite(A,0);
		digitalWrite(B,1);
		digitalWrite(C,0);
		digitalWrite(D,0);
	}
	if( (nb_goal) == 3){
		digitalWrite(A,1);
		digitalWrite(B,1);
		digitalWrite(C,0);
		digitalWrite(D,0);
	}
}


void celebration(int nb_goal){
	int buts = 3;
	nb_goal = (nb_goal) +1;
	aff_7seg_but(nb_goal);
	lcd_but();
	if( nb_goal == 3){
		lcd_victoire();
		nb_goal = 0;
	}
	if(nb_goal == 0)
	{
		aff_7seg_but(nb_goal);
	}
	
}


