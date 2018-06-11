#pragma once
#include <afxwin.h>
#include <string>
using std::string;
//本题主要是考察对于宽字符和窄字符的理解及相互的转换，核心在于MultiByteToWideChar函数和WideCharToMultiByte函数

//在VS里面，常用的字符数组char*或者标准库的str::string类型，都是传统的ascii码来表示的，也就是一个字节表示一个字符
//但ascii码只有0-127，无法包含中文等其他国家语言，这时候便引入了宽字符wchar_t，两个字节表示一个字符
//就包含了世界上几乎所有国家的文字了,同时MFC里面用的CString会根据系统的配置，
//项目属性-常规-字符集来选择使用哪种字符集
//第一种是多字节，也就是说表示一个字符需要多个字节，其实就是我们前面说的窄字符，当出现了ascii码无法表示的字符时，
//便查找指定的编码集,汉字就是gb2312编码进行编码，两个字节组合后表示一个字符，也就是所谓的多字节，其实就是窄字符
//第二种是unicode，也就是前面说的宽字符，两个字节表示一个字符，所有语言都能表示，通用性更好
//默认情况下，VS采用后一种方式（但VC6以前是默认窄字符），故CString内的数据是宽字符的
namespace yxp_utility {
	class StrCvt //这个类用来进行转换
	{
	public:
		//定义成静态函数
		static void Convert(const string &str, CString & cstr);
		static void Convert(const string &str, char **pszStr);
		static void Convert(const char* szStr, string &str);
		static void Convert(const char* szStr, CString &cstr);
		static void Convert(const CString &cstr, string &str);
		static void Convert(const CString &cstr, char **pszStr);

		inline static size_t GetCvtlength(const wchar_t *wszstr, const int len);
		inline static size_t GetCvtlength(const char *szstr, const int len);
	};

}

