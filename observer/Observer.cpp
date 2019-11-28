#include "Observer.h"
#include "Event.h"
#include "Subject.h"
#include <string>

Observer1::Observer1(std::shared_ptr<Subject>& subject)
{
	create(subject);
}

void Observer1::update(std::unique_ptr<Event>&& event)
{
	std::shared_ptr<Subject> s = event->getSubject();
	const std::string desc = event->getDescription();
	if (desc == "attr1")
		m_attribute = s->getAttribute1();
}

void Observer1::create(std::shared_ptr<Subject>& sub)
{
	m_attribute = sub->getAttribute1();
	sub->attach(this);
}

Observer2::Observer2(std::shared_ptr<Subject>& subject)
{
	create(subject);
}

void Observer2::update(std::unique_ptr<Event>&& event)
{
	std::shared_ptr<Subject> s = event->getSubject();
	const std::string desc = event->getDescription();
	if (desc == "attr2")
		m_attribute = s->getAttribute2();
}

void Observer2::create(std::shared_ptr<Subject>& sub)
{
	m_attribute = sub->getAttribute2();
	sub->attach(this);
}

Observer12::Observer12(std::shared_ptr<Subject>& subject)
{
	create(subject);
}

void Observer12::update(std::unique_ptr<Event>&& event)
{
	if (++m_counter % 3 == 0) {  
		std::shared_ptr<Subject> s = event->getSubject();
		m_attribute1 = s->getAttribute1();
		m_attribute2 = s->getAttribute2();
	}
}

void Observer12::create(std::shared_ptr<Subject>& sub)
{
	m_attribute1 = sub->getAttribute1();
	m_attribute2 = sub->getAttribute2();
	m_counter = 0;
	sub->attach(this);
}