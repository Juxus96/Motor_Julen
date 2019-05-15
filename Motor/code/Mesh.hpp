
#ifndef MESHHEADER
#define MESHHEADER


namespace Zynkro
{
	class Mesh
	{
	public:
		static const float vertices[];
		unsigned int VBO;
		unsigned int VAO; 
		unsigned int EBO;

	public:
		Mesh();
		~Mesh();
	};

	

	

}
#endif