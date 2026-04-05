/**
 * @file shared_ptr.h
 * @brief Header file for a HPC::shared_ptr for 5614 Assignment 5. 
 * @author R. Morrin
 * @version 2.0
 * @date 2026-03-27
 */
#ifndef SHARED_PTR_H_CJNUWRSH
#define SHARED_PTR_H_CJNUWRSH


#include <print>

namespace HPC
{
	template <typename T>
		class shared_ptr
		{
			public:
				shared_ptr() = delete;
				shared_ptr (T* in);

				// Move Semantics
				shared_ptr(shared_ptr&& rhs);
				shared_ptr& operator=(shared_ptr&& rhs);

				// Copy Semantics
				shared_ptr(shared_ptr const & in);
				shared_ptr& operator=(shared_ptr const & rhs);

				// Destructor
				~shared_ptr ();

				T* get();
				T* release();
				unsigned int use_count();

				T& operator*();
				T operator*() const;

			private:
				T* managed_object;
				unsigned int * counter;
		};

		//Constructor
		template <typename T>
		shared_ptr<T>::shared_ptr (T* in) : managed_object{in}, counter{new unsigned int{1}} {
			std::println("Constructing HPC::shared_ptr object for type {}", typeid(managed_object).name());
			if(managed_object==nullptr){
			std::println(" containing null pointer");
	    	}
	    	else{
			std::println(" with value {}", *managed_object);
	    	}
		}

		//Deconstructor
		template <typename T>
		shared_ptr<T>::~shared_ptr (){
			std::println("Deconstructing HPC::shared_ptr object for type {}", typeid(managed_object).name());
			if(managed_object==nullptr){
			std::println(" containing null pointer");
	    	}
	    	else{
			std::println(" with value {}", *managed_object);
	    	}
			if(*(this->counter) > 1){
				--*(this->counter);
			}
			else if(*(this->counter) == 1){
				--*(this->counter);
				delete this->managed_object;
			}
		}

		//Move constructor
		template <typename T>
		shared_ptr<T>::shared_ptr(shared_ptr&& rhs){
			std::println("Calling move constructor");
			this->managed_object = rhs.managed_object;
    		this->counter = rhs.counter; 

    		rhs.managed_object = nullptr;
    		rhs.counter = nullptr;
		}

		template <typename T>
		shared_ptr<T>& shared_ptr<T>::operator=(shared_ptr&& rhs){
			std::println("Calling move assignment operator");
			if(this->managed_object == rhs.managed_object){ //Checks if same object
				return *this;
			}
			//Checks if old rhs objects count is greater than 1 and decrements count
			if(*(this->counter) > 1) --*(this->counter);
			if(*(this->counter) == 1){ //If count is 1 delete old object.
				delete this->managed_object;
				delete this->counter;
			}
			//Move over data
			this->managed_object = rhs.managed_object;
    		this->counter = rhs.counter; 

			//Set old data to null
    		rhs.managed_object = nullptr;
    		rhs.counter = nullptr;

			return *this;

		}

		//Copy constructor
		template <typename T>
		shared_ptr<T>::shared_ptr(shared_ptr const & in){
			this->managed_object = in.managed_object;
			this->counter = in.counter;
			if (this->counter != nullptr) {
        		++*this->counter; 
    		}
		}

		//Copy Assignment operator
		template <typename T>
		shared_ptr<T>& shared_ptr<T>::operator=(shared_ptr const & rhs){
			if (this == &rhs) {//Check if same object
        		return *this;
    		}

    		if (this->counter != nullptr) {
        		--*this->counter;
        
        		if (*this->counter == 0) { //If last object
            		delete this->managed_object;
            		delete this->counter;
        		}
    		}

    		//Copy over data
    		this->managed_object = rhs.managed_object;
    		this->counter = rhs.counter;

    		//Add to count
    		if (this->counter != nullptr) {
        		++(*this->counter);
    		}
    		return *this;
		}

		template <typename T>
		T* shared_ptr<T>::get(){
			return managed_object;
		}

		template <typename T>
		T* shared_ptr<T>::release(){
			if (this->counter == nullptr) {//Check if null
        		return nullptr;
    		}

			T* saved_ptr = this->managed_object;
			if(*(this->counter) > 1){
				--*(this->counter);
			}
			else if(*(this->counter) == 1){
				delete this->counter;
			}
			this->managed_object = nullptr;
			this->counter = nullptr;

			return saved_ptr;
		}

		template <typename T>
		T& shared_ptr<T>::operator*() {
    		return *(this->managed_object);
		}

		template <typename T>
		unsigned int shared_ptr<T>::use_count(){
			if (this->counter == nullptr) {
        		return 0;
    		}
			return *(this->counter);
		}
} /* HPC */ 

#endif /* end of include guard: SHARED_PTR_H_CJNUWRSH */
