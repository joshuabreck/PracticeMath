#include "MultiplyProblem.h"

// Class MultiplyProblem

/// <summary>
/// 
/// </summary>
/// <param name="a_op1"></param>
/// <param name="a_op2"></param>
MultiplyProblem::MultiplyProblem(int a_op1, int a_op2)
	: Problem(a_op1, a_op2)
{
	m_answer = a_op1 * a_op2;
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
std::string MultiplyProblem::Display()
{
	return Problem::DisplayBase('x');
}