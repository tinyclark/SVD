//该代码用于测试类

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "MatrixSVD.h"
#include <cstring>

using namespace std;

int main()
{

	Matrix A(true);
	Matrix B(false);

	A.print();
	B.print();

	A.Add(B);
	A.print();

	A.NumProd(2);
	A.print();

	Matrix *C;
	C=A.Trans();
	C->print();

	Matrix *D;
	D=A.DotProd(*C);
	D->print();

	system("pause");
	return 0;


}