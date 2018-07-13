#include <iostream>
#include "SkinInfo.hpp"

#include <iostream>
#include <fstream>
#include "ChunkWriterKCD.hpp"
#include "ChunkHeaderKCD.hpp"
#include "ChunkFactory.hpp"
#include "DataChunkKCD.hpp"
#include "VertexData.hpp"
#include "VertexChunkOBJ.hpp"
#include "ChunkHeaderOBJ.hpp"
#include "DataChunkVrt.hpp"
#include "ChunkHeaderVrt.hpp"
#include "math.h"
using namespace std;

// TODO: fix minor rounding errors across all coordinates
void rotate90x(Coordinates& c)
{
	float tmp = c.z;
	c.z = c.y * -1;
	c.y = tmp * 1;
}

VertexChunkOBJ readOBJ(string filename);
DataChunkVrt readVrt(string filename);

int main(int argc, char *argv[]){
	if(argc <= 2){
		cout << "--usage\nfilename.verts filename.skin" << endl;
		exit(1);
	}
	string vrt_file = string(argv[1]);
	string skin_file = string(argv[2]);
	string dest_file = (argc <= 3) ? skin_file : string(argv[3]);
	auto vrt_chunk = readVrt(vrt_file);
	ifstream file(skin_file, ifstream::in | ifstream::binary);
	if(!file.is_open()){
		cerr << "file not found" << endl;
		throw "Not found!";
	}
	file.seekg(0, ifstream::beg);
	SkinInfo s(file);
	file.close();
	for(auto chunk : s.chunks){
		if(chunk->getHeader().getField(CHUNKTYPE) == DataStream){
			DataChunkKCD* data_chunk = static_cast<DataChunkKCD*>(chunk);
			if((uint16_t) data_chunk->getDataChunkType() == VERTICES){
				cerr << "found vertex chunk" << endl;
				// modify data chunk here
				Data<vector<Coordinates>>* data = static_cast<Data<vector<Coordinates>>*>(data_chunk->getInterface());
				vector<Coordinates>* coords = data->getData();
				for(auto x = 0; x < coords->size(); x++){
					Coordinates* c = &(coords->at(x));
					try{
						Coordinates new_c = vrt_chunk.findNewCoords(c->x, c->z, c->y);
						c->x = new_c.x; c->y = new_c.y; c->z = new_c.z;
					}catch(...){
						//TODO: add valid error message
						cerr << "error occured" << endl;
					}
				}
				// end modification here 
				ChunkWriterKCD writer;
				ofstream f(dest_file, ofstream::binary | ofstream::out | ofstream::in);
				writer.writeChunk(*data_chunk, f);
				f.close();
			}
		}
	}
	file.close();
	return 1;
};

VertexChunkOBJ readOBJ(string filename){
	cout << "filename for obj: " << filename << endl;
	ifstream f(filename, ifstream::in);
	VertexChunkOBJ chunk(new ChunkHeaderOBJ(f));
	f.seekg(0, ifstream::beg);
	chunk.load(f);
	f.close();
	return chunk;
}

DataChunkVrt readVrt(string filename){
	cout << filename << " opened" << endl;
	ifstream f(filename, ifstream::in | ifstream::binary);
	DataChunkVrt chunk(new ChunkHeaderVrt(f));
	chunk.load(f);
	f.close();
	return chunk;
}