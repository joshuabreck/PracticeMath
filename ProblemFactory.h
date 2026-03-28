#pragma once
#include "OperatorEnum.h"
#include "Problem.h"

class ProblemFactory
{
private:
	OperatorEnum m_problemType;
	int m_ceiling1;
	int m_ceiling2;
	bool m_includeZero;

	void InitRand();
	int RandomNumber(int a_ceiling, bool a_includeZero);

public:
	ProblemFactory(OperatorEnum a_problemType, int a_ceiling1, int a_ceiling2, bool a_includeZero);

	Problem* GetProblem();
};