#ifndef CHUNKWRITER
#define CHUNKWRITER

#include "ChunkKCD.hpp"
#include "fstream"
#include <string>
class ChunkWriter{
protected:
	std::ifstream f;
	std::string filename;
public:	
	ChunkWriter();
	ChunkWriter(std::string filename);
	virtual ~ChunkWriter();
	virtual void writeChunk(ChunkKCD& chunk)=0;
	virtual void writeChunk(ChunkKCD& chunk, std::ofstream& f)=0;
};

#endif