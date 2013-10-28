#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "MatrixSVD.h"
#include <string>

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
	int i=0;
	double sum=0;
	for(i=0;i<n;i++)
		sum+=vector[i]*A[i];
}

Matrix * Vector::Trans()
{
	Matrix result(n,1);
	int i=0;
	for(i=0;i<n;i++)
		result.set(i,1,vector[i]);
	return &result;
}

void Vector::set(int i,double value)
{
	vector[i]=value;
}

double Vector::Max()
{
	int i=1;
	double temp=vector[0];
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

void Vector::fprint()
{
	ofstream outfile;
	outfile.open("outfile.txt",ios::app,0);
	int i=0;
	cout<<"(";
	for(i=0;i<n;i++)
		outfile<<vector[i]<<" ";
	cout<<")";
	outfile.close();
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
	mn=m*n;
	int i=0;
	for(;i<mn;i++)
		matrix[i]=0;
	for(i=0;i<m;i++)
		matrix[i*n+i]=1;
}

Matrix::Matrix(int Nnum,int Mnum)
{
	matrix=new double[Mnum*Nnum];
	m=Mnum;
	n=Nnum;
	mn=m*n;
	int i=0;
	for(;i<mn;i++)
		matrix[i]=0;
}

Matrix::Matrix(bool num)
{
	ifstream infile;
	if(num==true)
		infile.open("inputMatrix1.txt",ios::in,1);
	else if(num==false)
		infile.open("inputMatrix2.txt",ios::in,1);
	infile>>m;
	infile>>n;
	mn=m*n;
	int i=0,j=0;
	for(;i<m;i++)
		for(j=0;j<n;j++)
			infile>>matrix[i*n+j];
	cout<<"*********数据读取完毕*********"<<endl;
}

double Matrix::a(int i,int j)
{
	return matrix[i*n+j];
}

double & Matrix::operator[](int index)
{
	return matrix[index];
}

int Matrix::M()
{
	return m;
}

int Matrix::N()
{
	return n;
}

void Matrix::Add(Matrix A)
{
	if(n!=A.N())
	{
		cout<<"ERRO:列数不匹配"<<endl;
		cout<<"列数分别为：";
		cout<<n<<"和"<<A.N()<<endl;
		system("pause");
		exit(1);
	}
	else if(m!=A.M())
	{
		cout<<"ERRO:行数不匹配"<<endl;
		cout<<"行数分别为：";
		cout<<n<<"和"<<A.N()<<endl;
		system("pause");
		exit(1);
	}

	int i=0;
	for(;i<mn;i++)
		matrix[i]=matrix[i]+A[i];
}
void Matrix::Minus(Matrix A)
{
	if(n!=A.N())
	{
		cout<<"ERRO:列数不匹配"<<endl;
		cout<<"列数分别为：";
		cout<<n<<"和"<<A.N()<<endl;
		system("pause");
		exit(1);
	}
	else if(m!=A.M())
	{
		cout<<"ERRO:行数不匹配"<<endl;
		cout<<"行数分别为：";
		cout<<n<<"和"<<A.N()<<endl;
		system("pause");
		exit(1);
	}

	int i=0;
	for(;i<mn;i++)
		matrix[i]=matrix[i]-A[i];
}
void Matrix::NumProd(double a)
{
	int i=0;
	for(;i<mn;i++)
		matrix[i]=matrix[i]*a;
}

Matrix * Matrix::DotProd(Matrix A)
{
	if(n!=A.M())
	{
		cout<<"ERRO:列数不匹配"<<endl;
		cout<<"列数分别为：";
		cout<<n<<"和"<<A.N()<<endl;
		system("pause");
		exit(1);
	}

	Matrix result(m,A.N());
	int i=0,j=0,k=0;
	for (;i<m;i++)
			for (j=0;j<A.N();j++)
			{
				result[i*A.N()+j]=0;
				for (k=0;k<n;k++)
					result[i*A.N()+j]+=matrix[i*n+k]*A[k*A.N()+j];
			}
	return &result;
}

Matrix * Matrix::Trans()
{
	Matrix trans(n,m);
	int i=0;
	for(;i<mn;i++)
		trans[i]=matrix[i];
	return &trans;
}

void Matrix::set(int i,int j,double value)
{
	matrix[i*n+j]=value;
}

Vector * Matrix::Row(int k)
{
	Vector v(n);
	int i=0;
	for(;i<n;i++)
		v[i]=matrix[k*n+i];
	return &v;
}

Vector * Matrix::Col(int k)
{
	Vector v(m);
	int i=0;
	for(;i<m;i++)
		v[i]=matrix[i*n+k];
	return &v;
}

Vector * Matrix::HRow(int k)//此处默认m>n，可能需要修改
{
	Vector v(n-k-1);
	int i=0;
	for(;i<v.N();i++)
		v[i]=matrix[k*n+k+i+1];
	return &v;
}

Vector * Matrix::HCol(int k)//此处默认m>n，可能需要修改
{
	Vector v(n-k);
	int i=0;
	for(;i<v.N();i++)
		v[i]=matrix[k*n+i*n+k];
	return &v;
}

double Matrix::Max()
{
	int i=1;
	double temp=matrix[0];
	for(;i<mn;i++)
		if(temp<matrix[i])
			temp=matrix[i];
	return temp;
}

void Matrix::print()
{

	int i=0,j=0;
	for(;i<m;i++)
	{
		cout<<"| ";
		for(j=0;j<n;j++)
			cout<<matrix[i*n+j]<<"";
		cout<<"|"<<endl;
	}
}
	
void Matrix::fprint()
{
	ofstream outfile;
	outfile.open("outfile.txt",ios::app,0);
	int i=0,j=0;
	for(;i<m;i++)
	{
		outfile<<"| ";
		for(j=0;j<n;j++)
			outfile<<matrix[i*n+j]<<"";
		outfile<<"|"<<endl;
	}
	outfile.close();
}

Matrix::~Matrix()
{
	delete []matrix;
}