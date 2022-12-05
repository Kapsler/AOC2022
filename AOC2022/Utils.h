#pragma once

#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

namespace Utils
{
	static void ReadFile( std::filesystem::path fileToRead, std::vector<std::string>& lines )
	{
		std::filesystem::path completePath( std::filesystem::current_path().string() + "/../" + fileToRead.string());

		if( std::filesystem::exists( completePath ) )
		{
			std::ifstream stream( completePath );

			std::string line;
			while( std::getline( stream, line ) )
			{
				lines.emplace_back( std::move(line) );
			}
		}
		else
		{
			printf( "File %s does not exist!\n", completePath.string().c_str() );
		}
	}

	static void ConvertStringsToInts( const std::vector<std::string>& inputs, std::vector< int32_t >& outputs, int32_t emptyStringInt = -1 )
	{
		outputs.reserve( inputs.size() );
		for( const auto& line : inputs )
		{
			if( line.empty() )
			{
				outputs.emplace_back( emptyStringInt );
			}
			else
			{
				outputs.emplace_back( std::stoi( line ) );
			}
		}
	}
}