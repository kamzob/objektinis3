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
    size_type mdydis_; // Konteinerio dydis (dabar kiek elementu yra vektoriuje)
    size_type mtalpa_; // Talpa (kiek elementų gali būti saugoma)
public:
    // member types
    typedef T value_type;
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;

    typedef T
    // Konstruktorius
    Vektorius() : r_masyvas(nullptr), dydis(0), kiekis(0) {}

    // Dekstruktorius
    ~Vektorius()
    {
        delete[] mduom_;
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

        size_type size() const noexcept { return mdydis_; }
        size_type capacity() const noexcept { return mtalpa_; }
        bool empty() const noexcept { return mdydis_ == 0; }
};
#endif /* vektorius_h */
