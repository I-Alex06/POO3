#pragma once
#include <string>

template <typename T=float >
class Produs{
    protected:
        std::string nume;
        double pret;
        T cantitate;
    public:
        Produs(const std::string& _nume,const double _pret,const T _cantitate);
        //virtual void PrintInfo();
        std::string getNume();
        double getPret();
        T getCantitate();
        //template <>
        //float getCantitate();
        void setNume(const std::string& _nume);
        void setPret(const double _pret);
        void setCantitate(const T _cantitate);
        
};
template <>
class Produs<std::string>{
protected:
        std::string nume;
        double pret;
        float cantitate;
    public:
        Produs(const std::string& _nume,const double _pret,const std::string& _cantitate);
        //virtual void PrintInfo();
        std::string getNume();
        double getPret();
        float getCantitate();
        //template <>
        //float getCantitate();
        void setNume(const std::string& _nume);
        void setPret(const double _pret);
        void setCantitate(const float _cantitate);

};