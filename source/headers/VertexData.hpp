#ifndef VERTEXDATA
#define VERTEXDATA

#include "Data.hpp"
#include <vector>
using std::vector;

typedef struct Coordinates{
    float x, y, z;
} Coordinates;

class VertexData : public Data<vector<Coordinates>>{
public:
	VertexData();
	~VertexData();
	void addCoordinates(Coordinates c);
	void addCoordinates(float x, float y, float z);
	char* asBytes(int& size) override;
};

#endif