#pragma once

#include <span>
#include <string>
#include <vector>

__forceinline constexpr uint64_t priorityFromCompartments( std::span< uint64_t > compartments )
{
	uint64_t sharedItems = compartments[ 0 ];
	for( int i = 1; i < compartments.size(); ++i )
	{
		sharedItems &= compartments[ i ];
	}
	
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
		uint64_t compartmentContents[ 2 ] = { 0 };
		auto& leftCompartment = compartmentContents[ 0 ];
		auto& rightCompartment = compartmentContents[ 1 ];

		for( int32_t itemIndex = 0; itemIndex < compartments.size(); ++itemIndex )
		{
			encodeIntoCompartment( itemIndex < midPoint ? leftCompartment : rightCompartment, compartments[ itemIndex ] );
		}

		sum += priorityFromCompartments( compartmentContents );
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
				encodeIntoCompartment( elfCompartments[ elfIndex ], compartments[ itemIndex ] );
			}
		}

		sum += priorityFromCompartments( elfCompartments );
	}

	return sum;
}