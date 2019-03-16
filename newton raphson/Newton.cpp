
#include<iostream>
#include<cmath>
#define E .00000001

int main(){
double(*f)(double)=[](double x){return (pow(x,3)-2*x-5);};//  add your own f(x)
double(*df)(double)=[](double x){ return (3*pow(x,2)-2);};//  f'(x)
void (*print)(double,double(*)(double))=[](double x,auto func){std::cout<<"Value :"<<func(x)<<std::endl;};
double x0,h;
std::cout.precision(10);
std::cout << "Enter the value for starting approximation :" << '\n';
std::cin>>x0;//first guess any number
std::cout << "first guess f(x) :" ;
print(x0,f);
std::cout << "first guess f'(x) :" ;
print(x0,df);

h=f(x0)/df(x0);
int itr=0;
while(fabs(h)>=E){
  h=f(x0)/df(x0);
  x0=x0-h;
  std::cout <<"Itr :"<<itr++ <<" Root :"<<x0<<"   f(x): "<<f(x0) <<"    df(x): "<<df(x0)<< '\n';
}
std::cout << "Root " <<x0<< '\n';

}
