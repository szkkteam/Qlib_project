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
                     friend class List;
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

                 private:
                     const Node *  pCurrentNode;

                     friend class List;
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
                    friend class List;
                };

             public:

                class const_Iterator
                {
                public:
                    const_Iterator() : pCurrentNode(nullptr) {}

                    const T& operator*() const;

                    const_Iterator& operator++() const;
                    const_Iterator operator++(int) const;

                    const_Iterator& operator--() const;
                    const_Iterator operator--(int) const;

                    bool operator!=(const const_Iterator& rhs) const;
                    bool operator==(const const_Iterator& rhs) const;

                protected :
                    T& Retrieve() const;

                    const_Iterator(Node * pNode) : pCurrentNode(pNode) {}

                    Node *  pCurrentNode;

                    friend class List;
                };

             public:

                class Iterator : public const_Iterator
                {
                public:
                    Iterator() { }

                    T& operator*() ;

                    Iterator& operator++() ;
                    Iterator operator++(int) ;

                    Iterator& operator--() ;
                    Iterator operator--(int) ;
                protected:
                    Iterator(Node * pNode) : const_Iterator(pNode) {}

                    friend class List;
                };

             public:
                List();
                ~List();

                List(const List& rhs);
                List& operator=(const List& rhs);
           //     List(const list&& rhs) : size(rhs.size), pHead(rhs.pHead);
                List& operator=(const List&& rhs);

                Iterator Begin(void);
                //const_Iterator Begin(void);
                Iterator End(void);
                //const_Iterator End(void);

                size_t Size(void);
                bool IsEmpty(void);
                void Clear(void);

                T& Front(void);
                T& Back(void);

                Iterator PushFront(T& data);
                Iterator PushBack(T& data);
#if 1
                Iterator PushFront(T&& data);
                Iterator PushBack(T&& data);
#endif
                Iterator Insert(Iterator it, T& data);
                Iterator Insert(Iterator it, T&& data);
                Iterator Erase (Iterator it);

                void PopFront(void);
                void PopBack(void);

             private:


                Node * pHead;
                Node * pTail;

                int size;


                void Init(void);

             };


    } // DL list

}   /** Qlib */

#include "list.cpp"

#endif /* LIST_H_ */
