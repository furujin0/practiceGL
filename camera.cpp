#include "camera.h"

Camera::Camera(const glm::vec3& pos, float pitch, float yaw):
cameraPos_(pos),
fov_deg_(45.0f)
{
	cameraFront_ 
		= glm::normalize(
			glm::vec3(
				std::cosf(glm::radians(yaw)) * cosf(glm::radians(pitch)),
				std::sinf(glm::radians(pitch)),
				std::sinf(glm::radians(yaw)) * cosf(glm::radians(pitch))
			)
		);
}

std::unique_ptr<Camera> Camera::Create(const glm::vec3& pos, float pitch, float yaw) {
	return std::make_unique<Camera>(pos, pitch, yaw);
}


