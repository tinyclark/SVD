#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
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
		cout<<"发生错误在";
		print();
		cout<<" + ";
		A.print();
		cout<<endl;
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
		cout<<"发生错误在";
		print();
		cout<<" - ";
		A.print();
		cout<<endl;
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
		cout<<"ERRO:向量维数不同，不能相乘"<<endl;
		cout<<"维数分别为"<<n<<"和"<<A.N()<<endl;
		cout<<"发生错误在";
		print();
		cout<<" ` ";
		A.print();
		cout<<endl;
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
	return result;
}

double Vector::Max()
{
	int i=1,double temp=vector[0];
	for(;i<n;i++)
		if(temp<vector[i])
			temp=vector[i];
	return temp;
}

void Vector::print()
{
	int i=0;
	cout<<"(";
	for(i=0;i<n;i++)
		cout<<vector[i]<<" ";
	cout<<")";
}

void Vector::fprint(fstream outfile)
{
	int i=0;
	cout<<"(";
	for(i=0;i<n;i++)
		outfile<<vector[i]<<" ";
	cout<<")";
}

Vector::~Vector()
{
	delete vector;
}
//Matrix类***************************************************************

Matrix::Matrix(int Nnum)
{
	matrix=new double[Nnum*Nnum];
	n=Nnum;
	m=Nnum;
	int i=0,j=0;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			matrix[i*n+j]=0;
	for(i=0;i<m;i++)
		matrix[i*n+i]=1;
}

Matrix::Matrix(int Nnum,int Mnum)
{
	matrix=new double[Mnum*Nnum];
}