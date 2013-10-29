// svd_1028.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "MatrixSVD.h"
#include "Givens.h"
#include "HouseHold.h"

using namespace std;

void BiDiag(Matrix A,Vector B1,Vector B2,Matrix U, Matrix V,int m,int n);//二对角化

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

void BiDiag(Matrix A,Vector B1,Vector B2,Matrix U, Matrix V,int m,int n)
{
	Matrix P(m,m),H(n,n),tH(n,n);
	int num=0;
	for(num=0;num<n-2;num++)
	{
		Vector tempU(m-num);
		tempU.HCol(A,num);
		tempU.print();
		Matrix temp1(m-num,m-num);
		HouseHold T1(temp1);
		T1.HouseHolder(tempU,m-num);
		B1[num]=T1.delta;
		Matrix tP(m);
		for(int i=0;i<m-num;i++)
			for(int j=0;j<m-num;j++)
				tP.set(num,num,T1.T.matrix[i][j]);
		P.MatrixMultiply(U,tP);
		tP=U;
		U=P;
		P=tP;


		Vector tempV(n-num-1);
		tempV.VectorRowSpecial(A,num);
		tempV.Print();
		Matrix temp2(n-1-num,n-num-1);
		HouseHold T2(temp2);
		T2.HouseHolder(tempV,n-num-1);
		B2.vector[num+1]=T2.delta;
		Matrix tH(n,n);
		Unit(tH,n);
		for(int i=0;i<n-num-1;i++)
			for(int j=0;j<n-num-1;j++)
				tH.matrix[num][num]=T2.T.matrix[i][j];
		H.MatrixMultiply(V,tH);
		tH=V;
		V=H;
		H=tH;
	}

	Vector tempU1(m-n+2),tempU2(m-n+2);
	int num2=num;
	for(;num2<m;num2++)
	{
		tempU1.vector[num2-num]=A.matrix[num2][n-2];
		tempU2.vector[num2-num]=A.matrix[num2][n-1];
	}
	tempU1.Print();
	tempU2.Print();

}