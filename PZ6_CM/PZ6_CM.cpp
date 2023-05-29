#include <iostream>
#include <fstream>
#include <iomanip>
#include "Wavelet_Analysis.h"

int main()
{
	//число отсчётов
	int N = 512;

	//число этапов
	int Stage = 4;

	//сигнал и его коэффициенты разложения по вэйвлет-базису
	std::vector<std::complex<double>> Z(N), Koef_Psi, Koef_Fi;

	//частичное восстановление, уточняющие данные и восстановленный сигнал
	std::vector<std::complex<double>> P, Q, Z_Rec;

	//формирование исходного сигнала
	for (int n = 0; n < N; n++)
	{
		if (n >= 128 && n <= 255) Z[n]._Val[0] = sin(fabs(pow(n - 128, 1.88)) / 128.0);
		if (n >= 384 && n <= 447) Z[n]._Val[0] = sin(fabs(pow(n - 128, 2.11)) / 128.0);
	}

	//выбор базисной системы
	Com_Methods::Wavelet_Analysis Wavelet_Test(N, Com_Methods::Wavelet_Analysis::Basis_Type::Dobeshi);

	//фаза анализа данных
	Wavelet_Test.Analysis_Phase(Stage, Z, Koef_Psi, Koef_Fi);

	//фаза восстановления
	Wavelet_Test.Synthesis_Phase(Stage, Koef_Psi, Koef_Fi, P, Q, Z_Rec);

	std::ofstream file("Rsignal.txt");
	for (int i = 0; i < N; i++) {
		file << Z_Rec[i]._Val[0] << "\n";
	}
	file.close();

	std::ofstream file1("Psi.txt");
	std::ofstream file2("Fi.txt");
	for (int i = 0; i < Koef_Fi.size(); i++) {
		file1 << Koef_Psi[i].real() << "\n";
		file2 << Koef_Fi[i].real() << "\n";
	}
	file1.close();
	file2.close();

	std::vector<std::complex<double>> E(N);
	for (int i = 0; i < N; ++i) {
		E[i]._Val[0] = fabs(Z[i]._Val[0] - Z_Rec[i]._Val[0]);
	}
	for (int i = 0; i < N; i++) {
		std::cout << E[i]._Val[0] << " " << E[i]._Val[1] << std::endl;
	}
	std::cout << "----------------------------------------------------------------------------------------------------------" << std::endl;
	for (int i = 0; i < N; i++) {
		std::cout << Z[i]._Val[0] << std::endl;
	}
}