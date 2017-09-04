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
                    const_iterator() : pCurrentNode(nullptr) {}

                    const T& operator*() const;

                    const_iterator& operator++() const;
                    const_iterator operator++(int) const;

                    const_iterator& operator--() const;
                    const_iterator operator--(int) const;

                    bool operator!=(const const_iterator& rhs) const;
                    bool operator==(const const_iterator& rhs) const;

                private :
                    const_iterator(Node * pNode) : pCurrentNode(pNode) {}

                    const Node *  pCurrentNode;

                    friend class list;
                };

             public:

                class iterator : public const_iterator
                {
                    iterator() { }

                    T& operator*() const { return  const_iterator::operator*(); }

                    iterator& operator++() const ;
                    iterator operator++(int) const;

                    iterator& operator--() const;
                    iterator operator--(int) const;

                    bool operator!=(const iterator& rhs) const;
                    bool operator==(const iterator& rhs) const;

                private:
                    iterator(Node * pNode) : const_iterator(pNode) {}
                };

             public:
                List();
                ~List();

                List(const List& rhs);
                List& operator=(const List& rhs);
           //     List(const list&& rhs) : size(rhs.size), pHead(rhs.pHead);
                List& operator=(const List&& rhs);

                iterator Begin(void);
                //const_iterator Begin(void);
                iterator End(void);
                //const_iterator End(void);

             private:


                Node * pHead;

                size_t size;

                iterator Erase (iterator it);
                void Clear(void);
                void Init(void);

             };


    } // DL list

}   /** Qlib */

#include "list.cpp"

#endif /* LIST_H_ */
