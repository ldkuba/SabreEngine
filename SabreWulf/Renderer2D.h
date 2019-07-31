#pragma once
#include "Renderer.h"

class Renderer2D : public Renderer {
private:
	const int MAX_SPRITES = 10000;
	const int MAX_VERTS = MAX_SPRITES * 4;
	const int MAX_INDEX = MAX_SPRITES * 6;

	const int MAX_TEXTURES = 32;

	Camera m_CurrentCamera;

	VertexArray m_VertexArray;
	VertexBuffer m_VertexBuffer;
	IndexBuffer m_IndexBuffer;

	

};