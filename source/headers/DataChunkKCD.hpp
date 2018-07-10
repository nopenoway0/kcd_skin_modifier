#ifndef DATACHUNKKCD
#define DATACHUNKKCD

#include "ChunkKCD.hpp"
#include "Data.hpp"
#include "VertexData.hpp"
#include "DataInterface.hpp"
#include <string>

enum DataStreamTypeEnum{
    VERTICES,
    NORMALS,
    UVS,
    COLORS,
    COLORS2,
    INDICES,
    TANGENTS,
    SHCOEFFS,
    SHAPEDEFORMATION,
    BONEMAP,
    FACEMAP,
    VERTMATS,
    UNKNOWN1,   // Prey Normals?
    UNKNOWN2,
    UNKNOWN3,
    VERTSUVS,
    UNKNOWN5,
    UNKNOWN6
};

class DataChunkKCD : public ChunkKCD{
private:
    uint32_t stream_type, element_amt, prefix;
    char* padding;
    uint16_t element_size;
    DataInterface* data;
    std::string type;
    void loadVertices(ifstream& f);
    void init();
public:

	DataChunkKCD(ChunkHeaderKCD& chunk_header);
	
	DataChunkKCD(ChunkHeaderKCD* chunk_header);

	~DataChunkKCD();

    DataInterface* getInterface();

	void load(ifstream& f) override;

    uint32_t getDataChunkType();

    char* asBytes(int& s) override;
};

#endif