#include "ProblemFactory.h"

#include "AddProblem.h"
#include "DivideProblem.h"
#include "MultiplyProblem.h"
#include "SubtractProblem.h"

#include <random>
#include <ctime>

// Class ProblemFactory

/// <summary>
/// 
/// </summary>
/// <param name="a_problemType"></param>
ProblemFactory::ProblemFactory(OperatorEnum a_problemType, int a_ceiling1, int a_ceiling2, bool a_includeZero)
	: m_problemType(a_problemType),
	  m_ceiling1(a_ceiling1),
	  m_ceiling2(a_ceiling2),
	  m_includeZero(a_includeZero)
{
	InitRand();
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
Problem* ProblemFactory::GetProblem()
{
	Problem* retval = NULL;
	int op1 = RandomNumber(m_ceiling1, m_includeZero);
	int op2 = RandomNumber(m_ceiling2, m_includeZero);
	switch (m_problemType)
	{
		case Add:
		{
			retval = new AddProblem(op1, op2);
			break;
		}
		case Subtract:
		{
			retval = new SubtractProblem(op1, op2);
			break;
		}
		case Multiply:
		{
			retval = new MultiplyProblem(op1, op2);
			break;
		}
		case Divide:
		{
			retval = new DivideProblem(op1, op2);
			break;
		}
		default:
		{
			break;
		}
	}
	return retval;
}

/// <summary>
/// 
/// </summary>
void ProblemFactory::InitRand()
{
	time_t timer;
	time(&timer);
	srand((unsigned int)timer);
}

/// <summary>
/// 
/// </summary>
/// <param name="a_ceiling"></param>
/// <param name="a_includeZero"></param>
/// <returns></returns>
int ProblemFactory::RandomNumber(int a_ceiling, bool a_includeZero)
{
	int retval = rand() % a_ceiling;
	if (!a_includeZero)
	{
		++retval;
	}
	return retval;
}