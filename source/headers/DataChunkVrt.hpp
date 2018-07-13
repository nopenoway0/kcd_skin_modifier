#ifndef DATACHUNKVRT
#define DATACHUNKVRT

#include "ChunkHeaderVrt.hpp"
#include "Chunk.hpp"
#include "VertexData.hpp"
#include <unordered_map>
#include <vector>
class DataChunkVrt : public Chunk<ChunkHeaderVrt>{
private:
	std::unordered_map<std::string, vector<float>> mapped_vertices;
	std::string coordinatesToKey(float x, float y, float z);
public:
	DataChunkVrt(ChunkHeaderVrt& chunk_header);
	DataChunkVrt(ChunkHeaderVrt* chunk_header);
	Coordinates findNewCoords(float x, float y, float z);
	~DataChunkVrt();
	void load(ifstream& f) override;
	char* asBytes(int& s) override;
};

#endif