#pragma once
#include <iostream>;
#include <vector>;
#include <cmath>;

struct source_struct {
	int id;
	double x, y, z;
	bool check_active = true;
	int nodal_positionX, nodal_positionY, nodal_positionZ;
	int nodal_position = -1;

	void build(int build_id, double build_x, double build_y, double build_z) {
		id = build_id;
		x = build_x; y = build_y; z = build_z;
	}

	void build_alt(int build_id,
		int build_nodal_positionX, int build_nodal_positionY, int build_nodal_positionZ,
		int nex, int ney, int nez,
		double lenght, double depth, double width) {
		//ALERT: no need for get_nodalPosition

		id = build_id;
		if (nez == 0 || width == 0.0) { nodal_positionZ = 1; z = 0.0; };
		nodal_position = build_nodal_positionX
			+ (nex + 1) * (build_nodal_positionY - 1)
			+ (nex + 1) * (ney + 1) * (build_nodal_positionZ - 1);

		//find x , y and z position:
		x = (build_nodal_positionX - 1.0) * (lenght / nex);
		y = (build_nodal_positionY - 1.0) * (depth / ney);
		if (nez > 0 && width > 0.0) { z = (build_nodal_positionZ - 1.0) * (width / nez); };
	}

	void turn_onoff(std::string onoff) {
		if (onoff == "on") { check_active = true; };
		if (onoff == "off") { check_active = false; };
		if (onoff != "on" && onoff != "off") { std::cout << "WARNING: Invalid input! "; };
	}

	void get_nodalPosition(int nex, int ney, int nez,
		double lenght, double depth, double width) {
		//INFO: quadratic linear element only

		//find X nodal position:
		double side_ratio;
		side_ratio = x / lenght;
		if (side_ratio > 1.0) { side_ratio = 1.0; };
		if (side_ratio < 0.0) { side_ratio = 0.0; };
		nodal_positionX = round((nex + 1.0) * side_ratio);
		if (nodal_positionX == 0) { nodal_positionX = 1; };

		//find Y nodal position:
		side_ratio = y / depth;
		if (side_ratio > 1.0) { side_ratio = 1.0; };
		if (side_ratio < 0.0) { side_ratio = 0.0; };
		nodal_positionY = round((ney + 1.0) * side_ratio);
		if (nodal_positionY == 0) { nodal_positionY = 1; };

		//find Z nodal position:
		if (width != 0 || nez != 0) {
			side_ratio = z / width;
			if (side_ratio > 1.0) { side_ratio = 1.0; };
			if (side_ratio < 0.0) { side_ratio = 0.0; };
			nodal_positionZ = round((nez + 1.0) * side_ratio);
			if (nodal_positionZ == 0) { nodal_positionZ = 1; };
		}
		else { nodal_positionZ = 1; };

		//find absolute nodal position:
		nodal_position = nodal_positionX
			+ (nex + 1) * (nodal_positionY - 1)
			+ (nex + 1) * (ney + 1) * (nodal_positionZ - 1);
	}

	void imp() {
		std::cout << "\n   source_struct REPORT \n";
		std::cout << " --------------------------- " << std::endl;
		std::cout << " id..................:  " << id << std::endl;
		std::cout << " x position..........:  " << x << std::endl;
		std::cout << " y position..........:  " << y << std::endl;
		std::cout << " z position..........:  " << z << std::endl;

		if (check_active == true) {
			std::cout << " check_active........: " << "on" << std::endl;
		};
		if (check_active == false) {
			std::cout << " check_active........: " << "off" << std::endl;
		};

		if (nodal_position > 0) {
			std::cout << " node................: " << nodal_position << std::endl;
		}
		else {
			std::cout << " WARNING: Generate nodal position before! " << std::endl;
			std::cout << ".. or check the dimensions of input data. " << std::endl;
		};
	}
};