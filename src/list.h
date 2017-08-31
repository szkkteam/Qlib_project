/*
 * list.h
 *
 *  Created on: 2017. aug. 30.
 *      Author: irusics
 */

#ifndef LIST_H_
#define LIST_H_

#include <stddef.h>

namespace Qlib
{
    namespace SL
    {

        template < class T >
             class List
             {
             private:

                 class Node
                 {

                 public:
                     Node& NewNode(T data);

                     T data;
                     Node * pNext;

                     // Linked list methods need to access Node information
                     friend class list;
                 };


             public:
                 class Iterator
                 {
                 public:
                     Iterator(const Node * pNode) noexcept : pCurrentNode(pNode) { }


                 private:

                 const Node *  pCurrentNode;


                     friend class list;
                 };



             public:
                 List(Node * head = nullptr) noexcept :pHead(head), size(1) { }
                 ~List();

                 Iterator Begin(void) const;
                 Iterator End(void) const;

                 void PushFront(T data);
                 void PushBack(T data);

             private:

                 Node * pHead;
                 size_t size;
             };

    }   /**Llist */
}   /** Qlib */


#endif /* LIST_H_ */
