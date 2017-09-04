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
        }

        template < class T >
        List<T>::List(const List& rhs)
        {
            Init();

  //          this->pHead = rhs.pHead;
    //        this->size = rhs.size;
        }

        template < class T >
        List<T>& List<T>::operator=(const List<T>& rhs)
        {
            List copy = rhs;
            std::swap(*this, copy);
            return *this;
        }

   //     List(const list&& rhs) : size(rhs.size), pHead(rhs.pHead);

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
/*
        template < class T >
        List<T>::const_Iterator List<T>::Begin(void)
        {
            return ( pHead->pNext);
        }
*/
        template < class T >
        class List<T>::Iterator List<T>::End(void)
        {
            return ( Iterator (pTail ) );
        }
/*
        template < class T >
        List<T>::const_Iterator List<T>::End(void)
        {
            return ( pHead );
        }
*/

        template < class T >
        size_t List<T>::Size(void)
        {
        	return this->size;
        }

        template < class T >
        bool List<T>::IsEmpty(void)
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
        	Node * element = new Node(data, tmp->pPrev, tmp);
        	tmp->pPrev = element;
        	tmp->pPrev->pNext = element;
            ++this->size;

        	return (Iterator( element ));
        }

        template < class T >
        class List<T>::Iterator List<T>::Insert(Iterator it, T&& data)
        {
#if 0
        	// DAFAQ?!?!?!!?! NOT working
    //    	cout << "It: " << size;
        	Node * tmp = it.pCurrentNode;
            ++size;

        	Node * element = new Node( std::move( data ), tmp->pPrev, tmp);
        	tmp->pPrev = element;
        	tmp->pPrev->pNext = element;

      //  	cout << "It: " << size;

        	return (Iterator( element ));
#else
            Node *p = it.pCurrentNode;
            ++this->size;
            return Iterator( p->pPrev = p->pPrev->pNext = new Node( std::move( data ), p->pPrev, p ) );
#endif
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
