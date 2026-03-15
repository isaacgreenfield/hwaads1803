#include <algorithm>
#include <iostream>

template <class T>
struct List{
  T val; List<T>* next;
};

template <class T>
struct Vec{
  T* data; size_t s, cap;
};

template <class T>
void clear(Vec<List<T>*>& v){
  for(size_t i = 0; i < v.s; ++i){
    while (v.data[i] != nullptr){
      List<T>* n = v.data[i]->next;
      delete v.data[i];
      v.data[i] = n;
    }
  }
}

template <class T>
size_t count (Vec<List<T>*> v){
  size_t ans = 0;
  for (size_t i = 0; i < v.s; ++i) for (List<T>* p = v.data[i]; p; p = p->next) ++ans;
  return ans;
}

template <class T>
List<T>* getNext(Vec<List<T>*>& v, size_t& pos){
  if(v.data[pos] != nullptr){
    List<T>* tmp = v.data[pos];
    v.data[pos] = tmp->next;
    return tmp;
  }
  while (pos < v.s && v.data[++pos] == nullptr) {}
  if (pos != v.s) return v.data[pos];
  else return nullptr;
}

template <class T>
Vec<List<T>*> balanced_move(Vec<List<T>*> v, size_t k){
  Vec<List<T>*> ans = Vec(new List<T>*[v.cap], v.s, v.cap);
  Vec<List<T>*> e = v;
  size_t pos = 0;
  try{
    for(size_t i = 0; i < std::min(count(e)/k, ans.cap); ++i){
      ans.data[i] = getNext(e, pos);
      List<T>* tmp = ans.data[i];
      for(size_t j = 1; j < k; ++j){
        tmp->next = getNext(e, pos);
        tmp = tmp->next;
      }
      tmp->next = nullptr;
    }
    ans.data[ans.cap - 1] = getNext(e, pos);
    List<T>* tmp = ans.data[ans.cap - 1];
    while (e.data[pos] != nullptr){
      tmp->next = getNext(e, pos);
      tmp = tmp->next;
    }
  } catch(...){
    clear(ans);
    std::cerr << "Balanced move faliure\n";
    throw;
  }
  return ans;
}
