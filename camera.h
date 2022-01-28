#ifndef _PRACTICE_GL_CAMERA_H
#define _PRACTICE_GL_CAMERA_H

#include <memory>
#include <glad/glad.h>
#include "glm/glm.hpp"
#include "privdef.h"

class Camera {
private:
	static constexpr float PITCH_MAX = 89.0f;
	static constexpr float PITCH_MIN = -89.0f;
	static inline int count_ = 0;
	
public:
	float pitch, yaw;
	glm::vec3 pos;
	float fov_deg;
	float speed = 0.1f;

	Camera(const glm::vec3& pos, float pitch, float yaw);

	static std::unique_ptr<Camera> create(const glm::vec3& pos = glm::vec3(0.0f, 1.0f, 0.0f), float pitch = 0.0f, float yaw = 90.0f);
	
	void moveTo(const glm::vec3& pos, float pitch, float yaw);
	
	glm::vec3 front() const;

	glm::vec3 up() const;

	glm::mat4 viewMatrix() const;
};

#endif // !_PRACTICE_GL_CAMERA_H
