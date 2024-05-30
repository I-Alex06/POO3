#pragma once
#include <string>
#include <vector>
#include <functional>

class Meniu{
    protected:
        std::vector<std::string> optiuni;
        std::vector<std::function<void()>> functii;
    public:
        virtual void addOptiune(const std::string& optiune,std::function<void()> functie);
        virtual void showOptiuni();
};