/*
 * list.c
 *
 *  Created on: 2017. aug. 30.
 *      Author: irusics
 */

#ifndef __LIST_CPP
#define __LIST_CPP

#include "list.h"

#include <iostream>
using namespace std;

namespace Qlib
{
    namespace SL
    {
        /**
         * Node methods
         */

        /**
         * Iterator methods
         */
    	template < class T >
    	const T& List<T>::const_Iterator::operator*() const
		{
    		return List<T>::const_Iterator::Retrieve();
		}

        template < class T >
        class List<T>::const_Iterator& List<T>::const_Iterator::operator++() const
		{

       		this->pCurrentNode = this->pCurrentNode->pNext;
        	return *this;
		}

        template < class T >
        class List<T>::const_Iterator List<T>::const_Iterator::operator++(int) const
		{
        	const_Iterator tmp = (*this);
        	++(*this);
        	return tmp;
		}

        template < class T >
        bool List<T>::const_Iterator::operator!=(const const_Iterator& rhs) const
		{
        	return (this->pCurrentNode != rhs.pCurrentNode);
		}

        template < class T >
        bool List<T>::const_Iterator::operator==(const const_Iterator& rhs) const
		{
        	return (this->pCurrentNode == rhs.pCurrentNode);
		}

        template < class T >
        T& List<T>::const_Iterator::Retrieve() const
        {
        	return this->pCurrentNode->data;
        }


        template < class T >
        T& List<T>::Iterator::operator*()
        {
            return List<T>::const_Iterator::Retrieve();
        }

        template < class T >
        class List<T>::Iterator& List<T>::Iterator::operator++()
		{

       		this->pCurrentNode = this->pCurrentNode->pNext;
        	return *this;
		}

        template < class T >
        class List<T>::Iterator List<T>::Iterator::operator++(int)
		{
        	Iterator tmp = (*this);
        	++(*this);
        	return tmp;
		}

        template < class T >
        bool List<T>::Iterator::operator!=(const Iterator& rhs)
		{
        	return (this->pCurrentNode != rhs.pCurrentNode);
		}

        template < class T >
        bool List<T>::Iterator::operator==(const Iterator& rhs)
        {
            return (this->pCurrentNode == rhs.pCurrentNode);
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
            delete this->pHead;
            delete this->pTail;
        }

        template < class T >
        List<T>::List(const List& rhs)
        {
        	//TODO:
            Init();

            for( auto & x : rhs )
            	PushFront( x );
        }

        template < class T >
        List<T>& List<T>::operator=(const List<T>& rhs)
        {
            List copy = rhs;
            std::swap(*this, copy);
            return *this;
        }

        template < class T >
        List<T>& List<T>::operator=(const List<T>&& rhs)
        {
            std::swap( this->size, rhs.size);
            std::swap( this->pHead, rhs.pHead);

            return *this;
        }

        template < class T >
        void List<T>::Clear(void)
		{
        	while (List<T>::IsEmpty() == false)
        	{
        		List<T>::PopFront();
        	}
		}


        template < class T >
        class List<T>::Iterator List<T>::Begin(void)
        {
            return Iterator(pHead->pNext);
        }

        template < class T >
        class List<T>::Iterator List<T>::End(void)
        {
            return Iterator(pTail);
        }


        template < class T >
        class List<T>::const_Iterator List<T>::Begin(void) const
        {
            return Iterator(pHead->pNext);
        }

        template < class T >
        class List<T>::const_Iterator List<T>::End(void) const
        {
            return Iterator(pTail);
        }

        template < class T >
        T& List<T>::Front(void)
        {
        	return *(List<T>::Begin());
        }

        template < class T >
        T& List<T>::Back(void)
        {
        	// Not implemented, because for single linked list it's not efficient
        	/*

            */
        }

        template < class T >
        const T& List<T>::Front(void) const
        {
        	return *(List<T>::Begin());
        }

        template < class T >
        const T& List<T>::Back(void) const
        {
        	// Not implemented, because for single linked list it's not efficient
        	/*

            */
        }

        template < class T >
        class List<T>::Iterator List<T>::PushFront(T& data)
        {
        	Node * element = new Node(data, this->pHead->pNext);
            ++this->size;

            this->pHead->pNext = element;

            return Iterator(element);
        }

        template < class T >
        class List<T>::Iterator List<T>::PushBack(T& data)
        {
        	// Not implemented, because for single linked list it's not efficient
        	/*

            */
        }

        template < class T >
        class List<T>::Iterator List<T>::PushFront(T&& data)
        {
        	Node * element = new Node( std::move(data), this->pHead->pNext);
            ++this->size;

            this->pHead->pNext = element;

            return Iterator(element);
        }

        template < class T >
        class List<T>::Iterator List<T>::PushBack(T&& data)
        {
        	// Not implemented, because for single linked list it's not efficient
        	/*

            */
        }

        template < class T >
        class List<T>::Iterator List<T>::Erase(Iterator it)
		{
        	// Not implemented, because for single linked list it's not efficient
			/*

			*/
		}

        template < class T >
        void List<T>::PopFront(void)
		{
        	Node * tmp = this->pHead->pNext;
        	this->pHead->pNext = this->pHead->pNext->pNext;
        	--this->size;
        	delete tmp;
		}

        template < class T >
        void List<T>::PopBack(void)
		{
        	// Not implemented, because for single linked list it's not efficient
        	/*
        	if (List<T>::IsEmpty() == false)
        	{
            	Node * crawler = this->pHead->pNext;
            	Node * prev = this->pHead;

            	while (crawler->pNext != this->pTail)
            	{
            		prev = crawler;
            		crawler = crawler->pNext;
            	}
        	}
        	*/
		}

        template < class T >
        bool List<T>::IsEmpty(void) const
		{
        	return (this->size == 0);
		}

        template < class T >
        size_t List<T>::Size(void) const
		{
        	return this->size;
		}

        template < class T >
        void List<T>::Init(void)
        {
        	this->pHead = new Node;
        	this->pTail = new Node;

            this->pHead->pNext = this->pTail;

            this->size = 0;
        }


    }   /** SL */

    namespace DL
    {
        /**
         * Node methods
         */

        /**
         * Iterator methods
         */
        template < class T >
        const T& List<T>::const_Iterator::operator*() const
        {
            return List<T>::const_Iterator::Retrieve();
        }

        template < class T >
        class List<T>::const_Iterator& List<T>::const_Iterator::operator++() const
        {
            this->pCurrentNode =  this->pCurrentNode->pNext;
            return *this;
        }

        template < class T >
        class List<T>::const_Iterator List<T>::const_Iterator::operator++(int) const
        {
            const_Iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        template < class T >
        class List<T>::const_Iterator& List<T>::const_Iterator::operator--() const
        {
            pCurrentNode = pCurrentNode->pPrev;
            return *this;
        }

        template < class T >
        class List<T>::const_Iterator List<T>::const_Iterator::operator--(int) const
        {
            const_Iterator tmp = *this;
            --(*this);
            return tmp;
        }

        template < class T >
        bool List<T>::const_Iterator::operator!=(const const_Iterator& rhs) const
        {
            return ( this->pCurrentNode != rhs.pCurrentNode);
        }

        template < class T >
        bool List<T>::const_Iterator::operator==(const const_Iterator& rhs) const
        {
            return (this->pCurrentNode == rhs.pCurrentNode);
        }

        template < class T >
        T& List<T>::const_Iterator::Retrieve() const
        {
        	return this->pCurrentNode->data;
        }


        template < class T >
        T& List<T>::Iterator::operator*()
        {
            return List<T>::const_Iterator::Retrieve();
        }

        template < class T >
        class List<T>::Iterator& List<T>::Iterator::operator++()
        {
            this->pCurrentNode = this->pCurrentNode->pNext;
            return *this;
        }

        template < class T >
        class List<T>::Iterator List<T>::Iterator::operator++(int)
        {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        template < class T >
        class List<T>::Iterator& List<T>::Iterator::operator--()
        {
            this->pCurrentNode = this->pCurrentNode->pPrev;
            return *this;
        }

        template < class T >
        class List<T>::Iterator List<T>::Iterator::operator--(int)
        {
            Iterator tmp = *this;
            --(*this);
            return tmp;
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
            delete this->pHead;
            delete this->pTail;
        }

        template < class T >
        List<T>::List(const List& rhs)
        {
            Init();

            for( auto & x : rhs )
                PushBack( x );
        }

        template < class T >
        List<T>& List<T>::operator=(const List<T>& rhs)
        {
            List copy = rhs;
            std::swap(*this, copy);
            return *this;
        }

        template < class T >
        List<T>& List<T>::operator=(const List<T>&& rhs)
        {
            std::swap( this->size, rhs.size);
            std::swap( this->pHead, rhs.pHead);

            return *this;
        }

        template < class T >
        class List<T>::Iterator List<T>::Begin(void)
        {
            return ( pHead->pNext );
        }

        template < class T >
        class List<T>::const_Iterator List<T>::Begin(void) const
        {
            return ( pHead->pNext);
        }

        template < class T >
        class List<T>::Iterator List<T>::End(void)
        {
            return ( Iterator (pTail ) );
        }

        template < class T >
        class List<T>::const_Iterator List<T>::End(void) const
        {
            return ( pHead );
        }


        template < class T >
        size_t List<T>::Size(void) const
        {
        	return this->size;
        }

        template < class T >
        bool List<T>::IsEmpty(void) const
        {
        	return ( List<T>::Size() == 0);
        }

        template < class T >
        void List<T>::Clear(void)
        {
        	while( List<T>::IsEmpty() == false )
        	{
        		List<T>::PopFront();
        	}
        }

        template < class T >
        T& List<T>::Front(void)
        {
        	return *(List<T>::Begin());
        }

        template < class T >
        T& List<T>::Back(void)
        {
        	return *(--List<T>::End());
        }


        template < class T >
        const T& List<T>::Front(void) const
        {
        	return *(List<T>::Begin());
        }

        template < class T >
        const T& List<T>::Back(void) const
        {
        	return *(--List<T>::End());
        }

        template < class T >
        class List<T>::Iterator List<T>::PushFront(T& data)
        {
        	return List<T>::Insert( List<T>::Begin(), data );
        }

        template < class T >
        class List<T>::Iterator List<T>::PushBack(T& data)
        {
           	return List<T>::Insert( List<T>::End(), data );
        }
#if 1
        template < class T >
        class List<T>::Iterator List<T>::PushFront(T&& data)
        {
        	return List<T>::Insert( List<T>::Begin(), std::move( data ) );
        }

        template < class T >
        class List<T>::Iterator List<T>::PushBack(T&& data)
        {
           	return List<T>::Insert( List<T>::End(), std::move( data ) );
        }
#endif
        template < class T >
        void List<T>::PopFront(void)
        {
        	List<T>::Erase( List<T>::Begin() );
        }

        template < class T >
        void List<T>::PopBack(void)
        {
        	List<T>::Erase( List<T>::End() );
        }

        template < class T >
        class List<T>::Iterator List<T>::Insert(Iterator it, T& data)
        {
        	Node * tmp = it.pCurrentNode;
            ++this->size;
        	Node * element = new Node(data, tmp->pPrev, tmp);
        	tmp->pPrev->pNext = element;
        	tmp->pPrev = tmp->pPrev->pNext;

        	return (Iterator( element ));
        }

        template < class T >
        class List<T>::Iterator List<T>::Insert(Iterator it, T&& data)
        {
        	Node * tmp = it.pCurrentNode;
            ++this->size;
        	Node * element = new Node( std::move( data ), tmp->pPrev, tmp);
        	tmp->pPrev->pNext = element;
        	tmp->pPrev = tmp->pPrev->pNext;

        	return (Iterator( element ));
        }

        template < class T >
        class List<T>::Iterator List<T>::Erase (List<T>::Iterator it)
        {
            Node * tmpNode = it.pCurrentNode;
            Iterator tmpIt (tmpNode->pNext);

            tmpNode->pPrev->pNext = tmpNode->pNext;
            tmpNode->pNext->pPrev = tmpNode->pPrev;

            delete tmpNode;

            --this->size;

            return tmpIt;
        }


        template < class T >
        void List<T>::Init(void)
        {
        	this->pHead = new Node;
        	this->pTail = new Node;

            this->pHead->pNext = this->pTail;
            this->pTail->pPrev = this->pHead;

            this->size = 0;
        }
    }
}   /** Qlib */

#endif
