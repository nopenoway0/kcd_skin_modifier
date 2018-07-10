#ifndef DATAINTERFACE
#define DATAINTERFACE

#include <typeinfo>
#include <string>
class DataInterface{
protected:
	const std::type_info* data_type;
public:
	DataInterface(const std::type_info& type){
		data_type = &type;
	};

	~DataInterface(){};

	virtual char* toBytes(int& size){
		size = 0;
		return nullptr;
	}

	std::string getTypeName(){
		return data_type->name();
	}
};

#endif