#include "Subject.h"
#include "Observer.h"
#include "Event.h"
#include <memory>


Subject::Subject()
{
}

Subject::Subject(int attr1, int attr2):m_attribute1(attr1), 
									   m_attribute2(attr2)
{

}

void Subject::attach(IObserver* observer)
{
	m_viewers.push_back(observer);
}

int Subject::getAttribute1()
{
	return m_attribute1;
}

int Subject::getAttribute2()
{
	return m_attribute2;
}

void Subject::setAttribute1(int value)
{
	m_attribute1 = value;

	std::unique_ptr<Event> event = std::make_unique<Event>(shared_from_this(), "attr1");
	notify(std::move(event));
}

void Subject::setAttribute2(int value)
{
	m_attribute2 = value;

	std::unique_ptr<Event> event = std::make_unique<Event>(shared_from_this(), "attr2");
	notify(std::move(event));
}

void Subject::notify(std::unique_ptr<Event>&& event)
{
	for (IObserver*& item : m_viewers)
	{
		item->update(std::move(event));
	}
}