#ifndef CHUNK
#define CHUNK
#include <iostream>

using std::ifstream;
template <class T>
class Chunk{
protected:
	T* chunk_header;
public:
	Chunk(T& chunk_header){
		this->chunk_header = new T(chunk_header);
	}

	Chunk(T* chunk_header){
		this->chunk_header = chunk_header;
	}

	virtual void load(ifstream& f){
		std::cerr << "unimplemented load";
		throw "unimplemented load";
	}

	T getHeader(){
		return *chunk_header;
	}

	virtual char* getBodyAsBytes(int& s){
		s = 0;
		std::cerr << "unimplemented body as bytes" << std::endl;
		return nullptr;
	};

	~Chunk(){
		//delete chunk_header;
	}
};

#endif