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
		std::println(" with value ", *managed_object);
	    }
	    delete managed_object;
	}

} /* HPC */ 

#endif /* end of include guard: UNIQUE_PTR_H_GUUARPK6 */
