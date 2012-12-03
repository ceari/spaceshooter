/*
 * Renderer.h
 *
 * Renderer interface class
 *
 *  Created on: Mar 24, 2009
 *      Author: daniel
 */

#ifndef RENDERER_H_
#define RENDERER_H_

#include "Math/Vec3.h"
#include "Math/Rect.h"
#include "Light.h"
#include "Texture.h"



#include <vector>
#include <string>

namespace DFXEngine
{
	class ParticleSystem;

	class Renderer
	{
	public:
		virtual bool initialize(int width, int height) = 0;
		virtual void bindTexture(const Texture* texture) = 0;
		virtual void unbindTexture() = 0;
		virtual void enableLight(Light* light) = 0;
		virtual void updateLight(Light* light) = 0;
		virtual void enableLighting() = 0;
		virtual void disableLighting() = 0;

		// virtual void enableMaterial() = 0;
		virtual void enableTexturing() = 0;
		virtual void disableTexturing() = 0;

		virtual void renderTexturedQuad(Vec3 coords, Vec3 rotation, Texture* texture, Rect texture_coords, double height, double width) = 0;
		virtual void renderTexturedQuad(Vec3 coords, Vec3 rotation, Texture* texture) = 0;
		virtual void renderTexturedQuad(Vec3 coords, Vec3 rotation, Texture* texture, double scale) = 0;
		virtual void renderQuad(Vec3 coords, Vec3 rotation, double height, double width) = 0;
		virtual void renderColoredQuad(Vec3 coords, Vec3 rotation, double height, double width, float r, float g, float b, float a) = 0;

		virtual void renderParticleSystem(const ParticleSystem& system) = 0;

		virtual void renderTexturedSphere(Vec3 coords, Vec3 rotation, double radius, double slices, Texture* texture) = 0;
		virtual void renderSphere(Vec3 coords, Vec3 rotation, double radius, double slices) = 0;

		virtual void renderText(string filename, string text, int size, Vec3 coords, float r, float g, float b) = 0;

		virtual void beginRender() = 0;
		virtual void finishRender() = 0;

		virtual void setCameraPosition(Vec3 position) = 0;
		virtual Vec3 getCameraPosition() const = 0;
		virtual void setCameraLookAt(Vec3 vec) = 0;
		virtual Vec3 getCameraLookAt() const = 0;
		virtual void moveCamera(Vec3 vec) = 0;

		Renderer();
		virtual ~Renderer();
	};

}

#endif /* RENDERER_H_ */
