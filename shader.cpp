#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "shader.h"

Shader::Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath) {
	{
		std::string vertexShaderSource;
		std::string fragmentShaderSource;
		try {
			std::ifstream vertexShaderFile(vertexShaderPath);
			std::ifstream fragmentShaderFile(fragmentShaderPath);
			std::stringstream vertexShaderStream; vertexShaderStream << vertexShaderFile.rdbuf();
			std::stringstream fragmentShaderStream; fragmentShaderStream << fragmentShaderFile.rdbuf();
			vertexShaderSource = vertexShaderStream.str();
			fragmentShaderSource = fragmentShaderStream.str();
		}
		catch (std::ifstream::failure e) {
			std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ" << std::endl;
		}

		GLuint vertexShader;
		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		auto pVertexShaderSource = vertexShaderSource.c_str();
		glShaderSource(vertexShader, 1, &pVertexShaderSource, NULL);
		glCompileShader(vertexShader);

		GLint success;
		constexpr int lengthLog = 512;
		char infoLog[lengthLog];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(vertexShader, lengthLog, NULL, infoLog);
			std::cout
				<< "ERROR in vertexShader:" << std::endl
				<< infoLog << std::endl;
		}
		GLuint fragmentShader;
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		auto pFragmentShaderSource = fragmentShaderSource.c_str();
		glShaderSource(fragmentShader, 1, &pFragmentShaderSource, NULL);
		glCompileShader(fragmentShader);
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(fragmentShader, lengthLog, NULL, infoLog);
			std::cout
				<< "ERROR in fragmentShader:" << std::endl
				<< infoLog << std::endl;
		}
		shaderProgram = glCreateProgram();
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);
		glLinkProgram(shaderProgram);
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(shaderProgram, lengthLog, NULL, infoLog);
			std::cout << "ERROR in shader program:" << std::endl
				<< infoLog << std::endl;
		}
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}
}


Shader::~Shader() {
	glDeleteProgram(this->shaderProgram);
}

void Shader::use() {
	glUseProgram(this->shaderProgram);
}

void Shader::setBool(const std::string& name, bool value) {
	glUniform1i(
		glGetUniformLocation(shaderProgram, name.c_str()),
		static_cast<int>(value)
	);
}

void Shader::setInt(const std::string& name, GLint value) {
	glUniform1i(
		glGetUniformLocation(shaderProgram, name.c_str()),
		value
	);
}

void Shader::setFloat(const std::string& name, GLfloat value) {
	glUniform1f(
		glGetUniformLocation(shaderProgram, name.c_str()),
		value
	);
}
