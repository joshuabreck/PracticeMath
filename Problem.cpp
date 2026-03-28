#include "Problem.h"

// Class Problem

/// <summary>
/// 
/// </summary>
/// <param name="a_op1"></param>
/// <param name="a_op2"></param>
Problem::Problem()
{
	m_operand1 = 0;
	m_operand2 = 0;
	m_answer = 0;
}

/// <summary>
/// 
/// </summary>
/// <param name="a_op1"></param>
/// <param name="a_op2"></param>
Problem::Problem(int a_op1, int a_op2)
	: m_operand1(a_op1),
	  m_operand2(a_op2)
{
	m_answer = 0;
}

/// <summary>
/// 
/// </summary>
/// <param name="a_operator"></param>
/// <returns></returns>
std::string Problem::DisplayBase(char a_operator)
{
	return std::to_string(m_operand1) + " " + a_operator + " " + std::to_string(m_operand2) + " = ";
}

/// <summary>
/// 
/// </summary>
/// <param name="a_answer"></param>
/// <returns></returns>
bool Problem::Evaluate(int a_answer)
{
	if (a_answer == m_answer)
	{
		return true;
	}
	return false;
}