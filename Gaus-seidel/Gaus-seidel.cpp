#include <iostream>
#include <cmath>
#include<iomanip>

int main()
{
std::cout.ios_base::precision(4);
std::cout.setf(std::ios::fixed);

int n,count=0,flag=0;	
std::cout<<"Enter the number of eqns :";
std::cin>>n;
double aug[n][n+1];
double x[n],err,y;
std::cout<<"Enter the augmented matrix row wise : \n";
for(int i=0;i<n;i++){
	for(int j=0;j<=n;j++){
		std::cin>>aug[i][j];
	}
}
std::cout<<"Enter initial values :";

for (int i=0;i<n;i++)
        std::cin>>x[i];

std::cout<<"Enter the error limit :";
std::cin>>err;
for(int i=0;i<n;i++){
	for(int k=i+1;k<n;k++){
		if(fabs(aug[i][i])<fabs(aug[k][i])){
			for(int j=0;j<=n;j++){
				double temp=aug[i][j];
				aug[i][j]=aug[k][j];
				aug[k][j]=temp;
			}
			
		}
	}
}

std::cout<<"Iter"<<std::setw(10);
for(int i=0;i<n;i++){
	std::cout<<"X"<<i<<std::setw(18);
}
std::cout<<"\n----------------------------------------------------------------------";
do{
	std::cout<<"\n"<<count+1<<"."<<std::setw(16);
	for(int i=0;i<n;i++){
		y=x[i];
		x[i]=aug[i][n];
		for(int j=0;j<n;j++){
			if(j!=i){
				x[i]=x[i]-aug[i][j]*x[j];
			}
		}
		x[i]=x[i]/aug[i][i];
        if (fabs(x[i]-y)<=err){        
            flag++;
		}
        std::cout<<x[i]<<std::setw(18);
	}
	std::cout<<std::endl;
	count++;
}while(flag<n);

std::cout<<"\n The solution is as follows:\n";
    for (int i=0;i<n;i++)
        std::cout<<"x"<<i<<" = "<<x[i]<<std::endl;
	return 0;
}