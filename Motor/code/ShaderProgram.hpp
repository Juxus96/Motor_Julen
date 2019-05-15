
#ifndef SHADERHEADER
#define SHADERHEADER


namespace Zynkro
{
	class ShaderProgram
	{
	public:
		unsigned int shaderProgram;
	private:
		static const std::string vertexShaderSource;
		static const std::string fragmentShaderSource;

	public:
		ShaderProgram();
		~ShaderProgram();

		void CompileShader(const std::string & vertex_shader_code, const std::string & fragment_shader_code);

	};

	

	

}
#endif