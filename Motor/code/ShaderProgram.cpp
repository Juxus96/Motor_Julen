#include "ModelComponent.hpp"
#include <iostream>

namespace Zynkro
{
	const std::string ShaderProgram::vertexShaderSource =
		"#version 330 core\n"
		"layout(location = 0) in vec3 aPos;"
		"layout(location = 1) in vec3 aColor;"
		"layout(location = 2) in vec2 aTexCoord;"
		""
		"out vec3 ourColor;"
		"out vec2 TexCoord;"
		""
		"void main()"
		"{"
		"	gl_Position = vec4(aPos, 1.0);"
		"	ourColor = aColor;"
		"	TexCoord = aTexCoord;"
		"}";
	const std::string ShaderProgram::fragmentShaderSource =
		"#version 330 core\n"
		"out vec4 FragColor;"
		""
		"in vec3 ourColor;"
		"in vec2 TexCoord;"
		""
		"uniform sampler2D ourTexture;"
		""
		"void main()"
		"{"
		"	FragColor = texture(ourTexture, TexCoord);"
		"}";
	ShaderProgram::ShaderProgram()
	{
		CompileShader(vertexShaderSource, fragmentShaderSource);
	}
	ShaderProgram::~ShaderProgram()
	{
	}

	void ShaderProgram::CompileShader(const std::string & vertex_shader_code, const std::string & fragment_shader_code)
	{
		GLint succeeded = GL_FALSE;
		char infoLog[512];

		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
		unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		const char *  vertex_shaders_code[] = { vertex_shader_code.c_str() };
		const char * fragment_shaders_code[] = { fragment_shader_code.c_str() };

		glShaderSource(vertexShader, 1, vertex_shaders_code, NULL);
		glShaderSource(fragmentShader, 1, fragment_shaders_code, NULL);

		glCompileShader(vertexShader);
		glCompileShader(fragmentShader);


		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &succeeded);
		if (!succeeded) {
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		}

		shaderProgram = glCreateProgram();
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);
		glLinkProgram(shaderProgram);
		glUseProgram(shaderProgram);
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

	}
}


