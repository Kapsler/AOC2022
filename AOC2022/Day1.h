#pragma once

#include "Utils.h"

int32_t day1part1( const std::vector<int32_t> data )
{
	int32_t mostCalories = 0;
	int32_t currentCalories = 0;

	for( int i = 0; i < data.size(); ++i )
	{
		const int32_t& currentData = data[ i ];
		if( currentData == -1 )
		{
			mostCalories = currentCalories > mostCalories ? currentCalories : mostCalories;
			currentCalories = 0;
			continue;
		}

		currentCalories += currentData;
	}

	return mostCalories;
}

int32_t day1part2( const std::vector<int32_t> data )
{
	int32_t mostCalories[ 3 ] = { 0 };
	int32_t currentCalories = 0;

	for( int i = 0; i < data.size(); ++i )
	{
		const int32_t& currentData = data[ i ];
		if( currentData == -1 )
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
			continue;
		}

		currentCalories += currentData;
	}

	return mostCalories[ 0 ] + mostCalories[ 1 ] + mostCalories[ 2 ];
}