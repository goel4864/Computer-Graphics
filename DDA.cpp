#include<graphics.h>
#include<iostream>
// 100 ,100  200,400
// 100,400  200,100
// 50,300  400,200
// 50,200  400,300
// 100,100 350,100
// 100,100  100,450
using namespace std; 
int main()
{
	float x,i,y,x1,y1,x2,y2,dx,dy,step;
	//request auto detection  
	int gd=DETECT,gm,errorcode;
	//initialize graphics and local variables
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	//read result of initialization
	errorcode = graphresult();
   //an error occurred 
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
	}  
	   
	cout<<"Enter the value of x1 and y1 : ";
	cin>>x1>>y1;
	cout<<"Enter the value of x2 and y2: ";
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
	i=1;
	while(i<=step)
	{
	putpixel(x,y,RED);
	x=x+dx;
	y=y+dy;
	i=i+1;
	}
	getch();
	closegraph();
	return 0;
}
