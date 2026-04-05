/**
 * @file assignment5b.cc
 * @brief Assignment 5 for 5614. Writing your own shared_ptr class
 * @author R. Morrin
 * @version 2.0
 * @date 2026-03-27
 */

#include <print>
#include "shared_ptr.h"

int main()
{
	// Construct shared_ptr to double
    std::println("{:->60}", "");
	std::println("Constructing A");
	HPC::shared_ptr<double> A {new double {10}};
    // Need the cast. formatter not implemented correctly for double* types
	std::println("A.get() = {}", static_cast<void *>(A.get()));
    std::println("A.use_count() = {}", A.use_count());
    std::println("*A = {}", *A);

	// Copy Construct
    std::println("{:->60}", "");
	std::println("Copy Constructing B from A");
	HPC::shared_ptr B {A}; 			// Uses CTAD
	std::println("B.get() = {}", static_cast<void *>(B.get()));
    std::println("B.use_count() = {}", B.use_count());
    std::println("*B = {}", *B);

	// Change via B and print via A
	*B = 100;
	std::println("*A = {}", *A);


	// Copy assign
    std::println("{:->60}", "");
	std::println("Constructing C");
	HPC::shared_ptr C {new double {20}};

	std::println("Before Assignment:");
    std::println("C.get() = {}", static_cast<void *>(C.get()));
    std::println("C.use_count() = {}", C.use_count());
    std::println("*C = ", *C);

	std::println("Copy Assignment C from A");
	C = A;

	std::println("After Assignment:"); 
    std::println("C.get() = {}", static_cast<void *>(C.get()));
    std::println("C.use_count() = {}", C.use_count());
    std::println("*C = {}", *C);

    std::println("{:->60}", "");
	std::println("End of main()");

	return 0;
}
