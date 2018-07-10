#ifndef VERTEXCHUNKOBJ
#define VERTEXCHUNKOBJ
#include "Chunk.hpp"
#include "ChunkHeaderOBJ.hpp"
#include "VertexData.hpp"
#include <vector>

class VertexChunkOBJ : public Chunk<ChunkHeaderOBJ>{
private:
	VertexData v_data;
public:
	VertexChunkOBJ(ChunkHeaderOBJ& header);
	VertexChunkOBJ(ChunkHeaderOBJ* header);
	~VertexChunkOBJ();
	vector<Coordinates> getVertices();
	void load(std::ifstream& f) override;
	char* asBytes(int& size) override;
};

#endif