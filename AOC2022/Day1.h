#pragma once

#include "Utils.h"

uint64_t day1part1( const std::vector< uint64_t >& data )
{
	uint64_t mostCalories = 0;
	uint64_t currentCalories = 0;

	for( int i = 0; i < data.size(); ++i )
	{
		const uint64_t& currentData = data[ i ];
		if( currentData == 0 )
		{
			mostCalories = currentCalories > mostCalories ? currentCalories : mostCalories;
			currentCalories = 0;
		}
		else
		{
			currentCalories += currentData;
		}
	}

	return mostCalories;
}

uint64_t day1part2( const std::vector<uint64_t>& data )
{
	uint64_t mostCalories[ 3 ] = { 0 };
	uint64_t currentCalories = 0;

	for( int i = 0; i < data.size(); ++i )
	{
		const uint64_t& currentData = data[ i ];
		if( currentData == 0 )
		{
			if( currentCalories > mostCalories[ 0 ] )
			{
				mostCalories[ 2 ] = mostCalories[ 1 ];
				mostCalories[ 1 ] = mostCalories[ 0 ];
				mostCalories[ 0 ] = currentCalories;
			}
			else if( currentCalories > mostCalories[ 1 ] )
			{
				mostCalories[ 2 ] = mostCalories[ 1 ];
				mostCalories[ 1 ] = currentCalories;
			}
			else if( currentCalories > mostCalories[ 2 ] )
			{
				mostCalories[ 2 ] = currentCalories;
			}
			currentCalories = 0;
		}
		else
		{
			currentCalories += currentData;
		}
	}

	return mostCalories[ 0 ] + mostCalories[ 1 ] + mostCalories[ 2 ];
}