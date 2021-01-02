#ifndef KEY_VALUE
#define KEY_VALUE

//create template class with two types and an int
template<typename K, typename V, int max_size>
class KeyValue{
private:
    std::array<K, max_size> keys_; //declare private array
    std::array<V, max_size> values_;//declare private array
    int size_;//declare private int to hold size

    int FindIndex(K key) const;//private method to find index

public:
    //constructor
    KeyValue();

    //destructor
    ~KeyValue() {}

    //getter
    int GetSize() const;

    //other methods
    bool KeyExists(K key) const;
    void Add(K key, V item);
    V ValueAt(K key) const;
    bool Full() const;
    bool Empty() const;
    bool RemoveOne(K key);
    int RemoveAll(K key);

    friend std::ostream& operator<<(std::ostream& out, const KeyValue<K, V, max_size>& rhs){
        for(int i = 0; i < rhs.GetSize(); i++) {
            out << rhs.keys_[i] << ": " << rhs.values_[i] << "\n";
        }
        return out;
    }
};

/**
 * @brief sets size_ to 0
 * @tparam K
 * @tparam V
 * @tparam max_size
 */
template<typename K, typename V, int max_size>
KeyValue<K, V, max_size>::KeyValue(){
    size_ = 0;
}

/**
 * @brief returns size_
 * @tparam K
 * @tparam V
 * @tparam max_size
 * @return size_
 */
template<typename K, typename V, int max_size>
int KeyValue<K, V,max_size>::GetSize() const {
    return size_;
}

/**
 * @brief method that adds new keys/values to next index in array
 * @tparam K
 * @tparam V
 * @tparam max_size
 * @param key variable of type K
 * @param item variable of type V
 */
template<typename K, typename V, int max_size>
void KeyValue<K, V, max_size>::Add(K key, V item) {
    if (size_ == max_size){
        throw std::out_of_range("The container is full");
    }

    keys_[size_] = key;
    values_[size_] = item;

    size_++;
}

/**
 * @brief method that finds the index of a specified key, if no match returns -1
 * @tparam K
 * @tparam V
 * @tparam max_size
 * @param key variable of type K
 * @return index of key variable
 */
template<typename K, typename V, int max_size>
int KeyValue<K, V, max_size>::FindIndex(K key) const {
    for(int i = 0; i < size_; i++){
        if (key == keys_[i]){
            return i;
        }
    }
    return -1;
}

/**
 * @brief method that returns true if a certain key exists, if not returns false. calls FindIndex
 * method to see if the key exists in array
 * @param key variable of type K
 * @return true if match exists, false otherwise
 */
template<typename K, typename V, int max_size>
bool KeyValue<K, V, max_size>::KeyExists(K key) const {
    if(FindIndex(key) == -1){
        return false;
    }
    return true;
}

/**
 * @brief method that returns the value paired with a specified key. if key doesn't exist throws
 * exception
 * @param key variable of type k
 * @return value associated with key or throws exception
 */
template<typename K, typename V, int max_size>
V KeyValue<K, V, max_size>::ValueAt(K key) const {
    for (int i = 0; i < size_; i++) {
        if (key == keys_[i]) {
            return values_[i];
        }
    }
    throw std::out_of_range("Key not found");
}

/**
 * @brief method to test if size is zero. if size is == 0 array is empty and returns true.
 * @return true if empty, false otherwise
 */
template<typename K, typename V, int max_size>
bool KeyValue<K, V, max_size>::Empty() const {
    if (size_ == 0){
        return true;
    }

    return false;
}

/**
 * @brief bool method that tests if array is full. if size_ == max_size array is full
 * @return true if array is full, false otherwise
 */
template<typename K, typename V, int max_size>
bool KeyValue<K, V, max_size>::Full() const {
    return (size_ == max_size);
}

/**
 * @brief bool method that returns true if a specified key was found and removed.
 * @param key variable of type K
 * @return true if key found and removed, false otherwise
 */
template<typename K, typename V, int max_size>
bool KeyValue<K, V, max_size>::RemoveOne(K key) {
    for (int i = 0; i < size_; i++) {
        if (key == keys_[i]) {
            //shift all elements above this element
            for (int j = i; j < size_; j++ ){
                if (j+1 < size_) {
                    keys_[j] = keys_[j + 1];
                    values_[j] = values_[j + 1];
                }
            }
            size_--;
            return true;
        }
    }
    return false;
}

/**
 * @brief method that looks for a specific key and if found removes it. then continues looking
 * through the rest of array looking for same key to remove. once key and corresponding value are
 * removed the other key/values shift and size_ is decremented
 * @param key
 * @return
 */
template<typename K, typename V, int max_size>
int KeyValue<K, V, max_size>::RemoveAll(K key) {
    int items_removed = 0;
    int i = FindIndex(key);

        while(i != -1){
            for (int j = i; j < size_; j++) {
                if (j + 1 < size_) {
                    keys_[j] = keys_[j + 1];
                    values_[j] = values_[j + 1];
                }
                else{
                    keys_[j] = keys_[j - 1];
                    values_[j] = values_[j - 1];
                }
            }
            i = FindIndex(key);
            items_removed++;
            size_--;
        }
        return items_removed;
}
#endif