
#ifndef SHADERHEADER
#define SHADERHEADER


namespace Zynkro
{
	class ShaderProgram
	{
	public:
		unsigned int shaderProgram;

	public:
		ShaderProgram(const char* vertexPath, const char* fragmentPath);
		~ShaderProgram();

		void CompileShader(const std::string & vertex_shader_code, const std::string & fragment_shader_code);
		void Use();
		// utility uniform functions
		void SetBool(const std::string &name, bool value) const;
		void SetInt(const std::string &name, int value) const;
		void SetFloat(const std::string &name, float value) const;
	};

	

	

}
#endif