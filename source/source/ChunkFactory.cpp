#include "ChunkFactory.hpp"
#include "ChunkKCD.hpp"
#include "ChunkHeaderKCD.hpp"
#include "MeshChunkKCD.hpp"
#include "MtlNameChunkKCD.hpp"
#include "DataChunkKCD.hpp"

#include <iostream>
#include <map>
using namespace std;

ChunkKCD* ChunkFactory::generateChunk(string type, int version){
	return nullptr;
}

ChunkKCD* ChunkFactory::generateChunk(ChunkHeaderKCD* header){
	int version = header->getField(VERSION), type = header->getField(CHUNKTYPE);
	switch(type){
		case Mesh: return new MeshChunkKCD(header);
		case Helper: cout << "Helper" << endl; break;
		case VertAnim: cout << "VertAnim" << endl; break;
		case BoneAnim: cout << "BoneAnim" << endl; break;
		case GeomNameList: cout << "GeomNameList" << endl; break;
		case BoneNameList: cout << "BoneNameList" << endl; break;
		case MtlList: cout << "MtlList" << endl; break;
		case MRM: cout << "MRM" << endl; break;
		case SceneProps: cout << "SceneProps" << endl; break;
		case Light: cout << "Light" << endl; break;
		case PatchMesh: cout << "PatchMesh" << endl; break;
		case Node: cout << "Node" << endl; break;
		case Mtl: cout << "Mtl" << endl; break;
		case Controller: cout << "Controller" << endl; break;
		case Timing: cout << "Timing" << endl; break;
		case BoneMesh: cout << "BoneMesh" << endl; break;
		case BoneLightBinding: cout << "BoneLightBinding" << endl; break;
		case MeshMorphTarget: cout << "MeshMorphTarget" << endl; break;
		case BoneInitialPos: cout << "BoneInitialPos" << endl; break;
		case SourceInfo: cout << "SourceInfo" << endl; break;
		case MtlName: return new MtlNameChunkKCD(header);
		case ExportFlags: cout << "ExportFlags" << endl; break;
		case DataStream: return new DataChunkKCD(header);
		case MeshSubsets: cout << "MeshSubsets" << endl; break;
		case MeshPhysicsData: cout << "MeshPhysicsData" << endl; break;
		case CompiledBones: cout << "CompiledBones" << endl; break;
		case CompiledPhysicalBones: cout << "CompiledPhysicalBones" << endl; break;

    	case CompiledMorphTargets: cout << "CompiledMorphTargets" << endl; break;
    	case CompiledPhysicalProxies: cout << "CompiledPhysicalProxies" << endl; break;
    	case CompiledIntFaces: cout << "CompiledIntFaces" << endl; break;
    	case CompiledIntSkinVertices: cout << "CompiledIntSkinVertices" << endl; break;
    	case CompiledExt2IntMap: cout << "CompiledExt2IntMap" << endl; break;
    	case BreakablePhysics: cout << "BreakablePhysics" << endl; break;
    	case FaceMap: cout << "FaceMap" << endl; break;
    	case SpeedInfo: cout << "SpeedInfo" << endl; break;
    	case FootPlantInfo: cout << "FootPlantInfo" << endl; break;
    	case BonesBoxes: cout << "BonesBoxes" << endl; break;
    	case FoliageInfo: cout << "FoliageInfo" << endl; break;
    	// Star Citizen versions
    	case CompiledBonesSC: cout << "CompiledBonesSC" << endl; break;
    	case CompiledPhysicalBonesSC: cout << "CompiledPhysicalBonesSC" << endl; break;
    	case CompiledMorphTargetsSC: cout << "CompiledMorphTargetsSC" << endl; break;
    	case CompiledPhysicalProxiesSC: cout << "CompiledPhysicalProxiesSC" << endl; break;
    	case CompiledIntFacesSC: cout << "CompiledIntFacesSC" << endl; break;
    	case CompiledIntSkinVerticesSC: cout << "CompiledIntSkinVerticesSC" << endl; break;
    	case CompiledExt2IntMapSC: cout << "CompiledExt2IntMapSC" << endl; break;
    	case BoneBoxesSC: cout << "BoneBoxesSC" << endl; break;
    	default: return new ChunkKCD(header);
	}
	return new ChunkKCD(header);
}