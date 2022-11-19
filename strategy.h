#ifndef STRATEGY_H
#define STRATEGY_H
#include <string>
#include <iostream>
#include "conversion.h"

Converter converter;

class Strategy {
	public:
		virtual void doConversion() {
		};
};

class FromNToTenStrategy: public Strategy {
	public:
		void doConversion() {
			std::string number;
			int baseOfSystem;
			
			std::cout << "enter any base number:" << std::endl;
			std::cin >> number;
			std::cout << "enter base of system of that number:" << std::endl;
			std::cin >> baseOfSystem;
			
			int result = converter.fromNBasedToTenBased(number, baseOfSystem);
			std::cout << result << std::endl;
		};
};

class FromTenToNStrategy: public Strategy {
	public:
		void doConversion() {
			int decimal;
			int baseOfSystem;
			
			std::cout << "enter ten base number:" << std::endl;
			std::cin >> decimal;
			std::cout << "enter base of destination system:" << std::endl;
			std::cin >> baseOfSystem;
			
			std::string result = converter.fromTenBasedToNBased(decimal, baseOfSystem);
			std::cout << result << std::endl;
		}
};

class FromNToNStrategy: public Strategy {
	public:
		void doConversion() {
			std::string number;
			int baseOfSrcSystem;
			int baseOfDestSystem;
			
			std::cout << "enter any base number:" << std::endl;
			std::cin >> number;
			std::cout << "enter base of system of that number:" << std::endl;
			std::cin >> baseOfSrcSystem;
			std::cout << "enter base of destination system:" << std::endl;
			std::cin >> baseOfDestSystem;
			
			int decimal = converter.fromNBasedToTenBased(number, baseOfSrcSystem);
			std::string result = converter.fromTenBasedToNBased(decimal, baseOfDestSystem);
			std::cout << result << std::endl;
		}
};

class Context {
	private:
		Strategy *strategy;
	public:
		void SetStrategy(Strategy *obj) {
			strategy = obj;
		}
		
		Strategy *GetStrategy() {
			return strategy;
		}
		
		void DispatchAction() {
			strategy->doConversion();
		}
};

#endif
