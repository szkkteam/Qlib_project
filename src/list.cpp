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
        /**
         * Node methods
         */
        template < class T >
        class List<T>::Node& List<T>::Node::NewNode(T data)
        {
            Node * element = new Node;
            element->data = data;
            element->pNext = nullptr;

            return element;
        }


        /**
         * Iterator methods
         */


        /**
         * List methods
         */
        template < class T >
        List<T>::~List()
        {
            Node * pCrawler = this->pHead;

            while (pCrawler)
            {
                Node * tmp = pCrawler;
                pCrawler = pCrawler->pNext;
                delete tmp;
            }
        }


        template < class T >
        class List<T>::Iterator List<T>::Begin(void) const
        {
            return Iterator(pHead);
        }

        template < class T >
        class List<T>::Iterator List<T>::End(void) const
        {
            return Iterator(nullptr);
        }

        template < class T >
        void List<T>::PushFront(T data)
        {
            Node * element = List<T>::Node::NewNode(data);

            element->pNext = this->pHead;
            this->pHead = element;
            this->size++;
        }

        template < class T >
        void List<T>::PushBack(T data)
        {
            Node * element = List<T>::Node::NewNode(data);

            if (this->pHead != nullptr)
            {
                Node * pCrawler = this->pHead;

                while(pCrawler->pNext != nullptr)
                {
                    pCrawler = pCrawler->pNext;
                }
                pCrawler->pNext = element;
            }
            else
            {
                this->pHead = element;
            }

            this->size++;
        }

    }   /** SL */
}   /** Qlib */

