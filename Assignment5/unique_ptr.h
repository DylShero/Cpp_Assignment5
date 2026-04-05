#ifndef UNIQUE_PTR_H_GUUARPK6
#define UNIQUE_PTR_H_GUUARPK6

#include <print>

namespace HPC
{
    template <typename T>
	class unique_ptr
	{
	    public:
		unique_ptr() = delete;
		// Constructor. Write all definitions outside class body
		unique_ptr (T*);

		/// TODO: Take care of declarations for move and copy semantics
		/// 	  Write function definitions outside class body

		//Deleted copy constructor
		unique_ptr(const unique_ptr& in) = delete;
		//Deletec copy assignment operator
    	unique_ptr& operator=(const unique_ptr& rhs) = delete;

		//Move constructor
		unique_ptr(unique_ptr&& in);
		//Move assignment operator
    	unique_ptr& operator=(unique_ptr&& rhs);

		// Destructor
		~unique_ptr ();
		
		//  Returns raw pointer to managed object
		T* get();

		/// TODO: Release ownership and return pointer to managed object
		/// Write definition outside class body
		/// Note that this does not delete the managed object. It just
		/// releases the ownship from the shared pointer.
		T* release();

		/// TODO:  overload * operator to dereference underlying managed object
		/// Write definitions outside class body
		T& operator*();
		T operator*() const;

	    private:
		T *managed_object;
	};


    /**
     * @brief  Destructor for unique_ptr<T>
     * @tparam T Type for managed object
     */
    template <typename T> 
	unique_ptr<T>::~unique_ptr (){
	    std::print("Deleting HPC::unique_ptr for type {}", typeid(managed_object).name());
	    if(managed_object==nullptr){
		std::println(" containing null pointer");
	    }
	    else{
		std::println(" with value {}", *managed_object);
	    }
	    delete managed_object;
	}

	//Constructor
	template <typename T>
	unique_ptr<T>::unique_ptr(T* in): managed_object{in}{
		std::print("Constructing HPC::unique_ptr for type {}", typeid(managed_object).name());
		if(managed_object==nullptr){
		std::println(" containing null pointer");
	    }
	    else{
		std::println(" with value {}", *managed_object);
	    }
	}
	

	//Move constructor
	template <typename T>
	unique_ptr<T>::unique_ptr(unique_ptr&& in){
		std::println("Calling HPC::unique_ptr move constructor");
		this->managed_object = in.managed_object;
		in.managed_object = nullptr;
	}

	//Move assignment
	template <typename T>
	unique_ptr<T>& unique_ptr<T>::operator=(unique_ptr<T>&& rhs){
		if(this->managed_object == rhs.managed_object){
			std::println("Called on same object");
			return *this;
		}
		std::println("Calling HPC::unique_ptr move assignment operator");
		delete this->managed_object;
		this->managed_object = rhs.managed_object;
		rhs.managed_object = nullptr;
		return *this;
	}

	template <typename T>
	T& unique_ptr<T>::operator*(){
		return *(this->managed_object);
	}

	template <typename T>
	T unique_ptr<T>::operator*() const{
		return this->managed_object;
	}

	template <typename T>
	T* unique_ptr<T>::get(){
		return managed_object;
	}

	template <typename T>
	T* unique_ptr<T>::release(){
		T* saved_ptr = this->managed_object;
		this->managed_object = nullptr;
		return saved_ptr;
	}

} /* HPC */ 

#endif /* end of include guard: UNIQUE_PTR_H_GUUARPK6 */
