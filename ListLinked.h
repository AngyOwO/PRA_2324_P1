#ifndef LISTLINKED_H
#define LISTLINKED_H

#include "List.h"
#include "Node.h"
#include <ostream>
#include <exception>

#define TRUE 1
#define FALSE 0

template <typename T>

class ListLinked : public List<T>{

	private:

		/*-------------------------------------------------*/
		/*			*first			   */
		/*-------------------------------------------------*/
		/*						   */
		/* DESCRIPCION:					   */
		/* Puntero al primer nodo de la secuencia enlazada */
		/* que almacena los datos de la lista ( de tipo T  */
		/* generico).					   */
		/*						   */
		/*-------------------------------------------------*/

		Node<T> *first;

		/*-------------------------------------------------*/
		/*			   n  			   */
		/*-------------------------------------------------*/
		/*						   */
		/* DESCRIPCION:					   */
		/* Numero de elementos que contiene la lista.      */
		/*						   */
		/*-------------------------------------------------*/

		int n;

	public:

		/*-------------------- INSERT ---------------------*/
		void insert(int pos, T e) override
		{
			if( !(pos < 0 || pos > size()) )
			{
				if(size() == 0)
				{
					first = new Node(e);
					n++;
				}
				else if(pos == 0)
					prepend(e);
				else if(pos == size())
					append(e);
				else
				{
					int i = 0;
					
					Node<T> *aux = first;
					Node<T> *prevAux = nullptr;

					while(i < pos)
					{
						prevAux = aux;
						aux = aux->next;
						i++;
					}
					Node<T> *insert = new Node(e, aux);
					prevAux->next = insert;
					n++;
				}
			}
			else
				throw std::out_of_range("Posicion no valida");
		}



		/*-------------------- APPEND ---------------------*/
		void append(T e) override
		{
			Node<T> *aux = new Node(e);
			first->next = aux;
			n++;
		}



		/*------------------- PREPEND ---------------------*/
		void prepend(T e) override
		{
			Node<T> *aux = new Node(e, first);
			first = aux;
    			n++;

		}



		/*-------------------- REMOVE ---------------------*/
		T remove(int pos) override
		{
			T elemento;

			if( pos >= 0 && pos < size() )
			{
				Node<T> *prevMark = nullptr;
				Node<T> *mark = first;

				int i = 0;

				// Quitamos el primero
				if(pos == 0)
					first = mark->next;

				//Quitamos del medio o del final
				else
				{
					while(i < pos)
					{
						prevMark = mark;
						mark = mark->next;
						i++;
					}
					prevMark->next = mark->next;
				}

				elemento = mark->data;
				delete mark;
				n--;
			}
			else
				throw std::out_of_range("Posicion no valida");

			return elemento;
		}



		/*--------------------- GET -----------------------*/
		T get(int pos) override
		{
			T elemento;

			if ( pos >= 0 && pos < size() )
			{
				Node<T> *aux = first;
 				int i = 0;
			
				while(i < pos)
				{
  					aux = aux->next;
  					i++;
				}
				elemento = aux->data;
 			}
			else 
				throw std::out_of_range("Posicion no valida");
			
			return elemento;
		}



		/*-------------------- SEARCH ---------------------*/
		int search(T e) override
		{
			Node<T> *aux = first;
 			int pos_aux = 0;
 			 
  			while ( aux != nullptr && aux->data != e )
  			{
  				aux = aux->next;
  				pos_aux++;
  			}
 
  			if (aux == nullptr) 
				pos_aux = -1; 

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
			return n;
		}



		/*-------------------------------------------------*/
                /*                    ListLinked                   */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Metodo constructor sin argumentos. Inicializara */
                /* los dos atributos de instancia (first sera      */
                /* nullptr). 					   */
                /*                                                 */
                /*-------------------------------------------------*/

		ListLinked()
		{
			first = nullptr;
			n = 0;
		}



		/*-------------------------------------------------*/
                /*                   ~ListLinked                   */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Metodo destructor. Se encargará de liberar la   */
                /* memoria dinamica resrvada por los nodos Node<T> */
                /* que componen la secuencia.                      */
                /*                                                 */
                /*-------------------------------------------------*/

		~ListLinked()
		{
			Node<T> *aux;
        		
        		while(size() > 0)
        		{
        			aux = first->next;
        			Node<T> *prevAux = first;
        			first = aux;
        			delete prevAux;
        			n--;
        		}
		}



		/*-------------------------------------------------*/
                /*                    operator[]                   */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Sobrecarga del operador []. Devuelve el         */
                /* elemento situado en la posición pos. Lanza una  */
                /* excepcion std::out_of_range si la posicion no   */
		/* es valida (fuera del intervalo [0, size() - 1]).*/
                /*                                                 */
                /*-------------------------------------------------*/

		T operator[](int pos)
        	{
        		return get(pos);
		}



		/*-------------------------------------------------*/
                /*                   operator <<                   */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Sobrecarga global del operador << para imprimir */
                /* una instancia de ListArray<T> por pantalla.     */
                /*                                                 */
                /*-------------------------------------------------*/

		friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list)
 		{
 			out << "List => [";
 			if(list.n == 0)
				out << ""; 
 			else
 			{
 				Node<T> *aux = list.first;

 				for(int i = 0; i < list.n; i++)
 				{
 					out << std::endl << "  " << aux->data;
 					aux = aux->next;
 				}
 				out << std::endl;
 			}

 			out << "]";

 			return out;
 		}


};

#endif
