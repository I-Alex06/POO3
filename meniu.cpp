#pragma once
#include <functional>
#include "meniu.hpp"
#include <iostream>
#include <string>

void Meniu::addOptiune(const std::string& optiune,std::function<void()> functie)
{
    optiuni.push_back(optiune);
    functii.push_back(functie);
}
void Meniu::showOptiuni()
{   bool exit=false;
    while(!exit){
    for(int i=0;i<optiuni.size();i++)
    {
        std::cout<<i+1<<". "<<optiuni[i]<<std::endl;
    }
    std::cout<<optiuni.size()+1<<". Iesire"<<std::endl;
    std::string opts;int opt;
    std::cin>>opts;
    bool nm=true,allzero=true;
    for (int i=0;i<opts.size();i++)
    {
        if(opts[i]<'0'||opts[i]>'9')
        {
            nm=false;
        }
        if(opts[i]!='0')
        {
            allzero=false;
        }
    }
    if(nm&&!allzero){
    opt=std::stoi(opts);
    }
    else
    {   
        system("cls");
        std::cout<<"Optiune invalida"<<std::endl;
        continue;
    }    

    system("cls");
    if (opt==optiuni.size()+1)
    {
        exit=true;
    }
    else
    {
        if(opt>optiuni.size())
        {
            std::cout<<"Optiune invalida"<<std::endl;
            continue;
        }
        else
        {
            functii[opt-1]();
        }
    }
    }
}
