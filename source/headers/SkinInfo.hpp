#ifndef SKININFO
#define SKININFO

#include <vector>
#include <iostream>
#include <fstream>
#include "Chunk.hpp"
#include "ChunkHeader.hpp"
#include "ChunkHeaderKCD.hpp"
#include "ChunkKCD.hpp"

using std::vector;
using std::ifstream;

class SkinInfo{
private:
	uint32_t chunk_amt, chunk_offset, version;
	char* signature;
	void loadHeaders(ifstream& file);
	void loadChunks(ifstream& file);
public:
	// TODO: write method that returns const instead of making chunks public
	vector<Chunk<ChunkHeaderKCD>*> chunks;
	SkinInfo(ifstream& file);
	int getVersion();
};

#endif