#pragma once
#include "mathUtils.h"
#include "vector"
#include "string"

class vertexBuffer;
class indexBuffer;
class constantBuffer;

class gameObject
{
public:
	gameObject();
	gameObject(std::string name);
	virtual ~gameObject();

	virtual void init();
	virtual void release();

	virtual void update(matrix4x4 world_camera_temp, float top, float bottom, float right, float left); //update every frame
	virtual void draw(); // draw object to scene

	enum gameObjectType
	{
		none = 0,
		mesh,
		cube
	};

	void loadVertexBuffer(void* shader_byte_code, size_t size_byte_shader); // load vertex buffer to object
	constantBuffer* getConstantBuffer() const;

	std::string getName();
	void setName(std::string name);
	gameObjectType getType();

	matrix4x4 m_transform = matrix4x4::identityMatrix(); // transform of object(public);
	// remove because of transform class?
	void setPosition(vector3 position);
	void setScale(vector3 scale);
	void setRotation(vector3 rotation);

private:

	//buffer data
	vertexBuffer* m_vertex_buffer;
	indexBuffer* m_index_buffer;

protected:
	std::string m_name = "";
	gameObjectType m_game_object_type = none;

	constantBuffer* m_constant_buffer;

	//scene data
	bool m_isActive = true; // active status
	//mesh data
	std::vector<vertex> m_vertex_list; // list of object vertices
	std::vector<unsigned int> m_index_list; // list of object indices
};
