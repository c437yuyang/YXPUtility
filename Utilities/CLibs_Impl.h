namespace yxp_utility
{
	//字符串类
	size_t strlen(char const* str)
	{
		assert(str != nullptr);
		size_t res = 0;
		while (*(str++) != '\0')
			++res;
		return res;
	}

	char *strcpy(char *dst, const char* src)
	{
		assert((dst != nullptr) && (src != nullptr));

		if (src == dst)
			return dst;

		char *dstCur = dst;
		const char *srcCur = src;
		if (src < dst)
		{
			int len = 0;
			while (*srcCur++ != '\0')
				++len;
			*(dst + len) = '\0';
			while (len--)
				*(dstCur + len) = *(src + len);
		}
		else
		{
			while (*srcCur != '\0')
				*(dstCur++) = *(srcCur++);
			*dstCur = '\0';
		}
		return dst;
	}

	char* strcat(char* dst, const char* src)
	{
		char* res = dst;
		while (*dst != '\0')
			++dst;
		while ((*(dst++) = *src) != '\0');
		return res;
	}

	int strcmp(const char *str1, const char *str2)
	{
		assert(str1 != nullptr  && str2 != nullptr);
		while (*str1 == *str2 && *str1 != '\0')
		{
			++str1;
			++str2;
		}
		return *str1 - *str2;
	}


	//数值类
	bool isOverFlow(long long res, bool neg)
	{
		if (neg)
			return -res < std::numeric_limits<int>::min();
		return res > std::numeric_limits<int>::max();
	}

	int atoi(const char *str)
	{
		if (str == nullptr)
			return 0;

		while (*str == ' ') //trim start
			++str;
		bool negative = false;
		if (*str == '-')
		{
			negative = true;
			++str;
		}
		if (*str == '+')
			++str;
		long long res = 0;
		while (*str != '\0')
		{
			if (*str < '0' || *str > '9')
				return negative ? static_cast<int>(-res) : static_cast<int>(res); //return valid part :-0012a42 返回-12
			res = res * 10 + (*str) - '0';
			if (isOverFlow(res, negative))
				return negative == true ? std::numeric_limits<int>::min() : std::numeric_limits<int>::max();
			++str;
		}
		return negative ? static_cast<int>(-res) : static_cast<int>(res);
	}


	int sqrt(int x)
	{
		//思路用二分法
		if (x < 2)
			return x;

		int left = 1, right = x / 2; //sqrt最大可能返回的也就是x / 2
		int lastLess;
		while (left <= right)
		{
			int mid = left + ((right - left) >> 1);
			if (x / mid > mid) //mid*mid <x
			{
				left = mid + 1;
				lastLess = mid;
			}
			else if (x / mid < mid)
				right = mid - 1;
			else
				return mid;
		}
		return lastLess;
	}


	//内存操作类
	void *memcpy(void *pDst, const void *pSrc, size_t size)
	{
		if (pDst == nullptr || pSrc == nullptr)
			return nullptr;

		if (pDst == pSrc)
			return pDst;

		const char* pSrcCh = static_cast<const char*>(pSrc);
		char *pDstCh = static_cast<char *>(pDst);
		if (pSrcCh > pDstCh)
			while (size--)
				*pDstCh++ = *pSrcCh++;
		else //maybe overlap && (pDst < pSrc + size)
			while (size--)
				*(pDstCh + size) = *(pSrcCh + size);
		return pDst;
	}

	

}
