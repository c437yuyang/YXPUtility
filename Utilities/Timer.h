#pragma once
#include <Windows.h>
#include<chrono>
#include<string>


namespace yxp_utility {

	//windows api版本
	class CStopWatch
	{
	public:
		CStopWatch();
		void start();
		void stop();
		double getElapsedTime(); //in s
	private:
		LARGE_INTEGER m_start;
		LARGE_INTEGER m_stop;
		LARGE_INTEGER m_frequency;
	};

	//StopWatch.cpp
	CStopWatch::CStopWatch()
	{
		m_start.QuadPart = 0;
		m_stop.QuadPart = 0;
		QueryPerformanceFrequency(&m_frequency);
	}

	void CStopWatch::start()
	{
		QueryPerformanceCounter(&m_start);
	}

	void CStopWatch::stop()
	{
		QueryPerformanceCounter(&m_stop);
	}

	double CStopWatch::getElapsedTime()
	{
		LARGE_INTEGER time;
		time.QuadPart = m_stop.QuadPart - m_start.QuadPart;
		return (double)time.QuadPart / (double)m_frequency.QuadPart;
	}




	//c++11 新标准版本
	class Timer
	{
		typedef std::chrono::steady_clock::time_point   time_point_type;
		typedef std::chrono::duration<double>           duration_type;
		typedef std::chrono::steady_clock               clock_type;
	private:
		time_point_type _begin;
		duration_type _span;
	public:
		Timer()
			: _begin(time_point_type()), _span(duration_type(0)) {}
		void start()
		{
			_begin = clock_type::now();
		}

		//void pause()
		//{
		//	tp _end = sc::now();
		//	_span += std::chrono::duration_cast<dd>(_end - _begin);
		//}

		void stop(std::string head = std::string(),
			std::string tail = std::string())
		{
			time_point_type _end = clock_type::now();
			_span = std::chrono::duration_cast<duration_type>(_end - _begin);
		}
		~Timer() {}

		double getElapsedTime() {
			return _span.count();
		}

	};



}

