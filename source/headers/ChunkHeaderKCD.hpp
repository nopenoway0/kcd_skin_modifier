#ifndef CHUNKHEADERKCD
#define CHUNKHEADERKCD

#include "ChunkHeader.hpp"

const int CHUNKTYPE = 0;
const int VERSION = 1;
const int ID = 2;
const int SIZE = 3;
const int OFFSET = 4;


class ChunkHeaderKCD : public ChunkHeader{
private:
	int* fields;
	uint32_t header_location;
public:
	ChunkHeaderKCD();
	ChunkHeaderKCD(std::ifstream& in);
	int getField(int field);
	uint32_t getHeaderStart();
	~ChunkHeaderKCD();
	virtual void load(std::ifstream& in) override;
	virtual char* asBytes(int& size) override;
};

#endif