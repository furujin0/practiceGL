#ifndef _PRACTICE_GL_SHADER_H
#define _PRACTICE_GL_SHADER_H

#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Eigen/Geometry>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader {

private:
	GLuint shaderProgram;

public:
	Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);

	~Shader();

	void use();

	void setBool(const std::string& name, bool value);

	void setInt(const std::string& name, GLint value);

	void setFloat(const std::string& name, GLfloat value);
	
	void setMatrix4f(const std::string& name, const glm::mat4& mat);
};

#endif // !_PRACTICE_GL_SHADER_H