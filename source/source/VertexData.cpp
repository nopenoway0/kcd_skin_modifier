#include "VertexData.hpp"
#include <iostream>
#include <vector>
using namespace std;

VertexData::VertexData() : Data(){
}

VertexData::~VertexData(){

}

void VertexData::addCoordinates(Coordinates c){
	data.push_back(c);
}

void VertexData::addCoordinates(float x, float y, float z){
	Coordinates c = {x,y,z};
	data.push_back(c);
}

char* VertexData::asBytes(int& size){
	size = 0;
	float* buffer = new float[sizeof(float) * 3 * data.size()]; 
	for(auto x = 0; x < data.size() * 3; x+=3){
		buffer[x] = data.at((int) (x / 3)).x;
		buffer[x + 1] = data.at((int) (x / 3)).y;
		buffer[x + 2] = data.at((int) (x / 3)).z;
		size += (sizeof(float) * 3);
	}
	return (char*) buffer;
}