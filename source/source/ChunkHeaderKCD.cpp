#include "ChunkHeaderKCD.hpp"

#include <iostream>

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
	in.read((char*) &fields[0], 2);
	fields[CHUNKTYPE] += 0xCCCBF000;
	fields[VERSION] = 0;
	in.read((char*) &fields[VERSION], 2);
	for(auto x = 2; x < FIELDS; x++)
		in.read((char*) &fields[x], 4);
}

int ChunkHeaderKCD::getField(int field){
	if(field > FIELDS)
		throw "Not valid field";
	return fields[field];
}

uint32_t ChunkHeaderKCD::getHeaderStart(){
	return header_location;
}