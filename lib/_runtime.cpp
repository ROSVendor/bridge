/**
 * Bridge运行时系统的实现
 */

#include <bridge/runtime.h>
#include <map>

extern "C" {

template <typename K, typename V>
class Map2D {
public:
    typedef std::map<K, std::map<K, V>> kernel_t;
    Map2D(V * def_val) {
        this->map2d = new kernel_t();
        this->def_val = def_val;
    }
    ~Map2D() {
        for (auto iter = this->map2d->begin();
             iter != this->map2d->end();
             ++iter) {
            delete iter->second;
        }
        delete this->map2d;
    }
    auto 
private:
    kernel_t * map2d = nullptr;
    V * def_val;
};


}



