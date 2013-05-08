#ifndef _Factory_H_
#define _Factory_H_
#include <map>
#include <string>
template <typename T>
class Factory
{
	template <typename DerivedT>
	static T* CreateT() { return new DerivedT; }
	std::map<std::string, T *(*)()> mTypeMap;
public:
	T* CreateInstance(const std::string &typeName)
	{
		auto it = mTypeMap.find(typeName);
		if (it != mTypeMap.end())
			return it->second();
		return nullptr;
	}
	template <typename DerivedT>
	void RegisterType(const std::string &derivedTypeName)
	{
		mTypeMap[derivedTypeName] = &Factory<T>::CreateT<DerivedT>;
	}
};
#endif
