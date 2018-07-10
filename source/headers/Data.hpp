#ifndef DATA
#define DATA

#include "DataInterface.hpp"
#include <typeinfo>
template <class T> class Data : public DataInterface{
protected:
	T data;
public:
	Data() : DataInterface() {};
	virtual ~Data(){};
	
	T* getData(){
		return &data;
	};
};

#endif