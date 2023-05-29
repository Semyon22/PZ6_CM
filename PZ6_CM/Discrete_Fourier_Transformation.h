#pragma once
#ifndef Discrete_Fourier_Transformation_h
#define Discrete_Fourier_Transformation_h

#include <vector>
#include <complex>
#include "CONST.h"

namespace Com_Methods
{
	//�������������� �����
	class Discrete_Fourier_Transformation
	{
	public:

		//������� �������������� (����� ������� - ������ �����)
		//Data - ������� ������, Result - ������ ����������
		void FFT(const std::vector<std::complex<double>>& Data, std::vector<std::complex<double>>& Result);

		//------------------------------------------------------------------------------------------

		//�������� ������� �������������� (����� ������� ������)
		//Data - ������� ������, Result - ������ ����������
		void IFFT(const std::vector<std::complex<double>>& Data, std::vector<std::complex<double>>& Result);

		//------------------------------------------------------------------------------------------

		//������ ����������� �������� res(m) = Vec1(m - n) * Vec2
		//Vec1 � Vec2 - ������� ������, Result - ������ ����������
		void Convolution(const std::vector<std::complex<double>>& Vec1,
			const std::vector<std::complex<double>>& Vec2,
			std::vector<std::complex<double>>& Result);
	};
}
#endif // !Discrete_Fourier_Transformation_h