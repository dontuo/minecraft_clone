#pragma once
#include "block.h"


class Chunk
{
public:
	Block block[32][256][32];

	Chunk();

	void draw();

	void update();
};

