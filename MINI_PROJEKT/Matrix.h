#pragma once
#include "ERROR_CODES.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "StringHelp.h"

#define DEFAULT_SIZE_ROWS 1;
#define DEFAULT_SIZE_COLUMNS 1;

using namespace std; 
template <typename T>
class Matrix {

public: 

	Matrix(); 
	Matrix(int rows, int columns, int &errorCode);
	Matrix(int rows, int columns, T**mtx);
	Matrix(const Matrix<T> &other);
	Matrix(Matrix<T> &&other); 
	void operator=(const Matrix<T> &other);
	void operator=(Matrix<T> &&other); 
	~Matrix();

	bool addMatrixes(const Matrix<T> &other, int &errorCode);
	bool substractMatrixes(const Matrix<T> &other, int &errorCode);
	Matrix<T> matrixesMultiplication(const Matrix<T> &other, int &errorCode);
	void multiplicateByScalar(const T number); 
	Matrix<T> transposeMatrix();
	T scalarVectorsMultiplication(const Matrix<T> &other, int &errorCode);
	bool makeIdentityMatrix(int &errorCode);
	Matrix<T> makeVct(int row_column_number, bool column_or_row, int &errorCode);

	Matrix<T> operator+(const Matrix<T> &other);
	Matrix<T> operator-(const Matrix<T> &other);
	Matrix<T> operator*(const T number);
	Matrix<T> operator*(const Matrix<T> &other);
	Matrix<T> operator~();
	T* operator[](int rowsIndex);

	bool setNewSize(int newSizeRows, int newSizeColumns, int &errorCode);
	bool getValueAt(T *val, int rowsIndex, int columnIndex, int &errorCode);
	bool setValueAt(T val, int rowsIndex, int columnIndex, int &errorCode);
	bool readMatrixFromFile(string fileName, int &errorCode); 

	void print(); 
	void fillRandom();


private: 

	T **matrix;
	int rowsNumber;
	int columnNumber;
	void createMatrix(); 
	void copy(const Matrix<T> &other); 
	void dealocMatrix(); 
	void helpAddMtx(const Matrix<T> &other);
	void helpSubMtx(const Matrix<T> &other);
	void convertFromVectorMatrixToArrayMatrix(vector<vector<T>> &vectorMatrix, int rowsSize, int columnsSize, int &errorCode); 
	int checkTotalElementsOfVectorMatrix(vector<vector<T>> &vectorMatrix); 
	void mover(Matrix<T> &other); 
};

template<typename T>
Matrix<T>::Matrix()
{
	rowsNumber = DEFAULT_SIZE_ROWS;
	columnNumber = DEFAULT_SIZE_COLUMNS;
	createMatrix(); 
}

template<typename T>
Matrix<T>::Matrix(int rows, int columns, int &errorCode)
{
	if (rows <= 0) { 
		errorCode = NEGATIVE_OFFSET;
		rowsNumber = DEFAULT_SIZE_ROWS;
	}
	else rowsNumber = rows;
	if (columns <= 0) {
		errorCode = NEGATIVE_OFFSET;
		columnNumber = DEFAULT_SIZE_COLUMNS;
	}
	else columnNumber = columns;
	createMatrix(); 
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& other)
{
	copy(other); 
}

template<typename T>
Matrix<T>::Matrix(Matrix<T>&& other)
{
	mover(other); 
}

template<typename T>
Matrix<T>::~Matrix()
{
	dealocMatrix(); 
}

template<typename T>
void Matrix<T>::operator=(const Matrix<T>& other)
{
	dealocMatrix(); 
	copy(other); 
}

template<typename T>
void Matrix<T>::operator=(Matrix<T>&& other)
{
	dealocMatrix(); 
	mover(other); 
}

template<typename T>
bool Matrix<T>::addMatrixes(const Matrix<T>& other, int &errorCode)
{
	if (rowsNumber == other.rowsNumber && columnNumber == other.columnNumber) {
		helpAddMtx(other); 
		return true;
	}
	else {
		errorCode = MATRIXES_NOT_THE_SAME_LENGTH;
		return false;
	}
}

template<typename T>
bool Matrix<T>::substractMatrixes(const Matrix<T>& other, int &errorCode)
{
	if (rowsNumber == other.rowsNumber && columnNumber == other.columnNumber)
	{
		helpSubMtx(other); 
		return true;
	}
	else {
		errorCode = MATRIXES_NOT_THE_SAME_LENGTH; 
		return false; 
	}
}

template<typename T>
Matrix<T> Matrix<T>::matrixesMultiplication(const Matrix<T>& other, int &errorCode)
{
	if (columnNumber != other.rowsNumber) {
		errorCode = COLUMNS_OF_ONE_MATRIX_NOT_EQUALS_ROWS_OF_OTHER; 
		return Matrix(); 
	}

	T **mtx = new T*[rowsNumber];
	for (int i = 0; i < rowsNumber; i++)
	{
		mtx[i] = new T[other.columnNumber];
		for (int j = 0; j < other.columnNumber; j++)
		{
			mtx[i][j] = 0;
			for (int k = 0; k < other.rowsNumber; k++)
			{
				mtx[i][j] += matrix[i][k] * other.matrix[k][j];
			}
		}
	}
	Matrix<T> poweredMatrix(rowsNumber, other.columnNumber, mtx);
	if (mtx != NULL) {
		for (int i = 0; i < rowsNumber; i++) {
			delete mtx[i];
		}
		delete mtx;
	}
	return std::move(poweredMatrix);
}

template<typename T>
void Matrix<T>::multiplicateByScalar(const T number)
{
	for (int i = 0; i < rowsNumber; i++)
	{
		for (int j = 0; j < columnNumber; j++)
		{
			matrix[i][j] *= number;
		}
	}
}

template<typename T>
T Matrix<T>::scalarVectorsMultiplication(const Matrix<T>& other, int &errorCode)
{
	T scalar = 0;
	if ((other.rowsNumber == 1 && rowsNumber == 1 && other.columnNumber == columnNumber)
		|| (other.rowsNumber == rowsNumber && other.columnNumber == 1 && columnNumber == 1))
	{
		for (int i = 0; i < other.rowsNumber; i++)
		{
			for (int j = 0; j < other.columnNumber; j++)
			{
				scalar += (matrix[i][j] * other.matrix[i][j]);
			}
		}
		return scalar; 
	}
	else {
		errorCode = BAD_SIZES_OF_VECTORS; 
		return NULL; 
	}
}

template<typename T>
bool Matrix<T>::makeIdentityMatrix(int &errorCode)
{
	if (!(rowsNumber == columnNumber))  { 
		errorCode = MATRIX_IS_NOT_SQUARE;
		return false; 
	}
	for (int i = 0; i < rowsNumber; i++) {
		for (int j = 0; j < columnNumber; j++) {
			if (i == j) {
				matrix[i][j] = 1;
			}
			else matrix[i][j] = 0;
		}
	}
	return true; 
}

template<typename T>
Matrix<T> Matrix<T>::transposeMatrix()
{
	T** mtx = new T*[columnNumber];
	for (int i = 0; i < columnNumber; i++) {
		mtx[i] = new T[rowsNumber];
	}
	for (int i = 0; i < rowsNumber; ++i) {
		for (int j = 0; j < columnNumber; ++j) {
			mtx[j][i] = matrix[i][j];
		}
	}
	Matrix mtx1(columnNumber, rowsNumber, mtx);
	if (mtx != NULL) {
		for (int i = 0; i < columnNumber; i++)
		{
			delete mtx[i];
		}
		delete mtx;
	}
	return std::move(mtx1);
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const T number)
{
	this->multiplicateByScalar(number);
	return this; 
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other)
{ 
	int errorCode = 0; 
	Matrix<T> mtx = matrixesMultiplication(other, errorCode);
	if (errorCode != 0) throw invalid_argument("ERROR CODE:" + to_string(errorCode));
	return std::move(mtx); 
}

template<typename T>
Matrix<T> Matrix<T>::operator~()
{
	return std::move(transposeMatrix()); 
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other)
{
	Matrix mtx = *this; 
	if (rowsNumber == other.rowsNumber && columnNumber == other.columnNumber) {
		mtx.helpAddMtx(other);
	}
	else {
		throw invalid_argument("ERROR CODE:" + to_string(MATRIXES_NOT_THE_SAME_LENGTH));
	}
	return std::move(mtx); 
}


template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& other)
{
	Matrix mtx = *this; 
	if (rowsNumber == other.rowsNumber && columnNumber == other.columnNumber) {
		mtx.helpSubMtx(other); 
	}
	else {
		throw invalid_argument("ERROR CODE:" + to_string(MATRIXES_NOT_THE_SAME_LENGTH));
	}
	return std::move(mtx); 
}

template<typename T>
T * Matrix<T>::operator[](int rowsIndex)
{
	if (rowsIndex < 0 || rowsIndex >= rowsNumber) return NULL;
	return matrix[rowsIndex];
}

template<typename T>
bool Matrix<T>::setNewSize(int newSizeRows, int newSizeColumns, int &errorCode)
{
	if (newSizeRows <= 0) {
		errorCode = NEGATIVE_OFFSET;
		return false;
	}
	if (newSizeColumns <= 0) {
		errorCode = NEGATIVE_OFFSET;
		return false;
	}

	T **tempMatrix = new T*[newSizeRows];
	for (int i = 0; i < newSizeRows; i++)
	{
		tempMatrix[i] = new T[newSizeColumns];
	}

	int sizeX = rowsNumber < newSizeRows ? rowsNumber : newSizeRows;
	int sizeY = columnNumber < newSizeColumns ? columnNumber : newSizeColumns;

	for (int i = 0; i < sizeX; i++) {
		for (int j = 0; j < sizeY; j++)
		{
			tempMatrix[i][j] = matrix[i][j]; 
		}
	}
	dealocMatrix(); 
	matrix = tempMatrix;
	rowsNumber = newSizeRows;
	columnNumber = newSizeColumns;
	return true; 
}

template<typename T>
bool Matrix<T>::getValueAt(T * val, int rowsIndex, int columnsIndex, int &errorCode)
{
	if (rowsIndex < 0 || columnsIndex < 0) {
		errorCode = NEGATIVE_OFFSET;
		return false;
	}
	if (rowsIndex > rowsNumber || columnsIndex > columnNumber) {
		errorCode = TOO_BIG_OFFSET;
		return false;
	}
	*val = matrix[rowsIndex][columnsIndex];
	return true;
}

template<typename T>
bool Matrix<T>::setValueAt(T val, int rowsIndex, int columnsIndex, int &errorCode)
{
	if (rowsIndex < 0 || columnsIndex < 0) {
		errorCode = NEGATIVE_OFFSET;
		return false;
	}
	if (rowsIndex > rowsNumber || columnsIndex > columnNumber) {
		errorCode = TOO_BIG_OFFSET;
		return false;
	}
	matrix[rowsIndex][columnsIndex] = val; 
	return true;
}

template<typename T>
bool Matrix<T>::readMatrixFromFile(string path, int &errorCode)
{
	vector<vector<T>> mtx; 
	ifstream file; 
	file.open(path); 
	if (file.fail()) {
		errorCode = ERROR_CANT_OPEN_FILE; 
		return false;
	} 
	string line; 
	string error;
	int countSlashes = 0;
	int totalSlashes = 0; 
	T number;
	while (!file.eof()) {
		getline(file, line);
		stringstream ss(line);
		StringHelp::replace(ss, ',', '.');
		vector<T> tmp; 
		countSlashes = StringHelp::checkSlashes(ss);
		StringHelp::checkIfThereIsNotTwoSlashesInRow(ss);
		StringHelp::replace(ss, '/', ' ');
		while (!ss.eof())
		{
			ss >> number;
			if (ss.fail()) {
				ss.clear();
				ss >> error; 
				errorCode = INCORECT_VALUE_IN_FILE;
				if (error[0] = ' ') {
					ss.ignore();
				}
				else {
					tmp.push_back(0);
				}
			}
			else {
				tmp.push_back(number);
			}
			
		}
		totalSlashes = totalSlashes + countSlashes;
		mtx.push_back(tmp); 
	}
	file.close(); 

	int rows = mtx.size();
	
	int columns = mtx[0].size(); 

	if ((totalSlashes - 1) != columns) return false; 

	int totalNumbers = rows * columns; 
	int totalCheck = checkTotalElementsOfVectorMatrix(mtx); 

	if (totalNumbers != totalCheck)  
	{
		errorCode = ITS_NOT_A_MATRIX_BAD_SIZES; 
		return false;
	}
	
	convertFromVectorMatrixToArrayMatrix(mtx, rows, columns, errorCode);
	return true; 
}

template<typename T>
Matrix<T> Matrix<T>::makeVct(int row_column_number, bool column_or_row, int &errorCode)
{
	if ((row_column_number > this->rowsNumber) || (row_column_number < 0) || (row_column_number > this->columnNumber)) { 
		errorCode = NEGATIVE_OFFSET;
		return Matrix(); 
	}
	Matrix<T> mtx(1,1, errorCode); 
	if (column_or_row == true) { mtx.setNewSize(rowsNumber,1, errorCode); }
	else mtx.setNewSize(1, columnNumber, errorCode);
	int l = 0; 
	for (int i = 0; i < rowsNumber; i++) {
		for (int j = 0; j < columnNumber; j++) {
			if (column_or_row == true) {
				if (row_column_number == j) {
					if (l != mtx.rowsNumber) {
						int k = j;
						mtx.matrix[l][0] = this->matrix[i][k];
						l++;
					}
				}
			}
			else {
				if (row_column_number == i) {
					if (l != mtx.columnNumber) {
						int k = i;
						mtx.matrix[0][l] = this->matrix[k][j];
						l++;
					}
				}
			}
		}
	}

	return mtx; 

}

template<typename T>
void Matrix<T>::print()
{

	for (int i = 0; i < rowsNumber; i++)
	{
		for (int j = 0; j < columnNumber; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << "\n"; 
	}
}

template<typename T>
 void Matrix<T>::fillRandom()
{
	 for (int i = 0; i < rowsNumber; i++)
	 {
		 for (int j = 0; j < columnNumber; j++)
		 {
			 matrix[i][j] = rand() % 10;
		 }
	 }
}

template<typename T>
void Matrix<T>::createMatrix()
{
	matrix = new T*[rowsNumber];
	for (int i = 0; i < rowsNumber; i++)
	{
		matrix[i] = new T[columnNumber]; 
	}
}

template<typename T>
void Matrix<T>::copy(const Matrix<T>& other)
{
	rowsNumber = other.rowsNumber;
	columnNumber = other.columnNumber;

	matrix = new T*[rowsNumber];
	for (int i = 0; i < rowsNumber; i++)
	{
		matrix[i] = new T[columnNumber];
		for (int j = 0; j < columnNumber; j++)
		{
			matrix[i][j] = other.matrix[i][j];
		}
	}
}

template<typename T>
void Matrix<T>::dealocMatrix()
{
	if (matrix != NULL)
	{
		for (int i = 0; i < rowsNumber; i++)
		{
			delete matrix[i];
		}
		delete matrix;
	}
}

template<typename T>
void Matrix<T>::helpAddMtx(const Matrix<T>& other)
{
	for (int i = 0; i < rowsNumber; i++)
	{
		for (int j = 0; j < columnNumber; j++)
		{
			matrix[i][j] += other.matrix[i][j];
		}
	}
}

template<typename T>
void Matrix<T>::helpSubMtx(const Matrix<T>& other)
{
	for (int i = 0; i < rowsNumber; i++)
	{
		for (int j = 0; j < columnNumber; j++)
		{
			matrix[i][j] -= other.matrix[i][j];
		}
	}
}

template<typename T>
void Matrix<T>::convertFromVectorMatrixToArrayMatrix(vector<vector<T>>& vectorMatrix, int rowsSize, int columnsSize, int &errorCode)
{

	setNewSize(rowsSize, columnsSize, errorCode); 
	for (int i = 0; i < rowsSize; i++)
	{
		for (int j = 0; j < columnsSize; j++)
		{
			
				matrix[i][j] = vectorMatrix[i][j];
		}
	}
}

template<typename T>
int Matrix<T>::checkTotalElementsOfVectorMatrix(vector<vector<T>>& vectorMatrix)
{
    int total = 0; 
	for (int i = 0; i < vectorMatrix.size(); i++) {
		for (int j = 0; j < vectorMatrix[i].size(); j++)
		{
			total = total + 1; 
		}
	}
	return total; 
}

template<typename T>
void Matrix<T>::mover(Matrix<T>& other)
{
	matrix = other.matrix;
	rowsNumber = other.rowsNumber;
	columnNumber = other.columnNumber;
	other.matrix = NULL;
}

template<typename T>
Matrix<T>::Matrix(int rowsSize, int columnsSize, T**mtx)
{
	rowsNumber = rowsSize;
	columnNumber = columnsSize;
	createMatrix();
	for (int i = 0; i < rowsNumber; i++) {
		for (int j = 0; j < columnNumber; j++) {
			matrix[i][j] = mtx[i][j];
		}
	}
}













