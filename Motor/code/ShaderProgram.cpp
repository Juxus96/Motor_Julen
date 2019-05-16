#include "ModelComponent.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
namespace Zynkro
{
	/*const std::string ShaderProgram::vertexShaderSource =
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
		"}";*/
	ShaderProgram::ShaderProgram(const char* vertexPath, const char* fragmentPath)
	{
		std::string vertexCode;
		std::string fragmentCode;
		std::ifstream vShaderFile;
		std::ifstream fShaderFile;
		// ensure ifstream objects can throw exceptions:
		vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		try
		{
			// open files
			vShaderFile.open(vertexPath);
			fShaderFile.open(fragmentPath);
			std::stringstream vShaderStream, fShaderStream;
			// read file's buffer contents into streams
			vShaderStream << vShaderFile.rdbuf();
			fShaderStream << fShaderFile.rdbuf();
			// close file handlers
			vShaderFile.close();
			fShaderFile.close();
			// convert stream into string
			vertexCode = vShaderStream.str();
			fragmentCode = fShaderStream.str();
		}
		catch (std::ifstream::failure e)
		{
			std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
		}
		//const char* vShaderCode = vertexCode.c_str();
		//const char* fShaderCode = fragmentCode.c_str();
		const char* vShaderCode =
			"#version 330 core\n"
			"layout(location = 0) in vec3 aPos;"
			"layout(location = 1) in vec3 aNormal;"
			"layout(location = 2) in vec2 aTexCoords;"
			""
			"out vec2 TexCoords;"
			""
			"uniform mat4 model;"
			"uniform mat4 view;"
			"uniform mat4 projection;"
			""
			"void main()"
			"{"
			"	TexCoords = aTexCoords;"
			"	gl_Position = projection * view * model * vec4(aPos, 1.0);"
			"}";
		const char* fShaderCode =
			"#version 330 core\n"
			"out vec4 FragColor;"
			""
			"in vec2 TexCoords;"
			""
			"uniform sampler2D texture_diffuse1;"
			""
			"void main()"
			"{"
			"	FragColor = texture(texture_diffuse1, TexCoords);"
			"}";
		CompileShader(vShaderCode, fShaderCode);
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
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &succeeded);
		if (!succeeded)
		{
			glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		}

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

	}
	void ShaderProgram::Use()
	{
		glUseProgram(shaderProgram);

	}
	void ShaderProgram::SetBool(const std::string & name, bool value) const
	{
		glUniform1i(glGetUniformLocation(shaderProgram, name.c_str()), (int)value);
	}
	void ShaderProgram::SetInt(const std::string & name, int value) const
	{
		glUniform1i(glGetUniformLocation(shaderProgram, name.c_str()), value);
	}
	void ShaderProgram::SetFloat(const std::string & name, float value) const
	{
		glUniform1f(glGetUniformLocation(shaderProgram, name.c_str()), value);
	}
	
}


