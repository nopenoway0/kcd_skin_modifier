#ifndef DATA
#define DATA

#include "DataInterface.hpp"
#include <typeinfo>
template <class T> class Data : public DataInterface{
protected:
	T data;
public:
	Data() : DataInterface(typeid(this)) {};
	Data(const std::type_info& type) : DataInterface(type) {};
	virtual ~Data(){};
	
	T getData(){
		return data;
	};
};

#endif