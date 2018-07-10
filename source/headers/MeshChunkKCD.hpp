#ifndef MESHCHUNKKCD
#define MESHCHUNKKCD

#include "ChunkKCD.hpp"

class MeshChunkKCD : public ChunkKCD{
private:
	typedef struct Bounds{
		int8_t x, y,z ;
	} Bounds;
	int32_t flags1, flags2, vertices_amt, indices_amt, vertsubset_amt, vertAnimID, vertice_data, normals_data, uv_data, mesh_subsets;
	int32_t color_data, color_2_data, indice_data, tangent_data, vert_uv_data, coeff_data, bonemap_data, facemap_data, deformation_data;
	Bounds min, max;
	int32_t* physics_data;
	void init_vars();
public:
	MeshChunkKCD(ChunkHeaderKCD& chunk_header);
	
	MeshChunkKCD(ChunkHeaderKCD* chunk_header);

	~MeshChunkKCD();

	void load(ifstream& f) override;

	char* asBytes(int& size) override;
};

#endif