#ifndef CHUNKHEADERVRT
#define CHUNKHEADERVRT

#include "ChunkHeader.hpp"

class ChunkHeaderVrt : public ChunkHeader{
private:
	int element_size;
	int offset;
	void init();
public:
	char* _name;
	ChunkHeaderVrt();
	ChunkHeaderVrt(std::ifstream& f);
	~ChunkHeaderVrt();
	void load(std::ifstream& f) override;
	char* asBytes(int& size) override;
	int getOffset();
};

#endif