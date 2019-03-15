#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define E .000001

double func(double x){
 return  ((pow(x,3)-x-1));// provide the equation
}
double bisection(double a,double b){
    return (a+b)/2;
}

int main(){
int i=0;
double a,b,xr;
printf("Enter the values of a and b : " );
scanf("%lf %lf",&a,&b );
/****************************************************
if (func(a)*func(b)>0) {
  perror("Error:THE root must be in interval");
  exit(1);
}****************************************************/
xr=bisection(a,b);
while((b-a)>=E){
i++;
if(func(xr)==0.0){
  break;
}
xr=bisection(a,b);
if (func(xr)*func(a)<0) {
  b=xr;
} else {
  a=xr;
}
}
printf("After %d interval : THE root is %lf\n",i,xr  );

}
