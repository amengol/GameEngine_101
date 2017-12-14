#ifndef _cAABBsManager_HG_
#define _cAABBsManager_HG_

#include "cAABB.h"
#include "cMesh.h"
#include <map>

class sAABB_Triangle;

class cAABBsManager
{
public:
    cAABBsManager();
    ~cAABBsManager();

    // Generates AABBs from a mesh, respecting a size
    void genAABBs(cMesh* mesh, float size);

    // Generates DebugRenderer triangles
    void genDebugTris();

    // Calculates the longest side of a triangle
    float calcLongestSide(sAABB_Triangle& triangle);

    // Calculates an ID from a vertice
    // Returns false if the vertice position is too long for the format
    bool calcID(glm::vec3 vertice, long long& ID);

    // Tesselates a triangle according to a minimum size
    // Set all tesselated triangles back in a vector
    // Returns false if no need to tesselate
    bool tesselate(sAABB_Triangle* triangle, float size, std::vector<sAABB_Triangle>& tesseleted);

    // Gets the centre point of two vertices
    glm::vec3 getCentreEdge(glm::vec3 vertice1, glm::vec3 vertice2);

    // Generates a vec3 from an ID (sort of a helper function)
    glm::vec3 genVecFromID(long long ID);

private:
   // std::vector<cAABB*> m_AABBs;                         // Stores all AABBs for the mesh
    std::map<long long, cAABB*> m_mapIDtoAABB;             // Map the IDs to the AABBs
    std::vector<sAABB_Triangle> m_vDebugTri;                   // Vector of Debug Triangles
};

#endif // !_cAABBsManager_HG_

