template <class T>
struct List{
  T val; List<T>* next;
}

template <class T>
struct Vec{
  T* data; size_t s, cap;
}

template <class T>
Vec<List<T>*> balanced_move(Vec<List<T>*> v, size_t k){
  
}
