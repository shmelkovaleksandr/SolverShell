﻿
#include <random>
#include "randomization.h"

using namespace std;

// ‘ункци¤ генерации рандомного вещественного числа в диапазоне от min до max
double GetRandRealNumb(int min, int max)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dist(min, max);
	return dist(gen);
}

// ‘ункци¤ генерации рандомного целого числа в диапазоне от min до max
int GetRandIntNumb(int min, int max)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(min, max);
	return dist(gen);
}

// ‘ункиц¤ нормального распределени¤ с математическим ожиданием u и стандартным отклонением o
double GetNormDistNumb(double u, double o)
{
	random_device rd;
	mt19937 gen(rd());
	normal_distribution<> dist(u, o);
	return dist(gen);
}