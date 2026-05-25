#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<dos.h>
 
void boundaryfill(int x,int y,int f_color,int b_color)
{
	if(getpixel(x,y)!=b_color && getpixel(x,y)!=f_color)
	{	delay(10);
		putpixel(x,y,f_color);
		boundaryfill(x+1,y,f_color,b_color);
		boundaryfill(x,y+1,f_color,b_color);
		boundaryfill(x-1,y,f_color,b_color);
		boundaryfill(x,y-1,f_color,b_color);
	}
}
//getpixel(x,y) gives the color of specified pixel 
 
void main()
{
	int gm,gd=DETECT,radius;
	int x,y;
	printf("Enter co-ordinates of center of circle: ");
	scanf("%d%d", &x, &y);
	printf("Enter the radius value:");
	scanf("%d",&radius);
	
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	circle(x,y,radius);
	delay(3000);
	boundaryfill(x,y,4,15);
	getch();
}