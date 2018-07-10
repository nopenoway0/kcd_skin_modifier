#include "ChunkHeaderOBJ.hpp"
using namespace std;

ChunkHeaderOBJ::ChunkHeaderOBJ() : ChunkHeader(){
}

ChunkHeaderOBJ::ChunkHeaderOBJ(ifstream& f) : ChunkHeader(){
	load(f);
}

ChunkHeaderOBJ::~ChunkHeaderOBJ(){

}

void ChunkHeaderOBJ::load(ifstream& f){
	header = "";
	string line = "";
	getline(f, line);
	while(line[0] != 'v'){
		header += line;
		getline(f, line);
	}
	f.seekg((line.length() + 1) * -1, ifstream::cur);
}

char* ChunkHeaderOBJ::asBytes(int& size){
	char* buffer = new char[header.length()];
	for(auto x = 0; x < header.length(); x++)
		buffer[x] = header[x];
	size = header.length();
	return buffer;
}