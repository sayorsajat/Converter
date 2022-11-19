#include <iostream>
#include <string>
#include "conversion.h"
#include "strategy.h"

int main() {
	Converter converter;
	
	int choice=0;
	std::cout << "1. from ten base to n base" << std::endl
			  << "2. from n base to ten base" << std::endl
			  << "3. from n base to n base" << std::endl;
	std::cin >> choice;
	
	
	switch (choice) 
	{
		case 1:
			{
				Context *context = new Context();
				FromTenToNStrategy *concreteStrat1 = new FromTenToNStrategy();
				context->SetStrategy(concreteStrat1);
				context->DispatchAction();
				break;
			}
		case 2:
			{
				Context *context = new Context();
				FromNToTenStrategy *concreteStrat2 = new FromNToTenStrategy();
				context->SetStrategy(concreteStrat2);
				context->DispatchAction();
				break;
			}
		case 3:
			{
				Context *context = new Context();
				FromNToNStrategy *concreteStrat3 = new FromNToNStrategy();
				context->SetStrategy(concreteStrat3);
				context->DispatchAction();
				break;
			}
		default:
			std::cout << "not availaible choice" << std::endl;
			return 1;
	}
	
	return 0;
}