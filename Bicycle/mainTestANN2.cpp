#include <iostream>
#include <Eigen/Dense>
#include <ctime>

using namespace std;
using namespace Eigen;

int main(int argc, char *argv[])
{
	Matrix<float, 15, 15> mat1;
	Matrix<float, 15, 15> mat2;
	Matrix<float, 15, 15> mat3;
	Matrix<float, 15, 15> mat4;

	Matrix<float, 15, 1> bias1;
	Matrix<float, 15, 1> bias2;
	Matrix<float, 15, 1> bias3;
	Matrix<float, 15, 1> bias4;

	Matrix<float, 15, 1> signal;

	mat1.setRandom();
	mat2.setRandom();
	mat3.setRandom();
	mat4.setRandom();

	bias1.setRandom();
	bias2.setRandom();
	bias3.setRandom();
	bias4.setRandom();

	signal.setZero();

	std::clock_t start;
	double duration;

	start = std::clock();

	for (int i = 0; i < 100000; i++)
	{
		signal = (mat1 * signal + bias1).array().tanh();
		signal = (mat2 * signal + bias2).array().tanh();
		signal = (mat3 * signal + bias3).array().tanh();
		signal = (mat4 * signal + bias4).array().tanh();
	}

	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

	std::cout << "printf: " << 100000.0f/duration << '\n';

	return 0;
}
