#pragma once


namespace day2
{
	enum class RoundCombo : uint64_t
	{
		ROCK_ROCK,
		ROCK_PAPER,
		ROCK_SCISSOR,
		PAPER_ROCK,
		PAPER_PAPER,
		PAPER_SCISSOR,
		SCISSOR_ROCK,
		SCISSOR_PAPER,
		SCIZZOR_SCISSOR
	};

	constexpr uint64_t part1Outcomes[] =
	{
		1+3,	//ROCK_ROCK,
		2+6,	//ROCK_PAPER,
		3+0,	//ROCK_SCISSOR,
		1+0,	//PAPER_ROCK,
		2+3,	//PAPER_PAPER,
		3+6,	//PAPER_SCISSOR,
		1+6,	//SCISSOR_ROCK,
		2+0,	//SCISSOR_PAPER,
		3+3		//SCIZZOR_SCISSOR
	};

	__forceinline RoundCombo convertToCombo( const std::string& roundString )
	{
		uint64_t roundInt = 0;

		roundInt += (roundString[ 0 ] - 'A') * 3;
		roundInt += roundString[ 2 ] - 'X';

		return static_cast< RoundCombo >( roundInt );
	}

	uint64_t day2part1( const std::vector< std::string >& data )
	{
		uint64_t sum = 0;
		for( const auto& round : data )
		{
			const auto& combo = convertToCombo( round );
			sum += part1Outcomes[ static_cast< uint64_t >( combo ) ];
		}

		return sum;
	}

	uint64_t day2part2( const std::vector< std::string >& data )
	{
	
	}
}
