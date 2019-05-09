/**
 *
 * \file    Duree.h
 *
 * \authors M. Laporte
 *
 * \date    02/04/2018
 *
 * \version V2.0
 *
 * \brief  déclarations de la classe Duree (avec constructeurs et
 *         destructeur)
 *
 **/

 #ifndef __DUREE_H__
 #define __DUREE_H__

namespace nsUtil
{
    typedef unsigned long long ULLong_t;

    class Duree
    {
      private :
        ULLong_t       myDuree;
        short unsigned mySeconds;
        short unsigned myMinutes;
        short unsigned myHours;
        ULLong_t       myDays;

        void normaliser (void);

      public :
        Duree  (const ULLong_t duree = ULLong_t (0));
        Duree  (const Duree & duree);
        ~Duree (void);

        ULLong_t getDuree (void) const;

        void display (void) const;

        Duree & operator ++ (void) noexcept; // préincrémentation de la classe CX
        Duree   operator ++ (int)  noexcept; // postincrémentation de la classe CX

        Duree & operator -- (void) noexcept; // préincrémentation de la classe CX
        Duree   operator -- (int)  noexcept; // postincrémentation de la classe CX

        Duree operator +  (const Duree & d) const;
        Duree operator -  (const Duree & d) const;

        Duree & operator += (const Duree &) noexcept;
        Duree & operator += (const unsigned long long &) noexcept;

        Duree & operator -= (const Duree &) noexcept;
        Duree & operator -= (const unsigned long long &) noexcept;

        bool  operator >  (const Duree & d) const;
        bool  operator <  (const Duree & d) const;
        bool  operator != (const Duree & d) const;
        bool  operator == (const Duree & d) const;

    }; // Duree

} // nsUtil

#endif /* __DUREE_H__ */
