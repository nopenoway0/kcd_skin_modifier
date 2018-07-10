#include "DataChunkKCD.hpp"
#include "VertexData.hpp"
#include <iostream>
#include <cstring>
using namespace std;

void DataChunkKCD::init(){
	stream_type = 0, element_size = 0, element_amt = 0, prefix = 0;
	padding = new char[10];
}

DataChunkKCD::DataChunkKCD(ChunkHeaderKCD& chunk_header) : ChunkKCD(chunk_header){
	init();
}

DataChunkKCD::DataChunkKCD(ChunkHeaderKCD* chunk_header) : ChunkKCD(chunk_header){
	init();
}

DataChunkKCD::~DataChunkKCD(){
	delete [] padding;
}

void DataChunkKCD::load(ifstream& f){
	ChunkKCD::load(f);
	f.read((char*) &prefix, 4); // data not needed
	f.read((char*) &stream_type, 4);
	f.read((char*) &element_amt, 4);
	f.read((char*) &element_size, 2);
	f.read(padding, 10);// skip next 2 bytes and then skip 8 more as written in https://github.com/Markemp/Cryengine-Converter/blob/github-master/cgf-converter/CryEngine_Core/Chunks/ChunkDataStream_800.cs
	switch(stream_type){
		case VERTICES: loadVertices(f); break;
	}
}

void DataChunkKCD::loadVertices(ifstream& f){
	VertexData* tmpdata = new VertexData();
	float x = 0, y = 0, z = 0;
	// TODO: add exception if element size is not 12 bytes
	for(auto i = 0; i < element_amt; i++){
		f.read((char*) &x, 4);
		f.read((char*) &y, 4);
		f.read((char*) &z, 4);
		Coordinates c = {x, y, z};
		//printf("x:%f y:%f z:%f \n", c.x, c.y, c.z);
		tmpdata->addCoordinates(c);
	}
	data = tmpdata;
}

DataInterface* DataChunkKCD::getInterface(){
	return data;
}

uint32_t DataChunkKCD::getDataChunkType(){
	return stream_type;
}

char* DataChunkKCD::getBodyAsBytes(int& s){
	char* result = data->toBytes(s);
	char* complete_data = new char[s + 14 + 10];
	memcpy(complete_data, &prefix, 4);
	memcpy(&complete_data[4], &stream_type, 4);
	memcpy(&complete_data[8], &element_amt, 4);
	memcpy(&complete_data[12], &element_size, 2);
	memcpy(&complete_data[14], &padding, 10);
	memcpy(&complete_data[24], result, s);
	delete [] result;
	s += 24;
	return complete_data;
}