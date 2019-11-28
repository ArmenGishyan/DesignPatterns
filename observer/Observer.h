#pragma once

#include <memory>

class Event;
class Subject;

class IObserver 
{
public:
	virtual ~IObserver() {}
	virtual void update(std::unique_ptr<Event>&& event) = 0;

private:
	virtual void create(std::shared_ptr<Subject>& sub) = 0;
};

class Observer1 : public IObserver
{
public:
	Observer1(std::shared_ptr<Subject>& subject);
	int getAttribute1() const { return m_attribute; }
	void update(std::unique_ptr<Event>&& event) override;

private:
	void create(std::shared_ptr<Subject>& sub) override;

private:
	int m_attribute;
};

class Observer2 : public IObserver
{
public:
	Observer2(std::shared_ptr<Subject>& subject);
	int getAttribute2() const { return m_attribute; }
	void update(std::unique_ptr<Event>&& event) override;

private:
	void create(std::shared_ptr<Subject>& sub) override;

private:
	int m_attribute;
};

class Observer12 : public IObserver
{
public:
	Observer12(std::shared_ptr<Subject>& subject);

	int getAttribute1() const { return m_attribute1; }
	int getAttribute2() const { return m_attribute2; }
	void update(std::unique_ptr<Event>&& event) override;

private:
	void create(std::shared_ptr<Subject>& sub) override;

private:
	int m_attribute1;
	int m_attribute2;
	int m_counter;
};