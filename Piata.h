#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Actiune.h"
#include "Crypto.h"
#include "Obligatiune.h"
#include "IObserverPiata.h"
#include "IStrategiePret.h"

// Functie libera template: cauta in orice vector un element dupa getNume()
template<typename T>
const T* cautaDupaNumeIn(const std::vector<T>& v, const std::string& n) {
    for (const auto& x : v)
        if (x.getNume() == n) return &x;
    return nullptr;
}

class Piata {
    std::vector<Actiune> actiuni;
    std::vector<Crypto> cryptos;
    std::vector<Obligatiune> obligatiuni;
    std::vector<IObserverPiata*> observatori;  // Observer
    IStrategiePret* strategie;                 // Strategy

    Piata();  // Singleton — constructor privat

public:
    static Piata& getInstance();
    ~Piata();

    Piata(const Piata&) = delete;
    Piata& operator=(const Piata&) = delete;

    void setStrategie(IStrategiePret* s);
    void inregistreaza(IObserverPiata* obs);
    void dezinregistreaza(IObserverPiata* obs);

    void actualizeazaPreturi();
    double getPret(const std::string& n) const;
    void cauta(const std::string& n) const;
    void afiseazaCatalogNumerot() const;
    void afiseazaActiuni(std::ostream& out) const;
    void afiseazaCrypto(std::ostream& out) const;
    void afiseazaObligatiuni(std::ostream& out) const;
    const InstrumentFinanciar& getInstrument(int idx) const;
    int numarInstrumente() const;

    friend std::ostream& operator<<(std::ostream& out, const Piata& p);
};
