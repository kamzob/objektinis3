//
//  vector.h
//  V3.0
//
//  Created by Kamilė Zobėlaitė on 2024-05-15.
//

#ifndef vektorius_h
#define vektorius_h


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
    
    void push_back(const T& x)
        {
            if (mdydis_ == mtalpa_)
                reserve(mtalpa_ == 0 ? 1 : mtalpa_ * 2);
            mduom_[mdydis_++] = x;
        }

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

        void pop_back()
        {
            if (mdydis_ > 0)
                --mdydis_;
        }

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

        size_type size() const noexcept { return mdydis_; }
        size_type capacity() const noexcept { return mtalpa_; }
        bool empty() const noexcept { return mdydis_ == 0; }

        iterator begin() noexcept { return mduom_; }
        const_iterator begin() const noexcept { return mduom_; }
        iterator end() noexcept { return mduom_ + mdydis_; }
        const_iterator end() const noexcept { return mduom_ + mdydis_; }

        void clear() noexcept
        {
            mdydis_ = 0;
        }
};
#endif /* vektorius_h */
