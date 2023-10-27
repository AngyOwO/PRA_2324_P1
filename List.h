#ifndef LIST_H
#define LIST_H

template <typename T>

class List {
	public:

		/*-------------------------------------------------*/
		/*			insert			   */		
		/*-------------------------------------------------*/
		/*						   */
		/* DESCRIPCION:					   */
		/* Inserta el elemento e en la posicion pos. Lanza */
		/* excepción std::out_of_range si la posicion pos  */
		/* no es valida (fuera del intervalo [0, size()]). */
		/*						   */
		/*-------------------------------------------------*/

		virtual void insert(int pos, T e) = 0;


		/*-------------------------------------------------*/
                /*                      append                     */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Inserta el elemento e al final de la lista.     */
                /*                                                 */
                /*-------------------------------------------------*/

		virtual void append(T e) = 0;


		/*-------------------------------------------------*/
                /*                     prepend                     */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Inserta el elemento e al principio de la lista. */
                /*                                                 */
                /*-------------------------------------------------*/

		virtual void prepend(T e) = 0;


		/*-------------------------------------------------*/
                /*                      remove                     */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Elimina y devuelve el elemento T situado en la  */
                /* posicion pos. 				   */
		/* Lanza una excepcion std::out_of_range si la     */
                /* posicion no es valida (fuera del intervalo [0,  */
		/* size()-1]).					   */
                /*                                                 */
                /*-------------------------------------------------*/

		virtual T remove(int pos) = 0;


		/*-------------------------------------------------*/
                /*                      get                        */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Devuelve el elemento T situado en la posicion   */
                /* pos. Lanza una excepcion std::out_of_range si   */
                /* la posicion no es valida (fuera del intervalo   */
                /* [0, size()-1]).                                 */
                /*                                                 */
                /*-------------------------------------------------*/

		virtual T get(int pos) = 0;


		/*-------------------------------------------------*/
                /*                      search                     */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Devuelve la posición en la que se encuentra la  */
                /* primera ocurrencia del elemento e, o -1 si no   */
                /* se encuentra. 				   */
                /*                                                 */
                /*-------------------------------------------------*/

		virtual int search(T e) = 0;


		/*-------------------------------------------------*/
                /*                      empty                      */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Indica si la lista esta vacia.                  */
                /*                                                 */
                /*-------------------------------------------------*/

		virtual bool empty() = 0;


		/*-------------------------------------------------*/
                /*                      size                       */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Devuelve el numero de elementos de la lista.    */
                /*                                                 */
                /*-------------------------------------------------*/

		virtual int size() = 0;


};

#endif
