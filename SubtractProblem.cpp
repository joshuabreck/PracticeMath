#include "SubtractProblem.h"

// Class SubtractProblem

/// <summary>
/// 
/// </summary>
/// <param name="a_op1"></param>
/// <param name="a_op2"></param>
SubtractProblem::SubtractProblem(int a_op1, int a_op2)
{
	if (a_op1 > a_op2)
	{
		m_operand1 = a_op1;
		m_operand2 = a_op2;
		m_answer = a_op1 - a_op2;
	}
	else
	{
		m_operand1 = a_op2;
		m_operand2 = a_op1;
		m_answer = a_op2 - a_op1;
	}
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
std::string SubtractProblem::Display()
{
	return Problem::DisplayBase('-');
}