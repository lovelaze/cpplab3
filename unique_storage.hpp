#ifndef UNIQUE_STORAGE_H
#define UNIQUE_STORAGE_H

#include <vector>
#include <memory>

namespace adventure {

    template<class T>
    class Unique_Storage {
        std::vector<std::unique_ptr<T>> data;


    public:
        Unique_Storage() {};
        virtual ~Unique_Storage() {};

        bool exists(T * element) {
            return at(element) != -1;
        }

        virtual std::unique_ptr<T> push_back(std::unique_ptr<T> e) {
            if (exists(e.get())) {
                e.release();
                throw std::invalid_argument("already in storage");
            }

            data.push_back(std::move(e));
            return nullptr;
        }


        virtual std::unique_ptr<T> remove(T * e) {
            std::unique_ptr<T> ptr = nullptr;

            for (auto it = data.begin(); it != data.end(); ++it) {
                if ((*it).get() == e) {
                    ptr = std::move(*it);
                    data.erase(it);
                    break;
                }
            }
            return ptr;
        }

        template <class E>
        std::unique_ptr<E> remove(const T * e) {
            std::unique_ptr<E> result((E*)((remove(e).release())));
            return result;
        }

        std::size_t size() const {
            return data.size();
        }

        void clear() {
            data.clear();
        }

        T * find(std::string type, std::string name) {

            for (auto it = data.begin(); it != data.end(); ++it) {
                if ((*it).get()->type() == type && (*it).get()->name() == name) return (*it).get();
            }

            return nullptr;
        }

    private:
        int at( T * element) {
            int index = 0;

            for (auto it = data.begin(); it != data.end(); ++it) {
                if ((*it).get() == element) return index;
                ++index;
            }

            return -1;
        }
    };

}


#endif
