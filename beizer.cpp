#include<iostream>
#include<stdio.h>
#include<graphics.h>
#include<math.h>
using namespace std;

int main(){
    int x[4],y[4],i;
    double puty,putx,t;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\TURBO3\\BGI");
    for ( i = 0; i < 4; i++)
    {
        cout<<"Enter X and Y coordinated of point ";
		cout<<i+1<<": ";
        cin>>x[i]>>y[i];
        putpixel(x[i],y[i],3);
        
    }
    for(t=0.0;t<=1.0;t=t+0.001){
        putx=pow(1-t,3)*x[0]+ 3*t*pow(1-t,2)*x[1]+ 3*t*t*pow(1-t,1)*x[2]+ pow(t,3)*x[3];
        puty=pow(1-t,3)*y[0]+ 3*t*pow(1-t,2)*y[1]+ 3*t*t*pow(1-t,1)*y[2]+ pow(t,3)*y[3];
        putpixel(putx,puty,WHITE);
    }
    getch();
    closegraph();
}

