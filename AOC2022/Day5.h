#pragma once


#include <string>
#include <vector>

namespace day5
{
	uint64_t day5part1( const std::vector<std::string>& data )
	{
		const auto& currentString = data[ 0 ];
		char latestCharacters[ 4 ] = { currentString[ 0 ], currentString[ 0 ], currentString[ 0 ],currentString[ 0 ] };
		for(  int i = 1; i < currentString.length(); ++i )
		{
			for( int j = 3; j > 0; --j )
			{
				latestCharacters[ j ] = latestCharacters[ j - 1 ];
			}
			latestCharacters[ 0 ] = currentString[ i ];

			bool allDifferent = true;
			for( int j = 0; j < 4; ++j )
			{
				for( int k = j + 1; k < 4; ++k )
				{
					allDifferent &= latestCharacters[ j ] != latestCharacters[ k ];
				}
			}

			if( allDifferent )
			{
				return i + 1;
			}
		}

		return 0;
	}

	uint64_t day5part2( const std::vector<std::string>& data )
	{
		const auto& currentString = data[ 0 ];
		char newCharacter = currentString[ 0 ];

		int alphabetCounter[ 26 ] = { 0 };
		alphabetCounter[ newCharacter - 'a' ] += 1;

		for( int i = 1; i < currentString.length(); ++i )
		{
			if( i > 13 )
			{
				char lastCharacter = currentString[ i - 14 ];
				alphabetCounter[ lastCharacter - 'a' ] -= 1;
			}
			
			newCharacter = currentString[ i ];
			alphabetCounter[ newCharacter - 'a' ] += 1;

			int sum = 0;

			for( int j = 0; j < 26; ++j )
			{
				if( alphabetCounter[ j ] & 0xFFFFFFE )
					break;
				sum += alphabetCounter[j];
				
			}
			
			if( sum == 14 )
			{
				return i + 1;
			}
		}

		return 0;
	}
}