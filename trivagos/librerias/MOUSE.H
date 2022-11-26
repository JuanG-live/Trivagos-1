/*

My Mouse Handling functions...

	Saravanan|Sugan

*/
#include<conio.h>
#include<dos.h>


union REGS i,o;

int initmouse()
{
i.x.ax=0;
int86(0x33,&i,&o);
return(o.x.ax);
}

void showmouse()
{
i.x.ax=1;
int86(0x33,&i,&o);
}

void hidemouse()
{
i.x.ax=2;
int86(0x33,&i,&o);
}

void getmousepos(int *butt,int *x,int *y)
{
i.x.ax=3;
int86(0x33,&i,&o);
*butt=o.x.bx;
*x=o.x.cx;
*y=o.x.dx;
}