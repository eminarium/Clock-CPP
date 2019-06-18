/*********************************************
	Author : Merdan Durdiyev
**********************************************/
#include<stdio.h>
#include<math.h>
#include<graphics.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
/*---------------------------------------------------------------------------*/
#define N 360
#define X_center 639/2
#define Y_center 479/2
#define pi 3.14
/*---------------------------------------------------------------------------*/
int temp1=0;
int temp2=0;
int temp3=0;

/*----------------------current time-----------------------------------------*/
struct  time t;
/*---------------------------------------------------------------------------*/

main(void)
{
 /*--------------------------*/
  int X_Y_coord_s(double angle, int r, int index);
  void check_gra_s(void);
  void draw_Ones_Share(void);
  void Show_time(void);
 /*--------------------------*/
  check_gra_s();
  setcolor(2);
  draw_Ones_Share();
  while (!kbhit()) Show_time();
  closegraph ();
}
/*---------------------------------------------------------------------------*/
void check_gra_s(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;

   /* initialize graphics mode */
   initgraph(&gdriver, &gmode, "c:\\progra~1\\bc311\\bgi");

   /* read result of initialization */
   errorcode = graphresult();

   if (errorcode != grOk)  /* an error occurred */
   {
	  printf("Graphics error: %s\n", grapherrormsg(errorcode));
	  printf("Press any key to halt:");
	  getch();
	  exit(1);             /* return with error code */
   }
}
/*---------------------------------------------------------------------------*/
void Show_time(void)
{
  /*------------------------------------------------*/
  int X_Y_coord_s(double angle, int r, int index);
  /*------------------------------------------------*/
  gettime(&t);
  setcolor(7);
  line(X_center,Y_center,X_Y_coord_s(-(t.ti_hour-12)*30-t.ti_min*0.5,120,1),X_Y_coord_s(-(t.ti_hour-12)*30-t.ti_min*0.5,120,0));
  setcolor(7);
  line(X_center,Y_center,X_Y_coord_s(-t.ti_min*6,160,1),X_Y_coord_s(-t.ti_min*6,160,0));
  setcolor(4);
  line(X_center,Y_center,X_Y_coord_s(-t.ti_sec*6,180,1),X_Y_coord_s(-t.ti_sec*6,180,0));
  setcolor(0);

 if(temp2 != t.ti_min)
 {
   line(X_center,Y_center,X_Y_coord_s(-temp2*6,160,1),X_Y_coord_s(-temp2*6,160,0));
   line(X_center,Y_center,X_Y_coord_s(-(temp1-12)*30-temp2*0.5,120,1),X_Y_coord_s(-(temp1-12)*30-temp2*0.5,120,0));
   temp2=t.ti_min;
   temp1=t.ti_hour;
 }
  if(temp3 != t.ti_sec)
	line(X_center,Y_center,X_Y_coord_s(-temp3*6,180,1),X_Y_coord_s(-temp3*6,180,0));
  temp3=t.ti_sec;
  delay(100);

}
/*---------------------------------------------------------------------------*/
void draw_Ones_Share(void)
{
  /*-----------------------------------------------*/
  int X_Y_coord_s(double angle, int r, int index);
  void Clock_numbers(void);
  /*-----------------------------------------------*/
  int temp=5;
  setcolor(1);
  for(double counter = 0; counter < N; counter+=6)
  {
	 if( temp != 5)
	 {
	   setcolor(7);
	   line(X_Y_coord_s(counter,200,1),X_Y_coord_s(counter,200,0),X_Y_coord_s(counter,205,1),X_Y_coord_s(counter,205,0));
	   temp++;
	 }
	 else
	 {
	   setcolor(4);
	   line(X_Y_coord_s(counter,200,1),X_Y_coord_s(counter,200,0),X_Y_coord_s(counter,210,1),X_Y_coord_s(counter,210,0));
	   temp=1;
	 }
  }
  Clock_numbers();
  outtextxy(410,450,"Copyright by hope, mat, shah");
}
/*---------------------------------------------------------------------------*/
void Clock_numbers(void)
{
  /*-----------------------------------------------*/
  int X_Y_coord_s(double angle, int r, int index);
  /*-----------------------------------------------*/
  outtextxy(X_Y_coord_s(330,190,1),X_Y_coord_s(330,190,0),"1");
  outtextxy(X_Y_coord_s(300,190,1),X_Y_coord_s(300,190,0),"2");
  outtextxy(X_Y_coord_s(270,190,1),X_Y_coord_s(270,190,0),"3");
  outtextxy(X_Y_coord_s(240,190,1),X_Y_coord_s(240,190,0),"4");
  outtextxy(X_Y_coord_s(210,190,1),X_Y_coord_s(210,190,0),"5");
  outtextxy(X_Y_coord_s(180,190,1),X_Y_coord_s(180,190,0),"6");
  outtextxy(X_Y_coord_s(150,190,1),X_Y_coord_s(150,190,0),"7");
  outtextxy(X_Y_coord_s(120,190,1),X_Y_coord_s(120,190,0),"8");
  outtextxy(X_Y_coord_s(90,190,1),X_Y_coord_s(90,190,0),"9");
  outtextxy(X_Y_coord_s(60,190,1),X_Y_coord_s(60,190,0),"10");
  outtextxy(X_Y_coord_s(30,190,1),X_Y_coord_s(30,190,0),"11");
  outtextxy(X_Y_coord_s(0,190,1),X_Y_coord_s(0,190,0),"12");
}
/*---------------------------------------------------------------------------*/
int X_Y_coord_s(double angle, int r, int index)
{
  return ( index == 1 )  ?  int(r*cos(double(-angle-90)*pi/180) + X_center)  : int(r*sin(double(-angle-90)*pi/180) + Y_center);
}
