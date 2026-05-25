#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <process.h>

int x1,x2,y1,y2,mx,my,depth;
void draw();
void scale();

void main()
{
	int gd = DETECT, gm,c;
	initgraph(&gd, &gm, "c:\\turboc3\\bgi");
	printf("\nProgram for 3D Scaling");
	printf("\n Enter the 1st top value of rectangle(x1,y1)");
	scanf("%d%d",&x1,&y1);
	printf("\n Enter the right value of rectangle(x2,y2)");
	scanf("%d%d",&x2,&y2);

	depth = (x2-x1)/4;
	mx = (x1+x2)/2;
	my = (y1+y2)/2;
	draw();
	getch();
	cleardevice();
	scale();
	getch();
}

	void draw()
	{
		bar3d(x1,y1,x2,y2,depth,1);

	}

	void scale()
	{
		int x, y;
		int  a1, a2, b1, b2, dep;
		printf("\nEnter the Scaling Factors Sx and Sy (Only Integer Values)");
		scanf("%d%d", &x,&y);
		a1= mx +(x1-mx) *x;
		a2= mx +(x2-mx) *x;
		b1= my +(y1-my) *y;
		b2= my +(y2-my) *y;
		dep = (a2-a1)/4;
		bar3d(a1,b1,a2,b2,dep,1);
		setcolor(5);
		draw();

	}
