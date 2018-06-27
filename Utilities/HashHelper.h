#ifndef HASHHELPER_H
#define HASHHELPER_H

#include <functional>
namespace yxp_utility
{
	//���ָ�붼��ʹ��
	template<class T>
	struct PtrHasher {}; //������һ��ģ��������е��µ�������

	template <class T>
	struct PtrHasher<T *>
	{
		size_t operator()(const T *ptr) const
		{
			return std::hash<size_t>()((size_t)ptr);
		}
	};

	//һ�����õ�hash_function
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
				0x9e3779b9 + //���������Դ�ڻƽ�ָ�
				(seed << 6) +
				(seed >> 2);
		}

		template <typename T>
		static inline void hash_val(size_t &seed, const T &val)
		{
			hash_combine(seed, val);
		}

		//������C++11�����Ե�Variadic Templates
		template <typename T, typename... Types>
		static inline void hash_val(size_t &seed, const T &val, const Types &... args)
		{
			hash_combine(seed, val);
			hash_val(seed, args...);
		}
	};
}

#endif
