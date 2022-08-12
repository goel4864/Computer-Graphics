#include<iostream>
#include<graphics.h>
using namespace std;
int main()
{
	int gd=DETECT,gm,errorcode;
	initgraph(&gd,&gm,(char *)"");
	 errorcode=graphresult();
	 if(errorcode!=grOk)
	 {
	 	printf(" GRAPHICS ERROR %s\n",grapherrormsg(errorcode));
	 	printf("press any key to halt :");
	 	getch();
	 	exit(1);
	 }
	 float x1,x2,y1,y2,step,dx,dy,x,y,i=1;
	 cout<<"Enter x1 and y1 coordinates";
	 cin>>x1>>y1;
	 cout<<"Enter x2 and y2 coordinates";
	 cin>>x2>>y2;
	 dx=abs(x2-x1);
	 dy=abs(y2-y1);
	 if(dx>=dy)
	 	step=dx;
	 else
		step=dy;
	 dx=dx/step;
	 dy=dy/step;
	 x=x1;
	 y=y1;
	 while(i<=step)
	 {
	 	putpixel(x,y,RED);
	 	x=x+dx;
	 	y=y+dy;
	 	i++;
		}
		getch();	
		closegraph();
		return 0;
}

