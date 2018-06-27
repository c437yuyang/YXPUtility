#ifndef HASHHELPER_H
#define HASHHELPER_H

#include <functional>
namespace yxp_utility
{
	//针对指针都能使用
	template<class T>
	struct PtrHasher {}; //必须有一个模板类才能有底下的特例化

	template <class T>
	struct PtrHasher<T *>
	{
		size_t operator()(const T *ptr) const
		{
			return std::hash<size_t>()((size_t)ptr);
		}
	};

	//一个万用的hash_function
	class HashHelper
	{

	public:
		template <typename... Types>
		static inline size_t hash_val(const Types &... args)
		{
			size_t seed = 0;
			hash_val(seed, args...);
			return seed;
		}

	private:
		template <typename T>
		static inline void hash_combine(size_t &seed, const T &val)
		{
			seed ^= std::hash<T>()(val) +
				0x9e3779b9 + //这个数是来源于黄金分割
				(seed << 6) +
				(seed >> 2);
		}

		template <typename T>
		static inline void hash_val(size_t &seed, const T &val)
		{
			hash_combine(seed, val);
		}

		//利用了C++11新特性的Variadic Templates
		template <typename T, typename... Types>
		static inline void hash_val(size_t &seed, const T &val, const Types &... args)
		{
			hash_combine(seed, val);
			hash_val(seed, args...);
		}
	};
}

#endif
