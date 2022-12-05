#pragma once

#include <string>
#include <vector>

namespace day4
{
	void prepareData ( const std::vector< std::string >& stringData, std::vector< uint64_t >& intData )
	{
		intData.reserve( stringData.size() * 4 );
		for( std::string_view stringView : stringData )
		{
			size_t indexAfter = 0;

			intData.emplace_back( std::stoi( stringView.data(), &indexAfter ) );
			stringView.remove_prefix( indexAfter + 1 );

			intData.emplace_back( std::stoi( stringView.data(), &indexAfter ) );
			stringView.remove_prefix( indexAfter + 1 );

			intData.emplace_back( std::stoi( stringView.data(), &indexAfter ) );
			stringView.remove_prefix( indexAfter + 1 );

			intData.emplace_back( std::stoi( stringView.data(), &indexAfter ) );
		}
	}

	uint64_t day4part1( const std::vector< uint64_t >& data )
	{
		uint64_t sum = 0;

		for( size_t i = 0; i < data.size(); i += 4 )
		{
			const auto& firstMin = data[ i ];
			const auto& firstMax = data[ i + 1 ];
			const auto& secondMin = data[ i + 2 ];
			const auto& secondMax = data[ i + 3 ];

			if( ( firstMin <= secondMin && firstMax >= secondMax )
				|| ( firstMin >= secondMin && firstMax <= secondMax ) )
			{
				++sum;
			}
		}

		return sum;
	}

	uint64_t day4part2( const std::vector< uint64_t >& data )
	{
		uint64_t sum = 0;

		for( size_t i = 0; i < data.size(); i += 4 )
		{
			const auto& firstMin = data[ i ];
			const auto& firstMax = data[ i + 1 ];
			const auto& secondMin = data[ i + 2 ];

			if( ( secondMin <= firstMax && secondMin >= firstMin )
				|| ( firstMin >= secondMin && firstMin <= data[ i + 3 ] ) )
			{
				++sum;
			}
		}

		return sum;
	}

}
