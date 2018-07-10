#include "VertexChunkOBJ.hpp"
#include "VertexData.hpp"
using namespace std;
#include <string>


VertexChunkOBJ::VertexChunkOBJ(ChunkHeaderOBJ* chunk_header) : Chunk<ChunkHeaderOBJ>(chunk_header){
}

VertexChunkOBJ::VertexChunkOBJ(ChunkHeaderOBJ& chunk_header) : Chunk<ChunkHeaderOBJ>(chunk_header){
}

VertexChunkOBJ::~VertexChunkOBJ(){
	//delete v_data;
}

vector<Coordinates> VertexChunkOBJ::getVertices(){
	return *v_data.getData();
}

void VertexChunkOBJ::load(ifstream& f){
	string line = "22";
	const char delim = ' ';
	float xyz[3];
	// TODO: change to do while loop
	while(!(getline(f, line).eof())){
		auto pos = line.find(delim);
		if(line.length() > 2 && line[0] == 'v' && line[1] == ' '){
			line = line.substr(2, line.length()); // trim out the v and space
			for(auto x = 0; x < 3; x++){
				pos = line.find(delim);
				xyz[x] = stof(line.substr(0, pos));
				line = line.substr(pos + 1, line.length());
			}
			// TODO: breaks everything
			v_data.addCoordinates(xyz[0], xyz[1], xyz[2]);
		}
	}
}

char* VertexChunkOBJ::asBytes(int& size){
	cerr << "asBytes not usable for VertexChunkOBJ because of behavior of the class" << endl;
	throw "asBytes not usable for VertexChunkOBJ because of behavior of the class";
}