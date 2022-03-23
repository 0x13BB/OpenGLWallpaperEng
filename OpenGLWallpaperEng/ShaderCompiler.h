#pragma once

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <glad/glad.h>


class ShaderCompiler {

public:
	static int load_shader(std::string frag_shader_file_path, std::string vert_shader_file_path);


};