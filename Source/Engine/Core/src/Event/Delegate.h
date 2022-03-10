#pragma once

#include "CoreTypes.h"

#include "Containers/Array.h"

namespace Event
{
	namespace Private
	{
		template<typename... ArgsType>
		class IEvent
		{
		public:
			virtual void Invoke(ArgsType... args) = 0;
		};

		template<typename... ArgsType>
		class TFunctionEvent : public IEvent<ArgsType...>
		{
			typedef void (*Function)(ArgsType...);

		public:
			TFunctionEvent(Function fn)
			{
				m_Fn = fn;
			}

		public:
			void Invoke(ArgsType... args) override
			{
				(*m_Fn)(args...);
			}

		private:
			Function m_Fn;
		};

		template<typename T, typename... ArgsType>
		class TMemberFunctionEvent : public IEvent<ArgsType...>
		{
			typedef void (T::*Function)(ArgsType...);

		public:
			TMemberFunctionEvent(T* cls, Function fn)
			{
				m_Class = cls;
				m_Fn = fn;
			}

			void Invoke(ArgsType... arg) override
			{
				(m_Class->*m_Fn)(arg...);
			}

		private:
			T* m_Class;
			Function m_Fn;
		};
	}
}

template<typename T, typename... ArgsType>
struct TMemberFunctionPtr
{
	typedef void (T::*Type)(ArgsType...);
};

template<typename... ArgsType>
struct TFunctionPtr
{
	typedef void (*Type)(ArgsType...);
};

template<typename... ArgsType>
class TITAN_API TDelegate
{
public:
	TDelegate() = default;

	~TDelegate()
	{
		// TODO: Use the new for instead (for (auto e : m_Events))
		for (int32 i = 0; i < m_Events.GetCount(); i++)
		{
			delete m_Events[i];
		}
	}

public:
	void AddObserver(typename TFunctionPtr<ArgsType...>::Type fn)
	{
		m_Events.Add(new Event::Private::TFunctionEvent<ArgsType...>(fn));
	}

	template<typename ClassType>
	void AddObserver(ClassType* cls, typename TMemberFunctionPtr<ClassType, ArgsType...>::Type fn)
	{
		m_Events.Add(new Event::Private::TMemberFunctionEvent<ClassType, ArgsType...>(cls, fn));
	}

	void Invoke(ArgsType... arg)
	{
		// TODO: Use the new for instead (for (auto e : m_Events))
		for (int32 i = 0; i < m_Events.GetCount(); i++)
		{
			m_Events[i]->Invoke(arg...);
		}
	}

private:
	TArray<Event::Private::IEvent<ArgsType...>*> m_Events;
};