#pragma once

#include <memory>
#include <vector>

class IObserver;
class Event;

class Subject : public std::enable_shared_from_this<Subject>
{
public:
	Subject();
	Subject(int attr1, int attr2);
	~Subject() = default;
	void attach(IObserver* observer);
	int getAttribute1();
	int getAttribute2();
	void setAttribute1(int value);
	void setAttribute2(int value);
	void notify(std::unique_ptr<Event>&& event);

private:
	int m_attribute1;
	int m_attribute2;
	std::vector<IObserver*> m_viewers;
};

