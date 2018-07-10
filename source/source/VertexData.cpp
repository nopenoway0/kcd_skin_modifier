#include "VertexData.hpp"
#include <iostream>
#include <vector>
using namespace std;

VertexData::VertexData() : Data(typeid(this)){
}

VertexData::~VertexData(){

}

void VertexData::addCoordinates(Coordinates c){
	data.push_back(c);
}

char* VertexData::toBytes(int& size){
	size = sizeof(float) * 3 * data.size(); // size of float * 3 floats per coordinate * number of coordinates
	float* buffer = new float[size / sizeof(float)]; 
	for(auto x = 0; x < data.size() * 3; x+=3){
		buffer[x] = data.at((int) (x / 3)).x;
		buffer[x + 1] = data.at((int) (x / 3)).y;
		buffer[x + 2] = data.at((int) (x / 3)).z;
	}
	return (char*) buffer;
}