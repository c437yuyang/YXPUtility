#include "stdafx.h"
#include "StrCvt.h"
using yxp_utility::StrCvt;
void StrCvt::Convert(const string &str, CString &cstr)
{
	//先取得字符串长度，其实在这里是相等的nLen = str.length()，出现非ascii码表里的字符(如中文)就会不相等
	size_t nLen = GetCvtlength(str.c_str(), str.length());

	wchar_t *pwch = new wchar_t[(nLen + 1) * sizeof(wchar_t)](); //新建临时宽字符数组
	//memset(pwch, 0, (str.length() + 1) * sizeof(wchar_t)); //new的时候带了括号则调用了默认构造函数，直接归0了

	MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), pwch, nLen); //从窄字符转换成宽字符
	cstr.Format(_T("%ls"), pwch); //再利用CString的方法格式化字符串
	delete[] pwch; //释放临时内存
	return;

	//方法二,CString类型直接有接受窄字符字符串的构造函数
	CString cstrTemp(str.c_str()); //这些赋值，拷贝，都是深拷贝
	cstr = cstrTemp;

	//方法三,利用windows提供的宏
	USES_CONVERSION;
	cstr = A2W(str.c_str());

}

void StrCvt::Convert(const string &str, char **pszStr)
{
	//这里只是起一个演示作用，平时使用基本都是直接使用str.c_str()就行了
	*pszStr = new char[str.length() + 1]();
	strcpy_s(*pszStr, str.length() + 1, str.c_str()); //注意,strcpy是连着\0一起copy的，所以要+1
}

void StrCvt::Convert(const char * szStr, string &str)
{
	string strTemp(szStr);
	str = strTemp;
}

void StrCvt::Convert(const char * szStr, CString & cstr)
{
	//方法1
	int nLen = GetCvtlength(szStr, strlen(szStr));
	wchar_t *pwch = new wchar_t[nLen + 1]();
	MultiByteToWideChar(CP_ACP, 0, szStr, strlen(szStr), pwch, nLen);
	cstr.Format(_T("%ls"), pwch);
	delete[] pwch;
	return;

	//方法2
	USES_CONVERSION;
	cstr = A2W(szStr);

	//方法3,利用构造函数
	CString cstrTemp(szStr);
	cstr = cstrTemp;

}

void StrCvt::Convert(const CString &cstr, string &str)
{
	//方法1
	CString cstrTemp = cstr; //先复制一份,底下的getbuffer不能是const对象
	wchar_t* pwch = cstrTemp.GetBuffer();
	int nLen = GetCvtlength(pwch, cstrTemp.GetLength());
	char *pch = new char[nLen + 1]();
	WideCharToMultiByte(CP_ACP, 0, pwch, cstrTemp.GetLength(), pch, nLen, '\0', false);
	string strTemp(pch);
	str = strTemp;
	//cstrTemp.ReleaseBuffer();
	delete[] pch;
	return;

	//方法2；
	CString cstrTemp2 = cstr;
	USES_CONVERSION;
	str = W2A(cstrTemp2);

}

void StrCvt::Convert(const CString & cstr, char ** pszStr)
{
	//先把CString转换成wchar *，再把wchar * 转换成 char *，最后把char*拷贝给目标
	CString cstrTemp = cstr; //先复制一份,底下的getbuffer不能是const对象
	wchar_t* pwch = cstrTemp.GetBuffer();
	int nLen = GetCvtlength(pwch, cstrTemp.GetLength());
	*pszStr = new char[nLen + 1]();
	WideCharToMultiByte(CP_ACP, 0, pwch, cstrTemp.GetLength(), *pszStr, nLen, '\0', false);
}

//取得从宽字符转换成窄字符的情况下，窄字符数组需要的大小
size_t StrCvt::GetCvtlength(const wchar_t * wszstr, const int len)
{
	return WideCharToMultiByte(CP_ACP, 0, wszstr, len, NULL, 0, '\0', false);
}

//取得从窄字符转换成宽字符的情况下，宽字符数组需要的大小，其实只有ascii码表里的字符的时候就是strlen(szstr)
size_t StrCvt::GetCvtlength(const char * szstr, const int len)
{
	return MultiByteToWideChar(CP_ACP, 0, szstr, len, NULL, 0);
}

