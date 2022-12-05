#pragma once

#include <string>
#include <vector>

__forceinline constexpr uint64_t priorityFromCompartments( const uint64_t& compartment1, const uint64_t& compartment2, const uint64_t compartment3 )
{
	uint64_t sharedItems = compartment1 & compartment2 & compartment3;
	for( int i = 0; i < ( sizeof( uint64_t ) * 8 ); ++i )
	{
		if( ( sharedItems & ( 1llu << i ) ) != 0 )
		{
			if( ( sharedItems > ( 1ull << 32llu ) ) )
			{
				return i - 32 + 1;
			}
			else
			{
				return i + 27;
			}
		}
	}

	return 0;
}

__forceinline constexpr uint64_t priorityFromCompartments( const uint64_t& leftCompartment, const uint64_t& rightCompartment )
{
	uint64_t sharedItems = leftCompartment & rightCompartment;
	for( int i = 0; i < ( sizeof( uint64_t ) * 8 ); ++i )
	{
		if( ( sharedItems & ( 1llu << i ) ) != 0 )
		{
			if( ( sharedItems > ( 1ull << 32llu ) ) )
			{
				return i - 32 + 1;
			}
			else
			{
				return i + 27;
			}
		}
	}

	return 0;
}

__forceinline constexpr void encodeIntoCompartment( uint64_t& compartment, const char& item )
{
	compartment |= 1llu << ( item - 'A' );
}

uint64_t day3part1( const std::vector< std::string >& data )
{
	uint64_t sum = 0;
	for( std::string_view compartments : data )
	{
		const int32_t midPoint = compartments.size() / 2;
		uint64_t leftCompartment = 0;
		uint64_t rightCompartment = 0;

		for( int32_t i = 0; i < compartments.size(); ++i )
		{
			char currentCharacter = compartments.at( i );
			encodeIntoCompartment( i < midPoint ? leftCompartment : rightCompartment, currentCharacter );
		}

		sum += priorityFromCompartments( leftCompartment, rightCompartment );
	}

	return sum;
}


uint64_t day3part2( const std::vector< std::string >& data )
{
	uint64_t sum = 0;
	
	for( int groupIndex = 0; groupIndex < data.size(); groupIndex += 3 )
	{
		uint64_t elfCompartments[ 3 ] = { 0 };
		for( int elfIndex = 0; elfIndex < 3; ++elfIndex )
		{
			const auto& compartments = data[ groupIndex + elfIndex ];
			for( int32_t itemIndex = 0; itemIndex < compartments.size(); ++itemIndex )
			{
				char currentCharacter = compartments.at( itemIndex );
				encodeIntoCompartment( elfCompartments[ elfIndex ], currentCharacter );
			}
		}

		sum += priorityFromCompartments( elfCompartments[ 0 ], elfCompartments[ 1 ], elfCompartments[ 2 ] );
	}

	return sum;
}