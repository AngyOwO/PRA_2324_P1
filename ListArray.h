#ifndef LISTARRAY_H
#define LISTARRAY_H


#include <string>
#include <exception>
#include <ostream>
#include "List.h"

#define TRUE 1
#define FALSE 0

template <typename T>

class ListArray : public List<T> {

	private:

		/*-------------------------------------------------*/
		/*			*arr			   */
		/*-------------------------------------------------*/
		/*						   */
		/* DESCRIPCION:					   */
		/* Puntero al inicio del array que almacenara los  */
		/* elementos de la lista de forma contigua. Estos  */
		/* elementos son de tipo T generico.               */
		/*						   */
		/*-------------------------------------------------*/

		T* arr;


		/*-------------------------------------------------*/
		/*			 max  			   */
		/*-------------------------------------------------*/
		/*						   */
		/* DESCRIPCION:					   */
		/* Tamaño actual del array. Podrá alterarse        */
		/* durante la vida de la lista, en caso necesario  */
		/* (ver metodo resize(int)).                       */
		/*						   */
		/*-------------------------------------------------*/

		int max;


		/*-------------------------------------------------*/
		/*			  n   			   */
		/*-------------------------------------------------*/
		/*						   */
		/* DESCRIPCION:					   */
		/* Numero de elementos que contiene la lista.      */
		/*						   */
		/*-------------------------------------------------*/

		int n;


		/*-------------------------------------------------*/
		/*			MINSIZE 		   */
		/*-------------------------------------------------*/
		/*						   */
		/* DESCRIPCION:					   */
		/* Tamanyo minimo del array. Debera inicializarse  */
		/* a 2.                                            */
		/* 						   */
		/*-------------------------------------------------*/

		static const int MINSIZE = 2;


		/*-------------------------------------------------*/
		/*			resize			   */
		/*-------------------------------------------------*/
		/*						   */
		/* DESCRIPCION:					   */
		/* Metodo que se encargara de redimensionar el     */
		/* array al tamaño especificado, con el objetivo   */
		/* de incrementar su capacidad (si esta lleno), o  */
		/* bien para reducirla (si esta "demasiado vacío").*/
		/*						   */
		/*-------------------------------------------------*/
		
		void resize(int new_size)
		{
			max = new_size;
			n = new_size;
		}

	public:

		/*-------------------- INSERT ---------------------*/
		void insert(int pos, T e) override
		{
			if( !(pos < 0 || pos > size()) )
			{
				if(pos == 0)
					prepend(e);
				else if(pos == size())
					append(e);
				else
				{
					int i, j, new_size = n + 1;

					T *aux = new T[new_size];

					for(i = 0, j = 0; i < new_size; i++)
					{
						if(pos == i)
							aux[i] = e;
						else
						{
							aux[i] = arr[j];
							j++;
						}
					}

					delete[] arr;
					arr = aux;
					resize(new_size);
				}
			}
			else
				throw std::out_of_range("Posicion no valida");
		}



		/*-------------------- APPEND ---------------------*/
		void append(T e) override
		{
			int new_size = size() + 1;
			T *aux = new T[new_size];

			for(int i = 0; i < size(); i++)
				aux[i] = arr[i];

			aux[size()] = e;

			delete[] arr;
			arr = aux;
			resize(new_size);
		}



		/*------------------- PREPEND ---------------------*/
		void prepend(T e) override
		{
			int new_size;

			(n == 0) ? (new_size = 1) : (new_size = size() + 1);

			T *aux = new T[new_size];

			aux[0] = e;

			if(n != 0)
			{
				for(int i = 0; i < size(); i++)
					aux[i+1] = arr[i];
			}

                        delete[] arr;
                        arr = aux;
                        resize(new_size);

		}



		/*-------------------- REMOVE ---------------------*/
		T remove(int pos) override
		{
			T elemento;

			if( pos >= 0 && pos < size() )
			{
				int i, j, new_size = size() - 1;

				T *aux = new T[new_size];

				for(i = 0, j = 0; i < size(); i++)
				{
					if(pos == i)
						elemento = arr[i];
					else
					{
						aux[j] = arr[i];
						j++
					}
				}

				delete[] arr;
				arr = aux;
				resize(new_size);
			}
			else
				throw std::out_of_range("Posicion no valida");

			return elemento;
		}



		/*--------------------- GET -----------------------*/
		T get(int pos) override
		{
			if(pos < 0 || pos >= size() )
				throw std::out_of_range("Posicion no valida");
			else
				return arr[pos];
		}



		/*-------------------- SEARCH ---------------------*/
		int search(T e) override
		{
			int i = 0, pos_aux;

			while( arr[i] != e && i < size() )
				i++;

			(i == size()) ? (pos_aux = -1) : (pos_aux = i);

			return pos_aux;
		}



		/*-------------------- EMPTY ----------------------*/
		bool empty() override
		{
			bool aux;

			(n = 0) ? (aux = TRUE) : (aux = FALSE);

			return aux;
		}



		/*--------------------- SIZE ----------------------*/
		int size() override
		{
			return max;
		}



		/*-------------------------------------------------*/
                /*                    ListArray                    */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Metodo constructor sin argumentos. Se encargara */
                /* de reservar memoria dinamica para crear un      */
                /* array de MINSIZE elementos de tipo T, ademas de */
                /* inicializar el resto de atributos de instancia. */
                /*                                                 */
                /*-------------------------------------------------*/

		ListArray()
		{
			arr = new T[MINSIZE];
			max = MINSIZE;	
			n = 0;
			
		}



		/*-------------------------------------------------*/
                /*                   ~ListArray                    */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Metodo destructor. Se encargara de liberar la   */
                /* memoria dinamica reservada.                     */
                /*                                                 */
                /*-------------------------------------------------*/

		~ListArray()
		{
			delete[] arr;			
		}



		/*-------------------------------------------------*/
                /*                    operator[]                   */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Sobrecarga del operador []. Devuelve el         */   
		/* elemento situado en la posición pos. Lanza una  */
		/* excepción std::out_of_range si la posición no   */
		/* es válida (fuera del intervalo [0, size()-1]).  */
                /*                                                 */
                /*-------------------------------------------------*/

		T operator[](int pos){

			return get(pos);
		}



		/*-------------------------------------------------*/
                /*                    operator<<                   */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Sobrecarga global del operador [] para imprimir */
                /* una instancia de ListArray<T> por pantalla.     */
                /*     		                                   */
                /*-------------------------------------------------*/

		friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list)
		{
			out << "Lista -> [";

			for(int i = 0; i < list.max; i++)
			{
				(list.n == 0) ? (out << "") : (out << std::endl << " " << list.arr[i]);

				if(i == (list.max-1) && list.n != 0 )
					out << std::endl;
			}
			out << "]";

			return out;

};

#endif
