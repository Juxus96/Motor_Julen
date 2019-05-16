
#ifndef CAMERACOMPONENTHEADER
#define CAMERACOMPONENTHEADER



namespace Zynkro
{
	class CameraComponent : public Component
	{
	
		
	public:
		CameraComponent(std::string modelPath, const char* vertexPath, const char* fragmentPath);
		~CameraComponent();


	};

	

	

}
#endif