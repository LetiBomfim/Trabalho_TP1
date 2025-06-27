// lembrar que a lista passa a ter ownership do valor alocado
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

        void push(T* val) {
            if (this->next == nullptr) {
                this->next = val;
                return;
            }

            this->next->push();
        }
};
