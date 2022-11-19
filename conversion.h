#ifndef CONVERSION_H
#define CONVERSION_H
#include <string>
#include <cmath>

class Converter {
	public:
		Converter() {
		};
		
		int fromNBasedToTenBased(std::string number, int baseOfSystem) {
			int length = number.length();
			int cursor, result;
		
			for (int i = 0; i < length; i++)
			{
				cursor = number[length - i - 1] - 48;
		
				if (cursor > 9)
				{
					cursor -= 7;
				}
		
				result += cursor * std::pow(baseOfSystem, i);
			}
		
			return result;
		};
		
		std::string fromTenBasedToNBased(int decimal, int baseOfSystem) {
			std::string result;
			std::string modValue;
			while (decimal != 0) {
				int buff = (decimal%baseOfSystem);
				modValue = char(buff + '0');
				if(buff >= 10) {
					modValue = char(buff) + 55;
				}
				result.insert(0, modValue);
				decimal = (decimal/baseOfSystem);
			}
			
			return result;
		};
};

#endif
