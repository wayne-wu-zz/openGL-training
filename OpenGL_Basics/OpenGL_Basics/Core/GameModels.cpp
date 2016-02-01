#include "GameModels.h"
using namespace Models; 

GameModels::GameModels() {
	//constructor
}

GameModels::~GameModels() {
	//deconstructor

	std::map<std::string, Model>::iterator it;
	for (it = GameModelList.begin(); it != GameModelList.end(); ++it) {
		//delete VAO and VBOs (if many)
		unsigned int* p = &it->second.vao;
		glDeleteVertexArrays(1, p);
		glDeleteBuffers(it->second.vbos.size(), &it->second.vbos[0]);
		it->second.vbos.clear();
	}
	GameModelList.clear();
}

void GameModels::CreateTriangleModel(const std::string& gameModelName) {
	unsigned int vao; //VAO handler
	unsigned int vbo; //VBO handler

	glGenVertexArrays(1, &vao); //create VAO container and get ID for it
	glBindVertexArray(vao); //build to OpenGL context

	//geometry vertices
	std::vector<VertexFormat> vertices;
	vertices.push_back(VertexFormat(glm::vec3(0.25, -0.25, 0.0), glm::vec4(1,0,0,1)));
	vertices.push_back(VertexFormat(glm::vec3(-0.25, -0.25, 0.0), glm::vec4(0,1,0,1)));
	vertices.push_back(VertexFormat(glm::vec3(0.25, 0.25, 0.0), glm::vec4(0,0,1,1)));

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo); //bind to context
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * 3, &vertices[0], GL_STATIC_DRAW);
	
	//buffer is binded to context, set pipes
	glEnableVertexAttribArray(0); //ready to be filled with data
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)0); //Tell OpenGL about our data format

	glEnableVertexAttribArray(1); //-> colour @ pipe1
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)12); //12 is offset from the first pipe. Position have 3attribute*4bytes

	Model myModel; 
	myModel.vao = vao;
	myModel.vbos.push_back(vbo);
	GameModelList[gameModelName] = myModel;
}

void GameModels::DeleteModel(const std::string& gameModelName) 
{
	Model model = GameModelList[gameModelName]; //gameModelName will map to the specific vao
	unsigned int p = model.vao; 
	glDeleteVertexArrays(1, &p); 
	glDeleteBuffers(model.vbos.size(), &model.vbos[0]);
	model.vbos.clear();
	GameModelList.erase(gameModelName);
}

unsigned int GameModels::GetModel(const std::string& gameModelName) 
{
	return GameModelList[gameModelName].vao;
}