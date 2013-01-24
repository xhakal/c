//JUEGO DEL AHORCADO
#include <conio.h>
#include <stdio.h>
#include <string.h>

char cadena1[26];/*Guarda la palabra o frase*/
char cadena2[26];/*Guarda blancos o guiones*/
char cadena3[2];/*Guarda la letra introducida*/
char cadena4[36];/*Guarda todas las letras introducidas*/
int i;
char *punt;//puntero
int horca=1;//numero de fallos
int cont;//contador
int longitud;
int sw;//switch
void main()
{
   //Introducir cadena1
   textbackground(3);
   textcolor(1);
   clrscr();
   printf("Introduce una frase o palabra de 25 caracteres:");
   gets(cadena1);
   longitud=strlen(cadena1);
   clrscr();
   //Rellenar cadena2 de guiones o blancos
   for(i=0,punt=&cadena1[0];*punt!=NULL;punt++,i++)
   {
      if(*punt==' ')
      {
   cadena2[i]=' ';
	 cont++;
      }
      else
      {
	 cadena2[i]='-';
      }
   }
   gotoxy(10,10);
   printf("%s",cadena2);
   //Bucle del juego
   while(horca<11)
   {
      gotoxy(1,1);
      printf("Introduce una letra:");
      gets(cadena3);
      strcat(cadena4,cadena3);
      gotoxy(3,22);
      printf("Las Letras Elegidas son: %s",cadena4);
      sw=0;
      for(i=0,punt=&cadena1[0];*punt!=NULL;punt++,i++)
      {
	 if(*punt==cadena3[0])  /*Acierto*/
	 {
	    cont++;
	    cadena2[i]=cadena3[0];
	    sw=1;
	 }
      }
      gotoxy(10,10);
      printf("%s",cadena2);
      //Fallo
      if (sw==0)
      {
	 if (horca==1) /*Pintar horca*/
	 {
	    gotoxy(69,16);
	    printf("º");
	    gotoxy(69,15);
	    printf("º");
	    gotoxy(69,14);
	    printf("º");
	    gotoxy(69,13);
	    printf("º");
	    gotoxy(69,12);
	    printf("º");
	    gotoxy(69,17);
	    printf("Ê");
	    gotoxy(70,17);
	    printf("ÍÍ");
	    gotoxy(67,17);
	    printf("ÍÍ");
	 }
	 if (horca==2) //pintar horca
	 {
	    gotoxy(69,11);
	    printf("É");
	    gotoxy(70,11);
	    printf("ÍÍ");
	 }
	 if (horca==3) //pintar horca
	 {
	    gotoxy(72,11);
	    printf("»");
	    gotoxy(72,12);
	    printf("|");
	 }
	 if (horca==4) //pintar cabeza
	 {
	    gotoxy(72,13);
	    printf("");
	 }
	 if (horca==5) //pintar tronco
	 {
	    gotoxy(72,14);
	    printf("|");
	 }
	 if (horca==6) //pintar pierna
	 {
	    gotoxy(73,15);
	    printf("\\");
	 }
	 if (horca==7) //pintar pierna
	 {
	    gotoxy(71,15);
	    printf("/");
	 }
	 if (horca==8) //pintar brazo
	 {
	    gotoxy(73,14);
	    printf("-");
	 }
	 if (horca==9) //pintar brazo
	 {
	    gotoxy(71,14);
	    printf("-");
	 }
	 if (horca==10)
	 {
	    clrscr();
	    gotoxy(30,20);
	    printf("­­YOU LOSE, GAME OVER!!");
	 }
	 horca++;
      }
      if (longitud==cont)
      {
	 clrscr();
	 gotoxy(30,20);
	 printf("­­YOU WINNER!!");
	 horca=11;
	 getch();
      }
   }
   getch();
}
