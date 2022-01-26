#ifndef _PRACTICE_GL_CAMERA_H
#define _PRACTICE_GL_CAMERA_H

#include <memory>
#include <glad/glad.h>
#include "glm/glm.hpp"
#include "privdef.h"

constexpr int zero = 0;

class Camera {
private:
	static constexpr float PITCH_MAX = 89.0f;
	static constexpr float PITCH_MIN = 89.0f;
	static inline int count_ = 0;
	glm::vec3 cameraPos_;
	glm::vec3 cameraFront_;
	float fov_deg_;
	
public:
	Camera(const glm::vec3& pos, float pitch, float yaw);

	std::unique_ptr<Camera> Create(const glm::vec3& pos = glm::vec3(0.0f, 1.0f, 0.0f), float pitch = 0.0f, float yaw = 90.0f);
	
	void MoveTo(const glm::vec3& pos, float pitch, float yaw);
};

#endif // !_PRACTICE_GL_CAMERA_H
