#include "ChunkWriter.hpp"
#include <string>
using namespace std;

ChunkWriter::ChunkWriter(){
	filename = "";
}

ChunkWriter::ChunkWriter(string filename){
	this->filename = filename;
	f.open(filename);
}

ChunkWriter::~ChunkWriter(){
	if(f.is_open())
		f.close();
}