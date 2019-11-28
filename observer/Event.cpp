#include "Event.h"



Event::Event(std::shared_ptr<Subject> subject, const std::string& desc):m_subject(subject), m_description(desc)
{
}

std::shared_ptr<Subject> Event::getSubject() const
{
	return m_subject;
}

std::string Event::getDescription() const
{
	return m_description;
}