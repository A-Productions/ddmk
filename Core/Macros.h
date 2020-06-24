#ifdef offsetof
#undef offsetof
#endif
#ifndef __INTELLISENSE__
#define offsetof(s, m) __builtin_offsetof(s, m)
#else
#define offsetof(s, m) reinterpret_cast<uint32>(&(*reinterpret_cast<s *>(0)).m)
#endif

#define for_all(type, name, end) for (type name = 0; name < end; name++)

#define for_each(type, name, start, end) for (type name = 0; name < end; name++)

#define HoboBreak() MessageBoxA(0, "break1", 0, 0); MessageBoxA(0, "break2", 0, 0)

#define FUNC_NAME __FUNCTION__

#define LogFunction(...) LogFunctionHelper(FUNC_NAME, __VA_ARGS__)

#define LogFunctionStart() Log("%s Start", FUNC_NAME)
#define LogFunctionEnd() Log("%s End", FUNC_NAME)
