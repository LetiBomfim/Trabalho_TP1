#include "storage.hpp"

Storage* Storage::singleton = nullptr;

Storage* Storage::get_singleton() {
    if (Storage::singleton == nullptr) {
        Storage::singleton = new Storage();
    }

    return Storage::singleton;
}
