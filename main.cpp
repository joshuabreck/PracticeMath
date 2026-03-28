#include <iostream>

#include "OperatorEnum.h"
#include "ProblemFactory.h"


int DEFAULT_CEILING = 12;

/// <summary>
/// 
/// </summary>
/// <param name="str1"></param>
/// <param name="str2"></param>
/// <returns></returns>
bool Compare(std::string str1, std::string str2)
{
	return str1.compare(str2) == 0;
}

/// <summary>
/// 
/// </summary>
/// <param name="argc"></param>
/// <param name="argv"></param>
/// <returns></returns>
int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		if (Compare(argv[1], "h"))
		{
			std::cout << "PracticeMath {operator symbol [ +,-,x,/ ]} {ceiling1 [ int ]} {ceiling2 [ int ]} {includeZero [ t,f ]}";
			return 0;
		}

		int ceiling1 = DEFAULT_CEILING;
		int ceiling2 = DEFAULT_CEILING;
		bool includeZero = true;
		ProblemFactory* factory;
		if (argc > 3)
		{
			ceiling1 = std::stoi(argv[2]);
			ceiling2 = std::stoi(argv[3]);
		}
		if (argc > 4)
		{
			std::string zero(argv[4]);
			if (Compare(zero, "f"))
			{
				includeZero = false;
			}
		}
		if (Compare(argv[1], "+"))
		{
			factory = new ProblemFactory(Add, ceiling1, ceiling2, includeZero);
		}
		else if (Compare(argv[1], "-"))
		{
			factory = new ProblemFactory(Subtract, ceiling1, ceiling2, includeZero);
		}
		else if (Compare(argv[1], "x"))
		{
			factory = new ProblemFactory(Multiply, ceiling1, ceiling2, includeZero);
		}
		else if (Compare(argv[1], "/"))
		{
			factory = new ProblemFactory(Divide, ceiling1, ceiling2, includeZero);
		}
		else
		{
			std::cout << "Invalid argument\n";
			return -1;
		}
		std::string input;
		while (!Compare(input, "q"))
		{
			bool correct = false;
			Problem* problem = factory->GetProblem();
			while (!correct)
			{
				std::cout << problem->Display();
				std::cin >> input;
				if (Compare(input, "q"))
				{
					break;
				}
				int answer = std::stoi(input);
				if (problem->Evaluate(answer))
				{
					std::cout << "Correct!\n";
					correct = true;
				}
				else
				{
					std::cout << "Try again!\n";
				}
			}
		}
	}


	return 0;
}