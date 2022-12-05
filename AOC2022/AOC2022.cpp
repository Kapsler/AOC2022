#include "stdafx.h"
#include "Day1.h"
#include "Day2.h"
#include "Day3.h"

int main()
{
	
	std::vector<std::string> inputDataStrings;
	Utils::ReadFile( "/data/day3/input.txt", inputDataStrings );
	//std::vector< int32_t > inputDataInts;
	//Utils::ConvertStringsToInts( inputDataStrings, inputDataInts );

	uint64_t answer = day3part1( inputDataStrings );

	printf( "%d\n", answer );
}
