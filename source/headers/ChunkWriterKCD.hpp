#ifndef CHUNKWRITERKCD
#define CHUNKWRITERKCD

#include "ChunkWriter.hpp"
#include "ChunkKCD.hpp"
#include "ChunkHeaderKCD.hpp"
#include <unordered_map>
#include <string>
#include <fstream>
#include <vector>
#include <utility>

class ChunkWriterKCD : public ChunkWriter{
private:
	static std::unordered_map<std::string, std::vector<std::pair<int, int>>> file_offsets;
	void writeHeader(ChunkHeaderKCD header, std::ofstream& f);
	void writeBody(ChunkKCD& chunk, std::ofstream& f);
public:
	ChunkWriterKCD(std::string filename);
	ChunkWriterKCD();
	~ChunkWriterKCD();
	void writeChunk(ChunkKCD& chunk) override;
	void writeChunk(ChunkKCD& chunk, std::ofstream& f) override;
};

#endif