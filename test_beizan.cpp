#include<stdio.h>
#include<graphics.h>
#include<iostream>
#include<math.h>
using namespace std;
void beizan(int x[4],int y[4]){
	
	for(double u=0.0;u<1.0;u+=0.0005)
	{
		double ux=pow((1-u),3)*x[0]+3*pow((1-u),2)*u*x[1]+3*pow(u,2)*(1-u)*x[2]+pow(u,3)*x[3];
		double uy=pow((1-u),3)*y[0]+3*pow((1-u),2)*u*y[1]+3*pow(u,2)*(1-u)*y[2]+pow(u,3)*y[3];
		putpixel(ux,uy,WHITE);
	}
	for(int i=0;i<4;i++)
	{
		putpixel(x[i],y[i],YELLOW);
	}

getch();
closegraph();
return;
}
int main()
{
	int gd=DETECT,gm,errorcode;
	initgraph(&gd,&gm,(char*)"");
	
	errorcode=graphresult();
	
	if(errorcode != grOk)
	{
		printf("GRAPHICS NOT WORKING: %s\n", grapherrormsg(errorcode));
		printf("Press any key to halt");
		getch();
		exit(1);
	}
	int x[4],y[4];
	cout<<"Enter Control points\n";
	for (int i=0;i<4;i++)
	{
		cout<<"Enter x[]"<<i+1<<"] and y["<<i+1<<"]";
		cin>>x[i]>>y[i];
	}
	beizan(x,y);
	
}
