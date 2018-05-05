#include <iostream>

#ifndef linkList_h
#define linkList_h
    template<typename T>
    class linkList
    {
        struct node
        {
            node *prev;
            node *next;
            T data;

            node(const T& tData, node* p = nullptr, node * n = nullptr)
                : data(tData), prev(p), next(n) {}

            node(T&& tData, node* p = nullptr, node * n = nullptr)
                : data(std::move(tData)), prev(p), next(n) {}
            
            node& operator= (node && rhs) {
                swap(prev, rhs.prev);
                swap(next, rhs.next);
                swap(data, rhs.data);
                return *this;
            }
        };
        
        class const_iterator {
            public:
                const_iterator() : curr(nullptr) {}
                const T& operator*() const {
                    return curr->data;
                }
                const_iterator& operator++ () {
                    curr = curr->next;
                    return *this;
                }
                const_iterator operator++ (int) {
                    const_iterator temp = *this;
                    ++(*this);
                    return temp;
                }
                const_iterator& operator-- () {
                    curr = curr->prev;
                    return *this;
                }
                const_iterator operator-- (int) {
                    const_iterator temp = *this;
                    --(*this);
                    return temp;
                }
                bool operator== (const_iterator& rhs) const {
                    return curr == rhs.curr;
                }
                bool operator!= (const_iterator& rhs) const {
                    return ! (*this == rhs);
                }
            private:
                node *curr;
                const_iterator(node* p): curr(p) {}
            
            friend class linkList<T>;
        };

        class iterator : public const_iterator {
            public:
                iterator() {};
                const T& operator* () const {
                    const_iterator* temp = const_cast<iterator*>(this);
                    return *(*temp);
                }
                T& operator* () {
                    return const_cast<T&>( *(static_cast<const iterator&>(*this)));
                }
                iterator& operator++ () {
                    const_iterator *temp = this;
                    ++(*temp);
                    return *this;
                }
                iterator operator++ (int) {
                    iterator temp = *this;
                    ++(*this);
                    return temp;
                }
                iterator& operator-- () {
                    const_iterator *temp = this;
                    --(*temp);
                    return *this;
                }
                iterator operator-- (int) {
                    iterator temp = *this;
                    --(*this);
                    return temp;
                }
            private:
                iterator(node* p): const_iterator(p) {}
            
            friend class linkList<T>;
        };
        public:
            linkList () {
                init();
            }
            linkList (const linkList& rhs) {
                std::cout << "In copy constructor" <<std::endl;
                init();
                for (const_iterator cIt = rhs.begin(); cIt != rhs.end(); cIt++)
                    pushBack(*cIt);
            }
            linkList (linkList&& rhs)
                :len(std::move(rhs.len)), head(std::move(rhs.head)), tail(std::move(rhs.tail))
            {
                rhs.len = 0;
                rhs.head = nullptr;
                rhs.tail = nullptr;

            }
            linkList& operator= (const linkList& rhs) {
                linkList temp = rhs;
                std::swap(*this, temp);
                return *this;
            }
            linkList& operator= (linkList&& rhs) {
                std::swap(len, rhs.len);
                std::swap(head, rhs.head);
                std::swap(tail, rhs.tail);
                return *this;
            }
            ~linkList() {
                clear();
                len = 0;
                delete head;
                delete tail;
            }
            int size() const {
                return len;
            }
            bool empty() const {
                return size() == 0;
            }
            const_iterator begin() const {
                return head->next;
            }
            iterator begin() {
                return head->next;
            }
            const_iterator end() const {
                return tail;
            }
            iterator end() {
                return tail;
            }
            void clear() {
                while(! empty())
                    popFront();
            }
            T& front() {
                return *(begin());
            }
            const T& front() const {
                return *(begin());
            }
            T& back() {
                return *(--end());
            }
            const T& back() const {
                return *(--end());
            }
            void pushFront(const T& x) {
                insert(x, begin());
            }
            void pushFront(T&& x) {
                insert(std::move(x), begin());
            }
            void pushBack(const T& x) {
                insert(x, end());
            }
            void pushBack(T&& x) {
                insert(std::move(x), end());
            }
            void popFront() {
                rem(begin());
            }
            void popBack() {
                rem(--end());
            }
            iterator insert(const T& x, iterator it) {
                node *temp = new node(x, it.curr->prev, it.curr);
                insertSubRoutine(it, temp);
                return it;
            }
            iterator insert(T&& x, iterator it) {
                node *temp = new node(std::move(x), it.curr->prev, it.curr);
                insertSubRoutine(it, temp);
                return it;
            }
            iterator rem(iterator it) {
                iterator rtIt (it.curr->next);
                it.curr->prev->next = it.curr->next;
                it.curr->next->prev = it.curr->prev;
                delete it.curr;
                len--;
                return rtIt;
            }
            iterator rem(iterator itrFrom, iterator itrTo) {
                iterator temp = itrFrom;
                while(temp != itrTo)
                    temp = rem(temp);
                return temp;
            }
            void printList() {
                for(auto it = begin(); it != end(); it++)
                    std::cout << *it << " ";
                std::cout << std::endl;
            }
        private:
            int len;
            node *head;
            node *tail;
            void init() {
                len = 0;
                head = new node(T());
                tail = new node(T(), head);
                head->next = tail;
            }
            void insertSubRoutine(iterator& it, node* newNode) {
                it.curr->prev->next = newNode;
                it.curr->prev = newNode;
                len++;
                it.curr = newNode;
            }
    };
#endif

/*
void main()
{
    linkList<int> tester;
    tester.pushBack(1);
    tester.pushBack(2);
    tester.pushBack(3);
    tester.pushFront(4);
    tester.popBack();

    linkList<int> tester2 = tester;
    tester2.pushFront(3);

    tester.printList();
    tester2.printList();
}
*/