#include "ShaderCompiler.h"


int ShaderCompiler::load_shader(std::string frag_shader_file_path, std::string vert_shader_file_path)
{
    std::ifstream f(frag_shader_file_path);
    std::stringstream file_buffer;
    file_buffer << f.rdbuf();
    auto file_content_frag = file_buffer.str();
    std::cout << file_content_frag << std::endl << std::endl;
    f.close();
    file_buffer.str("");

    f.open(vert_shader_file_path);
    file_buffer << f.rdbuf();
    auto file_content_vert = file_buffer.str();
    std::cout << file_content_vert << std::endl;
    f.close();


    const char* vertexShaderSource = file_content_vert.c_str();

    const char* fragmentShaderSource = file_content_frag.c_str();

    // Компилирование нашей шейдерной программы

   // Вершинный шейдер
    int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    // Проверка на наличие ошибок компилирования вершинного шейдера
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        std::cin.get();
    }

    // Фрагментный шейдер
    int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    // Проверка на наличие ошибок компилирования фрагментного шейдера
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        std::cin.get();
    }

    // Связывание шейдеров
    int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // Проверка на наличие ошибок связывания шейдеров
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        std::cin.get();
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);






    return shaderProgram;
}

