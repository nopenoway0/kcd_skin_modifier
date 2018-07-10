#include <iostream>
#include "SkinInfo.hpp"

#include <iostream>
#include <fstream>
#include "ChunkWriterKCD.hpp"
#include "ChunkHeaderKCD.hpp"
#include "ChunkFactory.hpp"
#include "DataChunkKCD.hpp"
using namespace std;

int main(){
	// temporary permamenent test name
	ifstream file("bernard.skin", ifstream::in);
	if(!file.is_open()){
		cerr << "file not found" << endl;
		throw "Not found!";
	}
	SkinInfo s(file);
	for(auto chunk : s.chunks){
		if(chunk->getHeader().getField(CHUNKTYPE) == DataStream){
			DataChunkKCD* data_chunk = dynamic_cast<DataChunkKCD*>(chunk);
			if(data_chunk->getDataChunkType() == VERTICES){
				file.close();
				ChunkWriterKCD writer;
				ofstream f("bernard.skin", ofstream::binary | ofstream::out | ofstream::in);
				writer.writeChunk(*data_chunk, f);
				f.close();
			}
		}
	}
	cout << "version: 0x" << hex << s.getVersion();
	return 1;
};