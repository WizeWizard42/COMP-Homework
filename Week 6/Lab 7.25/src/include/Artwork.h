#ifndef ARTWORKH
#define ARTWORKH

#include "Artist.h"
#include <string>

class Artwork{
    public:
        Artwork();

        Artwork(std::string title, int yearCreated, Artist artist);

        std::string GetTitle();

        int GetYearCreated();

        void PrintInfo();

    private:
        std::string title;
        int yearCreated;

        Artist artist;

};

#endif