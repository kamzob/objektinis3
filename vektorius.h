//
//  vector.h
//  V3.0
//
//  Created by Kamilė Zobėlaitė on 2024-05-15.
//

#ifndef vektorius_h
#define vektorius_h
#include <iterator>

template <typename T>
class Vektorius
{
private:
    T* mduom_; // Dinaminis masyvas, saugantis duomenis
    size_t mdydis_; // Konteinerio dydis (dabar kiek elementu yra vektoriuje)
    size_t mtalpa_; // Talpa (kiek elementų gali būti saugoma)
public:
    // member types
    typedef T value_type;
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
    
    // MEMBER FUNCTIONS
    // Konstruktoriai
        // (1) Empty container constructor (default constructor)
        Vektorius() : mduom_(nullptr), mdydis_(0), mtalpa_(0) {}

        // (2) Fill constructor
        Vektorius(size_type dydis, const T& value = T())
            : mduom_(new T[dydis]), mdydis_(dydis), mtalpa_(dydis)
        {
            std::fill(mduom_, mduom_ + mdydis_, value);
        }

        // (3) Range constructor
//        template <typename InputIterator>
//        Vektorius(InputIterator first, InputIterator last)
//        {
//            mdydis_ = std::distance(first, last);
//            mtalpa_ = mdydis_;
//            mduom_ = new T[mdydis_];
//            std::copy(first, last, mduom_);
//        }
    // (3) Range constructor
//        template <typename InputIterator>
//        Vektorius(InputIterator first, InputIterator last)
//            : mduom_(nullptr), mdydis_(0), mtalpa_(0)
//        {
//            while (first != last) {
//                push_back(*first);
//                first=std::next(first);
//            }
//        }

        // (4) Copy constructor
        Vektorius(const Vektorius& kitas)
            : mduom_(new T[kitas.mdydis_]), mdydis_(kitas.mdydis_), mtalpa_(kitas.mtalpa_)
        {
            for(int i = 0; i !=mdydis_; ++i)
            {
                mduom_[i]=kitas.mduom_[i];
            }
        }

        // (5) Move constructor
        Vektorius(Vektorius&& kitas) noexcept
            : mduom_(kitas.mduom_), mdydis_(kitas.mdydis_), mtalpa_(kitas.mtalpa_)
        {
            kitas.mduom_ = nullptr;
            kitas.mdydis_ = 0;
            kitas.mtalpa_ = 0;
        }

        // (6) Initializer list constructor
        Vektorius(std::initializer_list<T> sarasas)
            : mduom_(new T[sarasas.size()]), mdydis_(sarasas.size()), mtalpa_(sarasas.size())
        {
            std::copy(sarasas.begin(), sarasas.end(), mduom_);
        }
    


    // Dekstruktorius
        ~Vektorius()
        {
            delete[] mduom_;
        }
    // Operatoriai =
    // Kopijavimo priskyrimo operatorius
    Vektorius& operator=(const Vektorius& kitas)
    {
        if (this != &kitas) {
            T* naujiDuom = new T[kitas.mdydis_];
            for(int i = 0; i !=mdydis_; ++i)
            {
                naujiDuom[i]=kitas.mduom_[i];
            }
            delete[] mduom_;    // atlaisvinama sena atmintis
            mduom_ = naujiDuom; // mduom pointina i nauja atminti
            mdydis_ = kitas.mdydis_;
            mtalpa_ = kitas.mtalpa_;
        }
        return *this;
    }
    // Perkelimo priskyrimo operatorius
    Vektorius& operator=(Vektorius&& kitas) { // pavogiame objekto duomenys priskirymo metu
      // Savęs priskyrimo aptikimas
    if (&kitas == this) return *this;
    delete[] mduom_; // atlaisviname seną atmintį
    mduom_ = kitas.mduom_; // elem point'ina į v.elem atmintį
    mdydis_ = kitas.mdydis_; // atnaujiname size
    mtalpa_ = kitas.mtalpa_;
    kitas.mduom_ = nullptr; // v neturi jokių elementų
    kitas.mdydis_ = 0;
    kitas.mtalpa_= 0;

      return *this; // grąžiname objektą
    }
    
    
        // element access

        T& operator[](size_type indeksas)
        {
            if (indeksas >= mdydis_)
                throw std::out_of_range("Index out of range");
            return mduom_[indeksas];
        }

        const T& operator[](size_type indeksas) const
        {
            if (indeksas >= mdydis_)
                throw std::out_of_range("Index out of range");
            return mduom_[indeksas];
        }

        T& at(size_type indeksas)
        {
            if (indeksas >= mdydis_)
                throw std::out_of_range("Index out of range");
            return mduom_[indeksas];
        }

        const T& at(size_type indeksas) const
        {
            if (indeksas >= mdydis_)
                throw std::out_of_range("Index out of range");
            return mduom_[indeksas];
        }
        T& front()
        {
            if (mdydis_ == 0)
                throw std::out_of_range("Vektorius tuscias");
            return mduom_[0];
        }

        const T& front() const
        {
            if (mdydis_ == 0)
                throw std::out_of_range("Vektorius tuscias");
            return mduom_[0];
        }

        T& back()
        {
            if (mdydis_ == 0)
                throw std::out_of_range("Vektorius tuscias");
            return mduom_[mdydis_ - 1];
        }

        const T& back() const
        {
            if (mdydis_ == 0)
                throw std::out_of_range("Vektorius tuscias");
            return mduom_[mdydis_ - 1];
        }
        T* data() noexcept { return mduom_; }

        const T* data() const noexcept { return mduom_; }
    // capacity

        size_type size() const noexcept { return mdydis_; }
        size_type capacity() const noexcept { return mtalpa_; }
        bool empty() const noexcept { return mdydis_ == 0; }
        size_type max_size() const noexcept { return std::numeric_limits<size_type>::max(); }
        void reserve(size_type naujaTalpa)
        {
            if (naujaTalpa <= mtalpa_)
                return;

            T* naujiDuom = new T[naujaTalpa];
            for (size_type k = 0; k < mdydis_; ++k)
                naujiDuom[k] = std::move(mduom_[k]);

            delete[] mduom_;
            mduom_ = naujiDuom;
            mtalpa_ = naujaTalpa;
        }
        void shrink_to_fit() 
        {
            if (mdydis_ < mtalpa_) {
                T* naujiDuom = new T[mdydis_];
                std::copy(mduom_, mduom_ + mdydis_, naujiDuom);
                delete[] mduom_;
                mduom_ = naujiDuom;
                mtalpa_ = mdydis_;
            }
        }



    
    
        // ITERATORIAI
        iterator begin() noexcept { return mduom_; }
        const_iterator begin() const noexcept { return mduom_; }
        iterator end() noexcept { return mduom_ + mdydis_; }
        const_iterator end() const noexcept { return mduom_ + mdydis_; }
        const_iterator cbegin() const noexcept { return mduom_; }
        const_iterator cend() const noexcept { return mduom_ + mdydis_; }
        reverse_iterator rbegin() noexcept { return reverse_iterator(end()); }
        const_reverse_iterator rbegin() const noexcept { return const_reverse_iterator(end()); }
        reverse_iterator rend() noexcept { return reverse_iterator(begin()); }
        const_reverse_iterator rend() const noexcept { return const_reverse_iterator(begin()); }
        const_reverse_iterator crbegin() const noexcept { return const_reverse_iterator(end()); }
        const_reverse_iterator crend() const noexcept { return const_reverse_iterator(begin()); }
        
        // MODIFIERS

        void clear() noexcept
        {
            mdydis_ = 0;
        }
        iterator insert(const_iterator pos, const T& value) {
            size_type index = pos - begin();
            if (mdydis_ == mtalpa_) {
                size_type new_capacity = (mtalpa_ == 0) ? 1 : mtalpa_ * 2;
                reserve(new_capacity);
            }

            // Perstumiam visus elementus nuo įterpimo vietos į dešinę per viena
            for (size_type i = mdydis_; i > index; --i) {
                mduom_[i] = std::move(mduom_[i - 1]);
            }

            // Įterpiame naują elementą į vietą 'pos'
            mduom_[index] = value;
            ++mdydis_;

            return begin() + index;
        }
        iterator erase(const_iterator pos) {
            size_type index = pos - begin();
            if (index >= mdydis_) {
                throw std::out_of_range("Index out of range");
            }

            // Perstumiam visus elementus nuo 'pos' vienetu į kairę
            for (size_type i = index; i < mdydis_ - 1; ++i) {
                mduom_[i] = std::move(mduom_[i + 1]);
            }

            --mdydis_;
            return begin() + index;
        }
    iterator erase(const_iterator first, const_iterator last)
    {
        size_type first_index = first - begin();
        size_type last_index = last - begin();
        if (first_index > last_index || last_index > mdydis_) {
            throw std::out_of_range("Invalid range");
        }

        size_type num_to_erase = last_index - first_index;
        for (size_type i = first_index; i < mdydis_ - num_to_erase; ++i) {
            mduom_[i] = std::move(mduom_[i + num_to_erase]);
        }

        mdydis_ -= num_to_erase;
        return begin() + first_index;
    }
        void push_back(const T& x)
            {
                if (mdydis_ == mtalpa_)
                    reserve(mtalpa_ == 0 ? 1 : mtalpa_ * 2);
                mduom_[mdydis_++] = x;
            }



        void pop_back()
            {
                if (mdydis_ > 0)
                    --mdydis_;
            }
        void resize(size_type new_size, const T& value = T())
        {
            if (new_size < mdydis_) {
                mdydis_ = new_size;
            } else if (new_size > mdydis_) {
                reserve(new_size);
                for (size_type i = mdydis_; i < new_size; ++i) {
                    mduom_[i] = value;
                }
                mdydis_ = new_size;
            }
        }
        void resize(size_type new_size)
        {
            if (new_size < mdydis_) {
                mdydis_ = new_size;
            } else if (new_size > mdydis_) {
                reserve(new_size);
                mdydis_ = new_size;
            }
        }
        void swap(Vektorius& other) noexcept
        {
            //using std::swap; // Importuojame swap iš std

            // Keičiame visus narius su kitu vektoriumi
            swap(mduom_, other.mduom_);
            swap(mdydis_, other.mdydis_);
            swap(mtalpa_, other.mtalpa_);
        }
    // NON-MEMBER FUNCTIONS
        bool operator== (const Vektorius<T>& other) const {
                if (size() != other.size()) {
                    return false;
                }

                return std::equal(begin(), end(), other.begin());
            }
            bool operator!= (const Vektorius<T>& other) const {
                return !(*this == other);
            }
            bool operator < (const Vektorius<T> & other) const {
                return std::lexicographical_compare(begin(), end(), other.begin(), other.end());
            }
            bool operator <= (const Vektorius<T> & other) const {
                return !(other < *this);
            }
            bool operator > (const Vektorius<T> & other) const {
                return std::lexicographical_compare(other.begin(), other.end(), begin(), end());
            }
            bool operator >= (const Vektorius<T> & other) const {
                return !(other > *this);
            }

            void swap (Vektorius<T>& x, Vektorius<T>& y) {
                std::swap(x,y);
            }
    void print() const {
            for(size_type i = 0; i < mdydis_; ++i) {
                std::cout << mduom_[i] << " ";
            }
            std::cout << std::endl;
        }





};
#endif /* vektorius_h */
