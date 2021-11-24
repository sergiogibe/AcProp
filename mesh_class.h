#pragma once
#include <iostream>;
#include <vector>;
#include <cmath>;
#include "receiver_struct.h";
#include "source_struct.h";

class Mesh {
//Atributes:
public:
	float lenght, depth, width;
	int nex, ney, nez;
private:
	

//Methods:
public:
	Mesh(float build_lenght, float build_depth, float build_width,
		 int build_nex, int build_ney, int build_nez) {
		//Standard build
		lenght = build_lenght;
		depth = build_depth;
		width = build_width;
		nex = build_nex;
		ney = build_ney;
		nez = build_nez;
	}
	Mesh(float build_lenght, float build_depth, float build_width, float ratio) {
		//Overload build
		lenght = build_lenght;
		depth = build_depth;
		width = build_width;
		if (ratio >= 1 || ratio <= 0) { ratio = 0.05; };
		nex = round(build_lenght / ratio);
		ney = round(build_depth / ratio);
		nez = round(build_width / ratio);
	}
private:

};

class LinearMesh2D : public Mesh {
//Atributes:
public:
	int const nodes_per_element = 4;
	float element_sizeX = -1; float element_sizeY = -1;
private:

//Methods:
public:
	LinearMesh2D(float build_lenght, float build_depth, float build_width,
		int build_nex, int build_ney, int build_nez) :
		Mesh(build_lenght, build_depth, build_width, build_nex, build_ney, build_nez) {}

	LinearMesh2D(float build_lenght, float build_depth, float build_width, float ratio) :
		Mesh(build_lenght, build_depth, build_width, ratio) {}

	void fillMesh(float* crd, int* cnn) {
		//crd é o ponteiro que aponta para o local ja
		//reservado previamente na heap como array 1D (contiguo)
		//para aproveitar local cache. Analogo a cnn.

		element_sizeX = lenght / nex;
		element_sizeY = depth / ney;
		
		//aqui precisa fazer indexacao correta.
		for (int i = 0; i < (nex + 1)*(nez + 1); i++) {
			crd[i] = element_sizeX * i;
			crd[i] = element_sizeY * i;
		}
	}
	
private:

};

