#include "stdafx.h"
#include "Day1.h"

int main()
{
	std::vector< int32_t > inputDataInts;
	{
		std::vector<std::string> inputDataStrings;
		Utils::ReadFile( "/data/day1/input.txt", inputDataStrings );
		Utils::ConvertStringsToInts( inputDataStrings, inputDataInts );
	}

	int32_t answer = day1part2( inputDataInts );

	printf( "%d\n", answer );
}
