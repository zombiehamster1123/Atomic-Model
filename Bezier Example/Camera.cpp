#include "Camera.h"

Camera* Camera::instance = nullptr;
Camera* Camera::GetInstance()
{
	if(instance == nullptr)
		instance = new Camera();

	return instance;
}

Camera::Camera()
{
	position = glm::vec3(0, 0, 2);
	horizontalAngle = PI;
	verticalAngle = 0.0f;
	initalFoV = 45.0f;

	speed = 3.0f;
	mouseSpeed = 0.005f;
}


Camera::~Camera()
{
}

glm::mat4 Camera::getViewMatrix() { return ViewMatrix; }
glm::mat4 Camera::getProjectionMatrix() { return ProjectionMatrix; }
glm::vec3 Camera::GetPosition() { return position; }
glm::vec3 Camera::Getdirection()
{
	return glm::vec3(
		cos(verticalAngle) * sin(horizontalAngle), 
		sin(verticalAngle),
		cos(verticalAngle) * cos(horizontalAngle)
		);
}

void Camera::ComputeMatrices()
{
	// glfwGetTime is called only once, the first time this function is called
	static double lastTime = glfwGetTime();

	// Compute time difference between current and last frame
	double currentTime = glfwGetTime();
	float deltaTime = float(currentTime - lastTime);

	if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
	{
		// Get mouse position
		double xpos, ypos;
		glfwGetCursorPos( window, &xpos, &ypos);

		// Reset mouse position for next frame
		glfwSetCursorPos(window, WINDOW_WIDTH/2, WINDOW_HEIGHT/2);

		// Compute new orientation
		horizontalAngle += mouseSpeed * float( WINDOW_WIDTH/2 - xpos );
		verticalAngle   += mouseSpeed * float( WINDOW_HEIGHT/2 - ypos );
	}

	// Get mouse position
	//double xpos, ypos;
	//glfwGetCursorPos( window, &xpos, &ypos);

	//// Reset mouse position for next frame
	//glfwSetCursorPos(window, WINDOW_WIDTH/2, WINDOW_HEIGHT/2);

	//// Compute new orientation
	//horizontalAngle += mouseSpeed * float( WINDOW_WIDTH/2 - xpos );
	//verticalAngle   += mouseSpeed * float( WINDOW_HEIGHT/2 - ypos );


	///////////////////////////////////////////////////////////////////
	///////		Personal Change - Make it so Aiming doesn't flip over

	// Cap Verticle angle
	if( verticalAngle >= PI/2.0f )
	{
		verticalAngle = PI/2.0f;
	}
	else if( verticalAngle <= -PI/2.0f )
	{
		verticalAngle = -PI/2.0f;
	}

	// Direction : Spherical coordinates to Cartesian coordinates conversion
	glm::vec3 direction(
		cos(verticalAngle) * sin(horizontalAngle), 
		sin(verticalAngle),
		cos(verticalAngle) * cos(horizontalAngle)
	);
	
	// Right vector
	glm::vec3 right = glm::vec3(
		sin(horizontalAngle - PI/2.0f), 
		0,
		cos(horizontalAngle - PI/2.0f)
	);
	
	// Up vector
	glm::vec3 up = glm::cross( right, direction );

	// Move forward
	if (glfwGetKey( window, GLFW_KEY_W ) == GLFW_PRESS){
		position += direction * deltaTime * speed;
	}
	// Move backward
	if (glfwGetKey( window, GLFW_KEY_S ) == GLFW_PRESS){
		position -= direction * deltaTime * speed;
	}
	// Strafe right
	if (glfwGetKey( window, GLFW_KEY_D ) == GLFW_PRESS){
		position += right * deltaTime * speed;
	}
	// Strafe left
	if (glfwGetKey( window, GLFW_KEY_A ) == GLFW_PRESS){
		position -= right * deltaTime * speed;
	}

	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS){
		position = glm::vec3(0, 0, 2);
		horizontalAngle = PI;
		verticalAngle = 0.0f;
		initalFoV = 45.0f;
	}

	float FoV = 45.0;

	// Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	ProjectionMatrix = glm::perspective(FoV, 4.0f / 3.0f, 0.00001f, 100.0f);
	// Camera matrix
	ViewMatrix       = glm::lookAt(
								position,           // Camera is here
								position+direction, // and looks here : at the same position, plus "direction"
								up                  // Head is up (set to 0,-1,0 to look upside-down)
						   );

	// For the next frame, the "last time" will be "now"
	lastTime = currentTime;
}
