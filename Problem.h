#pragma once
#include <string>

/// <summary>
/// 
/// </summary>
class Problem
{
protected:
	int m_operand1;
	int m_operand2;
	int m_answer;

	std::string DisplayBase(char a_operator);

public:
	Problem();
	Problem(int a_op1, int a_op2);

	virtual std::string Display() = 0;
	bool Evaluate(int a_answer);
};