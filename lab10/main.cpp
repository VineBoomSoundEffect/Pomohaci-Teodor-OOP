#include <iostream>
#include <exception>

class outofboundsexception : public std::exception {
    virtual const char *what() const throw() {
        return "OUT OF BOUNDS\n";
    }
};
class outofmemoryexception : public std::exception {
    virtual const char *what() const throw() {
        return "ARRAY IS FULL\n";
    }
};

class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};
template<class T>
class ArrayIterator
{
private:
    T *current;
    T *start;
    int index, size;
public:
    ArrayIterator() {
        current = nullptr;
    }
    ArrayIterator(T *start, int index, int size) {
        current = start;
        this->index = index;
        this->size = size;
    }
    ArrayIterator& operator ++ () {
        // if outoboundsexception
        this->current++;
        index++;
        return this;
    }
    ArrayIterator& operator -- ();
    bool operator==(ArrayIterator<T> &) {
        return Compare::CompareElements(static_cast<void *>(this->current), static_cast<void *>(other)) == 0;
    }
    bool operator!=(ArrayIterator<T> &);
    T* GetElement();
};
template<class T>
class Array
{
private:
    T** List; // lista cu pointeri la obiecte de tipul T*
    int Capacity; // dimensiunea listei de pointeri
    int Size; // cate elemente sunt in lista
public:
    Array() {
        this->List = nullptr;
        this->Capacity = 0;
        this->Size = 0;
    }
    ~Array() {
        for (int i = 0; i < this->Size; i++) {
            delete this->List[i];
        }
        delete[] this->List;
    }
    Array(int capacity) {
        this->Capacity = capacity;
        this->List = new T*[capacity];
        this->Size = 0;
    }
    Array(const Array<T> &otherArray); // constructor de copiere

    T& operator[] (int index) {
        if (0 > index || index >= this->Size) {
            throw new outofboundsexception();
        }
        return this->List[index];
    }

    const Array<T>& operator+=(const T &newElem) {
        if (this->Size == this->Capacity) {
            throw new outofmemoryexception();
        }
        this->List[this->Size] = newElem;
        this->Size++;
        return this; // pentru a face chaining de +=
    }
    const Array<T>& Insert(int index, const T &newElem) {
        if (0 > index || index >= this->Capacity) {
            throw new outofboundsexception();
        }
        this->List[index] = newElem;
        return this;
    }

    const Array<T>& Insert(int index, const Array<T> otherArray) {
        if (0 > index || index >= this->Capacity) {
            throw new outofboundsexception();
        }
        int currentCap = this->Capacity - this->Size;
        if (currentCap < otherArray.Size) {
            throw new outofmemoryexception();
        }
        for (int i = this->Size; i >= index; i--) {
            this->List[i + otherArray.Size] = this->List[i];
        }
    }
    const Array<T>& Delete(int index) {
        if (0 > index || index >= this->Size) {
            throw new outofboundsexception();
        }
        for (int i = index; i < this->Size; i++) {
            this->List[i+1] = this->List[i];
        }
    }

    bool operator=(const Array<T> &otherArray);

    void Sort() {
        for (int i = 0; i < this->Size; i++) {
            for (int j = 0; j < this->Size; j++) {
                //if ()
            }
        }
    }
    void Sort(int(*compare)(const T&, const T&)){
        for (int i = 0; i < this->Size; i++) {
            for (int j = i; j < this->Size; j++) {
                if (compare(this->List[i], this->[j]) < 0) {
                    T *aux = this->List[i];
                    this->List[i] = this->List[j];
                    this->List[j] = aux;
                }
            }
        }
    }
    void Sort(Compare *comparator){
        for (int i = 0; i < this->Size; i++) {
            for (int j = i; j < this->Size; j++) {
                 = 0;
                if (Compare::CompareElements(static_cast<T*>(this->List[i]), static_cast<T*>(this->[j])) < 0) {
                    T *aux = this->List[i];
                    this->List[i] = this->List[j];
                    this->List[j] = aux;
                }
            }
        }
    }

    // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
    int BinarySearch(const T& elem) {
        this->Sort();
        int index = this->Size/2;
        if (this->List[index] < elem) BinarySearch();
    } // cauta un element folosind binary search in Array
    int BinarySearch(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind binary search si o functie de comparatie
    int BinarySearch(const T& elem, Compare *comparator);//  cauta un element folosind binary search si un comparator

    int Find(const T& elem); // cauta un element in Array
    int Find(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind o functie de comparatie
    int Find(const T& elem, Compare *comparator);//  cauta un element folosind un comparator

    int GetSize() {
        return this->Size;
    }
    int GetCapacity() {
        return this->Capacity;
    }

    ArrayIterator<T> GetBeginIterator();
    ArrayIterator<T> GetEndIterator();
};

int main() {
    Array<int> a();
    return 0;
}
