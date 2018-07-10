#include "ChunkKCD.hpp"

ChunkKCD::ChunkKCD(ChunkHeaderKCD& chunk_header) : Chunk<ChunkHeaderKCD>(chunk_header){}
	
ChunkKCD::ChunkKCD(ChunkHeaderKCD* chunk_header) : Chunk<ChunkHeaderKCD>(chunk_header){}

ChunkKCD::~ChunkKCD(){}

void ChunkKCD::load(ifstream& f){
	f.seekg(chunk_header->getField(OFFSET), ifstream::beg);
}