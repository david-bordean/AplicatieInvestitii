#pragma once
#include <cstdlib>

// Interfata Strategy: algoritmul de calcul al variatiei de pret
class IStrategiePret {
public:
    virtual ~IStrategiePret() = default;
    virtual double genereazaProcent() = 0;
};

class StrategieAleatoare : public IStrategiePret {
public:
    double genereazaProcent() override {
        return 0.90 + (std::rand() % 21) / 100.0;
    }
};
