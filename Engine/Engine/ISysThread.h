class ISysThread
{
	virtual ~IThread() = default;
	virtual void init() = 0;
	virtual void update() = 0;
};