#include "assignment/insertion_sort.hpp"

#include <utility>  // move, swap

#include "assignment/partitioning.hpp"  // middle_of

namespace assignment {

  int linear_search(const std::vector<int>& arr, int index) {

    // итерация всех предыдущих элементов [0, index - 1] (они находятся в отсортированном порядке)
    for (int curr_pos = 0; curr_pos < index; curr_pos++) {
      // если текущий элемент меньше или равен вставляемому, позиция для вставки найдена ...
      if (arr[curr_pos] > arr[index]) {
        return curr_pos;
      }
    }
    return index;
  }

  int binary_search(const std::vector<int>& arr, int index) {

    // начало, конец и середина области поиска места для вставки [0, index - 1]
    int start = 0 /* здесь что-то не так ... */;
    int stop = index - 1 /* здесь что-то не так ... */;
    int middle = middle_of(start, stop) /* здесь что-то не так ... */;

    // ищем до тех пор, пока границы не схлопнулись
    while (start <= stop) {

      // возвращаем позицию для вставки
      if (arr[index] == arr[middle]) {
        return middle /* здесь что-то не так ... */;
      }
      // обновляем границы области поиска ...
      if (arr[index] < arr[middle]) {
        stop = middle - 1;
      } else {
        start = middle + 1;
      }
      // обновляем середину области поиска
      middle = middle_of(start, stop);  // здесь что-то не так ...
    }

    // в конечном счете возвращаем начало последней области поиска
    return start;  // здесь что-то не так ...
  }

  void InsertionSort::Sort(std::vector<int>& arr) const {

    // - проходимся по элементам, начиная со второго
    // - после каждой итерации, слева от index будет формироваться отсортированный массив
    // - первый элемент слева считается отсортированным
    for (int index = 1; index < static_cast<int>(arr.size()); index++) {

      // поиск индекса для вставки элемента с индексом index в область [0, index - 1]
      const int ins_index = searcher_(arr, index);
      // если индекс вставки не совпадает с текущей позицией элемента,
      if (index != ins_index) {
        int elem = arr[index];
        // производим вставку элемента на вычисленную позицию (std::copy или цикл for) ...
        for (int i = index; i > ins_index; i--) {
          arr[i] = arr[i - 1];
        }
        arr[ins_index] = elem;
      }
    }
  }

  InsertionSort::InsertionSort(Searcher searcher) : searcher_{std::move(searcher)} {}

}  // namespace assignment