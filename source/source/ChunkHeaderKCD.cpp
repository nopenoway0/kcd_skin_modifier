#include "ChunkHeaderKCD.hpp"

#include <iostream>
#include <cstring>

using namespace std;
#define FIELDS 5
ChunkHeaderKCD::ChunkHeaderKCD(){

}

ChunkHeaderKCD::ChunkHeaderKCD(ifstream& in){
	fields = new int[FIELDS];
	load(in);
}

ChunkHeaderKCD::~ChunkHeaderKCD(){
	//delete fields;
}

void ChunkHeaderKCD::load(ifstream& in){
	header_location = in.tellg();
	uint16_t tmp = 0;
	in.read((char*) &tmp, 2);
	fields[CHUNKTYPE] = 0 | tmp;
	fields[CHUNKTYPE] += 0xCCCBF000;
	in.read((char*) &tmp, 2);
	fields[VERSION] = 0 | tmp;
	for(auto x = 2; x < FIELDS; x++)
		in.read((char*) &fields[x], 4);
}

// TODO: fix when returning fields < 2 the return value needs to be recasted to uint16_t
int ChunkHeaderKCD::getField(int field){
	if(field > FIELDS)
		throw "Not valid field";
	return fields[field];
}

uint32_t ChunkHeaderKCD::getHeaderStart(){
	return header_location;
}

char* ChunkHeaderKCD::asBytes(int& size){
	size = 16;
	char* bytes = new char[16];
	uint16_t chunktype = fields[CHUNKTYPE] - 0xCCCBF000;
	memcpy(bytes, &chunktype, 2);
	memcpy(&bytes[2], &fields[VERSION], 2);
	memcpy(&bytes[4], &fields[ID], 4);
	memcpy(&bytes[8], &fields[SIZE], 4);
	memcpy(&bytes[12], &fields[OFFSET], 4);
	return bytes;
}