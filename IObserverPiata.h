#pragma once
class Piata;

// Interfata Observer: implementata de oricine vrea sa fie notificat la schimbari de pret
class IObserverPiata {
public:
    virtual ~IObserverPiata() = default;
    virtual void notificaActualizarePret(const Piata& p) = 0;
};
