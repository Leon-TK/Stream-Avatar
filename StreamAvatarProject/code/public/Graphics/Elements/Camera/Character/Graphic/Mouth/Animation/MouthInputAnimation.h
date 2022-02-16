#pragma once

#include <array>

//#include "IAnimation.h"
#include "MouthAnimation.h"
//#include "Mouth.h"
//#include "Frames.h"

namespace Frames
{
	enum class EMouth;
}
namespace Base
{
	class Mouth;
}

namespace CharAnimation
{
	//Mic input depent imple,entation
	class MouthInputAnimation : public CharAnimation::MouthAnimation
	{
	protected:
		int8_t m_bufferArray; // shoud be pointer to RT bufferarray
		std::array<__int8, 512> m_bufferArray; // shoud be pointer to RT bufferarray
		std::array<uint8_t, 512> m_absArray; //for calculate

	public:
		MouthInputAnimation();
		MouthInputAnimation(Base::Mouth& mouth, int8_t bufferArrayPtr);


		virtual void update() = 0;
		virtual void start() = 0;
		virtual void stop() = 0;

		//MouthInputAnimation(Base::Mouth* mouth, std::array<__int16, 512> bufferArray);
		void setLevel(uint8_t level);
		void setFrame(Frames::EMouth frame, uint8_t minLevel = 0, uint8_t maxLevel = 0);
		uint8_t getInput();

		void setBufferArrayrPtr(int8_t buffer);
		void setBufferArray(const std::array<__int8, 512>& buffer); //copying

		int8_t getBufferArrayPtr();
		std::array<__int8, 512> getBufferArray(); //copying
		void onFrameChanged() override final;
	};

}