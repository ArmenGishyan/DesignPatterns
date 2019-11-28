#pragma once

#include <memory>
#include <string>

class Subject;

class Event
{
public:
	Event(std::shared_ptr<Subject> subject, const std::string& desc);
	~Event() = default;

	std::shared_ptr<Subject> getSubject() const;
	std::string getDescription() const;

private:
	std::shared_ptr<Subject> m_subject;
	std::string m_description;
};

