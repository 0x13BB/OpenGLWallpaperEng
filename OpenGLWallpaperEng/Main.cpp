#include "stdafx.h"
#define GLFW_EXPOSE_NATIVE_WIN32
#include "PerfTimer.h"



int main(int argc, char* argv[])
{
	int a = 1;
	while (a < 5)
	{
		PerfTimer<std::chrono::milliseconds> v1("first");

		a++;
	}


	//std::cout << a;
	std::cin.get();

	return 0;
}
