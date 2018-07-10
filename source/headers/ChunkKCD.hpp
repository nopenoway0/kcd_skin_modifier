#ifndef CHUNKKCD
#define CHUNKKCD

#include "Chunk.hpp"
#include "ChunkHeaderKCD.hpp"
class ChunkKCD : public Chunk<ChunkHeaderKCD>{
private:
public:
	ChunkKCD(ChunkHeaderKCD& chunk_header);
	
	ChunkKCD(ChunkHeaderKCD* chunk_header);

	~ChunkKCD();

	void load(ifstream& f) override;
};

#endif