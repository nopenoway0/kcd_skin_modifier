#ifndef BYTABLE
#define BYTABLE

class Bytable{
public:
	Bytable(){};
	virtual ~Bytable(){};
	virtual char* asBytes(int& size)=0;
};

#endif