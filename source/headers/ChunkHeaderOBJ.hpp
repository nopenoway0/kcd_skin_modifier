#ifndef CHUNKHEADEROBJ
#define CHUNKHEADEROBJ

#include "ChunkHeader.hpp"

class ChunkHeaderOBJ : public ChunkHeader{
private:
	std::string header;
public:
	ChunkHeaderOBJ();
	ChunkHeaderOBJ(std::ifstream& f);
	~ChunkHeaderOBJ();
	void load(std::ifstream& f) override;
	char* asBytes(int& size) override;
};

#endif