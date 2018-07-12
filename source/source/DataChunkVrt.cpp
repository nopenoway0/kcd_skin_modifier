#include "DataChunkVrt.hpp"
#include "Chunk.hpp"
#include "VertexData.hpp"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

DataChunkVrt::DataChunkVrt(ChunkHeaderVrt& chunk_header) : Chunk<ChunkHeaderVrt>(chunk_header){

}
DataChunkVrt::DataChunkVrt(ChunkHeaderVrt* chunk_header) : Chunk<ChunkHeaderVrt>(chunk_header){

}

DataChunkVrt::~DataChunkVrt(){

}

string DataChunkVrt::coordinatesToKey(float x, float y, float z){
	int x_int, y_int, z_int;
	x_int = trunc(x * 10000);
	y_int = trunc(y * 10000);
	z_int = trunc(z * 10000);
	return to_string(x_int) + to_string(y_int) + to_string(z_int);
}

void DataChunkVrt::load(ifstream& f){
	f.seekg(0, ifstream::beg);
	float og_x = 0, og_y, og_z = 0;
	float x = 0, y = 0, z = 0;
	int count = 0;
	while(f.good()){
		f.read((char*) &og_x, 4);
		f.read((char*) &x, 4);

		f.read((char*) &og_y, 4);
		f.read((char*) &y, 4);

		f.read((char*) &og_z, 4);
		f.read((char*) &z, 4);

		vector<float> old_cords, new_cords;

		new_cords.push_back(x); new_cords.push_back(y); new_cords.push_back(z);
		string key = coordinatesToKey(og_x, og_y, og_z);
		mapped_vertices[key] = new_cords;
	}
}

Coordinates DataChunkVrt::findNewCoords(float x, float y, float z){
	Coordinates c = {};
	string key = coordinatesToKey(x, y, z);
	if(mapped_vertices.find(key) != mapped_vertices.end()){
		vector<float> f = mapped_vertices[key];
		c.x = f[0]; c.y = f[1]; c.z = f[2];
	}
	else{
		printf("couldn't find x: %f y: %f z: %f with key %s\n", x, y, z, key.c_str());
		throw "invalid vertex";
	}
	//printf("new coords x: %f y: %f z: %f\n", f[0], f[1], f[2]);
	//Coordinates c = {f[0], f[1], f[2]};
	return c;
}

char* DataChunkVrt::asBytes(int& s){
	cerr << "as bytes not implemented" << endl;
	s = 0;
	return nullptr;
}