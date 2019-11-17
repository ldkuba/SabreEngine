#include "Camera.h"

Camera::Camera()
{
	m_Position = glm::vec3(0, 0, -1.0f);
	m_Direction = glm::vec3(0, 0, 1.0f);

	m_ViewMatrix = glm::lookAt(m_Position, m_Position + m_Direction, glm::vec3(0, 1.0f, 0));

	projectionMatrix = glm::mat4();
}

void Camera::setPosition(glm::vec3 pos)
{
	m_Position = pos;

	// Recalculate view matrix
	m_ViewMatrix = glm::lookAt(m_Position, m_Position + m_Direction, glm::vec3(0, 1.0f, 0));
}

void Camera::setDirection(glm::vec3 dir)
{
	m_Direction = glm::normalize(dir);

	// Recalculate view matrix
	m_ViewMatrix = glm::lookAt(m_Position, m_Position + m_Direction, glm::vec3(0, 1.0f, 0));
}