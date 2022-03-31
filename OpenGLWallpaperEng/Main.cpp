#include <glad/glad.h>
#include <GLFW/glfw3.h>
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>
#include <iostream>
#include <chrono>
#include <cmath>
#include <Windows.h>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <random>
#include <thread>

#include "PerfTimer.h"


int main(int argc, char* argv[])
{
	while(true)
	{
		PerfTimer<std::chrono::milliseconds> v1("first");
		int a = 1;
		while (a < 10000000)
		{

			a++;

		}
	}
	
	//std::cout << a;
	std::cin.get();

	return 0;
}
