#include <iostream>
#include "List.h"

template <typename T>

class ListArray : public List<T> {

	private:
		T* arr;
		int max;
		int n;
		static const int MINSIZE = 2;
		
		void resize(int new_size){
			new T* aux[new_size];
			aux = arr;
			delete[arr];
			//actualizar puntero arr para que paunte a la nueva direccion de memoria
			max = new_size;


		}

	public:
		ListArray(){
			
		}

		~ListArray(){
			
		}

		T operator[](int pos){
			get(pos);
		}

		friend std::iostream &operator<<(std::iostream &out, const ListArray<T> &list){
			std::cout << " " << arr[out] << std::endl;
		}



};
