#pragma once

#include <vector>

using std::vector;

class Matrice
{
private:
	unsigned int rows;
	unsigned int columns;
	vector<vector<double>> m_matrix;

public:
	Matrice(unsigned, unsigned, double);
	~Matrice() = default;

	int get_rows() const;
	int get_columns() const;
	void print() const;
	void change(int, int, double);

	Matrice transpose();

	Matrice operator+(Matrice &B);
	Matrice operator-(Matrice &B);

	Matrice operator+(double);
	Matrice operator-(double);
	Matrice operator*(double);
	Matrice operator/(double);

	double& operator()(const unsigned&, const unsigned&);
};

