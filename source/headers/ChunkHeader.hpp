#ifndef CHUNKHEAD
#define CHUNKHEAD
#include <fstream>
#include "Bytable.hpp"
class ChunkHeader : public Bytable{
public:
	ChunkHeader(){};
	virtual ~ChunkHeader() {};
	
	virtual void load(std::ifstream& in){
		throw "unsupported load";
	};

	virtual char* asBytes(int& size){
		size = 0;
		return nullptr;
	}
};

#endif