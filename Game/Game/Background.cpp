#include "Background.h"
#include<cstdlib>

void Background::Render(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, getTexture(), NULL, NULL);
}

void Background::GroundRender(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, getTexture(), &getSrc(), &getDest());
}

void Background::PipeRender(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, getTexture(), &getSrc(), &getDest());
}

bool Background::Pipe_Above1Update(int incY)
{
	this->incY1 = incY;
	if (pipeDistance1 <= -60)
	{
		pipeDistance1 = 805;
		return true;
	}
	else
	{
		pipeDistance1--;
		setSrc(0, 0, 320, 52);
		setDest(pipeDistance1, -200 + this->incY1, 400, 52);
		return false;
	}
}

bool Background::Pipe_Below1Update(int incY)
{
	this->incY1 = incY;
	if (pipeDistance1 <= -60)
	{
		pipeDistance1 = 805;
		return true;
	}
	else
	{
		pipeDistance1--;
		setSrc(0, 0, 320, 52);
		setDest(pipeDistance1, 350 + this->incY1, 400, 52);
		return false;
	}
}

bool Background::Pipe_Above2Update(int incY)
{
	this->incY2 = incY;
	if (pipeDistance2 <= -60)
	{
		pipeDistance2 = 805;
		return true;
	}
	else
	{
		pipeDistance2--;
		setSrc(0, 0, 320, 52);
		setDest(pipeDistance2, -200 + this->incY2, 400, 52);
		return false;
	}
}

bool Background::Pipe_Below2Update(int incY)
{
	this->incY2 = incY;
	if (pipeDistance2 <= -60)
	{
		pipeDistance2 = 805;
		return true;
	}
	else
	{
		pipeDistance2--;
		setSrc(0, 0, 320, 52);
		setDest(pipeDistance2, 350 + this->incY2, 400, 52);
		return false;
	}
}

bool Background::Pipe_Above3Update(int incY)
{
	this->incY3 = incY;
	if (pipeDistance3 <= -60)
	{
		pipeDistance3 = 805;
		return true;
	}
	else
	{
		pipeDistance3--;
		setSrc(0, 0, 320, 52);
		setDest(pipeDistance3, -200 + this->incY3, 400, 52);
		return false;
	}
}

bool Background::Pipe_Below3Update(int incY)
{
	this->incY3 = incY;
	if (pipeDistance3 <= -60)
	{
		pipeDistance3 = 805;
		return true;
	}
	else
	{
		pipeDistance3--;
		setSrc(0, 0, 320, 52);
		setDest(pipeDistance3, 350 + this->incY3, 400, 52);
		return false;
	}
}

void Background::GroundUpdate1()
{
	if (distance1 <= -800)
	{
		distance1 = 805;
	}
	else
	{
		distance1--;
		setSrc(0, 0, 112, 336);
		setDest(distance1, 520, 112, 805);
	}
}

void Background::GroundUpdate2()
{
	if (distance2 <= -800)
	{
		distance2 = 805;
	}
	else
	{
		distance2--;
		setSrc(0, 0, 112, 336);
		setDest(distance2, 520, 112, 805);
	}
}

void Background::Reset()
{
	pipeDistance1 = 400;
	pipeDistance2 = 700;
	pipeDistance3 = 1000;
	incY1 = 0;
	incY2 = 0;
	incY3 = 0;
}