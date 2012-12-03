/*
 * OpenGLRenderer.cpp
 *
 *  Created on: Mar 24, 2009
 *      Author: daniel
 */

#include "OpenGLRenderer.h"

namespace DFXEngine
{

	OpenGLRenderer::OpenGLRenderer()
	{
		mInitialized = false;
		mWidth = mHeight = 0;
	}

	OpenGLRenderer::~OpenGLRenderer()
	{

	}

	bool OpenGLRenderer::initialize(int width, int height)
	{
		if (TTF_Init())
		{
	#ifdef DEBUG
			Debug::Instance()->writeLn("OpenGLRenderer::initialize - TTF_Init() failed");
	#endif
			return false;
		}

		glEnable(GL_COLOR_MATERIAL);
		glDepthFunc(GL_LEQUAL);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_CULL_FACE);
		glClearColor( 0.0, 0.0, 0.0, 1.0 );
		glEnable(GL_DEPTH_TEST);

		glShadeModel(GL_SMOOTH);

		/*glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);	// Really Nice Perspective Calculations
		glHint(GL_POINT_SMOOTH_HINT,GL_NICEST);				// Really Nice Point Smoothing
		glEnable(GL_LINE_SMOOTH);
		glEnable(GL_POLYGON_SMOOTH);
		glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
		glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);*/

		SDL_GL_SetAttribute( SDL_GL_RED_SIZE,	8 );
		SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE,	8 );
		SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE,	8 );
		SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE,	16 );
		SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

		/*
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, w, h, 0, -100, 100);
		*/

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45.0f, (float)width/(float)height, 10, 10000000);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		mInitialized = true;
		Debug::Instance()->writeLn("OpenGLRenderer::initialize - successfully initialized");
		return true;
	}

	void OpenGLRenderer::bindTexture(const Texture *texture)
	{
		const OpenGLTexture* tex = static_cast<const OpenGLTexture*>(texture);	// static cast to OpenGLTexture since that's what should be used with this OpenGL renderer
		glBindTexture(GL_TEXTURE_2D, tex->getGLTexturePtr());
	}

	void OpenGLRenderer::unbindTexture()
	{
		glBindTexture(GL_TEXTURE_2D, NULL);
	}

	void OpenGLRenderer::enableLight(Light* light)
	{
		enableGLLight(light, GL_LIGHT0 + light->getId());
	}

	void OpenGLRenderer::updateLight(Light* light)
	{
		if (light->getActive()) {
			updateGLLight(light, GL_LIGHT0 + light->getId());
		}
		else {
			glDisable(GL_LIGHT0 + light->getId());
		}
	}

	void OpenGLRenderer::enableGLLight(Light* light, int GLLightID)
	{
		glEnable(GLLightID);
	}

	void OpenGLRenderer::updateGLLight(Light* light, int GLLightID)
	{
		GLfloat ambientLight[]= {light->getAmbient().r, light->getAmbient().g, light->getAmbient().b, light->getAmbient().a};
		glLightfv(GLLightID, GL_AMBIENT, ambientLight);

		GLfloat diffuseLight[]={light->getDiffuse().r, light->getDiffuse().g, light->getDiffuse().b, light->getDiffuse().a};
		glLightfv(GLLightID, GL_DIFFUSE, diffuseLight);

		GLfloat lightPos[]= {light->getPosition().x, light->getPosition().y, light->getPosition().z, 1};
		glLightfv(GLLightID, GL_POSITION, lightPos);
	}

	void OpenGLRenderer::enableLighting()
	{
		glEnable(GL_LIGHTING);
		GLfloat ambientLight[]= {0.1, 0.1, 0.1, 1};
		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
		glEnable(GL_COLOR_MATERIAL);
	}

	void OpenGLRenderer::disableLighting()
	{
		glDisable(GL_LIGHTING);
	}

	/**
	 * Renders a simple textured quad
	 * @param coords world coordinates of the quad
	 * @param rotation rotation angles around the 3 axes
	 * @param texture
	 * @param scale scaling factor
	 */
	void OpenGLRenderer::renderTexturedQuad(Vec3 coords, Vec3 rotation, Texture *texture, double scale)
	{
		enableTexturing();
		bindTexture(texture);
		renderQuad(coords, rotation, texture->getHeight() * scale, texture->getWidth() * scale);
		unbindTexture();
		disableTexturing();
	}

	void OpenGLRenderer::renderParticleSystem(const ParticleSystem& system)
	{
		enableTexturing();
		bindTexture(system.getTexture());

		std::vector<Particle>::const_iterator it;
		float w = system.getTexture()->getWidth() / 2;
		float h = system.getTexture()->getHeight() / 2;

		glBlendFunc(GL_SRC_ALPHA, GL_ONE);

		glPushMatrix();
		glBegin(GL_QUADS);
		for (it = system.getParticles().begin(); it != system.getParticles().end(); it++)
		{
			if (it->mActive)
			{
				glColor4f(it->mRed, it->mGreen, it->mBlue, it->mLife);	// life specifies the alpha value

				glTexCoord2f(0, 0);	glVertex3f(it->mPosition.x + (-w), it->mPosition.y + (-h), it->mPosition.z);
				glTexCoord2f(0, 1);	glVertex3f(it->mPosition.x + (-w), it->mPosition.y + h, it->mPosition.z);
				glTexCoord2f(1, 1);	glVertex3f(it->mPosition.x + w, it->mPosition.y + h, it->mPosition.z);
				glTexCoord2f(1, 0);	glVertex3f(it->mPosition.x + w, it->mPosition.y + (-h), it->mPosition.z);
			}
		}
		glEnd();
		glPopMatrix();

		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		unbindTexture();
		disableTexturing();
	}

	void OpenGLRenderer::renderTexturedQuad(Vec3 coords, Vec3 rotation, Texture *texture, Rect texture_coords, double height, double width)
	{
		enableTexturing();
		bindTexture(texture);

		glColor4f(1,1,1,1);

		glPushMatrix();
		glTranslatef(coords.x, coords.y, coords.z);
		glRotatef(rotation.x, 1, 0, 0);
		glRotatef(rotation.y, 0, 1, 0);
		glRotatef(rotation.z, 0, 0, 1);

		glBegin(GL_QUADS);
			glTexCoord2f(texture_coords.x, texture_coords.y);	glVertex2f(-width/2, -height/2);
			glTexCoord2f(texture_coords.x, texture_coords.y + texture_coords.h);	glVertex2f(-width/2, height/2);
			glTexCoord2f(texture_coords.x + texture_coords.w, texture_coords.y + texture_coords.h);	glVertex2f(width/2, height/2);
			glTexCoord2f(texture_coords.x + texture_coords.w, texture_coords.y);	glVertex2f(width/2, -height/2);
		glEnd();

		glPopMatrix();

		unbindTexture();
		disableTexturing();
	}

	void OpenGLRenderer::renderTexturedQuad(Vec3 coords, Vec3 rotation, Texture* texture)
	{
		enableTexturing();
		bindTexture(texture);
		renderQuad(coords, rotation, texture->getHeight(), texture->getWidth());
		unbindTexture();
		disableTexturing();
	}

	void OpenGLRenderer::renderQuad(Vec3 coords, Vec3 rotation, double height, double width)
	{
		if (!mInitialized) return;

		double w = width / 2;
		double h = height / 2;

		glColor4f(1,1,1,1);

		glPushMatrix();
		glTranslatef(coords.x, coords.y, coords.z);
		glRotatef(rotation.x, 1, 0, 0);
		glRotatef(rotation.y, 0, 1, 0);
		glRotatef(rotation.z, 0, 0, 1);

		glBegin(GL_QUADS);
			glTexCoord2f(0, 0); glVertex2f(-w, -h);
			glTexCoord2f(0, 1);	glVertex2f(-w, h);
			glTexCoord2f(1, 1); glVertex2f(w, h);
			glTexCoord2f(1, 0);	glVertex2f(w, -h);
		glEnd();

		glPopMatrix();
	}

	void OpenGLRenderer::renderColoredQuad(Vec3 coords, Vec3 rotation, double height, double width, float r, float g, float b, float a)
	{
		if (!mInitialized) return;

		double w = width / 2;
		double h = height / 2;

		glColor4f(r, g, b, a);

		glPushMatrix();
		glTranslatef(coords.x, coords.y, coords.z);
		glRotatef(rotation.x, 1, 0, 0);
		glRotatef(rotation.y, 0, 1, 0);
		glRotatef(rotation.z, 0, 0, 1);

		glBegin(GL_QUADS);
			glTexCoord2f(0, 0); glVertex2f(-w, -h);
			glTexCoord2f(0, 1);	glVertex2f(-w, h);
			glTexCoord2f(1, 1); glVertex2f(w, h);
			glTexCoord2f(1, 0);	glVertex2f(w, -h);
		glEnd();

		glPopMatrix();
	}

	void OpenGLRenderer::renderTexturedSphere(Vec3 coords, Vec3 rotation, double radius, double slices, Texture* texture)
	{
		if (!mInitialized) return;

		enableTexturing();
		bindTexture(texture);
		renderSphere(coords, rotation, radius, slices);
		unbindTexture();
		disableTexturing();
	}

	void OpenGLRenderer::renderSphere(Vec3 coords, Vec3 rotation, double radius, double slices)
	{
		if (!mInitialized) return;

		GLUquadric* quad = gluNewQuadric();
		gluQuadricDrawStyle( quad, GLU_FILL);
		gluQuadricNormals( quad, GLU_SMOOTH);
		gluQuadricOrientation( quad, GLU_OUTSIDE);
		gluQuadricTexture( quad, GL_TRUE);

		glPushMatrix();
			glTranslatef(coords.x, coords.y, coords.z);
			glRotatef(rotation.x, 1, 0, 0);
			glRotatef(rotation.y, 0, 1, 0);
			glRotatef(rotation.z, 0, 0, 1);

			glColor4f(1,1,1,1);
			gluSphere(quad, radius, slices, slices);
		glPopMatrix();

		gluDeleteQuadric(quad);
	}

	void OpenGLRenderer::beginRender()
	{
		if (!mInitialized) return;

		glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		gluLookAt(mCameraPosition.x, mCameraPosition.y, mCameraPosition.z, mCameraLookAt.x, mCameraLookAt.y, mCameraLookAt.z, 0, -1, 0);
	}

	void OpenGLRenderer::enableTexturing()
	{
		glEnable(GL_TEXTURE_2D);
	}

	void OpenGLRenderer::disableTexturing()
	{
		glDisable(GL_TEXTURE_2D);
	}

	void OpenGLRenderer::renderText(string filename, string text, int size, Vec3 coords, float r, float g, float b)
	{
		if (!mInitialized) return;
		TTF_Font* Font;
		Font = TTF_OpenFont(filename.c_str(), size);
		if (Font == NULL) return;

		/*Create some variables.*/
		SDL_Color Color = {r, g, b};
		SDL_Surface *Message = TTF_RenderText_Blended(Font, text.c_str(), Color);
		GLuint Texture;

		/*Generate an OpenGL 2D texture from the SDL_Surface*.*/
		glGenTextures(1, &Texture);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, Texture);

		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, Message->w, Message->h, 0, GL_BGRA, GL_UNSIGNED_BYTE, Message->pixels);


		glColor4f(1,1,1,1);
		/*Draw this texture on a quad with the given xyz coordinates.*/
		glPushMatrix();
		glTranslatef(coords.x+ Message->w/2,coords.y + Message->h/2, coords.z);
		glBegin(GL_QUADS);
			glTexCoord2f(0, 0);	glVertex2f(-Message->w/2, -Message->h/2);
			glTexCoord2f(0, 1);	glVertex2f(-Message->w/2, Message->h/2);
			glTexCoord2f(1, 1);	glVertex2f(Message->w/2, Message->h/2);
			glTexCoord2f(1, 0);	glVertex2f(Message->w/2, -Message->h/2);
		glEnd();
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);

		/*Clean up.*/
		glDeleteTextures(1, &Texture);
		SDL_FreeSurface(Message);
	}



	void OpenGLRenderer::finishRender()
	{
		if (!mInitialized) return;

		SDL_GL_SwapBuffers();
	}

	void OpenGLRenderer::setCameraPosition(Vec3 position)
	{
		mCameraPosition = position;
	}

	Vec3 OpenGLRenderer::getCameraPosition() const
	{
		return mCameraPosition;
	}

	void OpenGLRenderer::setCameraLookAt(Vec3 vec)
	{
		mCameraLookAt = vec;
	}

	Vec3 OpenGLRenderer::getCameraLookAt() const
	{
		return mCameraLookAt;
	}

	void OpenGLRenderer::moveCamera(Vec3 vec)
	{
		mCameraPosition += vec;
		mCameraLookAt += vec;
	}
}


