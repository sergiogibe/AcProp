#pragma once
#include <iostream>;
#include <cmath>;

//SETUP:

//DISCRETE PROBLEM:
std::string discret_system = "FEM"; //FEM or DF
int nex = 50;
int ney = 50;
int nez = 50;

//ENVIRONMENT DESIGN:
double lenght = 2.0;
double depth = 2.0;
double width = 2.0;
bool sponge_layer = false;
int n_receivers = 60;
int n_shots = 4;

//WAVE PROPAGATION:
double new_beta = 0;
double new_gamma = 0.5;

//OPTIMIZATION PARAMETERS:
double pseudo_time = 0.05;
int opt_niter = 50;
int adv_niter = 2;
int red_niter = 4;
bool reset_psd_time = true;

//REACT-DIFFUSION:
double tau = 5 * pow(10, -6);

//GRADIENT MODIFIERS:
double kappa = 0;
double norm_par = 0.1;


//MATERIAL MODELING:
std::string mat_mod = "LS"; // FWI, SIMP, LS

//SIMP SETUP:

//FWI SETUP:

//LS SETUP:

//EXPERIMENTAL SETUP:
bool run_exp = true;

//INCLUSIONS: