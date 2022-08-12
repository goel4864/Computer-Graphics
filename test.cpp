#include <graphics.h>   
#include <iostream>  
using namespace std;
void midPointCircleDraw(int a, int b, int r) 
{  
    int x=0,y=r,p;  
    putpixel (a, b+r, RED);  
    //if radius is zero only a single point is printed
    if(r>0)
    {
    putpixel (a, b-r, RED);  
    putpixel (a-r, b, RED);  
    putpixel (a+r, b, RED);  
	}
    p=1-r;
	while (x<=y)  
    {  
        if (p<=0)
		{
        	p+=(2*x)+1; 	
		}   
        else  
        {  
            p+=(2*(x-y))+1;  
            y--;  
        }  
        x++;  
        putpixel (a+x, b+y, RED);  
        putpixel (a-x, b+y, RED);  
        putpixel (a+x, b-y, RED);  
        putpixel (a-x, b-y, RED);  
        putpixel (a+y, b+x, RED);  
        putpixel (a-y, b+x, RED);  
        putpixel (a+y, b-x, RED);  
        putpixel (a-y, b-x, RED);  
    }  
}  
int main()  
{   
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
   int x_center,y_center,radius;
    cout<< "Enter Coordinates of Center(x, y) :";  
    cin>>x_center>>y_center;  
    cout<<"Enter radius of the circle : ";  
    cin>>radius;
	//if radius is negative
	if(radius<0)
	{
		cout<<"Radius cannot be negative";
		exit(1);
	} 
    midPointCircleDraw(x_center,y_center,radius);
    getch();
}  
