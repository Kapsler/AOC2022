#pragma once


namespace day2
{
	constexpr uint64_t part1Outcomes[] =
	{
		1 + 3,	//ROCK_ROCK,
		2 + 6,	//ROCK_PAPER,
		3 + 0,	//ROCK_SCISSOR,
		1 + 0,	//PAPER_ROCK,
		2 + 3,	//PAPER_PAPER,
		3 + 6,	//PAPER_SCISSOR,
		1 + 6,	//SCISSOR_ROCK,
		2 + 0,	//SCISSOR_PAPER,
		3 + 3	//SCIZZOR_SCISSOR
	};

	constexpr uint64_t part2Outcomes[] =
	{
		3 + 0,	//ROCK_LOSE(SCISSOR),
		1 + 3,	//ROCK_DRAW(ROCK),
		2 + 6,	//ROCK_WIN(PAPER),
		1 + 0,	//PAPER_LOSE(ROCK),
		2 + 3,	//PAPER_DRAW(PAPER),
		3 + 6,	//PAPER_WIN(SCISSOR),
		2 + 0,	//SCISSOR_LOSE(PAPER),
		3 + 3,	//SCISSOR_DRAW(SCISSOR),
		1 + 6	//SCIZZOR_WIN(ROCK),
	};

	__forceinline int calculateComboIndex( const std::string& round )
	{
		return ( ( round[ 0 ] - 'A' ) * 3 ) + ( round[ 2 ] - 'X' );
	}

	uint64_t day2part1( const std::vector< std::string >& data )
	{
		uint64_t sum = 0;
		for( const auto& round : data )
		{
			const auto& comboIndex = calculateComboIndex( round );
			sum += part1Outcomes[ comboIndex ];
		}

		return sum;
	}

	uint64_t day2part2( const std::vector< std::string >& data )
	{
		uint64_t sum = 0;
		for( const auto& round : data )
		{
			const auto& comboIndex = calculateComboIndex( round );
			sum += part2Outcomes[ comboIndex ];
		}

		return sum;
	}
}
