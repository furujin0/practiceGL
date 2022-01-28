#include <algorithm>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "camera.h"

Camera::Camera(const glm::vec3& pos, float pitch, float yaw):
	pos(pos),
	pitch(pitch),
	yaw(yaw),
	fov_deg(45.0f)
{
	count_++;
	return;
}


std::unique_ptr<Camera> Camera::create(const glm::vec3& pos, float pitch, float yaw) {
	return std::make_unique<Camera>(pos, pitch, yaw);
}

void Camera::moveTo(const glm::vec3& pos, float pitch, float yaw) {
	this->pos = pos;
	this->pitch = std::clamp(pitch, PITCH_MIN, PITCH_MAX);
	this->yaw = yaw;
	return;
}


glm::vec3 Camera::front() const {
	return glm::normalize(
		glm::vec3(
			std::cosf(glm::radians(yaw)) * cosf(glm::radians(pitch)),
			std::sinf(glm::radians(pitch)),
			std::sinf(glm::radians(yaw)) * cosf(glm::radians(pitch))
		)
	);
}

glm::vec3 Camera::up() const {
	return glm::vec3(0.0f, 1.0f, 0.0f);
}

glm::mat4 Camera::viewMatrix() const {
	return glm::lookAt(pos, pos + this->front(), this->up());
}


