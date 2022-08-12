#include<iostream>
#include<graphics.h>
// 100 ,100  200,400
// 100,400  200,100
// 50,300  400,200
// 50,200  400,300
// 100,100 350,100
// 100,100  100,450
using namespace std;
void bresenham(int x0,int y0,int x1,int y1)
{
	int dx,dy,p;
	dx=(x1-x0);
	dy=(y1-y0);
	p=2*dy-dx;
	
	int x = x0;
	int y = y0;
	
	if(dx>=0 & dy>=0) //positive slope
	{
		if(dy>dx) //positive steep slope
		{
			if(dx==0)
			{
				while(y0<=y1)
				{
					putpixel(x,y,WHITE);
					y++;
					if(p<0){
						p=p+2*dy;
					}
					else{
							p=p+2*dy-2*dx;
						
					}
				}
			}
			else
			{
				while(x0<=x1)
				{
					putpixel(x,y,WHITE);
					x++;
					if(p<0){
						p=p+2*dy;
					}
					else{
							p=p+2*dy-2*dx;
							y++;
						
					}
					
				}
			}
		}
		else if(dx>dy) //positive gradual slope
		{
			while(x0<=x1)
			{
				putpixel(x,y,WHITE);
				x++;
					if(p<0){
						p=p+2*dy;
					}
					else{
							p=p+2*dy-2*dx;
							y++;
						}
				
			}
		}
	}
	else if(dy<0 || dx<0) //negative steep and gradual slope
	{
		swap(x0,x1);
		swap(y0,y1);
		while(x0>x1)
		{
			putpixel(x,y,WHITE);
				x--;
					if(p<0){
						p=p-2*dy;
					}
					else{
							p=p-2*dy-2*dx;
							y++;
						}
				
		}
	}
}
int main()
{ 
	int x1,x2,y1,y2;
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
	cout<<"Enter the x1,y1 coordinates: ";
	cin>>x1>>y1;
	cout<<"Enter the x2,y2 coordinates: ";
	cin>>x2>>y2;
	bresenham(x1,y1,x2,y2);
	getch(); 
	closegraph();
	return 0;	
}
