#ifndef CHUNKHEAD
#define CHUNKHEAD
#include <fstream>

class ChunkHeader{
public:
	ChunkHeader(){};
	virtual ~ChunkHeader() {};
	virtual void load(std::ifstream& in){
		throw "unsupported load";
	};
};

#endif