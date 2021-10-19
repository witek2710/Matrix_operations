#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#include "Matrix.h"

#include <iostream>


void test1ADD()
{
	int errorCode = 0; 
	Matrix<int> mtx1(2, 3, errorCode);
	Matrix<int> mtx2(2, 3, errorCode);

	mtx1.fillRandom();
	mtx2.fillRandom();
	cout << "MACIERZ 1:" << endl;
	mtx1.print();
	cout << "MACIERZ 2:" << endl;
	mtx2.print();
	cout << "MACIERZ 1 + 2:" << endl; 
	mtx1.addMatrixes(mtx2, errorCode);
	mtx1.print();
	cout << "Macierz 1 + 2: operator+" << endl;
	Matrix<int> mtx12(0,0, errorCode);
	mtx12 = mtx1 + mtx2; 
	mtx12.print(); 
	
	Matrix<double> mtx3(2, 3, errorCode);
	Matrix<double> mtx4(2, 3, errorCode);
	Matrix<double> mtx34(0, 0, errorCode);

	mtx3.fillRandom();
	mtx4.fillRandom();
	cout << "MACIERZ 3:" << endl;
	mtx3.print();
	cout << "MACIERZ 4:" << endl;
	mtx4.print();
	cout << "MACIERZ 3 + 4:" << endl;
	mtx3.addMatrixes(mtx4, errorCode);
	mtx3.print();
	cout << "MACIERZ 3 +4 : OPERATOR+" << endl;
	mtx34 = mtx3 + mtx4; 
	mtx34.print(); 

	Matrix<float> mtx5(2, 3, errorCode);
	Matrix<float> mtx6(2, 3, errorCode);
	Matrix<float> mtx56(0, 0, errorCode);
	mtx5.fillRandom();
	mtx6.fillRandom();
	cout << "MACIERZ 5:" << endl;
	mtx5.print();
	cout << "MACIERZ 6:" << endl;
	mtx6.print();
	cout << "MACIERZ 5 + 6:" << endl;
	mtx5.addMatrixes(mtx6, errorCode);
	mtx5.print();
	cout << "MACIERZ 5 + 6 : OPERATOR+" << endl;
	mtx56 = mtx5 + mtx6;
	mtx56.print();

}

void test1SUB()
{
	int errorCode = 0; 
	Matrix<int> mtx1(2, 3, errorCode);
	Matrix<int> mtx2(2, 3, errorCode);

	mtx1.fillRandom();
	mtx2.fillRandom();
	cout << "MACIERZ 1:" << endl;
	mtx1.print();
	cout << "MACIERZ 2:" << endl;
	mtx2.print();
	cout << "MACIERZ 1 - 2:" << endl;
	mtx1.substractMatrixes(mtx2, errorCode);
	mtx1.print();
	cout << "Macierz 1 - 2: operator-" << endl;
	Matrix<int> mtx12(0, 0, errorCode);
	mtx12 = mtx1 - mtx2;
	mtx12.print();

	Matrix<double> mtx3(2, 3, errorCode);
	Matrix<double> mtx4(2, 3, errorCode);
	Matrix<double> mtx34(0, 0, errorCode);

	mtx3.fillRandom();
	mtx4.fillRandom();
	cout << "MACIERZ 3:" << endl;
	mtx3.print();
	cout << "MACIERZ 4:" << endl;
	mtx4.print();
	cout << "MACIERZ 3 - 4:" << endl;
	mtx3.substractMatrixes(mtx4, errorCode);
	mtx3.print();
	cout << "MACIERZ 3 - 4 : OPERATOR-" << endl;
	mtx34 = mtx3 - mtx4;
	mtx34.print();

	Matrix<float> mtx5(2, 3, errorCode);
	Matrix<float> mtx6(2, 3, errorCode);
	Matrix<float> mtx56(0, 0, errorCode);
	mtx5.fillRandom();
	mtx6.fillRandom();
	cout << "MACIERZ 5:" << endl;
	mtx5.print();
	cout << "MACIERZ 6:" << endl;
	mtx6.print();
	cout << "MACIERZ 5 - 6:" << endl;
	mtx5.substractMatrixes(mtx6, errorCode);
	mtx5.print();
	cout << "MACIERZ 5 - 6 : OPERATOR-" << endl;
	mtx56 = mtx5 - mtx6;
	mtx56.print();

}

void test1MUL()
{
	int errorCode = 0;
	Matrix<int> mtx1(4, 3, errorCode);
	Matrix<int> mtx2(3, 2, errorCode);
	Matrix<int> mtx1_2;
	mtx1.fillRandom();
	mtx2.fillRandom();
	cout << "MACIERZ 1:" << endl;
	mtx1.print();
	cout << "MACIERZ 2:" << endl;
	mtx2.print();
	cout << "MACIERZ 1 * 2:" << endl;
	mtx1_2 = mtx1.matrixesMultiplication(mtx2, errorCode);
	mtx1_2.print();
	cout << "Macierz 1 * 2: operator*" << endl;
	Matrix<int> mtx12;
	mtx12 = mtx1 * mtx2;
	cout << "KOD BLEDU: " << errorCode << endl;
	mtx12.print();

	Matrix<double> mtx3(4, 3, errorCode);
	Matrix<double> mtx4(3, 2, errorCode);
	Matrix<double> mtx34(0, 0, errorCode);
	Matrix<double> mtx3_4(0, 0, errorCode);
	mtx3.fillRandom();
	mtx4.fillRandom();
	cout << "MACIERZ 3:" << endl;
	mtx3.print();
	cout << "MACIERZ 4:" << endl;
	mtx4.print();
	cout << "MACIERZ 3 * 4:" << endl;
	mtx3_4 = mtx3.matrixesMultiplication(mtx4, errorCode);
	mtx3_4.print();
	cout << "MACIERZ 3 * 4 : OPERATOR*" << endl;
	mtx34 = mtx3 * mtx4;
	mtx34.print();

	Matrix<float> mtx5(4, 3, errorCode);
	Matrix<float> mtx6(3, 2, errorCode);
	Matrix<float> mtx56(0, 0, errorCode);
	Matrix<float> mtx5_6(0, 0, errorCode);
	mtx5.fillRandom();
	mtx6.fillRandom();
	cout << "MACIERZ 5:" << endl;
	mtx5.print();
	cout << "MACIERZ 6:" << endl;
	mtx6.print();
	cout << "MACIERZ 5 * 6:" << endl;
	mtx5_6 = mtx5.matrixesMultiplication(mtx6, errorCode);
	mtx5_6.print();
	cout << "MACIERZ 5 * 6 : OPERATOR*" << endl;
	mtx56 = mtx5 * mtx6;
	mtx56.print();

}

void test1MULSCALAR(){

	int errorCode = 0;
	Matrix<int> mtx1(3, 5, errorCode);
	Matrix<double> mtx2(3, 5, errorCode);
	Matrix<float> mtx3(4, 5, errorCode);

	mtx1.fillRandom();
	mtx2.fillRandom();
	mtx3.fillRandom();

	cout << "MACIERZ 1:" << endl;
	mtx1.print();
	cout << "MACIERZ 2:" << endl;
	mtx2.print();
	cout << "MACIERZ 3:" << endl;
	mtx3.print();
	cout << "MACIERZ 1: scalar 2" << endl;
	mtx1.multiplicateByScalar(2);
	mtx1.print();
	cout << "MACIERZ 2: scalar 3.2" << endl;
	mtx2.multiplicateByScalar(3.2);
	mtx2.print();
	cout << "MACIERZ 3: scalar 3.0004" << endl;
	mtx3.multiplicateByScalar(3.0004f);
	mtx3.print();

}

void testMUL_vectors() {
	int errorCode = 0; 
	Matrix<int> mtx1(5, 1, errorCode);
	Matrix<int> mtx2(1, 5, errorCode);
	Matrix<int> mtx3(0, 0, errorCode);
	mtx1.fillRandom();
	mtx2.fillRandom();
	cout << "WEKTOR 1: " << endl;
	mtx1.print();
	cout << "WEKTOR 2: " << endl;
	mtx2.print();
	cout << "WEKTOR 1 * 2: " << endl; 
	mtx3 = mtx1 * mtx2; 
	mtx3.print(); 
}

void testScalarVectorsMultiplication() {

	int errorCode = 0; 
	Matrix<int> mtx1(1, 5, errorCode);
	Matrix<int> mtx2(1, 5, errorCode);
	Matrix<float> mtx3(5, 1, errorCode);
	Matrix<float> mtx4(5, 1, errorCode);
	mtx1.fillRandom();
	mtx2.fillRandom();
	mtx3.fillRandom();
	mtx4.fillRandom();
	cout << "MACIERZ 1:" << endl;
	mtx1.print();
	cout << "MACIERZ 2:" << endl;
	mtx2.print();
	cout << "ILOCZYN SKALARNY 1 i 2: " << endl;
	int val = mtx1.scalarVectorsMultiplication(mtx2, errorCode);
	cout << val << endl; 
	cout << "MACIERZ 3: " << endl;
	mtx3.setValueAt(20.20005f,4,0, errorCode);
	mtx3.print();
	cout << "MACIERZ 4: " << endl;
	mtx4.setValueAt(50.70001f,4,0, errorCode);
	mtx4.print();
	cout << "ILOCZYN SKALARNY 3 i 4: " << endl; 
	float val1 = mtx3.scalarVectorsMultiplication(mtx4, errorCode);
	cout << val1 << endl; 
	mtx3 = mtx4;
	mtx3.print();
}

void testTranspose()
{
	int errorCode = 0; 
	Matrix<int> mtx1(3, 5, errorCode);
	cout << "MATRIX 1: " << endl;
	mtx1.fillRandom(); 
	mtx1.print(); 
	mtx1 = mtx1.transposeMatrix(); 
	cout << "MATRIX 1 transpose: " << endl; 
	mtx1.print(); 
	Matrix<double> mtx2(5, 3, errorCode);
	mtx2.fillRandom(); 
	cout << "MATTRIX 2: " << endl; 
	mtx2.print();
	cout << "MATRIX 2 transpose: " << endl;
	mtx2 = mtx2.operator~();
	mtx2.print(); 
}
void testIdentityMatrix()
{
	int errorCode = 0; 
	Matrix<float> mtx1(4, 4, errorCode);
	mtx1.fillRandom(); 
	cout << "MACIERZ 1:" << endl;
	mtx1.print(); 
	mtx1.makeIdentityMatrix(errorCode);
	cout << errorCode << endl; 
	cout << "MACIERZ 1 zamieniona na jednostkowa: " << endl; 
	mtx1.print(); 
}

void testMakeVectorsFromMatrix()
{
	int errorCode = 0;
	Matrix<int> mtx1(4, 5, errorCode);
	cout << "MATRIX 1: " << endl; 
	mtx1.fillRandom(); 
	mtx1.print(); 
	Matrix<int> vct(0, 0, errorCode);
	vct = mtx1.makeVct(4, true, errorCode);
	cout << "WEKTOR STWORZONY Z 5 KOLUMNY MACIERZY 1: " << endl;
	vct.print(); 
	Matrix<int> vct1(0, 0, errorCode);
	cout << "WEKTOR STWORZONY Z 4 WIERSZA MACIERZY 1: " << endl;
	vct1 = mtx1.makeVct(3, false, errorCode);
	vct1.print();

}

void testSetSize() {

	int errorCode = 0; 
	Matrix<int> mtx1(4, 5, errorCode);
	cout << "MATRIX 1: " << endl; 
	mtx1.fillRandom();
	mtx1.print();
	mtx1.setNewSize(2, 3, errorCode);
	cout << "MATRIX 1 po zmianie rozmiaru na mniejszy: " << endl; 
	mtx1.print(); 
	Matrix<double> mtx2(5, 8, errorCode);
	cout << "MATRIX 2: " << endl; 
	mtx2.fillRandom();
	mtx2.print();
	cout << "MATRIX 2 po zmianie rozmiaru na wiekszy" << endl; 
	mtx2.setNewSize(6, 9, errorCode);
	mtx2.print(); 
	mtx2.setNewSize(-5, -5, errorCode);
}

void testSetGetElement()
{
	int errorCode = 0;
	Matrix<double> mtx1(3, 4, errorCode);
	mtx1.fillRandom();
	cout << "MATRIX 1: " << endl; 
	mtx1.print();
	cout << "MATRIX 1 po zamianie elementu: " << endl;
	mtx1.setValueAt(20.558, 2, 3,errorCode);
	mtx1.print(); 
	cout << "ELEMENT POBRANY Z MACIERZYL " << endl; 
	double *val = new double(); 
	mtx1.getValueAt(val, 2, 3, errorCode);
	cout << *val << endl; 
	cout << "DOSTEP DO ELEMENTU" << endl; 
	cout << mtx1[2][3] << endl;
	delete val; 
}

void testReadMatrixFromFile()
{
	int errorCode = 0; 
	cout << "WCZYTYANA MACIERZ INT" << endl; 
	Matrix<int> matrix1;
	string fileName = "int.txt"; 
	string fileName3 = "doublefloat.txt"; 
	matrix1.readMatrixFromFile(fileName, errorCode);
	matrix1.print(); 
	cout << "WCZYTANA MACIERZ DOUBLE" << endl; 
	Matrix<double> matrix2;
	string fileName1 = "float_double.txt"; 
	matrix2.readMatrixFromFile(fileName1, errorCode);
	matrix2.print();
	cout << "WCZYTANA MACIERZ FLOAT" << endl; 
	Matrix<float> matrix3; 
	matrix3.readMatrixFromFile(fileName3, errorCode);
	matrix3.print(); 
	//float liczba = matrix3[2][5];
	//cout << liczba << endl; 
	cout << "ZAPIS DO PLIKU" << endl; 
	Matrix<double> matrix4; 
	matrix4.setNewSize(5, 5, errorCode);
	matrix4.fillRandom();
	string fileName2 = "macierz.txt"; 
	matrix4.setValueAt(20.456, 4, 4, errorCode); 
	matrix4.print(); 
	cout << "ODCZYT Z PLIKU" << endl; 
	matrix3.readMatrixFromFile(fileName2, errorCode);
	matrix3.print(); 

}

int main()
{
	cout << "DODAWANIE MACIERZY: " << endl; 
	test1ADD(); 
	cout << "ODEJMOWANIE MACIERZY: " << endl;
	test1SUB(); 
	cout << "MNOZENIE MACIERZY: " << endl; 
	test1MUL(); 
	cout << "MNOZENIE MACIERZY PRZEZ LICZBE" << endl; 
	test1MULSCALAR(); 
	cout << "MNOZENIE DWOCH WEKTOROW" << endl;
	testMUL_vectors(); 
	cout << "ILOCZYN SKALARNY" << endl; 
	testScalarVectorsMultiplication();
	cout << "TRANSPONOWANIE MACIERZY" << endl; 
	testTranspose();
	cout << "PRZYPISYWANIE MACIERZY KWADRATOWEJ WARTOSCI MACIERZY JEDNOSTKOWEJ:" << endl; 
	testIdentityMatrix(); 
	cout << "TWORZENIE WEKTORÓW Z MACIERZY" << endl; 
	testMakeVectorsFromMatrix(); 
	cout << "USTAWIANIE NOWEGO ROZMIARU MACIERZY" << endl; 
	testSetSize(); 
	cout << "POBIERANIE USTAWIANIE ELEMNTU MACIERZY" << endl; 
	testSetGetElement(); 
	cout << "ODCZYT MACIERZY Z PLIKU" << endl; 
	testReadMatrixFromFile(); 
	_CrtDumpMemoryLeaks();
	
}
