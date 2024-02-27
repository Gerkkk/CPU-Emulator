#ifndef UNTITLED_CPUEMUL_H
#define UNTITLED_CPUEMUL_H

#include<iostream>
#include<vector>
#include<exception>

namespace stack{
    class StackException: public std::exception{
    public:
        explicit StackException(std::string &&cur_message) {
            message = std::move(cur_message);
        }

        const char* what() {
            return message.c_str();
        }
    private:
        std::string message;
    };

    template <class T>
    class Stack{
    private:
        int reserve{};
        int len{};

        T *data;

    public:
        Stack() {
            reserve = 4;
            len = 0;
            data = new T[4];
        }

        Stack(const Stack &s) {
            reserve = s.reserve;
            len = s.len;
            data = new T[s.reserve];
            for (int i = 0; i < s.len; i++){
                data[i] = s.data[i];
            }
        }

         Stack(const Stack &&s) noexcept{
            reserve = s.reserve;
            len = s.len;
            data = std::move(s.data);
        }

        Stack& operator=(const Stack &other){
            this = Stack(other);
            return *this;
        }

        Stack& operator=(Stack&& other) noexcept{
            len = std::move(other.len);
            reserve = std::move(other.reserve);
            data = std::move(other.data);
            return *this;
        }

        ~Stack(){
            delete []data;
        };

        int size() {
            return this->len;
        }

        T &top() {
            if (this->len == 0) {
                throw StackException("Trying to get the top element of empty stack");
            } else {
                T &a = this->data[this->len - 1];
                return a;
            }
        }

        bool empty() {
            if (this->len == 0) {
                return true;
            } else {
                return false;
            }
        }

        void push(T& elem) {
            if (this->len < this->reserve) {
                data[len] = elem;
                ++len;
            } else {
                T *new_data = new T[this->reserve * 2];
                for (int i = 0; i < this->len; i++) {
                    new_data[i] = data[i];
                }

                T *temp = this->data;
                this->data = new_data;
                delete [] temp;

                data[len] = elem;
                ++len;
                reserve = this->reserve * 2;
            }
        }

        void push(T&& elem) {
            if (this->len < this->reserve) {
                data[len] = std::move(elem);
                ++len;
            } else {
                T *new_data = new T[this->reserve * 2];
                for (int i = 0; i < this->len; i++) {
                    new_data[i] = data[i];
                }

                T *temp = this->data;
                this->data = new_data;
                delete [] temp;

                data[len] = std::move(elem);
                ++len;
                reserve = this->reserve * 2;
            }
        }

        void pop() {
            if (this->len > 0) {
                --len;
            } else {
                throw StackException("Trying to pop from empty stack");
            }
        }

    };
}

#endif //UNTITLED_CPUEMUL_H
