/*
 * BackgroundTexture.h
 *
 *  Created on: Mar 28, 2009
 *      Author: daniel
 */

#ifndef BACKGROUNDTEXTURE_H_
#define BACKGROUNDTEXTURE_H_

#include "BackgroundObject.h"
#include "../graphics/Renderer.h"

class BackgroundTexture: public BackgroundObject
{
	friend class BackgroundTextureController;
protected:
	bool fixed_to_camera;

	float texture_scale;
	DFXEngine::Texture* texture;
public:
	BackgroundTexture();
	virtual ~BackgroundTexture();

	virtual void render(DFXEngine::Renderer& renderer);
    bool getFixed_to_camera() const
    {
        return fixed_to_camera;
    }

    void setFixed_to_camera(bool fixed_to_camera)
    {
        this->fixed_to_camera = fixed_to_camera;
    }

    float getTexture_scale() const
    {
        return texture_scale;
    }

    void setTexture_scale(float texture_scale)
    {
        this->texture_scale = texture_scale;
    }

    DFXEngine::Texture *getTexture() const
    {
        return texture;
    }

    void setTexture(DFXEngine::Texture *texture)
    {
        this->texture = texture;
    }

};

#endif /* BACKGROUNDTEXTURE_H_ */
