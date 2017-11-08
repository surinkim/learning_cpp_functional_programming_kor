#pragma once

#include <windows.h>

template <typename C>
class UniqueHandle
{
private:
	HANDLE m_val;

	void Close()
	{
		if (*this)
		{
			C::Exit(m_val);
		}
	}

public:
	// 복사 대입 연산자
	UniqueHandle(UniqueHandle const &) = delete;
	auto operator=(UniqueHandle const &)->UniqueHandle & = delete;

	// 생성자
	explicit UniqueHandle(HANDLE value = C::Invalid()) :
		m_val{ value }
	{
	}

	// 이동 생성자
	UniqueHandle(UniqueHandle && other) :
		m_val{ other.Release() }
	{
	}

	// 이동 대입 연산자
	auto operator=(UniqueHandle && other) -> UniqueHandle &
	{
		if (this != &other)
		{
			Reset(other.Release());
		}

		return *this;
	}

	// 소멸자
	~UniqueHandle()
	{
		Close();
	}

	// 동일성 검사를 위한 bool 연산자
	explicit operator bool() const
	{
		return m_val != C::Invalid();
	}

	// HANDLE 값을 얻기 위한 함수
	HANDLE Get() const
	{
		return m_val;
	}

	// HANDLE을 해제하기 위한 함수
	HANDLE Release()
	{
		auto value = m_val;
		m_val = C::Invalid();
		return value;
	}

	// HANDLE을 리셋하는 함수
	bool Reset(HANDLE value = C::Invalid())
	{
		if (m_val != value)
		{
			Close();
			m_val = value;
		}

		return static_cast<bool>(*this);
	}
};

template <typename C>
auto swap(UniqueHandle<C> & left,
	UniqueHandle<C> & right) throw() -> void
{
	left.swap(right);
}

template <typename C>
auto operator==(UniqueHandle<C> const & left,
	UniqueHandle<C> const & right) throw() -> bool
{
	return left.Get() == right.Get();
}

template <typename C>
auto operator!=(UniqueHandle<C> const & left,
	UniqueHandle<C> const & right) throw() -> bool
{
	return left.Get() != right.Get();
}

template <typename C>
auto operator<(UniqueHandle<C> const & left,
	UniqueHandle<C> const & right) throw() -> bool
{
	return left.Get() < right.Get();
}

template <typename C>
auto operator>=(UniqueHandle<C> const & left,
	UniqueHandle<C> const & right) throw() -> bool
{
	return left.Get() >= right.Get();
}

template <typename C>
auto operator>(UniqueHandle<C> const & left,
	UniqueHandle<C> const & right) throw() -> bool
{
	return left.Get() > right.Get();
}

template <typename C>
auto operator<=(UniqueHandle<C> const & left,
	UniqueHandle<C> const & right) throw() -> bool
{
	return left.Get() <= right.Get();
}

struct NullHandleCharacteristics
{
	// 잘못된 HANDLE이면 nullptr을 반환
	static HANDLE Invalid()
	{
		return nullptr;
	}

	// HANDLE 종료
	static void Exit(HANDLE val)
	{
		CloseHandle(val);
	}
};

//struct invalid_handle_traits
//{
//	using pointer = HANDLE;
//
//	static auto invalid() throw() -> pointer
//	{
//		return INVALID_HANDLE_VALUE;
//	}
//
//	static auto close(pointer value) throw() -> void
//	{
//		CloseHandle(value);
//	}
//};

using NullHandle = UniqueHandle<NullHandleCharacteristics>;
//using invalid_handle = unique_handle<invalid_handle_traits>;

