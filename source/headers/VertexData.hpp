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
	char* toBytes(int& size) override;
};

#endif