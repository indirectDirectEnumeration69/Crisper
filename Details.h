#pragma once
#include <unordered_map>

template <typename T>
class Details {
public:
    std::unordered_map<std::thread::id, T> Infomation;
};

template <typename R>
class ThreadDetails : public Details<R> {
public:
    typename std::unordered_map<std::thread::id, R>::iterator Info;

    ThreadDetails() {
        Info = this->Infomation.begin();
    }

    ~ThreadDetails() {
       
    }
};
