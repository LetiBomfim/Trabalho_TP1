#include "storage.hpp"
#include <cstdint>
#include "iostream"

using namespace std;

Storage* Storage::singleton = nullptr;
int64_t Storage::maior_codigo_de_carteira = 0;
int64_t Storage::maior_codigo_de_ordem = 0;

Storage* Storage::get_singleton() {
    cout << "batata" << endl;
    if (Storage::singleton == nullptr) {
        Storage::singleton = new Storage();
    }

    return Storage::singleton;
}
