#pragma once

#include <span>
#include <string>
#include <vector>

namespace day3
{
	__forceinline uint64_t priorityFromSharedItems( std::span< uint64_t > compartments )
	{
		uint64_t sharedItems = compartments[ 0 ];
		for( int i = 1; i < compartments.size(); ++i )
		{
			sharedItems &= compartments[ i ];
		}

		uint64_t itemIndex = std::countr_zero( sharedItems );
		if( itemIndex >= 32 )
		{
			return itemIndex - 31;
		}

		return itemIndex + 27;
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
			const uint64_t midPoint = compartments.size() / 2;
			uint64_t compartmentContents[ 2 ] = { 0 };
			auto& leftCompartment = compartmentContents[ 0 ];
			auto& rightCompartment = compartmentContents[ 1 ];
			
			for( uint64_t itemIndex = 0; itemIndex < midPoint; ++itemIndex )
			{
				encodeIntoCompartment( leftCompartment, compartments[ itemIndex ] );
				encodeIntoCompartment( rightCompartment, compartments[ itemIndex + midPoint ] );
			}

			sum += priorityFromSharedItems( compartmentContents );
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

			sum += priorityFromSharedItems( elfCompartments );
		}

		return sum;
	}
}
