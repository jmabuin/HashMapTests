#ifndef LOCATION_H
#define LOCATION_H

struct location {
        constexpr
        location(unsigned int g = 0, unsigned int w = 0) noexcept :
            tgt{g}, win{w}
        {}

        unsigned int tgt;
        unsigned int win;

        friend bool
        operator < (const location& a, const location& b) noexcept {
            if(a.tgt < b.tgt) return true;
            if(a.tgt > b.tgt) return false;
            return (a.win < b.win);
        }

};



#endif // LOCATION_H
