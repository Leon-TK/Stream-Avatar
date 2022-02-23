#pragma once

#include <vector>

#include "SFML\System\Vector2.hpp"

typedef sf::Vector2f Vectorf;

class ASnapBase
{
	
protected:
	Vectorf m_pos;
	virtual void _updatePosition(const Vectorf& rPos) = 0;
	void _setPosition(const Vectorf& rPos);
public:
	const Vectorf* getPos();
};

class SnapClaw;
class SnapPoint: public ASnapBase
{
	friend class SnapClaw;

	SnapClaw* m_pClaw = nullptr;
	void _onPositionChanged();
	void _addClaw(SnapClaw& rClaw);
	
public:
	void updatePosition(const Vectorf& rPos) override final;
	
};

class SnapClaw : public ASnapBase
{
	friend class SnapPoint;
	
	Vectorf m_offset;
	SnapPoint* m_pPoint = nullptr;
	void _onPositionChanged();
	void _updatePositionByPoint();
	void _updatePosition(const Vectorf& rPos) override final;

public:
	void setOffset(const Vectorf& rOffset);
	void addOffset(const Vectorf& rDeltaOffset);
	void attachToPoint(const SnapPoint& rPoint);
};