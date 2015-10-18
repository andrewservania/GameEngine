#pragma once
#include "glm\glm.hpp"

#include <vector>

class ModelLoader
{
private:
	std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
	std::vector<glm::vec3> temp_vertices;
	std::vector<glm::vec2> temp_uvs;
	std::vector<glm::vec3> temp_normals;

public:
	ModelLoader();
	~ModelLoader();
	bool LoadObject(const char *path,
		std::vector<glm::vec3>& out_vertices,
		std::vector<glm::vec2>& out_uvs,
		std::vector<glm::vec3>& out_normals);
		
};

