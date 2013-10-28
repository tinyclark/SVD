#ifndef MATRIXSVD_H
#define MATRIXSVD_H

//该头文件包括在SVD中可能会用到的矩阵和向量类以及函数

class Vector
{
private:
	double *vector;
	int n;
public:
	Vector(int num); //构造n维向量

	double &operator[](int index);//返回向量中第index维的值
	int N();//返回向量维数

	void Add(Vector A);//加
	void Minus(Vector A);//减
	void NumProd(double a);//数乘
	double DotProd(Vector A);//点乘
	Matrix * Trans();//转置

	void set(int i,double value);//修改值

	double Max();//向量中最大的数

	void print();//在屏幕上打印向量
	void fprint();//在文件中打印向量

	~Vector();//析构函数
};

class Matrix
{
private:
	double *matrix;//一维数组指针，线性存放数组元素
	int m,n,mn;//m是行数，n是列数

public:
	Matrix(int Nnum);//构造函数，n*n的单位矩阵
	Matrix(int Mnum,int Nnum);//构造函数， Mnum*Nnum的矩阵
	Matrix(bool num);//从文件中读取构造矩阵

	double a(int i,int j);//返回a_{ij}的值
	double &operator[](int index);//返回matrix[index]
	int M();//返回矩阵行数
	int N();//返回矩阵列数

	void Add(Matrix A);//加
	void Minus(Matrix A);//减
	void NumProd(double a);//数乘
	Matrix * DotProd(Matrix A);//乘
	Matrix * Trans();//转置

	void set(int i,int j,double value);//修改值

	Vector * Row(int k);//取矩阵第k行行向量
	Vector * Col(int k);//取矩阵第k列列向量

	Vector * HRow(int k);//Household中取行向量的方法
	Vector * HCol(int k);//Household中取列向量的方法

	double Max();//矩阵中最大的数

	void print();//在屏幕上打印矩阵
	void fprint();//在文件中打印矩阵

	~Matrix();//析构函数

};





#endif