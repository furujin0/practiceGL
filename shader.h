#ifndef _PRACTICE_GL_SHADER_H
#define _PRACTICE_GL_SHADER_H

#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

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

};

#endif // !_PRACTICE_GL_SHADER_H