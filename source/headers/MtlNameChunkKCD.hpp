#ifndef MTLNAMECHUNKKCD
#define MTLNAMECHUNKKCD

#include "ChunkKCD.hpp"

class MtlNameChunkKCD : public ChunkKCD{
private:
	int* physics_type;
	int children_amt;
	char* name;
	void init();
public:
	MtlNameChunkKCD(ChunkHeaderKCD& chunk_header);
	
	MtlNameChunkKCD(ChunkHeaderKCD* chunk_header);

	~MtlNameChunkKCD();

	void load(ifstream& f) override;

};

#endif