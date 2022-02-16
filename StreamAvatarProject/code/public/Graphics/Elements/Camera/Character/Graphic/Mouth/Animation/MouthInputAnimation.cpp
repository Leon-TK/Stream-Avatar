#include "MouthInputAnimation.h"
#include "Mouth.h"
#include "EnumFrames.h"
#include "FrameFactory.h"
#include "MouthFrameFactory.h"
CharAnimation::MouthInputAnimation::MouthInputAnimation()
{
}

CharAnimation::MouthInputAnimation::MouthInputAnimation(Base::Mouth * mouth, __int8* bufferArrayPtr)
{
	this->bufferArrayPtr = bufferArrayPtr;
	this->mouth = mouth;
}

void CharAnimation::MouthInputAnimation::Update()
{
}

void CharAnimation::MouthInputAnimation::Start()
{
}

void CharAnimation::MouthInputAnimation::Stop()
{
}

//CharAnimation::MouthInputAnimation::MouthInputAnimation(Base::Mouth * mouth, std::array<__int16, 512> bufferArray)
//{
//	this->bufferArray = bufferArray;
//	this->mouth = mouth;
//}


void CharAnimation::MouthInputAnimation::SetLevel(unsigned __int8* level)
{
	//this->level = level;
}

void CharAnimation::MouthInputAnimation::SetFrame(Frames::EMouth* frame, unsigned __int8 minLevel, unsigned __int8 maxLevel)
{

	if (maxLevel == 0)
	{
		if (mouth->getCurrentFrame() != *frame)
		{
			if (GetInput() < minLevel)
			{
				delete bframe;
				bframe = factory->getFrame(frame);
				bframe->UpdateElement(mouth);
				onFrameChanged();
			}
		}
	}
	else
	{
		if (minLevel != 0)
		{
			if (mouth->getCurrentFrame() != *frame)
			{
				unsigned __int8 val = GetInput(); //optimization
				if (val > minLevel && val < maxLevel)
				{
					delete bframe;
					bframe = factory->getFrame(frame);
					bframe->UpdateElement(mouth);
					onFrameChanged();
				}
			}
		}
		else
		{
			if (mouth->getCurrentFrame() != *frame)
			{
				if (GetInput() > maxLevel)
				{
					delete bframe;
					bframe = factory->getFrame(frame);
					bframe->UpdateElement(mouth);
					onFrameChanged();
				}
			}
		}
		
	}
}

unsigned __int8 CharAnimation::MouthInputAnimation::GetInput()
{
	///*
	//std::array<unsigned __int8, 512> absArray; // must be in stack . definition in class.
	//unsigned __int16 absArray[512];
	
	for (int i = 0; i < 512; ++i)
	{
		absArray[i] = std::abs(bufferArrayPtr[i]); //bufferarray shoud be pointer
	}

	//unsigned __int16 value = *std::max_element(absArray.begin(), absArray.end());
	//std::cout << *std::max_element(absArray.begin(), absArray.end());
	//std::cout << std::endl;
	//*std::max_element(absArray.begin(), absArray.end());
	return *std::max_element(absArray.begin(), absArray.end()); //*std::max_element(absArray.begin(),absArray.end())
	//*/
	/*
	std::array<unsigned __int16, 512> absArray;
	//unsigned __int16 absArray[512];
	for (short i = 0; i < 512; ++i)
	{
		absArray[i] = std::abs(bufferArray[i]); //bufferarray shoud be pointer
	}
	//std::cout << *std::max_element(absArray.begin(), absArray.end());
	//std::cout << std::endl;
	return *std::max_element(absArray.begin(), absArray.end()); //*std::max_element(absArray.begin(),absArray.end())
	*/
}

void CharAnimation::MouthInputAnimation::setBufferArrayrPtr(__int8 * buffer)
{
	this->bufferArrayPtr = buffer;
}

void CharAnimation::MouthInputAnimation::setBufferArray(std::array<__int8, 512> buffer)
{
	this->bufferArray = buffer;
}

__int8 * const CharAnimation::MouthInputAnimation::getBufferArrayPtr()
{
	return bufferArrayPtr;
}

std::array<__int8, 512> CharAnimation::MouthInputAnimation::getBufferArray()
{
	return bufferArray;
}

void CharAnimation::MouthInputAnimation::onFrameChanged()
{
	mouth->updateChildPosition();
}
