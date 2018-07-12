#include "ChunkHeaderVrt.hpp"
#include <iostream>
#include <fstream>
using namespace std;

#define ELEMENT_HEAD_SIZE 4
#define NAME_SIZE 128

void ChunkHeaderVrt::init(){
	element_size = 0;
	_name = new char[NAME_SIZE];
}

ChunkHeaderVrt::ChunkHeaderVrt(ifstream& f){
	init();
	load(f);
}

ChunkHeaderVrt::ChunkHeaderVrt(){
	init();
}

ChunkHeaderVrt::~ChunkHeaderVrt(){
	delete [] _name;
}
void ChunkHeaderVrt::load(ifstream& f){
	//f.read((char*) &element_size, ELEMENT_HEAD_SIZE);
	//f.read(_name, NAME_SIZE);
	//offset = f.tellg();
}
char* ChunkHeaderVrt::asBytes(int& size){
	cerr << "unimplemnted bytes" << endl;
	size = 0; 
	return nullptr;
}

int ChunkHeaderVrt::getOffset(){
	return offset;
}