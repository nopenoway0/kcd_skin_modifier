#include "MeshChunkKCD.hpp"
#include <iostream>
using namespace std;

#define PHYSICS_SIZE 4


void MeshChunkKCD::init_vars(){
	flags1 = 0, flags2 = 0, vertices_amt = 0, indices_amt = 0, vertsubset_amt = 0, vertAnimID = 0, vertice_data = 0, normals_data = 0, uv_data = 0, mesh_subsets = 0;
	color_data = 0, color_2_data = 0, indice_data = 0, tangent_data = 0, vert_uv_data = 0, coeff_data = 0, bonemap_data = 0, facemap_data = 0, deformation_data = 0;
	physics_data = new int[PHYSICS_SIZE];
}

MeshChunkKCD::MeshChunkKCD(ChunkHeaderKCD& chunk_header) : ChunkKCD(chunk_header){
	init_vars();
}

MeshChunkKCD::MeshChunkKCD(ChunkHeaderKCD* chunk_header) : ChunkKCD(chunk_header){
	init_vars();
}

MeshChunkKCD::~MeshChunkKCD(){}

// TODO: double check proper loading complete
void MeshChunkKCD::load(ifstream& f){
	ChunkKCD::load(f);
	f.read((char*) &flags1, 4);
	f.read((char*) &flags2, 4);
	f.read((char*) &vertices_amt, 4);
	f.read((char*) &indices_amt, 4);
	f.read((char*) &vertsubset_amt, 4);
	f.read((char*) &mesh_subsets, 4);
	f.read((char*) &vertAnimID, 4);
	f.read((char*) &vertice_data, 4);
	f.read((char*) &normals_data, 4);
	f.read((char*) &uv_data, 4);
	f.read((char*) &color_data, 4);
	f.read((char*) &color_2_data, 4);
	f.read((char*) &indice_data, 4);
	f.read((char*) &tangent_data, 4);
	f.seekg(16, ifstream::cur); // skip 16 bytes
	for(auto x = 0; x < PHYSICS_SIZE; x++)
		f.read((char*) &physics_data[x], 4);

	f.read((char*) &vert_uv_data, 4);
	f.read((char*) &coeff_data, 4);
	f.read((char*) &deformation_data, 4);
	f.read((char*) &bonemap_data, 4);
	f.read((char*) &facemap_data, 4);

	f.read((char*) &min.x, 1);
	f.read((char*) &min.y, 1);
	f.read((char*) &min.z, 1);

	f.read((char*) &max.x, 1);
	f.read((char*) &max.y, 1);
	f.read((char*) &max.z, 1);

	cout << mesh_subsets << endl;
}