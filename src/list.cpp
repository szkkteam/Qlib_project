/*
 * list.c
 *
 *  Created on: 2017. aug. 30.
 *      Author: irusics
 */

#ifndef __LIST_CPP
#define __LIST_CPP

#include "list.h"

namespace Qlib
{
    namespace SL
    {
        /**
         * Node methods
         */
        template < class T >
        class List<T>::Node* List<T>::Node::NewNode(T data)
        {
            Node * element = new Node;
            element->data = data;
            element->pNext = nullptr;

            return element;
        }


        /**
         * Iterator methods
         */
        template < class T >
        class List<T>::Iterator& List<T>::Iterator::operator=(List<T>::Node * pNode)
        {
        	this->pCurrentNode = pNode;
        	return *this;
        }

        template < class T >
        class List<T>::Iterator& List<T>::Iterator::operator++()
		{
        	if (this->pCurrentNode)
        	{
        		this->pCurrentNode = this->pCurrentNode->pNext;
        	}
        	return *this;
		}

        template < class T >
        class List<T>::Iterator List<T>::Iterator::operator++(int)
		{
        	Iterator tmp = (*this);
        	++*this;
        	return tmp;
		}

        template < class T >
        bool List<T>::Iterator::operator!=(const Iterator& iterator) const
		{
        	return (this->pCurrentNode != iterator.pCurrentNode);
		}

        template < class T >
        T List<T>::Iterator::operator*()
        {
        	return pCurrentNode->data;
        }


        /**
         * List methods
         */

        template < class T >
        List<T>::~List()
        {
        	Clear();
        }

        template < class T >
        void List<T>::Clear(void)
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
        class List<T>::Iterator List<T>::PushFront(T data)
        {
        	Node * element = this->sentinel.NewNode(data);

            element->pNext = this->pHead;
            this->pHead = element;
            this->size++;

            return Iterator(element);
        }

        template < class T >
        class List<T>::Iterator List<T>::PushBack(T data)
        {
            Node * element = this->sentinel.NewNode(data);

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

            return Iterator(element);
        }

        template < class T >
        void List<T>::Erase(Iterator& element)
		{

        	if (element.pCurrentNode == this->pHead)
        	{
        		this->pHead = element.pCurrentNode->pNext;
        		delete element.pCurrentNode;
        	}

        	else if (element.pCurrentNode != nullptr)
        	{
                Node * pCrawler = this->pHead;

                while(pCrawler->pNext != element.pCurrentNode)
                {
                    pCrawler = pCrawler->pNext;
                }

                pCrawler->pNext = element.pCurrentNode->pNext;
                delete element.pCurrentNode;
        	}
		}

        template < class T >
        bool List<T>::IsEmpty(void)
		{
        	return (this->pHead == nullptr);
		}

        template < class T >
        size_t List<T>::Size(void)
		{
        	return this->size;
		}


    }   /** SL */
}   /** Qlib */

#endif
