#include <algorithm>

template <class T>
struct List{
  T val; List<T>* next;
}

template <class T>
struct Vec{
  T* data; size_t s, cap;
}

template <class T>
void clear(Vec<List<T>*> v){
  for(size_t i = 0; i < s; ++i){
    while (v.data[i] != nullptr){
      List<T>* n = v.data[i]->next;
      delete v.data[i];
      v.data[i] = n;
    }
  }
}

template <class T>
size_t count (Vect<List<T>*> v){
  size_t ans = 0;
  for(size_t i = 0; i < v.s; ++i){
    while(v.data[i] != nullptr) {
      ans++;
      v.data[i] = v.data[i[->next;
    }
  }
  return ans;
}

template <class T>
List<T>* getNext(Vec<List<T>*> v, size_t& pos){
  if(v.data[pos]->next != nullptr){
    v.data[pos] = v.data[pos]->next;
    return v.data[pos];
  }
  while (v.data[++pos] == nullptr) {}
  return v.data[pos];
}

template <class T>
Vec<List<T>*> balanced_move(Vec<List<T>*> v, size_t k){
  Vec<List<T>*> ans = Vec(new T[v.cap], v.s, v.cap);
  Vec<List<T>*> e = v;
  size_t pos = 0;
  for(size_t i = 0; i < std::max(count(e)/k, ans.cap); ++i){
    ans.data[i] = getNext(Vec<List<T>*> e, pos);
    List<T>* tmp = ans.data[i];
    for(size_t j = 1; j < k; ++j){
      tmp = tmp->next;
      tmp = getNext(Vec<List<T>*> e, pos);
    }
    tmp->next = nullptr;
  }
  ans.data[ans.cap - 1] = getNext(Vec<List<T>*> e, pos);
  List<T>* tmp = ans.data[i];
  while (e.data[pos] != nullptr){
    tmp = tmp->next;
    tmp = getNext(Vec<List<T>*> e, pos);
  }
  return ans;
}
