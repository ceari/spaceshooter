/*
 * OpenGLRenderer.h
 *
 *  Created on: Mar 24, 2009
 *      Author: daniel
 */

#ifndef OPENGLRENDERER_H_
#define OPENGLRENDERER_H_

#include "includes.h"

#include "OpenGLTexture.h"
#include "../ParticleSystem.h"
#include "../Particle.h"
#include "../Renderer.h"
#include "../Math/Vec3.h"
#include "../Math/Rect.h"
#include "../Light.h"

namespace DFXEngine
{

	class OpenGLRenderer: public Renderer
	{
	protected:
		Vec3 mCameraPosition;
		Vec3 mCameraLookAt;
		int mWidth, mHeight;
		bool mInitialized;
	public:
		OpenGLRenderer();
		virtual ~OpenGLRenderer();

		// Renderer interface implementations

		bool initialize(int width, int height);
		void bindTexture(const Texture* texture);
		void unbindTexture();
		void enableLight(Light* light);
		void updateLight(Light* light);
		void enableLighting();
		void disableLighting();

		// virtual void enableMaterial();
		void enableTexturing();
		void disableTexturing();

		void renderTexturedQuad(Vec3 coords, Vec3 rotation, Texture* texture, Rect texture_coords, double height, double width);
		void renderTexturedQuad(Vec3 coords, Vec3 rotation, Texture* texture);
		void renderTexturedQuad(Vec3 coords, Vec3 rotation, Texture* texture, double scale);
		void renderQuad(Vec3 coords, Vec3 rotation, double height, double width);
		void renderColoredQuad(Vec3 coords, Vec3 rotation, double height, double width, float r, float g, float b, float a);
		void renderParticleSystem(const ParticleSystem& system) ;

		void renderTexturedSphere(Vec3 coords, Vec3 rotation, double radius, double slices, Texture* texture);
		void renderSphere(Vec3 coords, Vec3 rotation, double radius, double slices);

		void renderText(string filename, string text, int size, Vec3 coords, float r, float g, float b);

		void setCameraPosition(Vec3 position);
		Vec3 getCameraPosition() const;
		void setCameraLookAt(Vec3 vec);
		Vec3 getCameraLookAt() const;
		void moveCamera(Vec3 vec);

		void beginRender();
		void finishRender();

		// OpenGL specific helper functions

		void enableGLLight(Light* light, int GLLightID);
		void updateGLLight(Light* light, int GLLightID);
	};
}

#endif /* OPENGLRENDERER_H_ */
