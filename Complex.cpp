#include "pch.h"
#include <iostream>
#include <math.h>
#include "tilt.h"

using namespace std;

Complex::Complex(double _re, double _im)
{
	re = _re;
	im = _im;
}

Complex::Complex(double _re)
{
	re = _re;
	im = 0;
}

Complex::Complex()
{
	re = 0;
	im = 0;
}

double Complex::Re() const
{
	return this->re;
}

double Complex::Im() const
{
	return this->im;
}

double Complex::R() const
{
	return sqrt(pow(re, 2) + pow(im, 2));
}

double Complex::Phi() const
{
	if (re > 0)
	{
		return atan(Im() / Re());
	}
	else if (re < 0 && im>0)
	{
		return 3.14159265 + atan(Im() / Re());
	}
	else if (re < 0 && im < 0)
	{
		return -3.14159265 + atan(Im() / Re());
	}
	return 1;
}

ostream& operator<<(ostream &out, const Complex &ex)
{
	out << "(" << ex.re << ", " << ex.im << ")";
	return out;
}

istream& operator>>(istream &in, Complex &ex)
{
	in >> ex.re >> ex.im;
	return in;
}

Complex Complex::operator+(Complex &ex)
{
	return Complex(re + ex.Re(), im + ex.Im());
}

Complex Complex::operator+=(Complex &ex)
{
	re += ex.Re();
	im += ex.Im();

	return *this;
}

Complex Complex::operator-(Complex &ex)
{
	return Complex(re - ex.Re(), im - ex.Im());
}

Complex Complex::operator-=(Complex &ex)
{
	re -= ex.Re();
	im -= ex.Im();

	return *this;
}

Complex Complex::operator*(Complex &ex)
{
	return Complex(re * ex.Re() - im * ex.Im(), re * ex.Im() + im * ex.Re());
}

Complex Complex::operator*=(Complex &ex)
{
	double _re = re;

	re = re * ex.Re() - im * ex.Im();
	im = _re * ex.Im() + im * ex.Re();

	return *this;
}

Complex Complex::operator/(Complex &ex)
{
	double r = ex.Re() * ex.Re() + ex.Im() * ex.Im();

	return Complex((re * ex.Re() + im * ex.Im()) / r, (im * ex.Re() - re * ex.Im()) / r);
}

Complex Complex::operator/=(Complex &ex)
{
	double _re = re;
	double r = ex.Re() * ex.Re() + ex.Im() * ex.Im();

	re = (re * ex.Re() + im * ex.Im()) / r;
	im = (im * ex.Re() - _re * ex.Im()) / r;

	return *this;
}
