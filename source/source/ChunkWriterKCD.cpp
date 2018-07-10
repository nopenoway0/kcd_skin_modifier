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
	uint32_t buffer = 0;
	// TODO: add calculation for changing offset, if multiple chunks are to be written and additional information added
	printf("writing header: %hu %hu %d %d %d\n", header.getField(CHUNKTYPE), (uint16_t) header.getField(VERSION), header.getField(ID), header.getField(SIZE), header.getField(OFFSET));
	f.seekp(header.getHeaderStart(), ofstream::beg);
	buffer = (uint16_t) header.getField(CHUNKTYPE);
	buffer -= 0xCCCBF000;
	f.write((char*) &buffer, 2);
	buffer = (uint16_t) header.getField(VERSION);
	f.write((char*) &buffer, 2);
	for(auto x = 2; x < FIELDS; x++){
		buffer = header.getField(x);
		f.write((char*) &buffer, 4);
	}
	if(f.bad())
		cerr << "error while modifying file" << endl;
}

void ChunkWriterKCD::writeBody(ChunkKCD& chunk, std::ofstream& f){
	f.seekp(chunk.getHeader().getField(OFFSET), std::ofstream::beg);
	int size = 0;
	char* data = chunk.getBodyAsBytes(size);
	f.write(data, size);
	delete[] data;
}