
#ifndef PROYECTOFINAL_HEAP_H
#define PROYECTOFINAL_HEAP_H
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>

#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>

using namespace std;
using index_t = int;

// 1. Funciones para recorrer el heap
auto get_left_index = [] (index_t root_index){return root_index * 2;};
auto get_right_index = [](index_t root_index){return root_index * 2 + 1;};
inline index_t get_root_index(index_t current_index){return current_index / 2;}


// 2. Para seleccionar el hijo o el padre para comparar
bool has_parent(index_t current_index){return current_index/2 != 0;}
bool has_children(index_t current_index, index_t last_index){
    return get_left_index(current_index) <= last_index;
}
bool has_right_child(index_t current_index, index_t last_index){
    return get_right_index(current_index) <= last_index;
}

/* 3. Seleccionar el hijo
template<typename Container>
index_t get_selected_child(Container cnt,index_t current_index){
    if(!has_right_child(current_index,std::size(cnt) - 1))
        return get_left_index(current_index);
    auto left_index= get_left_index(current_index);
    auto right_index= get_right_index( current_index);

    return cnt[left_index] > cnt[right_index]? left_index:right_index;
}*/



auto get_selected_child=[](const auto& cnt,index_t current_index,auto& cmp){
    if(!has_right_child(current_index,std::size(cnt) - 1))
        return get_left_index(current_index);
    auto left_index= get_left_index(current_index);
    auto right_index= get_right_index( current_index);

    //std::less<>cmp;
    return cmp(cnt[right_index], cnt[left_index]) ? left_index:right_index; //Comparacion de valores
};

// 4. Implementar percolate up
template<typename Container,typename Compare>
void percolate_up(Container& cnt, index_t current_index,Compare& cmp) {
    // Ubicar el indice de la raíz inmediata
    auto root_index = get_root_index(current_index);
    //Condiciones Base de Recursividad
    // a. Si no tiene padre se detiene
    if (!has_parent(current_index)) return;
    // b. (Max heap) si el padre es mayor detener
    //std::less<>cmp;
    if (cmp(cnt[current_index] ,cnt[root_index])) return;
    //Intercambio de valores entre el padre y el hijo
    swap(cnt[root_index], cnt[current_index]);
    //Condicion Recursiva de ubicarse en el padre y llamar al percolate_up
    percolate_up(cnt, root_index,cmp);
}

// 5. Implementar percolate down
template<typename Container,typename Compare>
void percolate_down(Container& cnt, index_t current_index,Compare& cmp) {
    // Obtener el sub-indice del hijo mayor
    auto selected_index = get_selected_child(cnt, current_index,cmp);
    //Condiciones Base
    // a. Si no tiene hijos se detiene
    if (!has_children(current_index,std::size(cnt) -1)) return;
    // b. Si el valor actual es mayor que del hijo, detenerse
    //std::less<>cmp;
    if (cmp(cnt[selected_index],cnt[current_index])) return;
    //Intercambio de valores entre el padre y el hijo
    swap(cnt[current_index], cnt[selected_index]);
    //Condicion Recursiva de ubicarse en el hijo y llamar al percolate_down
    percolate_down(cnt, selected_index,cmp);
}


// 6. Heapify
template<typename Container, typename Compare>
void heapify(Container& cnt, Compare& cmp){
    // Ir al padre el ultimo
    auto current_index = get_root_index(std::size(cnt) -1);
    while (current_index > 0) {
        percolate_down(cnt, current_index,cmp);
        --current_index; // Ir al anterior
    }
}


template<typename T,
        template <typename...> typename Container = std::vector,
        typename Compare = less<T>>
class heap{
    Container<T> data;
    Compare cmp;
public:
    heap():data(1){}
    explicit heap(Compare cmp):data(1),cmp(cmp){}
    heap(std::initializer_list<T> lst): data(1+std::size(lst)){
        //Copiar lista de inicialización
        copy(begin(lst),end(lst),next(begin(data)));
        //Generar el heap
        heapify(data,cmp);
    }
    T top() { return data[1]; }
    bool empty() { return std::size(data)==1; }
    int size() { return std::size(data) -1; }
    void push(T value) {
        // Insertar al final
        data.push_back(value);
        // Ejecutar el percolate up
        percolate_up(data, std::size(data) -1,cmp);
    }
    void pop() {
        //Validación de vacío
        if(empty()) return;
        // Intercambio entre el primero y el último
        swap(data[1],data.back());
        data.pop_back();
        // Ejecutar el percolate down
        percolate_down(data,1,cmp);
    }

    bool replace(T old_value, T new_value){
        if(empty()) return false;
        auto iter = std::find(std::next(begin(data)),std::end(data),old_value);
        if(iter!= end(data)){
            *iter = new_value; //Formalmente deja de ser heap
            heapify(data,cmp);
            return true;
        }
        return false;
    }

    template<typename ...Params>
    void emplace(Params ...params){
        data.emplace_back(params...);
        percolate_down(data, std::size(data)-1,cmp);
    }


};



#endif //PROYECTOFINAL_HEAP_H
