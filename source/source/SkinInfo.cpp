#include "SkinInfo.hpp"
#include "ChunkFactory.hpp"
#define VERSION_LENGTH 4

using std::cout;
using std::endl;
using std::hex;
using std::cerr;
using std::string;

SkinInfo::SkinInfo(ifstream& file){
	chunk_amt = 0; chunk_offset = 0, version = 0;
	signature = new char[VERSION_LENGTH];
	file.read(signature, VERSION_LENGTH);
	
	file.read((char*) &version, 4);
	file.read((char*) &chunk_amt, 4);
	
	chunks.reserve(chunk_amt);
	file.read((char*) &chunk_offset, 4);

	//TODO: throw exception here and version comparison
	if(chunk_amt > 1000)
		cerr << "error occured loading file info" << endl;
	else{
		loadHeaders(file);
		loadChunks(file);
	}
};

void SkinInfo::loadHeaders(ifstream& file){
	file.seekg(chunk_offset, ifstream::beg);
	for(auto x = 0; x < chunk_amt; x++){
		ChunkHeaderKCD *header = new ChunkHeaderKCD(file);
		chunks.push_back(ChunkFactory::generateChunk(header));
	}
}

void SkinInfo::loadChunks(ifstream& file){
	for(auto x = 0; x < chunks.size(); x++)
		chunks.at(x)->load(file);
}

int SkinInfo::getVersion(){
	return version;
}