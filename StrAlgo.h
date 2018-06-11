#pragma once
#include <string>
#include <vector>
#include <sstream>
namespace yxp_utility
{
	class StrAlgo
	{
	public:
		static void Split(const std::string src, char delim,std::vector<std::string>& v);
		static std::vector<std::string> StrAlgo::Split(const std::string src, char delim);
		static std::vector<std::string> StrAlgo::Split2(const std::string src, char delim);
			
	};
}




