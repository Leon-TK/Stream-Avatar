#include "BodyAnimations.h"
//#include "EnumFrames.h"
/*
BodyAnimations::Idle1::Idle1(Base::Body * body, Base::Timer * timer, float t): CharAnimation::BodyTimeAnimation(body,timer,t)
{
}
*/
BodyAnimations::Idle1::Idle1()
{
}

BodyAnimations::Idle1::Idle1(Base::Body& body): CharAnimation::BodyTimeAnimation(body)
{
}

void BodyAnimations::Idle1::update()
{
	timer.Update(&clock);
	Frames::EBody f1 = Frames::EBody::F1IDLE;
	Frames::EBody f2 = Frames::EBody::F2IDLE;
	SetFrame(&f1, 3.3f);
	SetFrame(&f2, 6.0f, 1);
}

void BodyAnimations::Idle1::start()
{
}

void BodyAnimations::Idle1::stop()
{
}

//void BodyAnimations::Idle1::UpdateDerivedLocation()
//{
	//Derived object->SetLocation(Frame data.mouthAnchor);
//}

BodyAnimations::Idle2::Idle2(Base::Body& body, const Base::Timer & timer, float t) : CharAnimation::BodyTimeAnimation(body)
{
}

BodyAnimations::Idle2::Idle2(Base::Body& body): CharAnimation::BodyTimeAnimation(body)
{
}

void BodyAnimations::Idle2::update()
{
	timer.Update(&clock);
	Frames::EBody f1 = Frames::EBody::F1RIGHT;
	Frames::EBody f2 = Frames::EBody::F1IDLE;
	Frames::EBody f3 = Frames::EBody::F1CLOSEEYES;
	Frames::EBody f4 = Frames::EBody::F1IDLE;
	SetFrame(&f1, 5.0f);
	SetFrame(&f2, 8.0f);
	SetFrame(&f3, 10.0f);
	SetFrame(&f4, 10.3f, 1);
}

void BodyAnimations::Idle2::start()
{
}

void BodyAnimations::Idle2::stop()
{
}
