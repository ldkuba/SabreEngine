#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>


class Camera {
public:
	Camera();

	void setPosition(glm::vec3 pos);
	void setDirection(glm::vec3 dir);

	inline glm::mat4 getViewMatrix() { return m_ViewMatrix; };
	inline glm::vec3 getPosition() { return m_Position; };
	inline glm::vec3 getDirection() { return m_Direction; };

	glm::mat4 projectionMatrix;

private:

	glm::mat4 m_ViewMatrix;

	glm::vec3 m_Position;
	glm::vec3 m_Direction;
};