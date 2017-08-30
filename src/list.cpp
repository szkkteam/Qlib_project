/*
 * list.c
 *
 *  Created on: 2017. aug. 30.
 *      Author: irusics
 */


#include "list.h"

namespace Qlib
{
    namespace SL
    {

        template < class T >
        class list
        {
            struct Node
            {
                T data;
                Node * next;
                Node(T data, Node * next = nullptr):data(data), next(next) { }
            };
            Node * head;

        public:
            list(Node *head = nullptr):head(head) { }
            ~list();


        };

    }   /** SL */
}   /** Qlib */
