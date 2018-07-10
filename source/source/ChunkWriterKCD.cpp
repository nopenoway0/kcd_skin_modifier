#include "ChunkWriterKCD.hpp"
#include "ChunkHeaderKCD.hpp"
#include "ChunkFactory.hpp"
#include "DataChunkKCD.hpp"

#include <iostream>
#include <string>
using namespace std;

#define BUFFER_SIZE 1024
#define FIELDS 5
ChunkWriterKCD::ChunkWriterKCD(std::string filename) : ChunkWriter(filename){

}
ChunkWriterKCD::ChunkWriterKCD() : ChunkWriter(){

}
ChunkWriterKCD::~ChunkWriterKCD(){

}
void ChunkWriterKCD::writeChunk(ChunkKCD& chunk){

}
void ChunkWriterKCD::writeChunk(ChunkKCD& chunk, std::ofstream& f){
	ChunkHeaderKCD header = chunk.getHeader();
	writeHeader(header, f);
	writeBody(chunk, f);
}

void ChunkWriterKCD::writeHeader(ChunkHeaderKCD header, std::ofstream& f){
	int size = 0;
	char* result = header.asBytes(size);
	f.seekp(header.getHeaderStart(), ofstream::beg);
	f.write(result, size);
	delete [] result;
}

void ChunkWriterKCD::writeBody(ChunkKCD& chunk, std::ofstream& f){
	f.seekp(chunk.getHeader().getField(OFFSET), std::ofstream::beg);
	int size = 0;
	char* data = chunk.asBytes(size);
	f.write(data, size);
	delete [] data;
}