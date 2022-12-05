#include "stdafx.h"
#include "Day1.h"
#include "Day2.h"
#include "Day3.h"

int __cdecl main()
{
	std::vector<std::string> inputDataStrings;
	Utils::ReadFile( "/data/day3/input.txt", inputDataStrings );
	//std::vector< uint64_t > inputDataInts;
	//Utils::ConvertStringsToInts( inputDataStrings, inputDataInts );

	auto begin = std::chrono::high_resolution_clock::now();
	uint64_t answer = day3::day3part1( inputDataStrings );
	auto end = std::chrono::high_resolution_clock::now();

	auto timing = end - begin;
	printf( "Answer %llu, Timing:%llu us \n", answer, std::chrono::duration_cast< std::chrono::microseconds >( timing ).count() );
}
