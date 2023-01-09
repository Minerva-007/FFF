#include"stdio.h"
#include"math.h"

class line{
private:
	double x1,y1;
	double x2,y2;
public:
	line(double xx1,double yy1,double xx2,double yy2)
	{
		x1=xx1;y1=yy1;
		x2=xx2;y2=yy2;
	}
	double retx1(){return x1;}
	double retx2(){return x2;}
	double rety1(){return y1;}
	double rety2(){return y2;}
	double findnormal()
	{
		return atan2(y2-y1,x2-x1)*180/3.141592;
	}
	double FFF(line);
};

class vector{
private:
	double x,y;
	double ox,oy;
	bool isVert;
public:
	vector(double xx,double yy,double oxx,double oyy)
	{
		x=xx;y=yy;
		ox=oxx;oy=oyy;
		isVert=(x==ox);
	}
	bool intersectdesuka(line l)
	{
		// Quick mafs along x axis
		// so l goes from x1 to x2
		double x1 = l.retx1();double x2 = l.retx2();
		double y1 = l.rety1();double y2 = l.rety2();
		double xi,yi;
		if(isVert)
		{
			//The system of equations are now
			// y = mx1 + c
			 double m1 = (y2-y1)/(x2-x1);
                         double c1 = -m1*x1 + y1;
                         xi=x;
                         yi=m1*xi + c1;
		}
		else
		{
			// equation of line is y=mx-mx1+y1
			// where m = (y2-y1)/(x2-21)
			double m1 = (y2-y1)/(x2-x1);
			double c1 = -m1*x1 + y1;
			double m2 = (y-oy)/(x-ox);
			double c2 = -m2*x + y;
			// y - mx = c is the equation
			// so [1 -m1;1 -m2] * [y x] = [c1 c2];
			// [y x] = [-m2 m1;-1 1] * [c1 c2];
			double det = -m2+m1;
			if(det==0)return false;
			yi = (-m2*c1+m1*c2)/det;
			xi = (-c1+c2)/det;
			//Debug
		}
		//printf("%f\t%f\n",xi,yi);
		// Intersection point is found.
		// Now xi = x1 + a(x1-x2)
		double ax = -(xi-x1)/(x1-x2);
		double ay = -(yi-y1)/(y1-y2);
		//printf("%f\t%f\n",ax,ay);
		// Check if ax or ay are above 1 or below 0
		if(ax<=0) return false;
		if(ax>=1) return false;
		if(ay<=0) return false;
		if(ay>=1) return false;
		return true;
	}
};

double line::FFF(line l2)
{
	 double mm = findnormal();
         int c=0,it=0;
         for(double a=0.0;a<1.0;a=a+0.02)
         {
                 for(signed int i=-89;i<89;i=i+1,it++)
                 {
                         double t = mm + (double)i/180*3.141592;
                         double xx=x1+a*(x2-x1);
                         double yy=y1+a*(y2-y1);
                         vector v( xx,yy,xx+cos(t),yy+sin(t) );
                         bool res=v.intersectdesuka(l2);
                         c = c+(res==true?1:0);
                 }
         }
         return (double)c/it;
}


int main()
{
	line l1(0.0,0.0,1.0,0.0);
	line l2(0.0,0.0,1.0,1.0);
	double F1=l1.FFF(l2), F2=l2.FFF(l1);
	printf("%f\t%f\t%f\n",F1,F2,F1/F2);
	return 0;
}
