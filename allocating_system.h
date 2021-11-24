#pragma once
#include "config.h";

//Allocating System

//=========================== FEM ===============================

//Mesh alloc
double* const alloc_fem_crd(int const& nodes)
{
	double* const crd_ptr = new double[nodes * 3];
	return crd_ptr;
}
int* const alloc_fem_cnn(int const& elements, int nodes_per_elem)
{
	int* const cnn_ptr = new int[elements * nodes_per_elem];
	return cnn_ptr;
}

//Pressure alloc
double* const alloc_fem_u(double const& dof, double const& steps) 
{
	double* const u_ptr = new double[dof * steps];
	return u_ptr;
}
double* const alloc_fem_v(double const& dof, double const& steps)
{
	double* const v_ptr = new double[dof * steps];
	return v_ptr;
}
double* const alloc_fem_a(double const& dof, double const& steps)
{
	double* const a_ptr = new double[dof * steps];
	return a_ptr;
}

//Discrete problem alloc
double* const alloc_fem_stiff(double const& dof) 
{
	double* const k_ptr = new double[dof * dof];
	return k_ptr;
}
double* const alloc_fem_damp(double const& dof)
{
	double* const c_ptr = new double[dof * dof];
	return c_ptr;
}
double* const alloc_fem_mass(double const& dof)
{
	double* const m_ptr = new double[dof * dof];
	return m_ptr;
}
double* const alloc_fem_diag(double const& dof)
{
	double* const d_ptr = new double[dof];
	return d_ptr;
}

//Material model alloc
double* const alloc_fem_mm1(double const& dof)
{
	double* const mm1_ptr = new double[dof];
	return mm1_ptr;
}
double* const alloc_fem_mm2(double const& dof)
{
	double* const mm2_ptr = new double[dof];
	return mm2_ptr;
}

//Newmark integration alloc
double* const alloc_fem_nm1(double const& dof)
{
	double* const nm1_ptr = new double[dof];
	return nm1_ptr;
}
double* const alloc_fem_nm2(double const& dof)
{
	double* const nm2_ptr = new double[dof];
	return nm2_ptr;
}
double* const alloc_fem_nm3(double const& dof)
{
	double* const nm3_ptr = new double[dof];
	return nm3_ptr;
}

//Element 2d bilinear
double* const alloc_fem_lin2d()
{
	double* const lin2d_ptr = new double[4];
	return lin2d_ptr;
}

//Deallocation
void dealloc_fem(double* const p) {
	delete[] p;
}


//============================ DF ===============================


