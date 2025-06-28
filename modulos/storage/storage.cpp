#include "storage.hpp"
#include <cstdint>

Storage* Storage::singleton = nullptr;
int64_t Storage::maior_codigo_de_carteira = 1;

Storage* Storage::get_singleton() {
    if (Storage::singleton == nullptr) {
        Storage::singleton = new Storage();
    }

    return Storage::singleton;
}
