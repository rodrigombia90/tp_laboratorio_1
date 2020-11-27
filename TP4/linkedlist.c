#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

static Node* getNode(LinkedList* this, int nodeIndex);//consigue la dir de memoria del nodo. recibe la dir de memoria del primer elemento y el indice, devuelve la dir de memoria del indice
static int addNode(LinkedList* this, int nodeIndex,void* pElement);//carga un nodo con una direccion de memoria

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;

    this = (LinkedList*) malloc(sizeof(LinkedList));
    if(this!=NULL)
    {
        this->size = 0;
        this->pFirstNode = NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)//es como si fuese un getter que accede al valor del campo
{
   // int size;
    int returnAux = -1;
    if(this!=NULL)
    {
        returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int contador=0;
    if(this!=NULL && nodeIndex>=0 && nodeIndex<ll_len(this))//menor a ll_l(this) tiene que estar entre 0 y el tamaño total que tiene
    {
        pNode=this->pFirstNode;//aca copio la dir de memoria del elemento 0 en pNode (primero vagon)

        while(contador<nodeIndex)//si el index es cero, no se entra aca y devuelve 0, caso contrario entra aca y devuelve el ultimo antes del 0
         {
            pNode=pNode->pNextNode;//aca copio el dir de memoria del elemento que sigue (el vagon que sigue y sigue y asi)
            contador++;
         }
         /*
         for(pNode=this->pFirstNode;contador<nodeIndex;contador++)
         {
             pNode=pNode->pNextNode;
         }*/
    }

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{//recibe una locomotora, lista y una carga
    //lo vagones se crean con un malloc

    int returnAux = -1;
 // Node* prev;
  //Node* next;
    Node* nuevoNodo= NULL;
    Node* nodoAuxiliar=NULL;//esto es una dir de memoria, cuando la cargamos

    if(this!=NULL && nodeIndex>=0 && nodeIndex<= ll_len(this))
    {
        nuevoNodo= (Node*) malloc(sizeof (Node));
        if(nuevoNodo !=NULL)
        {
            nuevoNodo->pElement=pElement;//aca se carga el vagon con la direccion de memori de la informacion a la que apunta (se lo cargar)
            if(nodeIndex==0)
            {
                //aca el nuevo nodo se engancha de la locomotora
                nuevoNodo->pNextNode=this->pFirstNode;
                this->pFirstNode= nuevoNodo;
            }
            else
            {
                //aca el nuevo nodo se engancha de un vagon
                //el nuevo nodo apunta a el vagon donde se va a insertar
                nodoAuxiliar=getNode(this,nodeIndex-1);
                nuevoNodo->pNextNode=nodoAuxiliar->pNextNode;
                nodoAuxiliar->pNextNode=nuevoNodo;
            }
            this->size++;
            returnAux=0;
        }
    }


    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
//esta no sabe la ubicacion
int ll_add(LinkedList* this, void* pElement)
{//crea un nuevo vagon y el campo apunta al vago que creamos, y este nuevo vagon hay que agregarlo al tren
    int returnAux = -1;
    //int indice = 0;
    //Node* actual;
    if(this!=NULL)
    {
       if(addNode(this,ll_len(this),pElement)==0)
       {
           returnAux=0;
       }
    }
    return returnAux;
}

//  ******* OJO CORREGIR *******************
/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
//ll_get trae la ubicacion de la carga,
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* auxNode=NULL;

     if(this!=NULL && index>=0 && index <ll_len(this))
     {
         auxNode=getNode(this,index);//si lo que trae es algo, ahi le asigno la carga
         if(auxNode!=NULL)
         {
             returnAux=auxNode->pElement;
         }
     }
    return returnAux;
}

/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */

int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* actual;
    //int cantidad;
    if(this!=NULL && index >=0 && index < ll_len(this))
    {
        actual=getNode(this,index);
        if(actual!=NULL)
        {
            actual->pElement=pElement;
            returnAux=0;
        }
    }

    return returnAux;
}

/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */

int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* actual;
    //Node* next;
    if(this!=NULL && index>=0 && index <ll_len(this))
    {
        actual=getNode(this,index);

        if(index==0)
        {
            this->pFirstNode=actual->pNextNode;
        }
        else
        {
            getNode(this,index-1)->pNextNode=actual->pNextNode;
        }
        free(actual);
        this->size--;
        returnAux=0;
    }
    return returnAux;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    //Node* nodo;

    if(this != NULL)
    {
        while(ll_len(this) != 0)//va actualizando el tamaño hasta que vale cero, ahi rompe el bucle y sale
        {
            ll_remove(this,ll_len(this));//va borrando y actualizanado los indices
            this->size--;
        }
        if(ll_len(this) == 0)
        {
            returnAux = 0;
        }
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        if(!ll_clear(this))//si devuelve algo distinto de cero es falso y no entra
        {
            free(this);
            returnAux=0;
        }
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        int tam=ll_len(this);//asi se llama una sola vez a ll_len, genera mejor eficiencia
        for(int i=0;i<tam;i++)
        {
            if(ll_get(this,i)==pElement)//aca devuelve el p element en la posicion i
            {
                returnAux=i;//la posicion del "vagon"
                break;
            }
        }
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        returnAux = 1;//asi le hago la pre carga asi me ahorro el else
        if( ll_len(this))
        {
            returnAux = 0;
        }
        //returnAux=ll_len(this)==0? 1: 0 ;

        //variable=condicion ? valor en caso de la condicion sea verdadera: valor en caso de que sea falsa;

    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */

int ll_push(LinkedList* this, int index, void* pElement)
{
    //int returnAux = -1;

         return addNode(this,index,pElement);

    //return returnAux;
}

/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
 //aca te da el elemento pero tambien lo saca de la lista
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this !=NULL && index>=0 && index < ll_len(this))
    {
        returnAux=ll_get(this,index);
        if(ll_remove(this,index))
        {
            returnAux=NULL;
        }
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
     if(this!=NULL)
     {
         returnAux=0;
         if(ll_indexOf(this,pElement)!=-1)
         {
             returnAux=1;
         }
     }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/


int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int len;
    void* aux;
    if(this!=NULL && this2 !=NULL)
    {
        returnAux=1;
        len=ll_len(this2);
        for(int i=0;i<len;i++)
        {
            aux=ll_get(this2,i);
            if(!ll_contains(this,aux))
            {
                returnAux=0;
                break;
            }
        }
    }

    return returnAux;
}



/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/


LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    if(this!=NULL && from>=0 && from<to && to<=ll_len(this) && to>from && from <ll_len(this))
    {
        cloneArray=ll_newLinkedList();
        for( ;from<to;from++)
        {
            ll_add(cloneArray,ll_get(this,from));
        }
    }
    return cloneArray;
}


/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this!=NULL)
    {
        return cloneArray=ll_subList(this,0,ll_len(this));
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    int tamanio;

    void* pElementI;
    void* pElementJ;
    void* pElementAuxiliar;

    if(this!= NULL && pFunc != NULL &&( order == 0 || order == 1))
    {
        tamanio = ll_len(this);
        for(int i = 0; i<tamanio-1;i++)
        {

           for(int j = i+1; j<tamanio;j++)
           {
               pElementI = ll_get(this,i);
               pElementJ = ll_get(this,j);


                if(order == 1)
                {
                    if(pFunc(pElementI,pElementJ))
                    {
                        pElementAuxiliar = pElementI;
                        pElementI = pElementJ;
                        pElementJ = pElementAuxiliar;
                        pElementI = ll_get(this,i);
                    }
                }else
                {
                    if(pFunc(pElementI,pElementJ)== -1)
                    {
                        pElementAuxiliar = ll_get(this,i);
                        ll_set(this,i,pElementJ);
                        ll_set(this,j,pElementAuxiliar);
                    }
                }
           }
           returnAux = 0;
        }
    }
    return returnAux;
}

