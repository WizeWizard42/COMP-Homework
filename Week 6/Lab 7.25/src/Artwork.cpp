#include <iostream>

#include "include/Artwork.h"

Artwork::Artwork()
{
    title = "None";
    yearCreated = 0;
}

Artwork::Artwork(std::string title, int yearCreated, Artist artist)
{
    this->title = title;
    this->yearCreated = yearCreated;
    this->artist = artist;
}

std::string Artwork::GetTitle()
{
    return title;
}

int Artwork::GetYearCreated()
{
    return yearCreated;
}

void Artwork::PrintInfo()
{
    artist.PrintInfo();

    std::cout << "Title: " << title << ", " << yearCreated << std::flush;
}
