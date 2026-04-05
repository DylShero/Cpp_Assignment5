/**
 * @file assignment4a.cc
 * @brief  Main function for assignment4a. Assignment 5, 5614
 * 	This should work with the HPC::unique_ptr class you write
 * 	
 * @author R. Morrin
 * @version 3.0
 * @date 2026-03-27
 */
#include "unique_ptr.h"
#include <memory>
#include <print>

int main(void)
{
	// Constructor
	HPC::unique_ptr<double> A {new double(1.0)};
	HPC::unique_ptr A2 {new double(2.0)}; 		// Uses CTAD

	// error: no matching function for call to ‘HPC::unique_ptr::unique_ptr()’
	 /*
	  *HPC::unique_ptr<double> B ;   	
	  */

	// error: use of deleted function ‘HPC::unique_ptr::unique_ptr(const HPC::unique_ptr&)’
	/*
	 * HPC::unique_ptr C {A};   	
	 */

	HPC::unique_ptr D {new double(3.0)};

	// error: use of deleted function ‘HPC::unique_ptr& HPC::unique_ptr::operator=(const HPC::unique_ptr&)’
	/*
	 * D = A; 			
	 */

	// Move Constructor
	HPC::unique_ptr E {std::move(D)};

	// Overloaded dereference operator
	std::println("E = {}", *E);
	*E=4;
	std::println("E = {}", *E);

	// Move assignment
	D=std::move(E);
	std::println("D =  {}", *D);

	return 0;
}
