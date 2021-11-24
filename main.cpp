#include <iostream>
#include <vector>
#include "config.h"
#include "receiver_struct.h"
#include "mesh_class.h";
#include "allocating_system.h";
#include <time.h>


int main() {

	LinearMesh2D linearmesh(1.0,1.2,1.0,10,10,10);

	//std::cout << linearmesh.lenght << std::endl;
	int nodes = 5;
	double* const crd = alloc_fem_crd(nodes);
	dealloc_fem(crd);


	return 0;
}
