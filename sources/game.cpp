#include "game.hpp"

static Mesh	*loadRoad()
{
	Mesh *mesh = new Mesh(3);
	mesh->begin();
	GLfloat vPos[] = {
		-1.f, 0.f, -1.f,	-1.f, 0.f, 1.f,		1.f, 0.f, 1.f,
		1.f, 0.f, 1.f,		1.f, 0.f, -1.f,		-1.f, 0.f, -1.f,
		-1.f, 2.f, -1.f,	1.f, 2.f, 1.f,		-1.f, 2.f, 1.f,
		1.f, 2.f, 1.f,		-1.f, 2.f, -1.f,	1.f, 2.f, -1.f,
		-1.f, 0.f, -1.f,	-1.f, 2.f, -1.f,	-1.f, 2.f, 1.f,
		-1.f, 2.f, 1.f,		-1.f, 0.f, 1.f,		-1.f, 0.f, -1.f,
		1.f, 0.f, -1.f,		1.f, 2.f, 1.f,		1.f, 2.f, -1.f,
		1.f, 2.f, 1.f,		1.f, 0.f, -1.f,		1.f, 0.f, 1.f,
	};
	GLfloat vColor[] = {
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		.8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f,
		.8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f,
		.8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f,
		.8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f,
	};
	GLfloat vTex[] = {
		0.f, 1.f, 0.f, 0.f, 1.f, 0.f,
		1.f, 0.f, 1.f, 1.f, 0.f, 1.f,
		0.f, 1.f, 1.f, 0.f, 0.f, 0.f,
		1.f, 0.f, 0.f, 1.f, 1.f, 1.f,
		0.f, 0.f, 0.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 1.f, 1.f, 0.f, 1.f,
		1.f, 1.f, 0.f, 0.f, 1.f, 0.f,
	};
	mesh->add(0, GL_FLOAT, 3, (void *)vPos, 24);
	mesh->add(1, GL_FLOAT, 3, (void *)vColor, 24);
	mesh->add(2, GL_FLOAT, 2, (void *)vTex, 24);
	mesh->end();
	return (mesh);
}

static Mesh	*loadClusterRoad()
{
	Mesh *mesh = new Mesh(3);
	mesh->begin();
	GLfloat vPos[] = {
		-1.f, 0.f, -1.f,	-1.f, 0.f, 1.f,		1.f, 0.f, 1.f,
		1.f, 0.f, 1.f,		1.f, 0.f, -1.f,		-1.f, 0.f, -1.f,
		-1.f, 2.f, -1.f,	1.f, 2.f, 1.f,		-1.f, 2.f, 1.f,
		1.f, 2.f, 1.f,		-1.f, 2.f, -1.f,	1.f, 2.f, -1.f,

		-3.f, 0.f, -1.f,	-3.f, 0.f, 1.f,		-1.f, 0.f, 1.f,
		-1.f, 0.f, 1.f,		-1.f, 0.f, -1.f,	-3.f, 0.f, -1.f,
		-3.f, 2.f, -1.f,	-1.f, 2.f, 1.f,		-3.f, 2.f, 1.f,
		-1.f, 2.f, 1.f,		-3.f, 2.f, -1.f,	-1.f, 2.f, -1.f,

		1.f, 0.f, -1.f,		1.f, 0.f, 1.f,		3.f, 0.f, 1.f,
		3.f, 0.f, 1.f,		3.f, 0.f, -1.f,		1.f, 0.f, -1.f,
		1.f, 2.f, -1.f,		3.f, 2.f, 1.f,		1.f, 2.f, 1.f,
		3.f, 2.f, 1.f,		1.f, 2.f, -1.f,		3.f, 2.f, -1.f,

		-3.f, 0.f, -1.f,	-3.f, 2.f, -1.f,	-3.f, 2.f, 1.f,
		-3.f, 2.f, 1.f,		-3.f, 0.f, 1.f,		-3.f, 0.f, -1.f,
		3.f, 0.f, -1.f,		3.f, 2.f, 1.f,		3.f, 2.f, -1.f,
		3.f, 2.f, 1.f,		3.f, 0.f, -1.f,		3.f, 0.f, 1.f,

		-3.f, 0.f, -0.f,	-3.f, 1.f, -0.f,	-1.f, 1.f, -0.f,
		-1.f, 1.f, -0.f,	-1.f, 0.f, -0.f,	-3.f, 0.f, -0.f,
		1.f, 0.f, -0.f,		1.f, 1.f, -0.f,		3.f, 1.f, -0.f,
		3.f, 1.f, -0.f,		3.f, 0.f, -0.f,		1.f, 0.f, -0.f,
	};
	GLfloat vColor[] = {
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,

		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,

		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,

		.8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f,
		.8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f,
		.8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f,
		.8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f,

		.9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f,
		.9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f,
		.9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f,
		.9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f,
	};
	GLfloat vTex[] = {
		0.f, 1.f, 0.f, 0.f, 1.f, 0.f,
		1.f, 0.f, 1.f, 1.f, 0.f, 1.f,
		0.f, 1.f, 1.f, 0.f, 0.f, 0.f,
		1.f, 0.f, 0.f, 1.f, 1.f, 1.f,

		0.f, 1.f, 0.f, 0.f, 1.f, 0.f,
		1.f, 0.f, 1.f, 1.f, 0.f, 1.f,
		0.f, 1.f, 1.f, 0.f, 0.f, 0.f,
		1.f, 0.f, 0.f, 1.f, 1.f, 1.f,

		0.f, 1.f, 0.f, 0.f, 1.f, 0.f,
		1.f, 0.f, 1.f, 1.f, 0.f, 1.f,
		0.f, 1.f, 1.f, 0.f, 0.f, 0.f,
		1.f, 0.f, 0.f, 1.f, 1.f, 1.f,

		0.f, 0.f, 0.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 1.f, 1.f, 0.f, 1.f,
		1.f, 1.f, 0.f, 0.f, 1.f, 0.f,

		0.f, .5f,	0.f, 1.f,	1.f, 1.f,
		1.f, 1.f,	1.f, .5f, 	0.f, .5f,
		0.f, .5f,	0.f, 1.f,	1.f, 1.f,
		1.f, 1.f,	1.f, .5f, 	0.f, .5f,
	};
	mesh->add(0, GL_FLOAT, 3, (void *)vPos, 60);
	mesh->add(1, GL_FLOAT, 3, (void *)vColor, 60);
	mesh->add(2, GL_FLOAT, 2, (void *)vTex, 60);
	mesh->end();
	return (mesh);
}

static Mesh	*loadClusterRoadEnd()
{
	Mesh *mesh = new Mesh(3);
	mesh->begin();
	GLfloat vPos[] = {
		-1.f, 0.f, -1.f,	-1.f, 0.f, 1.f,		1.f, 0.f, 1.f,
		1.f, 0.f, 1.f,		1.f, 0.f, -1.f,		-1.f, 0.f, -1.f,
		-1.f, 2.f, -1.f,	1.f, 2.f, 1.f,		-1.f, 2.f, 1.f,
		1.f, 2.f, 1.f,		-1.f, 2.f, -1.f,	1.f, 2.f, -1.f,

		-1.f, 0.f, -1.f,	-1.f, 2.f, -1.f,	-1.f, 2.f, 1.f,
		-1.f, 2.f, 1.f,		-1.f, 0.f, 1.f,		-1.f, 0.f, -1.f,
		1.f, 0.f, -1.f,		1.f, 2.f, 1.f,		1.f, 2.f, -1.f,
		1.f, 2.f, 1.f,		1.f, 0.f, -1.f,		1.f, 0.f, 1.f,

		-3.f, 0.f, -1.f,	-3.f, 2.f, -1.f,	-1.f, 2.f, -1.f,
		-1.f, 2.f, -1.f,	-1.f, 0.f, -1.f,	-3.f, 0.f, -1.f,
		1.f, 0.f, -1.f,		1.f, 2.f, -1.f,		3.f, 2.f, -1.f,
		3.f, 2.f, -1.f,		3.f, 0.f, -1.f,		1.f, 0.f, -1.f,
	};
	GLfloat vColor[] = {
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,

		.9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f,
		.9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f,
		.9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f,
		.9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f,

		.8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f,
		.8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f,
		.8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f,
		.8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f,
	};
	GLfloat vTex[] = {
		0.f, 1.f, 0.f, 0.f, 1.f, 0.f,
		1.f, 0.f, 1.f, 1.f, 0.f, 1.f,
		0.f, 1.f, 1.f, 0.f, 0.f, 0.f,
		1.f, 0.f, 0.f, 1.f, 1.f, 1.f,

		0.f, 0.f, 0.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 1.f, 1.f, 0.f, 1.f,
		1.f, 1.f, 0.f, 0.f, 1.f, 0.f,

		0.f, 1.f, 0.f, 0.f,	1.f, 0.f,
		1.f, 0.f, 1.f, 1.f, 0.f, 1.f,
		0.f, 1.f, 0.f, 0.f,	1.f, 0.f,
		1.f, 0.f, 1.f, 1.f, 0.f, 1.f,
	};
	mesh->add(0, GL_FLOAT, 3, (void *)vPos, 36);
	mesh->add(1, GL_FLOAT, 3, (void *)vColor, 36);
	mesh->add(2, GL_FLOAT, 2, (void *)vTex, 36);
	mesh->end();
	return (mesh);
}


static Mesh	*loadRoadL()
{
	Mesh *mesh = new Mesh(3);
	mesh->begin();
	GLfloat vPos[] = {
		-1.f, 0.f, -1.f,	-1.f, 0.f, 1.f,		1.f, 0.f, 1.f,
		1.f, 0.f, 1.f,		1.f, 0.f, -1.f,		-1.f, 0.f, -1.f,
		-1.f, 2.f, -1.f,	1.f, 2.f, 1.f,		-1.f, 2.f, 1.f,
		1.f, 2.f, 1.f,		-1.f, 2.f, -1.f,	1.f, 2.f, -1.f,
		-1.f, 0.f, 1.f,		-1.f, 2.f, 1.f,		1.f, 2.f, 1.f,
		1.f, 2.f, 1.f,		1.f, 0.f, 1.f,		-1.f, 0.f, 1.f,
		1.f, 0.f, -1.f,		1.f, 2.f, 1.f,		1.f, 2.f, -1.f,
		1.f, 2.f, 1.f,		1.f, 0.f, -1.f,		1.f, 0.f, 1.f,
	};
	GLfloat vColor[] = {
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		.9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f,
		.9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f,
		.8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f,
		.8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f,
	};
	GLfloat vTex[] = {
		0.f, 1.f, 0.f, 0.f, 1.f, 0.f,
		1.f, 0.f, 1.f, 1.f, 0.f, 1.f,
		0.f, 1.f, 1.f, 0.f, 0.f, 0.f,
		1.f, 0.f, 0.f, 1.f, 1.f, 1.f,
		0.f, 1.f, 0.f, 0.f, 1.f, 0.f,
		1.f, 0.f, 1.f, 1.f, 0.f, 1.f,
		0.f, 0.f, 1.f, 1.f, 0.f, 1.f,
		1.f, 1.f, 0.f, 0.f, 1.f, 0.f,
	};
	mesh->add(0, GL_FLOAT, 3, (void *)vPos, 24);
	mesh->add(1, GL_FLOAT, 3, (void *)vColor, 24);
	mesh->add(2, GL_FLOAT, 2, (void *)vTex, 24);
	mesh->end();
	return (mesh);
}

static Mesh	*loadRoadR()
{
	Mesh *mesh = new Mesh(3);
	mesh->begin();
	GLfloat vPos[] = {
		-1.f, 0.f, -1.f,	-1.f, 0.f, 1.f,		1.f, 0.f, 1.f,
		1.f, 0.f, 1.f,		1.f, 0.f, -1.f,		-1.f, 0.f, -1.f,
		-1.f, 2.f, -1.f,	1.f, 2.f, 1.f,		-1.f, 2.f, 1.f,
		1.f, 2.f, 1.f,		-1.f, 2.f, -1.f,	1.f, 2.f, -1.f,
		-1.f, 0.f, 1.f,		-1.f, 2.f, 1.f,		1.f, 2.f, 1.f,
		1.f, 2.f, 1.f,		1.f, 0.f, 1.f,		-1.f, 0.f, 1.f,
		-1.f, 0.f, -1.f,	-1.f, 2.f, -1.f,	-1.f, 2.f, 1.f,
		-1.f, 2.f, 1.f,		-1.f, 0.f, 1.f,		-1.f, 0.f, -1.f,
	};
	GLfloat vColor[] = {
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		.9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f,
		.9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f,
		.8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f,
		.8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f,
	};
	GLfloat vTex[] = {
		0.f, 1.f, 0.f, 0.f, 1.f, 0.f,
		1.f, 0.f, 1.f, 1.f, 0.f, 1.f,
		0.f, 1.f, 1.f, 0.f, 0.f, 0.f,
		1.f, 0.f, 0.f, 1.f, 1.f, 1.f,
		0.f, 1.f, 0.f, 0.f, 1.f, 0.f,
		1.f, 0.f, 1.f, 1.f, 0.f, 1.f,
		0.f, 0.f, 0.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 0.f, 0.f, 0.f,
	};
	mesh->add(0, GL_FLOAT, 3, (void *)vPos, 24);
	mesh->add(1, GL_FLOAT, 3, (void *)vColor, 24);
	mesh->add(2, GL_FLOAT, 2, (void *)vTex, 24);
	mesh->end();
	return (mesh);
}

static Mesh	*loadRoadLR()
{
	Mesh *mesh = new Mesh(3);
	mesh->begin();
	GLfloat vPos[] = {
		-1.f, 0.f, -1.f,	-1.f, 0.f, 1.f,		1.f, 0.f, 1.f,
		1.f, 0.f, 1.f,		1.f, 0.f, -1.f,		-1.f, 0.f, -1.f,
		-1.f, 2.f, -1.f,	1.f, 2.f, 1.f,		-1.f, 2.f, 1.f,
		1.f, 2.f, 1.f,		-1.f, 2.f, -1.f,	1.f, 2.f, -1.f,
		-1.f, 0.f, 1.f,		-1.f, 2.f, 1.f,		1.f, 2.f, 1.f,
		1.f, 2.f, 1.f,		1.f, 0.f, 1.f,		-1.f, 0.f, 1.f,
	};
	GLfloat vColor[] = {
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		.9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f,
		.9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f
	};
	GLfloat vTex[] = {
		0.f, 1.f, 0.f, 0.f, 1.f, 0.f,
		1.f, 0.f, 1.f, 1.f, 0.f, 1.f,
		0.f, 1.f, 1.f, 0.f, 0.f, 0.f,
		1.f, 0.f, 0.f, 1.f, 1.f, 1.f,
		0.f, 1.f, 0.f, 0.f, 1.f, 0.f,
		1.f, 0.f, 1.f, 1.f, 0.f, 1.f,
	};
	mesh->add(0, GL_FLOAT, 3, (void *)vPos, 18);
	mesh->add(1, GL_FLOAT, 3, (void *)vColor, 18);
	mesh->add(2, GL_FLOAT, 2, (void *)vTex, 18);
	mesh->end();
	return (mesh);
}

static Mesh	*loadPlayer()
{
	Mesh *mesh = new Mesh(2);
	mesh->begin();
	GLfloat vPos[] = {
		-.25f, .5f, -.25f, .25f, .5f, -.25f, -.25f, .0f, -.25f,
		.25f, .0f, -.25f, -.25f, .0f, -.25f, .25f, .5f, -.25f,
		-.25f, .5f, .25f, -.25f, .0f, .25f, .25f, .5f, .25f,
		.25f, .0f, .25f, .25f, .5f, .25f, -.25f, .0f, .25f,
		-.25f, .5f, -.25f, -.25f, .0f, -.25f, -.25f, .5f, .25f,
		-.25f, .0f, .25f, -.25f, .5f, .25f, -.25f, .0f, -.25f,
		.25f, .5f, -.25f, .25f, .5f, .25f, .25f, .0f, -.25f,
		.25f, .0f, .25f, .25f, .0f, -.25f, .25f, .5f, .25f,
		-.25f, .5f, .25f, .25f, .5f, .25f, -.25f, .5f, -.25f,
		.25f, .5f, -.25f, -.25f, .5f, -.25f, .25f, .5f, .25f,
		-.25f, .0f, .25f, -.25f, .0f, -.25f, .25f, .0f, .25f,
		.25f, .0f, -.25f, .25f, .0f, .25f, -.25f, .0f, -.25f
	};
	GLfloat vColor[] = {
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		.9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f,
		.9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f,
		.9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f,
		.9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f,
		.8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f,
		.8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f,
		.8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f,
		.8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f
	};
	mesh->add(0, GL_FLOAT, 3, (void *)vPos, 36);
	mesh->add(1, GL_FLOAT, 3, (void *)vColor, 36);
	mesh->end();
	return (mesh);
}

static Mesh	*loadPoto()
{
	Mesh *mesh = new Mesh(3);
	mesh->begin();
	GLfloat vPos[] = {
		-.4f, 2.f, -.4f, .4f, 2.f, -.4f, -.4f, .0f, -.4f,
		.4f, .0f, -.4f, -.4f, .0f, -.4f, .4f, 2.f, -.4f,

		-.4f, 2.f, -.4f, -.4f, .0f, -.4f, -.4f, 2.f, .4f,
		-.4f, .0f, .4f, -.4f, 2.f, .4f, -.4f, .0f, -.4f,

		.4f, 2.f, -.4f, .4f, 2.f, .4f, .4f, .0f, -.4f,
		.4f, .0f, .4f, .4f, .0f, -.4f, .4f, 2.f, .4f,
	};
	GLfloat vColor[] = {
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,

		.9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f,
		.9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f,

		.9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f,
		.9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f,
	};
	GLfloat vTex[] = {
		0.f, 1.f, .5f, 1.f, 0.f, 0.f,
		.5f, 0.f, 0.f, 0.f, .5f, 1.f,

		.5f, 1.f, .5f, 0.f, 0.f, 1.f,
		0.f, 1.f, 0.f, 0.f, .5f, 1.f,

		0.f, 1.f, .5f, 1.f, 0.f, 0.f,
		.5f, 0.f, 0.f, 0.f, .5f, 1.f,
	};
	mesh->add(0, GL_FLOAT, 3, (void *)vPos, 24);
	mesh->add(1, GL_FLOAT, 3, (void *)vColor, 24);
	mesh->add(2, GL_FLOAT, 2, (void *)vTex, 24);
	mesh->end();
	return (mesh);
}

static Mesh	*loadTrash()
{
	Mesh *mesh = new Mesh(2);
	mesh->begin();
	GLfloat vPos[] = {
		-.1f, .0f, -.1f, -.15f, .5f, -.15f, .15f, .5f, -.15f,
		.15f, .5f, -.15f, .1f, .0f, -.1f, -.1f, .0f, -.1f,
		-.1f, .0f, -.1f, -.1f, .0f, .1f, -.15f, .5f, .15f,
		-.15f, .5f, .15f, -.15f, .5f, -.15f, -.1f, .0f, -.1f,
		.1f, .0f, -.1f, .15f, .5f, -.15f, .15f, .5f, .15f,
		.15f, .5f, .15f, .1f, .0f, .1f, .1f, .0f, -.1f,
		-.15f, .5f, -.15f, -.1f, .7f, -.1f, .15f, .5f, -.15f,
		.15f, .5f, -.15f, -.1f, .7f, -.1f, .1f, .7f, -.1f,
		-.15f, .5f, -.15f, -.15f, .5f, .15f, -.1f, .7f, -.1f,
		-.1f, .7f, -.1f, -.15f, .5f, .15f, -.1f, .7f, -.025f,
		.15f, .5f, -.15f, .1f, .7f, -.1f, .15f, .5f, .15f,
		.1f, .7f, -.1f, .1f, .7f, -.025f, .15f, .5f, .15f,
		.1f, .7f, -.1f, -.1f, .7f, -.1f, .1f, .7f, -.025f,
		-.1f, .7f, -.1f, -.1f, .7f, -.025f, .1f, .7f, -.025f,
		.35f + -.1f, .0f, -.1f,		.35f + -.15f, .5f, -.15f,	.35f + .15f, .5f, -.15f,
		.35f + .15f, .5f, -.15f,	.35f + .1f, .0f, -.1f,		.35f + -.1f, .0f, -.1f,
		.35f + -.1f, .0f, -.1f,		.35f + -.1f, .0f, .1f,		.35f + -.15f, .5f, .15f,
		.35f + -.15f, .5f, .15f,	.35f + -.15f, .5f, -.15f,	.35f + -.1f, .0f, -.1f,
		.35f + .1f, .0f, -.1f,		.35f + .15f, .5f, -.15f,	.35f + .15f, .5f, .15f,
		.35f + .15f, .5f, .15f,		.35f + .1f, .0f, .1f,		.35f + .1f, .0f, -.1f,
		.35f + -.15f, .5f, -.15f,	.35f + -.1f, .7f, -.1f,		.35f + .15f, .5f, -.15f,
		.35f + .15f, .5f, -.15f,	.35f + -.1f, .7f, -.1f,		.35f + .1f, .7f, -.1f,
		.35f + -.15f, .5f, -.15f,	.35f + -.15f, .5f, .15f,	.35f + -.1f, .7f, -.1f,
		.35f + -.1f, .7f, -.1f,		.35f + -.15f, .5f, .15f,	.35f + -.1f, .7f, -.025f,
		.35f + .15f, .5f, -.15f,	.35f + .1f, .7f, -.1f,		.35f + .15f, .5f, .15f,
		.35f + .1f, .7f, -.1f,		.35f + .1f, .7f, -.025f,	.35f + .15f, .5f, .15f,
		.35f + .1f, .7f, -.1f,		.35f + -.1f, .7f, -.1f,		.35f + .1f, .7f, -.025f,
		.35f + -.1f, .7f, -.1f,		.35f + -.1f, .7f, -.025f,	.35f + .1f, .7f, -.025f,
		.7f + -.1f, .0f, -.1f,		.7f + -.15f, .5f, -.15f,	.7f + .15f, .5f, -.15f,
		.7f + .15f, .5f, -.15f,		.7f + .1f, .0f, -.1f,		.7f + -.1f, .0f, -.1f,
		.7f + -.1f, .0f, -.1f,		.7f + -.1f, .0f, .1f,		.7f + -.15f, .5f, .15f,
		.7f + -.15f, .5f, .15f,		.7f + -.15f, .5f, -.15f,	.7f + -.1f, .0f, -.1f,
		.7f + .1f, .0f, -.1f,		.7f + .15f, .5f, -.15f,		.7f + .15f, .5f, .15f,
		.7f + .15f, .5f, .15f,		.7f + .1f, .0f, .1f,		.7f + .1f, .0f, -.1f,
		.7f + -.15f, .5f, -.15f,	.7f + -.1f, .7f, -.1f,		.7f + .15f, .5f, -.15f,
		.7f + .15f, .5f, -.15f,		.7f + -.1f, .7f, -.1f,		.7f + .1f, .7f, -.1f,
		.7f + -.15f, .5f, -.15f,	.7f + -.15f, .5f, .15f,		.7f + -.1f, .7f, -.1f,
		.7f + -.1f, .7f, -.1f,		.7f + -.15f, .5f, .15f,		.7f + -.1f, .7f, -.025f,
		.7f + .15f, .5f, -.15f,		.7f + .1f, .7f, -.1f,		.7f + .15f, .5f, .15f,
		.7f + .1f, .7f, -.1f,		.7f + .1f, .7f, -.025f,		.7f + .15f, .5f, .15f,
		.7f + .1f, .7f, -.1f,		.7f + -.1f, .7f, -.1f,		.7f + .1f, .7f, -.025f,
		.7f + -.1f, .7f, -.1f,		.7f + -.1f, .7f, -.025f,	.7f + .1f, .7f, -.025f,
	};
	GLfloat vColor[] = {
		.90f, .90f, .90f, .90f, .90f, .90f, .90f, .90f, .90f,
		.90f, .90f, .90f, .90f, .90f, .90f, .90f, .90f, .90f,
		.75f, .75f, .75f, .75f, .75f, .75f, .75f, .75f, .75f,
		.75f, .75f, .75f, .75f, .75f, .75f, .75f, .75f, .75f,
		.75f, .75f, .75f, .75f, .75f, .75f, .75f, .75f, .75f,
		.75f, .75f, .75f, .75f, .75f, .75f, .75f, .75f, .75f,
		.0f, .0f, .90f, .0f, .0f, .90f, .0f, .0f, .90f,
		.0f, .0f, .90f, .0f, .0f, .90f, .0f, .0f, .90f,
		.825f, .825f, .825f, .825f, .825f, .825f, .825f, .825f, .825f,
		.825f, .825f, .825f, .825f, .825f, .825f, .825f, .825f, .825f,
		.825f, .825f, .825f, .825f, .825f, .825f, .825f, .825f, .825f,
		.825f, .825f, .825f, .825f, .825f, .825f, .825f, .825f, .825f,
		.95f, .95f, .95f, .95f, .95f, .95f, .95f, .95f, .95f,
		.95f, .95f, .95f, .95f, .95f, .95f, .95f, .95f, .95f,

		.90f, .90f, .90f, .90f, .90f, .90f, .90f, .90f, .90f,
		.90f, .90f, .90f, .90f, .90f, .90f, .90f, .90f, .90f,
		.75f, .75f, .75f, .75f, .75f, .75f, .75f, .75f, .75f,
		.75f, .75f, .75f, .75f, .75f, .75f, .75f, .75f, .75f,
		.75f, .75f, .75f, .75f, .75f, .75f, .75f, .75f, .75f,
		.75f, .75f, .75f, .75f, .75f, .75f, .75f, .75f, .75f,
		.5f, .5f, .5f, .5f, .5f, .5f, .5f, .5f, .5f,
		.5f, .5f, .5f, .5f, .5f, .5f, .5f, .5f, .5f,
		.825f, .825f, .825f, .825f, .825f, .825f, .825f, .825f, .825f,
		.825f, .825f, .825f, .825f, .825f, .825f, .825f, .825f, .825f,
		.825f, .825f, .825f, .825f, .825f, .825f, .825f, .825f, .825f,
		.825f, .825f, .825f, .825f, .825f, .825f, .825f, .825f, .825f,
		.95f, .95f, .95f, .95f, .95f, .95f, .95f, .95f, .95f,
		.95f, .95f, .95f, .95f, .95f, .95f, .95f, .95f, .95f,

		.90f, .90f, .90f, .90f, .90f, .90f, .90f, .90f, .90f,
		.90f, .90f, .90f, .90f, .90f, .90f, .90f, .90f, .90f,
		.75f, .75f, .75f, .75f, .75f, .75f, .75f, .75f, .75f,
		.75f, .75f, .75f, .75f, .75f, .75f, .75f, .75f, .75f,
		.75f, .75f, .75f, .75f, .75f, .75f, .75f, .75f, .75f,
		.75f, .75f, .75f, .75f, .75f, .75f, .75f, .75f, .75f,
		.0f, .90f, .0f, .0f, .90f, .0f, .0f, .90f, .0f,
		.0f, .90f, .0f, .0f, .90f, .0f, .0f, .90f, .0f,
		.825f, .825f, .825f, .825f, .825f, .825f, .825f, .825f, .825f,
		.825f, .825f, .825f, .825f, .825f, .825f, .825f, .825f, .825f,
		.825f, .825f, .825f, .825f, .825f, .825f, .825f, .825f, .825f,
		.825f, .825f, .825f, .825f, .825f, .825f, .825f, .825f, .825f,
		.95f, .95f, .95f, .95f, .95f, .95f, .95f, .95f, .95f,
		.95f, .95f, .95f, .95f, .95f, .95f, .95f, .95f, .95f,
	};
	mesh->add(0, GL_FLOAT, 3, (void *)vPos, 126);
	mesh->add(1, GL_FLOAT, 3, (void *)vColor, 126);
	mesh->end();
	return (mesh);
}

static Mesh	*loadFont(void)
{
	float u = 1.f / 16.f;
	float v = 1.f / 8.f;
	Mesh *mesh = new Mesh(3);
	mesh->begin();
	GLfloat vPos[] = {
		0.f, 0.f,	50.f, 0.f,	50.f, 50.f,
		50.f, 50.f,	0.f, 50.f,	0.f, 0.f,
	};
	GLfloat vTex[] = {
		0.f, 0.f,	u, 0.f,	u, v,
		u, v,		0.f, v,	0.f, 0.f
		// u * 1.f, v * 4.f,	u * 2.f, v * 4.f,	u * 2.f, v * 5.f,
		// u * 2.f, v * 5.f,	u * 1.f, v * 5.f,	u * 1.f, v * 4.f
	};
	mesh->add(0, GL_FLOAT, 2, (void *)vPos, 6);
	mesh->add(1, GL_FLOAT, 2, (void *)vTex, 6);
	mesh->end();
	return (mesh);
}

Game::Game(Window *win) : _win(win)
{
	if (!_sample.loadFragmentShader("shaders/sample.frag"))
		throw std::logic_error("Erreur chargement sample.frag");
	if (!_sample.loadVertexShader("shaders/sample.vert"))
		throw std::logic_error("Erreur chargement sample.vert");
	if (!_sample.build())
		throw std::logic_error("Erreur compilation shader(player)");
	if (!_playerShader.loadFragmentShader("shaders/player.frag"))
		throw std::logic_error("Erreur chargement player.frag");
	if (!_playerShader.loadVertexShader("shaders/player.vert"))
		throw std::logic_error("Erreur chargement player.vert");
	if (!_playerShader.build())
		throw std::logic_error("Erreur compilation shader(font)");
	if (!_fontShader.loadFragmentShader("shaders/font.frag"))
		throw std::logic_error("Erreur chargement font.frag");
	if (!_fontShader.loadVertexShader("shaders/font.vert"))
		throw std::logic_error("Erreur chargement font.vert");
	if (!_fontShader.build())
		throw std::logic_error("Erreur compilation shader(font)");

	_cluster[0] = loadClusterRoad();
	_cluster[1] = loadClusterRoadEnd();
	_road[0] = loadRoad();
	_road[1] = loadRoadL();
	_road[2] = loadRoadR();
	_road[3] = loadRoadLR();
	_player = loadPlayer();
	_items[0] = loadTrash();
	_items[1] = loadPoto();
	_textures[0] = Texture::LoadBMP("textures/uvtemplate.bmp");
	_textures[1] = Texture::LoadBMP("textures/poto.bmp");
	_font = Texture::LoadPNG("textures/font.png");
	_meshFont = loadFont();
	_playerPos = Vec3f(0, 0.5, 0);
	_fakeRot = 0.f;
	while (_rooms.size() < 10)
		addRoom();
}

Game::~Game()
{
	while (!_rooms.empty())
	{
		delete _rooms.back();
		_rooms.pop_back();
	}
	delete _textures[0];
	delete _textures[1];
	delete _road[0];
	delete _road[1];
	delete _road[2];
	delete _road[3];
	delete _cluster[0];
	delete _cluster[1];
	delete _player;
	delete _items[0];
	delete _items[1];
	delete _meshFont;
	delete _font;
}


void				Game::renderStart(void)
{

}

void				Game::updateStart(void)
{ }

void				Game::renderGame(void)
{
	static Mat4 identity = Mat4::Identity();
	Mat4 viewRot = Quat::Angle(Vec3f(-22.5, _fakeRot, 0)).toMat4();
	glEnable(GL_DEPTH_TEST);
	Mat4 view = Mat4::Translate(0, -1.5, 1 - _playerPos[2]) * viewRot;
	_sample.bind();
	_sample.uniformMat4((GLchar *)"projection", (GLfloat *)&(_win->projection));
	_sample.uniformMat4((GLchar *)"view", (GLfloat *)&view);
	_sample.uniformMat4((GLchar *)"model", (GLfloat *)&identity);
	glActiveTexture(GL_TEXTURE0);
	_sample.uniform1i((GLchar *)"uTexture", 0);
	_textures[0]->bind();
	Mat4 model;
	for (std::vector<Room *>::iterator it = _rooms.begin() ; it != _rooms.end(); ++it)
	{
		model = Mat4::Translate((*it)->getPos());
		_sample.uniformMat4((GLchar *)"model", (GLfloat *)&model);
		(*it)->getRender()->render(GL_TRIANGLES);
		// if ((*it)->getRender() == _cluster[1])
		// 	_road[0]->render(GL_TRIANGLES);
		if ((*it)->getItem() >= 0)
		{
			if ((*it)->getItem() == 1)
				_textures[1]->bind();
			model = Mat4::Translate((*it)->getPos() + (*it)->getItemPos());
			_sample.uniformMat4((GLchar *)"model", (GLfloat *)&model);
			_items[(*it)->getItem()]->render(GL_TRIANGLES);
			_textures[0]->bind();
		}
		if ((*it)->getType() > 0)
		{
			// std::vector<Room *>::iterator itNext = it + 1;
			// if (itNext != _rooms.end())
			int i = 1;
			while (i < 20)
			{
				std::vector<Room *>::iterator itNext = it + i;
				if (itNext == _rooms.end())
					break ;
				if (((*it)->getType() & 1) == 1)
				{
					Mat4 rot = Quat::AxisAngle(Vec3f(0, 1, 0), TORADIANS(-90)).toMat4();
					model = rot * Mat4::Translate((*it)->getPos() + Vec3f(-2 * i, 0, 0));
					_sample.uniformMat4((GLchar *)"model", (GLfloat *)&model);
					(*itNext)->getRender()->render(GL_TRIANGLES);
					// if ((*itNext)->getRender() == _cluster[1])
					// 	_road[0]->render(GL_TRIANGLES);
					if ((*itNext)->getItem() >= 0)
					{
						Vec3f iPos = (*it)->getItemPos();
						model = rot *  Mat4::Translate((*it)->getPos() + Vec3f(-2 * i, 0, 0) + Vec3f(iPos[2], 0, iPos[1]));
						_sample.uniformMat4((GLchar *)"model", (GLfloat *)&model);
						_items[(*itNext)->getItem()]->render(GL_TRIANGLES);
					}
				}
				if (((*it)->getType() & 2) == 2)
				{
					Mat4 rot = Quat::AxisAngle(Vec3f(0, 1, 0), TORADIANS(90)).toMat4();
					model = rot * Mat4::Translate((*it)->getPos() + Vec3f(2 * i, 0, 0));
					_sample.uniformMat4((GLchar *)"model", (GLfloat *)&model);
					(*itNext)->getRender()->render(GL_TRIANGLES);
					// if ((*itNext)->getRender() == _cluster[1])
					// 	_road[0]->render(GL_TRIANGLES);
					if ((*itNext)->getItem() >= 0)
					{
						Vec3f iPos = (*it)->getItemPos();
						model = rot *  Mat4::Translate((*it)->getPos() + Vec3f(2 * i, 0, 0) + Vec3f(-iPos[2], 0, iPos[1]));
						_sample.uniformMat4((GLchar *)"model", (GLfloat *)&model);
						_items[(*itNext)->getItem()]->render(GL_TRIANGLES);
					}
				}
				i++;
			}
			break ;
		}
	}
	_playerShader.bind();
	_playerShader.uniformMat4((GLchar *)"projection", (GLfloat *)&(_win->projection));
	_playerShader.uniformMat4((GLchar *)"view", (GLfloat *)&view);
	model = Mat4::Translate(_playerPos + _playerOffset);
	_playerShader.uniformMat4((GLchar *)"model", (GLfloat *)&model);
	_player->render(GL_TRIANGLES);

	/* ******************* */
	/* *RENDER 2D        * */
	/* ******************* */
	glDisable(GL_DEPTH_TEST);
	_fontShader.bind();
	_fontShader.uniformMat4((GLchar *)"projection", (GLfloat *)&(_win->ortho));
	glActiveTexture(GL_TEXTURE0);
	_fontShader.uniform1i((GLchar *)"uTexture", 0);
	_font->bind();
	static float u = 1.f / 16.f;
	static float v = 1.f / 8.f;
	int j = (int)_playerPos[2];
	int i = 0;
	while (j != 0)
	{
		model = Mat4::Translate(Vec2f(1280.f - (i + 1.f) * 50.f, 0));
		_fontShader.uniformMat4((GLchar *)"model", (GLfloat *)&model);
		int k = 47 + (j % 10);
		j /= 10;
		_fontShader.uniform2fv((GLchar *)"id", (float)(k % 16) * u, (float)(k / 16) * v);
		_meshFont->render(GL_TRIANGLES);
		i++;
	}
}

void				Game::updateGame(void)
{
	static float fakeRotStep = 11.25f;//5.625f;//11.25f;

	if (glfwGetKey(_win->getGLFW(), GLFW_KEY_A) == GLFW_PRESS || glfwGetKey(_win->getGLFW(), GLFW_KEY_LEFT) == GLFW_PRESS)
	{
		_playerOffset[0] -= .05f;
		if (_playerOffset[0] < -0.4f)
			_playerOffset[0] = -0.4f;
		if (((*(_rooms.begin()))->getType() & 1) == 1 && _fakeRot == 0.f)
			_fakeRot = fakeRotStep;
	}
	else if (glfwGetKey(_win->getGLFW(), GLFW_KEY_D) == GLFW_PRESS || glfwGetKey(_win->getGLFW(), GLFW_KEY_RIGHT) == GLFW_PRESS)
	{
		_playerOffset[0] += .05f;
		if (_playerOffset[0] > 0.4f)
			_playerOffset[0] = 0.4f;
		if (((*(_rooms.begin()))->getType() & 2) == 2 && _fakeRot == 0.f)
			_fakeRot = -fakeRotStep;
	}
	else
	{
		if (_playerOffset[0] > 0.f)
		{
			_playerOffset[0] -= .05f;
			if (_playerOffset[0] < 0.f)
				_playerOffset[0] = 0.f;
		}
		else if (_playerOffset[0] < 0.f)
		{
			_playerOffset[0] += .05f;
			if (_playerOffset[0] > 0.f)
				_playerOffset[0] = 0.f;
		}
	}
	if (_playerOffset[1] == 0.f)
	{
		if (glfwGetKey(_win->getGLFW(), GLFW_KEY_W) == GLFW_PRESS || glfwGetKey(_win->getGLFW(), GLFW_KEY_UP) == GLFW_PRESS)
		{
			_velocity = 0.15f;
		}
	}
	if (_velocity != 0.f)
	{
		_playerOffset[1] += _velocity;
		_velocity -= 0.01f;
	}
	if (_playerOffset[1] < 0.01f)
	{
		_playerOffset[1] = 0.f;
		_velocity = 0.f;
	}
	float speed = (0.11f + (_playerPos[2] / 5000.f));
	if (_fakeRot < 0.f)
	{
		_fakeRot -= fakeRotStep;
		if (_fakeRot < -90.f)
			_fakeRot = -90.f;
	}
	if (_fakeRot > 0.f)
	{
		_fakeRot += fakeRotStep;
		if (_fakeRot > 90.f)
			_fakeRot = 90.f;
	}
	_playerPos[2] += speed;
	std::vector<Room *>::iterator it = _rooms.begin();
	while (it != _rooms.end())
	{
		Vec3f pos = (*it)->getPos();
		if (pos[2] + 1.5f > _playerPos[2])
		{
			break ;
		}
		else
		{
			if ((*it)->getType() > 0 && _fakeRot == 0.f)
			{
				reset();
				return ;
			}
			_rooms.erase(it);
			it = _rooms.begin();
			_fakeRot = 0.f;
		}
	}
	while (_rooms.size() < 30)
		addRoom();
	Vec3f v = _playerPos + _playerOffset;
	static Vec3f size(0.25f, 0.f, 0.25f);
	if (!_rooms.empty())
		if ((*(_rooms.begin()))->itemCollid(v, size))
			reset();
}

void				Game::reset(void)
{
	_state = -1;
	std::cout << "Score: " << _playerPos[2] << std::endl;
	while (!_rooms.empty())
	{
		delete _rooms.back();
		_rooms.pop_back();
	}
	_playerPos = Vec3f(0, 0.5, 0);
	_playerOffset = Vec3f(0);
	_fakeRot = 0.f;
	while (_rooms.size() < 10)
		addRoom();
}

void				Game::renderLost(void)
{
	glDisable(GL_DEPTH_TEST);
	_fontShader.bind();
	_fontShader.uniformMat4((GLchar *)"projection", (GLfloat *)&(_win->ortho));
	glActiveTexture(GL_TEXTURE0);
	_fontShader.uniform1i((GLchar *)"uTexture", 0);
	_font->bind();
	static float u = 1.f / 16.f;
	static float v = 1.f / 8.f;
	const char *str = "YOU LOST !";
	int i = -1;
	Mat4 model;
	while (str[++i])
	{
		model = Mat4::Translate(Vec2f(50.f + (i + 1.f) * 50.f, 50.f));
		_fontShader.uniformMat4((GLchar *)"model", (GLfloat *)&model);
		int k = (int)str[i] - 1;
		_fontShader.uniform2fv((GLchar *)"id", (float)(k % 16) * u, (float)(k / 16) * v);
		_meshFont->render(GL_TRIANGLES);
	}
	str = "PRESS SPACE";
	i = -1;
	while (str[++i])
	{
		model = Mat4::Translate(Vec2f(50.f + (i + 1.f) * 50.f, 620.f));
		_fontShader.uniformMat4((GLchar *)"model", (GLfloat *)&model);
		int k = (int)str[i] - 1;
		_fontShader.uniform2fv((GLchar *)"id", (float)(k % 16) * u, (float)(k / 16) * v);
		_meshFont->render(GL_TRIANGLES);
	}
}

void				Game::updateLost(void)
{

}

void				Game::nextState(void)
{
	if (_state == 0)
		_state = 1;
	else if (_state == 1)
		_state = 2;
	else if (_state == 2)
		_state = 1;
	else if (_state == -1)
		_state = 0;
}


void	Game::render(void)
{
	glClearColor((_state == -1) ? .5f : 0.f, 0.f, (_state == 0) ? .5f : 0.f, 1);
	if (_state == 0)
		renderStart();
	else if (_state == 1 || _state == 2)
		renderGame();
	else if (_state == -1)
		renderLost();
}

void	Game::update(void)
{
	if (_state == 0)
		updateStart();
	else if (_state == 1)
		updateGame();
	else if (_state == -1)
		updateLost();

}

void	Game::addRoom(void)
{
	static int lastType = 0;
	static int clusterType = 0;
	if (_rooms.empty())
	{
		_rooms.push_back(new Room(_road[0]));
	}
	else
	{
		Room *back = _rooms.back();
		int type = 0;
		if (back->getPos()[2] > 10.f && back->getType() == 0 && lastType == 0 && clusterType == 0)
 		{
			int random = std::rand() % 35;
			if (random == 1)
			{
				lastType = 10;
				type = 1;
			}
			if (random == 11)
			{
				lastType = 10;
				type = 2;
			}
			if (random == 21)
			{
				lastType = 10;
				type = 3;
			}
		}
		Mesh *renderer = _road[type];
		if (type == 0 && (std::rand() % 8 == 3 || clusterType > 0))
		{
			if (clusterType == 0)
				clusterType = 4;
			if (clusterType == 1)
				renderer = _cluster[1];
			else if (clusterType > 1)
				renderer = _cluster[0];
			// else if (clusterType == 2)
			// 	renderer = _cluster[1];
			clusterType--;
		}
		Room *r = new Room(renderer, type, back->getPos() + Vec3f(0, 0, 2));
		if (back->getPos()[2] > 5.f && type == 0 && lastType < 7)
		{
			if (back->getItem() == -1 && back->getType() == 0)
			{
				if (std::rand() % 12 == 3)
				{
					r->setItem(0);
					int random = std::rand() % 3;
					if (random == 0)
						r->setItemPos(Vec3f(0.1f, 0, 0));
					else if (random == 1)
						r->setItemPos(Vec3f(-0.35f, 0, 0));
					else
						r->setItemPos(Vec3f(-0.85f, 0, 0));
				}
				else if (std::rand() % 12 == 8)
				{
					r->setItem(1);
					int random = std::rand() % 2;
					if (random == 0)
						r->setItemPos(Vec3f(0.6f, 0, 0));
					else
						r->setItemPos(Vec3f(-0.6f, 0, 0));
				}
			}
		}
		_rooms.push_back(r);
	}
	if (lastType > 0)
		lastType--;
}
