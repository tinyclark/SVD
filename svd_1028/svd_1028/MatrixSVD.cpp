#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include "MatrixSVD.h"

using namespace std;

//Vector类***************************************************************

Vector::Vector(int num)
{
	vector=new double[num];
	n=num;
	int i=0;
	for(i=0;i<n;i++)
		vector[i]=0;
}

double & Vector::operator[](int index)
{
	return vector[index];
}

int Vector::N()
{
	return n;
}

void Vector::Add(Vector A)
{
	if(n!=A.N())
	{
		cout<<"ERRO:向量维数不同，不能相加"<<endl;
		cout<<"维数分别为"<<n<<"和"<<A.N()<<endl;
		cout<<"发生错误在 (";
		print();
		cout<<") + (";
		A.print();
		cout<<")";
		system("pause");
		exit(1);
	}
	int i=0;
	for(i=0;i<n;i++)
		vector[i]=vector[i]+A[i];
}
	

void Vector::Minus(Vector A)
{
	if(n!=A.N())
	{
		cout<<"ERRO:向量维数不同，不能相减"<<endl;
		cout<<"维数分别为"<<n<<"和"<<A.N()<<endl;
		cout<<"发生错误在 (";
		print();
		cout<<") + (";
		A.print();
		cout<<")";
		system("pause");
		exit(1);
	}
	int i=0;
	for(i=0;i<n;i++)
		vector[i]=vector[i]-A[i];
}

void Vector::NumProd(double a)
{
	int i=0;
	for(i=0;i<n;i++)
		vector[i]=vector[i]*a;
	}
	
double Vector::DotProd(Vector A)
{
	if(n!=A.N())
	{
		cout<<"ERRO:向量维数不同，不能相减"<<endl;
		cout<<"维数分别为"<<n<<"和"<<A.N()<<endl;
		cout<<"发生错误在 (";
		print();
		cout<<") + (";
		A.print();
		cout<<")";
		system("pause");
		exit(1);
	}
	int i=0,sum=0;
	for(i=0;i<n;i++)
		sum+=vector[i]*A[i];
}

Matrix Vector::Trans()
{
	Matrix result(n,1);
	int i=0;
	for(i=0;i<n;i++)
		result.set(i,1,vector[i]);

}

	double Max();//向量中最大的数

	void print();//在屏幕上打印向量
	void fprint();//在文件中打印向量

//Matrix类***************************************************************