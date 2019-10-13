#pragma once

class Renderer {
public:
	Renderer(bool renderer2D, bool renderer3D, bool rendererUI);
	~Renderer();

	// std::unique_ptr<Renderer2D> renderer2D;
	// std::unique_ptr<Renderer3D> renderer3D;
	// std::unique_ptr<RendererUI> rendererUI;

	void renderAll();
	
private:
	
};