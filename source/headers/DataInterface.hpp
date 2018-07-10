#ifndef DATAINTERFACE
#define DATAINTERFACE
#include "Bytable.hpp"
#include <typeinfo>
#include <string>
class DataInterface : public Bytable{
protected:
public:
	DataInterface(){
	};

	~DataInterface(){};

	virtual char* asBytes(int& size){
		size = 0;
		return nullptr;
	}
};

#endif