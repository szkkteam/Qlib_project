/*
 * list.h
 *
 *  Created on: 2017. aug. 30.
 *      Author: irusics
 */

#ifndef LIST_H_
#define LIST_H_

#include <stddef.h>
#include <algorithm>

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
                     Node* NewNode(T data);

                     T  data;
                     Node * pNext;

                     // Linked list methods need to access Node information
                     friend class list;
                 };


             public:
                 class Iterator
                 {
                 public:
                     Iterator(const Node * pNode) noexcept : pCurrentNode(pNode) { }

                     Iterator& operator=(Node * pNode);
                     Iterator& operator++();
                     Iterator operator++(int);

                     bool operator!=(const Iterator& iterator) const;
                     bool operator==(const Iterator& iterator) const;

                     T operator*() const;
                     T* operator->() const;

                     const Node *  pCurrentNode;
                 private:

                     friend class list;
                 };

             public:
                 List() noexcept :pHead(nullptr), size(0) { }
                 ~List();

                 void Clear(void);

                 Iterator Begin(void) const;
                 Iterator End(void) const;

                 Iterator PushFront(T data);
                 Iterator PushBack(T data);

                 void Erase(Iterator& element);

                 bool IsEmpty(void);
                 size_t Size(void);

             private:


                 // FIXME : Change this sentinel, to something else
                 Node sentinel;
                 Node * pHead;
                 size_t size;
             };

    }   /**Llist */


    namespace DL
    {
        template < class T >
             class List
             {

             private:
                class Node
                {

                public:
                    Node* NewNode(T data);

                    T  data;
                    Node * pNext;
                    Node * pPrev;

                    Node(const T& data = T {}, Node * pPrev = nullptr, Node * pNext = nullptr)
                    : data(data), pPrev(pPrev), pNext(pNext) {}

                    Node ( T&& data, Node * pPrev = nullptr, Node * pNext = nullptr)
                    : data(std::move(data)), pPrev(pPrev), pNext(pNext) {}

                    // Linked list methods need to access Node information
                    friend class list;
                };

             public:

                class const_iterator
                {
                    const_iterator(Node * pNode) : pCurrentNode(pNode) {}
                    const_iterator() : pCurrentNode(nullptr) {}

                    const T& operator*() const;

                    const_iterator& operator++() const;
                    const_iterator& operator++(int) const;



                private :

                    const Node *  pCurrentNode;

                    friend class list;
                };

             public:
                List();
                ~List();


             private:


                Node * pHead;

                size_t size;

             };


    } // DL list

}   /** Qlib */

#include "list.cpp"

#endif /* LIST_H_ */
