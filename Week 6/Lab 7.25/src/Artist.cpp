#include <iostream>
#include <string>

#include "include/Artist.h"

Artist::Artist()
{
    artistName = "None";
    birthYear = 0;
    deathYear = 0;
}

Artist::Artist(std::string artistName, int birthYear, int deathYear)
{
    this->artistName = artistName;
    this->birthYear = birthYear;
    this->deathYear = deathYear;
}

std::string Artist::GetName() const
{
    return artistName;
}

int Artist::GetBirthYear() const
{
    return birthYear;
}

int Artist::GetDeathYear() const
{
    return deathYear;
}

void Artist::PrintInfo() const
{
    std::cout << "Artist: " << artistName;

    if (deathYear == -1)
    {
        std::cout << ", born " << birthYear;
    }
    else
    {
        std::cout << " (" << birthYear << "-" << deathYear << ")";
    }
    std::cout << std::endl;
}
