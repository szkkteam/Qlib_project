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
        bool List<T>::Iterator::operator==(const Iterator& iterator) const
        {
            return (this->pCurrentNode == iterator.pCurrentNode);
        }

        template < class T >
        T List<T>::Iterator::operator*() const
        {
        	return pCurrentNode->data;
        }

        template < class T >
        T* List<T>::Iterator::operator->() const
        {
            return &pCurrentNode->data;
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
        		this->size--;
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
                this->size--;
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

    namespace DL
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
            element->pPrev = nullptr;

            return element;
        }


        /**
         * Iterator methods
         */
        template < class T >
        const T& List<T>::const_iterator::operator*() const
        {
            return pCurrentNode->data;
        }

        template < class T >
        class List<T>::const_iterator& List<T>::const_iterator::operator++() const
        {
            pCurrentNode = pCurrentNode->pNext;
            return *this;
        }

        template < class T >
        class List<T>::const_iterator List<T>::const_iterator::operator++(int) const
        {
            const_iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        template < class T >
        class List<T>::const_iterator& List<T>::const_iterator::operator--() const
        {
            pCurrentNode = pCurrentNode->pPrev;
            return *this;
        }

        template < class T >
        class List<T>::const_iterator List<T>::const_iterator::operator--(int) const
        {
            const_iterator tmp = *this;
            --(*this);
            return tmp;
        }

        template < class T >
        bool List<T>::const_iterator::operator!=(const const_iterator& rhs) const
        {
            return ( this->pCurrentNode != rhs.pCurrentNode);
        }

        template < class T >
        bool List<T>::const_iterator::operator==(const const_iterator& rhs) const
        {
            return (this->pCurrentNode == rhs.pCurrentNode);
        }


        template < class T >
        class List<T>::iterator::iterator& List<T>::iterator::operator++() const
        {
            this->pCurrentNode = this->pCurrentNode->pNext;
            return *this;
        }

        template < class T >
        class List<T>::iterator::iterator List<T>::iterator::operator++(int) const
        {
            const_iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        template < class T >
        class List<T>::iterator::iterator& List<T>::iterator::operator--() const
        {
            this->pCurrentNode = this->pCurrentNode->pPrev;
            return *this;
        }

        template < class T >
        class List<T>::iterator::iterator List<T>::iterator::operator--(int) const
        {
            const_iterator tmp = *this;
            --(*this);
            return tmp;
        }

        template < class T >
        bool List<T>::iterator::operator!=(const iterator& rhs) const
        {
            return ( this->pCurrentNode != rhs.pCurrentNode);
        }

        template < class T >
        bool List<T>::iterator::operator==(const iterator& rhs) const
        {
            return ( this->pCurrentNode == rhs.pCurrentNode);
        }

        /**
         * List methods
         */
        template < class T >
        List<T>::List()
        {
            Init();
        }


        template < class T >
        List<T>::~List()
        {
            Clear();
        }


        template < class T >
        void List<T>::Clear(void)
        {

        }


        template < class T >
        void List<T>::Init(void)
        {
            Node * sentinel = new Node;

            this->pHead = sentinel;

            this->pHead->pNext = sentinel;
            this->pHead->pPrev = sentinel;

            this->size = 0;
        }
    }
}   /** Qlib */

#endif
