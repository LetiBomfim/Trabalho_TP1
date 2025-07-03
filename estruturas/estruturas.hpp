#pragma once
template <typename T>
class lista {
    public:
        T value;
        lista* next = nullptr;

        void free() {
            if (this->next == nullptr) {
                return;
            }

            this->next->free();
            delete this->next;
        }

        void push(const T& val) {
            if (this->next == nullptr) {
                this->next = new lista<T>;
                this->next->value = val;
                this->next->next = nullptr;
                return;
            }

            this->next->push(val);
        }
};
