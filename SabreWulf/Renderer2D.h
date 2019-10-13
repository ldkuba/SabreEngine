#pragma once

class Renderer2D {
public:
	Renderer2D();
	~Renderer2D();

	void begin();
	void submit(Renderable2D& renderable);
	void render();

private:
	VertexBuffer m_VertexBuffer;
	IndexBuffer m_IndexBuffer;
	VertexArray m_VertexArray;
	ShaderProgram m_ShaderProgram;
	
};