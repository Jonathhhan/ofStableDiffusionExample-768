#pragma once

#include "stableDiffusion/stable-diffusion.h"

class stableDiffusionThread : public ofThread {
public:
	StableDiffusion stableDiffusion;
	ofTexture tex;
	std::vector<uint8_t> stableDiffusionPixelVector;
	std::string prompt;
	bool diffused;
	void threadedFunction() {
		stableDiffusionPixelVector = stableDiffusion.txt2img(prompt, "", 7.0, 768, 768, EULER_A, 8, ofRandom(100000));
		diffused = true;
	}
};
