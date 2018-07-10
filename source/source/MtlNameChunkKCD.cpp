#include "MtlNameChunkKCD.hpp"

#define MTL_NAME_LENGTH 128

#include <iostream>
using namespace std;

void MtlNameChunkKCD::init(){
	name = new char[MTL_NAME_LENGTH];
	children_amt = 0;
}

MtlNameChunkKCD::MtlNameChunkKCD(ChunkHeaderKCD& chunk_header) : ChunkKCD(chunk_header){
	init();
}
MtlNameChunkKCD::MtlNameChunkKCD(ChunkHeaderKCD* chunk_header) : ChunkKCD(chunk_header){
	init();
}
MtlNameChunkKCD::~MtlNameChunkKCD(){

}

void MtlNameChunkKCD::load(ifstream& f){
	ChunkKCD::load(f);
	f.read(name, MTL_NAME_LENGTH);
	f.read((char*) &children_amt, 4);
	physics_type = new int[children_amt];
	for(auto x = 0; x < children_amt; x++)
		f.read((char*) &physics_type[x], 4);
}