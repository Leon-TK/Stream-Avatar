#pragma once


namespace Base
{
	class IAnchor
	{
	public:
		virtual ~IAnchor() {};
		virtual void updateDerivedLocation() = 0;
	};
}
